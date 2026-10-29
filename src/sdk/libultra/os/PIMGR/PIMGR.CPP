#include "sdk/thread_queue.h"
#include "include_asm.h"
#include "sdk/OSINT/CREATE.H"
#include "sdk/libultra/os/pi_device_manager_operations.h"

/* 802BDEA0.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#include "TYPES.H"
#include "COMMON/OSVISCALE.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
extern OSDevMgr g_piManagerState;
extern void osSetEventMesg(s32, OSMesgQueue *, s32);
extern s32 osGetThreadPri(struct OSThread_s *);
extern void Scene_SetThreadPriority(struct OSThread_s *, s32);
extern void osCreateThread(struct OSThread_s *, s32, void (*)(void *), void *, void *, s32);

void osCreatePiManager(s32 pri, OSMesgQueue *cmdQ, void **cmdBuf, s32 cmdMsgCnt)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (g_piManagerState.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&g_peripheralManagerAccessQueue, g_peripheralAccessMessages, 1);

    if (!g_peripheralAccessQueueInitialized[0]) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(8, &g_peripheralManagerAccessQueue, 0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(0);

    if (myPri < pri) {
        oldPri = myPri;
        Scene_SetThreadPriority(0, pri);
    }

    savedMask = __osDisableInt();
    g_piManagerState.active = 1;
    g_piManagerState.acsQueue = &g_peripheralDmaAccessQueue;
    g_piManagerState.dma = System_PeripheralRawDmaEntry;
    g_piManagerState.edma = System_PeripheralExtendedDmaEntry;
    g_piManagerState.evtQueue = &g_peripheralManagerAccessQueue;
    g_piManagerState.thread = &g_peripheralManagerThread;
    g_piManagerState.cmdQueue = cmdQ;
    osCreateThread(&g_peripheralManagerThread, 0, System_PeripheralManagerThreadEntry, &g_piManagerState, g_peripheralManagerThreadStack + sizeof(g_peripheralManagerThreadStack), pri);
    osStartThread(&g_peripheralManagerThread);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        Scene_SetThreadPriority(0, oldPri);
    }
}
#endif

#if defined(VERSION_EU)
unsigned int func_802B8F48_de_padding_B9DE8[2] = {
    0xAFB1001C, 0xAFB00018,
};
#endif

/* 802BDEC0.CPP */
#if defined(VERSION_US_REV1)
#include "TYPES.H"
#include "COMMON/OSVISCALE.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
extern OSDevMgr g_piManagerState;
extern void osSetEventMesg(s32, OSMesgQueue *, s32);
extern s32 osGetThreadPri(struct OSThread_s *);
extern void Scene_SetThreadPriority(struct OSThread_s *, s32);
extern void osCreateThread(struct OSThread_s *, s32, void (*)(void *), void *, void *, s32);

void osCreatePiManager(s32 pri, OSMesgQueue *cmdQ, void **cmdBuf, s32 cmdMsgCnt)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (g_piManagerState.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&g_peripheralManagerAccessQueue, g_peripheralAccessMessages, 1);

    if (!g_peripheralAccessQueueInitialized[0]) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(8, &g_peripheralManagerAccessQueue, 0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(0);

    if (myPri < pri) {
        oldPri = myPri;
        Scene_SetThreadPriority(0, pri);
    }

    savedMask = __osDisableInt();
    g_piManagerState.active = 1;
    g_piManagerState.acsQueue = &g_peripheralDmaAccessQueue;
    g_piManagerState.dma = System_PeripheralRawDmaEntry;
    g_piManagerState.edma = System_PeripheralExtendedDmaEntry;
    g_piManagerState.evtQueue = &g_peripheralManagerAccessQueue;
    g_piManagerState.thread = &g_peripheralManagerThread;
    g_piManagerState.cmdQueue = cmdQ;
    osCreateThread(&g_peripheralManagerThread, 0, System_PeripheralManagerThreadEntry, &g_piManagerState, g_peripheralManagerThreadStack + sizeof(g_peripheralManagerThreadStack), pri);
    osStartThread(&g_peripheralManagerThread);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        Scene_SetThreadPriority(0, oldPri);
    }
}
#endif
