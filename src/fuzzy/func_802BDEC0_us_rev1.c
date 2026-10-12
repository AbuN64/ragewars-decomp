/* osCreatePiManager, drafted from ultralib src/io/pimgr.c (2.0I, _FINALROM).
 * When no manager is active yet: initializes the command queue and the private event queue, starts
 * the manager thread at the requested priority, records the thread, queues, and the ROM's PIF DMA
 * handlers in the device-manager block D_800D4360, then restores the previous interrupt mask. */
#include "span_1000/code_802BAC58.h"
#include "types.h"

typedef void *OSMesg;
typedef struct OSMesgQueue OSMesgQueue;

struct OSThread_s_func_802BB5F0_de;
typedef struct OSThread_s_func_802BB5F0_de OSThread_s_func_802BB5F0_de;
struct ThreadNode;
typedef struct ThreadNode ThreadNode;

typedef struct {
    u32 active;
    OSThread_s *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*edma)(void *, s32, u32, void *, u32);
} OSDevMgr;

extern OSDevMgr D_800D4360;
extern s32 D_800D83C0;
extern OSThread_s D_80147470;
extern OSMesgQueue D_801486A0;
extern OSMesg D_801486B8[1];
extern OSMesgQueue D_8014EA58;

extern s32 D_002B9A40(s32, u32, void *, u32);
extern s32 D_002B93B0(void *, s32, u32, void *, u32);
extern void D_002B9010(void *);

extern void func_802BAC60_de(void *mq, s32 msg, s32 count);
extern void func_802B9950_de(void);
extern void func_802BB550_de(s32 event, s32 mq, s32 msg);
extern int func_802BADA0_de(void *t);
extern void func_802BB5F0_de(OSThread_s_func_802BB5F0_de *t, s32 pri);
extern void func_802BAC90_de(OSThread_s *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 p);
extern void func_802BB750_de(void *node);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 mask);

void func_802BDEC0_us_rev1(s32 pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (D_800D4360.active) {
        return;
    }
    func_802BAC60_de(cmdQ, (s32) cmdBuf, cmdMsgCnt);
    func_802BAC60_de(&D_801486A0, (s32) D_801486B8, 1);

    if (!D_800D83C0) {
        func_802B9950_de();
    }

    func_802BB550_de(8, (s32) &D_801486A0, 0x22222222);
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
    func_802BAC90_de(&D_80147470, 0, D_002B9010, &D_800D4360, &D_801486A0, pri);
    func_802BB750_de(&D_80147470);
    func_802BCF50_de(savedMask);

    if (oldPri != -1) {
        func_802BB5F0_de(0, oldPri);
    }
}
