#include "sdk/thread_queue.h"
#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"
#include "COMMON/BOOT_TV_TYPE.H"
#include "sdk/AUDIO/vi.H"
#include "SYSTEM/VIMGR.H"
#include "sdk/os.h"
#include "include_asm.h"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "SYSTEM/VIDEO_CONTEXT_VIEWS.H"
#include "sdk/AUDIO/__OSVISWAPCONTEXT.H"

/* 802BA5F0_22.CPP */
#if !(defined(VERSION_EU))
/* osCreateViManager, drafted from ultralib src/io/vimgr.c (2.0I: no __additional_scanline). */

typedef struct OSThread OSThread;

extern OSThread g_videoManagerThread;
extern OSMesgQueue g_videoManagerEventQueue;
extern OSMesg g_videoManagerEventMessages[5];

extern void osSetEventMesg(s32 event, OSMesgQueue *mq, OSMesg msg);
extern s32 osGetThreadPri(OSThread *t);
extern void Scene_SetThreadPriority(OSThread *t, s32 pri);


void System_CreateVideoManager(s32 pri)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (g_videoDeviceManager.active) {
        return;
    }
    Util_InitializeTimerServices();
    osCreateMesgQueue(&g_videoManagerEventQueue, g_videoManagerEventMessages, 5);
    g_videoRetraceEvent.hdr.type = 13;
    g_videoRetraceEvent.hdr.pri = 0;
    g_videoRetraceEvent.hdr.retQueue = 0;
    g_videoTimerEvent.hdr.type = 14;
    g_videoTimerEvent.hdr.pri = 0;
    g_videoTimerEvent.hdr.retQueue = 0;
    osSetEventMesg(7, &g_videoManagerEventQueue, &g_videoRetraceEvent);
    osSetEventMesg(3, &g_videoManagerEventQueue, &g_videoTimerEvent);
    oldPri = -1;
    myPri = osGetThreadPri(0);

    if (myPri < pri) {
        oldPri = myPri;
        Scene_SetThreadPriority(0, pri);
    }

    savedMask = __osDisableInt();
    g_videoDeviceManager.active = 1;
    g_videoDeviceManager.thread = &g_videoManagerThread;
    g_videoDeviceManager.cmdQueue = &g_videoManagerEventQueue;
    g_videoDeviceManager.evtQueue = &g_videoManagerEventQueue;
    g_videoDeviceManager.acsQueue = 0;
    g_videoDeviceManager.dma = 0;
    g_videoDeviceManager.edma = 0;
    osCreateThread(&g_videoManagerThread, 0, System_VideoManagerThreadEntry, &g_videoDeviceManager, g_videoManagerThreadStack + 0x1000 / sizeof(u64), pri);
    __osViInit();
    osStartThread(&g_videoManagerThread);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        Scene_SetThreadPriority(0, oldPri);
    }
}
#endif

/* 802BA5F0_23.CPP */
#if defined(VERSION_EU)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/NODERECAT1C.H"
void osSetEventMesg(s32 event, OSMesgQueue *queue, void *message);
s32 osGetThreadPri(OSThread_s *thread);
void Scene_SetThreadPriority(OSThread_s *thread, s32 priority);
extern OSThread_s g_videoManagerThread;
extern struct OSMesgQueue g_videoManagerEventQueue;
extern void *g_videoManagerEventMessages[5];
extern u64 g_videoManagerThreadStack[0x200];

void System_CreateVideoManagerEu(s32 managerPriority) {
    s32 currentPriority;
    s32 restorePriority;
    u32 savedInterruptMask;

    if (g_videoDeviceManager.active == 0) {
        restorePriority = -1;
        Util_InitializeTimerServices();
        osCreateMesgQueue(&g_videoManagerEventQueue, g_videoManagerEventMessages, 5);
        g_videoRetraceEvent.hdr.type = 0xD;
        g_videoRetraceEvent.hdr.pri = 0;
        g_videoRetraceEvent.hdr.retQueue = 0;
        g_videoTimerEvent.hdr.type = 0xE;
        g_videoTimerEvent.hdr.pri = 0;
        g_videoTimerEvent.hdr.retQueue = 0;
        osSetEventMesg(7, &g_videoManagerEventQueue, &g_videoRetraceEvent);
        osSetEventMesg(3, &g_videoManagerEventQueue, &g_videoTimerEvent);
        currentPriority = osGetThreadPri(0);
        if (currentPriority < managerPriority) {
            restorePriority = currentPriority;
            Scene_SetThreadPriority(0, managerPriority);
        }
        savedInterruptMask = __osDisableInt();
        g_videoDeviceManager.active = 1;
        g_videoDeviceManager.cmdQueue = &g_videoManagerEventQueue;
        g_videoDeviceManager.evtQueue = &g_videoManagerEventQueue;
        g_videoDeviceManager.thread = &g_videoManagerThread;
        g_videoDeviceManager.acsQueue = 0;
        g_videoDeviceManager.dma = 0;
        g_videoDeviceManager.edma = 0;
        osCreateThread(&g_videoManagerThread, 0, System_VideoManagerThreadEntry, &g_videoDeviceManager, g_videoManagerThreadStack + sizeof(g_videoManagerThreadStack) / sizeof(g_videoManagerThreadStack[0]), managerPriority);
        __osViInit();
        osStartThread(&g_videoManagerThread);
        __osRestoreInt(savedInterruptMask);
        if (restorePriority != -1) {
            Scene_SetThreadPriority(0, restorePriority);
        }
    }
}
#endif

/* viMgrMain, drafted from ultralib src/io/vimgr.c: the VI manager thread swaps the video context on
   each retrace, posts the client's retrace message every retraceCount retraces, advances the
   64-bit OS time, and runs timer interrupts. retrace is its static u16. */

extern u16 g_videoManagerRetraceCountdown;

extern struct __OSViContext *System_GetCurrentVideoContext(void);

extern void Util_HandleTimerInterrupt(void);

static inline u16 *viRetrace(void)
{
    return &g_videoManagerRetraceCountdown;
}

void System_RunVideoManager(struct OSDevMgr *arg)
{
    struct __OSViContext *vc;
    struct OSDevMgr *dm;
    struct OSIoMesg *mb;
    s32 first;
    u32 count;

    u16 *retraceInit;
    u32 *intrCount;
    u32 *baseCounter;
    u64 *currentTime;

    mb = 0;
    first = 0;
    vc = System_GetCurrentVideoContext();
    retraceInit = &g_videoManagerRetraceCountdown;
    *retraceInit = vc->retraceCount;
    if (*retraceInit == 0) {
        *retraceInit = 1;
    }
    dm = arg;

    while (1) {
        osRecvMesg(dm->evtQueue, (OSMesg *)&mb, 1);
        switch (mb->hdr.type) {
            case 13:
                __osViSwapContext();
                if (--*viRetrace() == 0) {
                    vc = System_GetCurrentVideoContext();
                    if (vc->msgq != 0) {
                        osSendMesg(vc->msgq, vc->msg, 0);
                    }
                    *viRetrace() = vc->retraceCount;
                }

                intrCount = &g_timerServiceCounter;
                (*intrCount)++;

                if (first) {
                    count = Util_ReadProcessorCount();
                    __osCurrentTime = count;
                    first = 0;
                }

                baseCounter = &__osBaseCounter;
                count = *baseCounter;
                *baseCounter = Util_ReadProcessorCount();
                count = *baseCounter - count;
                currentTime = &__osCurrentTime;
                *currentTime = *currentTime + count;
                break;
            case 14:
                Util_HandleTimerInterrupt();
                break;
            default:
                break;
        }
    }
}
