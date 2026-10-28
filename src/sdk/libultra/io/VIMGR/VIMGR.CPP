#include "sdk/thread_queue.h"
#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "sdk/AUDIO/vi.H"
#include "SYSTEM/VIMGR.H"
#include "sdk/os.h"
#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "SYSTEM/VIDEO_CONTEXT_VIEWS.H"
#include "sdk/AUDIO/__OSVISWAPCONTEXT.H"

/* 802BA5F0_22.CPP */
#if !(defined(VERSION_EU))
/* osCreateViManager, drafted from ultralib src/io/vimgr.c (2.0I: no __additional_scanline). */

typedef struct OSThread OSThread;

extern OSThread D_80148850;
extern OSMesgQueue D_80149A80;
extern OSMesg D_80149AA0[5];

extern void osSetEventMesg(s32 event, OSMesgQueue *mq, OSMesg msg);
extern s32 osGetThreadPri(OSThread *t);
extern void Scene_SetThreadPriority(OSThread *t, s32 pri);


void func_802BA350_de(s32 pri)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (D_800D4420.active) {
        return;
    }
    Util_InitializeTimerServices();
    osCreateMesgQueue(&D_80149A80, D_80149AA0, 5);
    D_80149AC0.hdr.type = 13;
    D_80149AC0.hdr.pri = 0;
    D_80149AC0.hdr.retQueue = 0;
    D_80149AE0.hdr.type = 14;
    D_80149AE0.hdr.pri = 0;
    D_80149AE0.hdr.retQueue = 0;
    osSetEventMesg(7, &D_80149A80, &D_80149AC0);
    osSetEventMesg(3, &D_80149A80, &D_80149AE0);
    oldPri = -1;
    myPri = osGetThreadPri(0);

    if (myPri < pri) {
        oldPri = myPri;
        Scene_SetThreadPriority(0, pri);
    }

    savedMask = __osDisableInt();
    D_800D4420.active = 1;
    D_800D4420.thread = &D_80148850;
    D_800D4420.cmdQueue = &D_80149A80;
    D_800D4420.evtQueue = &D_80149A80;
    D_800D4420.acsQueue = 0;
    D_800D4420.dma = 0;
    D_800D4420.edma = 0;
    osCreateThread(&D_80148850, 0, D_002BA4C0, &D_800D4420, D_8014ED10_de + 0x1000 / sizeof(u64), pri);
    __osViInit();
    osStartThread(&D_80148850);
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
extern OSThread_s D_80148850;
extern struct OSMesgQueue D_80149A80;
extern void *D_80149AA0[5];
extern u64 D_8014ED10_de[0x200];

void func_802BA5F0_eu(s32 managerPriority) {
    s32 currentPriority;
    s32 restorePriority;
    u32 savedInterruptMask;

    if (D_800D4420.active == 0) {
        restorePriority = -1;
        Util_InitializeTimerServices();
        osCreateMesgQueue(&D_80149A80, D_80149AA0, 5);
        D_80149AC0.hdr.type = 0xD;
        D_80149AC0.hdr.pri = 0;
        D_80149AC0.hdr.retQueue = 0;
        D_80149AE0.hdr.type = 0xE;
        D_80149AE0.hdr.pri = 0;
        D_80149AE0.hdr.retQueue = 0;
        osSetEventMesg(7, &D_80149A80, &D_80149AC0);
        osSetEventMesg(3, &D_80149A80, &D_80149AE0);
        currentPriority = osGetThreadPri(0);
        if (currentPriority < managerPriority) {
            restorePriority = currentPriority;
            Scene_SetThreadPriority(0, managerPriority);
        }
        savedInterruptMask = __osDisableInt();
        D_800D4420.active = 1;
        D_800D4420.cmdQueue = &D_80149A80;
        D_800D4420.evtQueue = &D_80149A80;
        D_800D4420.thread = &D_80148850;
        D_800D4420.acsQueue = 0;
        D_800D4420.dma = 0;
        D_800D4420.edma = 0;
        osCreateThread(&D_80148850, 0, D_002BA4C0, &D_800D4420, D_8014ED10_de + sizeof(D_8014ED10_de) / sizeof(D_8014ED10_de[0]), managerPriority);
        __osViInit();
        osStartThread(&D_80148850);
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

extern u16 D_80148840;

extern struct __OSViContext *System_GetCurrentVideoContext(void);

extern void Util_HandleTimerInterrupt(void);

static inline u16 *viRetrace(void)
{
    return &D_80148840;
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
    retraceInit = &D_80148840;
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

                intrCount = &D_80149B94;
                (*intrCount)++;

                if (first) {
                    count = func_802BCF00_de();
                    D_80149B98 = count;
                    first = 0;
                }

                baseCounter = &D_80149B90;
                count = *baseCounter;
                *baseCounter = func_802BCF00_de();
                count = *baseCounter - count;
                currentTime = &D_80149B98;
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
