#include "sdk/thread_queue.h"
#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/SCHED/osscremoveclient.H"
#include "sdk/libgultra/OSWRITEBACKDCACHEALL.H"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
extern s32 D_80142C30;
extern s32 D_80142C38;
/* Initialises a panel: marks it active, clears its counters, lays out its two eight-slot rows, binds text 0x29B to 0x29D and 0x29A with the given style byte to the first row, and builds its element list from the D_28E910 template. */




extern void osSetEventMesg(s32 slot, char *row, s32 text);

extern void System_SetVideoEvent(char *row, s32 text, s32 style);

extern void osCreateThread(char *list, s32 count, void *entryTemplate, Panel *owner, s32 arg4, s32 arg5);


s32 Sched_SelectRunnableTasks(OSSched *scheduler, OSScTask_s **arg1, OSScTask_s **arg2, s32 arg3) {
    OSScTask_s *gfxListHead;
    OSScTask_s *audioListHead;
    OSScTask_s *next;
    OSScTask_s *var_v1;
    s32 temp_s5;
    s32 temp_v0_2;
    s32 state;
    s32 availableProcessors;

    availableProcessors = arg3;
    gfxListHead = scheduler->gfxListHead;
    audioListHead = scheduler->audioListHead;
    temp_s5 = availableProcessors;
    if ((scheduler->doAudio != 0) && (availableProcessors & 2)) {
        if ((gfxListHead == 0) || !(gfxListHead->flags & 0x10)) {
            *arg1 = audioListHead;
            scheduler->doAudio = 0;
            next = scheduler->audioListHead->next;
            availableProcessors &= ~2;
            scheduler->audioListHead = next;
            if (next == 0) {
                scheduler->audioListTail = 0;
            }
        } else {
            *arg1 = gfxListHead;
            availableProcessors &= ~2;
        }
    } else {
        if (gfxListHead == 0) {
            var_v1 = 0;
        } else if ((s32)gfxListHead->framebuffer == D_80142C38) {
            var_v1 = 0;
        } else if (gfxListHead->framebuffer == osViGetCurrentFramebuffer()) {
            var_v1 = 0;
        } else if ((s32)gfxListHead->framebuffer == D_80142C30) {
            var_v1 = 0;
        } else {
            var_v1 = gfxListHead;
        }
        if (var_v1 != 0) {
            temp_v0_2 = gfxListHead->flags & 7;
            switch (temp_v0_2) {
            case 1:
            case 4:
            case 5:
                break;
            case 3:
                if (gfxListHead->state & 0x20) {
                    if (availableProcessors & 2) {
                        *arg1 = gfxListHead;
                        availableProcessors &= ~2;
                        if (gfxListHead->state & 1) {
                            *arg2 = gfxListHead;
                            availableProcessors &= ~1;
                        }
                        scheduler->gfxListHead = scheduler->gfxListHead->next;
                        if (scheduler->gfxListHead == 0) {
                            scheduler->gfxListTail = 0;
                        }
                    }
                } else if (availableProcessors == 3) {
                    *arg2 = gfxListHead;
                    *arg1 = gfxListHead;
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
                        *arg1 = gfxListHead;
                        availableProcessors &= ~2;
                    }
                } else if ((state & 1) && (availableProcessors & 1)) {
                    *arg2 = gfxListHead;
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
    if (availableProcessors != temp_s5) {
        availableProcessors = Sched_SelectRunnableTasks(scheduler, arg1, arg2, availableProcessors);
    }
    return availableProcessors;
}

void Sched_InitializeSchedulerThread(Panel *panel, s32 threadStack, s32 priority, s32 arg3, unsigned char style) {
    panel->active = 1;
    panel->field2F4 = 0;
    panel->field2F8 = 0;
    panel->field2E0 = 0;
    panel->field2FC = 0;
    panel->field2E4 = 0;
    panel->field2E8 = 0;
    panel->field2EC = 0;
    panel->field2F0 = 0;
    panel->field300 = 0;
    panel->mode = 4;
    osCreateMesgQueue(panel->row0, panel->row0Slots, 8);
    osCreateMesgQueue(panel->row1, panel->row1Slots, 8);
    osSetEventMesg(4, panel->row0, 0x29B);
    osSetEventMesg(9, panel->row0, 0x29C);
    osSetEventMesg(0xE, panel->row0, 0x29D);
    System_SetVideoEvent(panel->row0, 0x29A, style);
    osCreateThread(panel->elements, 7, &D_0028E930, panel, threadStack, priority);
    osStartThread(panel->elements);
}
