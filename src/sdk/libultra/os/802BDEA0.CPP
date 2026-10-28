#include "include_asm.h"
#include "sdk/OSINT/802BEA40.H"
#include "sdk/libultra/os/802BDEA0.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#include "TYPES.H"
#include "COMMON/OSVISCALE.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
extern OSDevMgr D_800D4360;
extern void osSetEventMesg(s32, OSMesgQueue *, s32);
extern s32 osGetThreadPri(struct OSThread_s *);
extern void Scene_SetThreadPriority(struct OSThread_s *, s32);
extern void osCreateThread(struct OSThread_s *, s32, void (*)(void *), void *, void *, s32);
extern void osStartThread(struct OSThread_s *);

void osCreatePiManager(s32 pri, OSMesgQueue *cmdQ, void **cmdBuf, s32 cmdMsgCnt)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (D_800D4360.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&D_801486A0, D_801486B8, 1);

    if (!D_800D83C0[0]) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(8, &D_801486A0, 0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(0);

    if (myPri < pri) {
        oldPri = myPri;
        Scene_SetThreadPriority(0, pri);
    }

    savedMask = __osDisableInt();
    D_800D4360.active = 1;
    D_800D4360.acsQueue = &D_8014EA58;
    D_800D4360.dma = D_002B9A40;
    D_800D4360.edma = D_002B93B0;
    D_800D4360.evtQueue = &D_801486A0;
    D_800D4360.thread = &D_80147470;
    D_800D4360.cmdQueue = cmdQ;
    osCreateThread(&D_80147470, 0, D_002B9010, &D_800D4360, D_801476A0 + sizeof(D_801476A0), pri);
    osStartThread(&D_80147470);
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
