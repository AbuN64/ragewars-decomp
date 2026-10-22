#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#include "TYPES.H"
#include "COMMON/OSVISCALE.H"
#include "sdk/os.h"
extern OSDevMgr D_800D4360;
extern s32 D_800D83C0;
extern struct OSThread_s D_80147470;
extern OSMesgQueue D_801486A0, D_8014EA58;
extern void *D_801486B8[1];
extern char D_801476A0[0x1000];
extern s32 D_002B9A40(s32, u32, void *, u32);
extern s32 D_002B93B0(struct OSPiHandle_s *, s32, u32, void *, u32);
extern void D_002B9010(void *);
extern void func_802B9950_de(void);
extern void func_802BB550_de(s32, OSMesgQueue *, s32);
extern s32 func_802BADA0_de(struct OSThread_s *);
extern void func_802BB5F0_de(struct OSThread_s *, s32);
extern void func_802BAC90_de(struct OSThread_s *, s32, void (*)(void *), void *, void *, s32);
extern void func_802BB750_de(struct OSThread_s *);
extern u32 func_802BCF30_de(void);

void func_802B8DC8_de(s32 pri, OSMesgQueue *cmdQ, void **cmdBuf, s32 cmdMsgCnt)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (D_800D4360.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&D_801486A0, D_801486B8, 1);

    if (!D_800D83C0) {
        func_802B9950_de();
    }

    func_802BB550_de(8, &D_801486A0, 0x22222222);
    oldPri = -1;
    myPri = func_802BADA0_de(0);

    if (myPri < pri) {
        oldPri = myPri;
        func_802BB5F0_de(0, pri);
    }

    savedMask = func_802BCF30_de();
    D_800D4360.active = 1;
    D_800D4360.acsQueue = &D_8014EA58;
    D_800D4360.dma = D_002B9A40;
    D_800D4360.edma = D_002B93B0;
    D_800D4360.evtQueue = &D_801486A0;
    D_800D4360.thread = &D_80147470;
    D_800D4360.cmdQueue = cmdQ;
    func_802BAC90_de(&D_80147470, 0, D_002B9010, &D_800D4360, D_801476A0 + sizeof(D_801476A0), pri);
    func_802BB750_de(&D_80147470);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        func_802BB5F0_de(0, oldPri);
    }
}
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("span_1000", func_802B8F48_de_padding_B9DE8);
#endif
