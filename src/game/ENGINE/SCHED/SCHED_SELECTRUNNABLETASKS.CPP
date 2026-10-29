#include "sdk/thread_queue.h"
#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/BOOT_TV_TYPE.H"
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/SCHED/osscremoveclient.H"
#include "sdk/libgultra/OSWRITEBACKDCACHEALL.H"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
extern s32 g_schedulerPendingFramebuffer;
extern s32 g_displayedFramebufferAndRefreshRate;
/* Initialises a panel: marks it active, clears its counters, lays out its two eight-slot rows, binds text 0x29B to 0x29D and 0x29A with the given style byte to the first row, and builds its element list from the PanelElementTemplate template. */




extern void osSetEventMesg(s32 slot, char *row, s32 text);

extern void System_SetVideoEvent(char *row, s32 text, s32 style);

extern void osCreateThread(char *list, s32 count, void *entryTemplate, Panel *owner, s32 stackPointer, s32 priority);


s32 Sched_SelectRunnableTasks(OSSched *scheduler, OSScTask_s **rspTaskOut, OSScTask_s **rdpTaskOut, s32 processorMask) {
    OSScTask_s *gfxListHead;
    OSScTask_s *audioListHead;
    OSScTask_s *next;
    OSScTask_s *runnableGraphicsTask;
    s32 initialProcessorMask;
    s32 graphicsTaskFlags;
    s32 state;
    s32 availableProcessors;

    availableProcessors = processorMask;
    gfxListHead = scheduler->gfxListHead;
    audioListHead = scheduler->audioListHead;
    initialProcessorMask = availableProcessors;
    if ((scheduler->doAudio != 0) && (availableProcessors & 2)) {
        if ((gfxListHead == 0) || !(gfxListHead->flags & 0x10)) {
            *rspTaskOut = audioListHead;
            scheduler->doAudio = 0;
            next = scheduler->audioListHead->next;
            availableProcessors &= ~2;
            scheduler->audioListHead = next;
            if (next == 0) {
                scheduler->audioListTail = 0;
            }
        } else {
            *rspTaskOut = gfxListHead;
            availableProcessors &= ~2;
        }
    } else {
        if (gfxListHead == 0) {
            runnableGraphicsTask = 0;
        } else if ((s32)gfxListHead->framebuffer == g_displayedFramebufferAndRefreshRate) {
            runnableGraphicsTask = 0;
        } else if (gfxListHead->framebuffer == osViGetCurrentFramebuffer()) {
            runnableGraphicsTask = 0;
        } else if ((s32)gfxListHead->framebuffer == g_schedulerPendingFramebuffer) {
            runnableGraphicsTask = 0;
        } else {
            runnableGraphicsTask = gfxListHead;
        }
        if (runnableGraphicsTask != 0) {
            graphicsTaskFlags = gfxListHead->flags & 7;
            switch (graphicsTaskFlags) {
            case 1:
            case 4:
            case 5:
                break;
            case 3:
                if (gfxListHead->state & 0x20) {
                    if (availableProcessors & 2) {
                        *rspTaskOut = gfxListHead;
                        availableProcessors &= ~2;
                        if (gfxListHead->state & 1) {
                            *rdpTaskOut = gfxListHead;
                            availableProcessors &= ~1;
                        }
                        scheduler->gfxListHead = scheduler->gfxListHead->next;
                        if (scheduler->gfxListHead == 0) {
                            scheduler->gfxListTail = 0;
                        }
                    }
                } else if (availableProcessors == 3) {
                    *rdpTaskOut = gfxListHead;
                    *rspTaskOut = gfxListHead;
                    scheduler->gfxListHead = scheduler->gfxListHead->next;
                    availableProcessors = 0;
                    if (scheduler->gfxListHead == 0) {
                        scheduler->gfxListTail = 0;
                    }
                }
                break;
            case 2:
            case 6:
            case 7:
                state = gfxListHead->state;
                if (state & 2) {
                    if (availableProcessors & 2) {
                        *rspTaskOut = gfxListHead;
                        availableProcessors &= ~2;
                    }
                } else if ((state & 1) && (availableProcessors & 1)) {
                    *rdpTaskOut = gfxListHead;
                    scheduler->gfxListHead = scheduler->gfxListHead->next;
                    availableProcessors &= ~1;
                    if (scheduler->gfxListHead == 0) {
                        scheduler->gfxListTail = 0;
                    }
                }
                break;
            }
        }
    }
    if (availableProcessors != initialProcessorMask) {
        availableProcessors = Sched_SelectRunnableTasks(scheduler, rspTaskOut, rdpTaskOut, availableProcessors);
    }
    return availableProcessors;
}

void Sched_InitializeSchedulerThread(Panel *panel, s32 threadStack, s32 priority, s32 unusedVideoMode, unsigned char style) {
    panel->active = 1;
    panel->curRSPTask = 0;
    panel->curRDPTask = 0;
    panel->clientList = 0;
    panel->frameCount = 0;
    panel->audioListHead = 0;
    panel->gfxListHead = 0;
    panel->audioListTail = 0;
    panel->gfxListTail = 0;
    panel->doAudio = 0;
    panel->mode = 4;
    osCreateMesgQueue(panel->row0, panel->row0Slots, 8);
    osCreateMesgQueue(panel->row1, panel->row1Slots, 8);
    osSetEventMesg(4, panel->row0, 0x29B);
    osSetEventMesg(9, panel->row0, 0x29C);
    osSetEventMesg(0xE, panel->row0, 0x29D);
    System_SetVideoEvent(panel->row0, 0x29A, style);
    osCreateThread(panel->elements, 7, &g_schedulerThreadEntryAddress, panel, threadStack, priority);
    osStartThread(panel->elements);
}
