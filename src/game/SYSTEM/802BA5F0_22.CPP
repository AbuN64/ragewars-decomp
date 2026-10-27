#include "COMMON/OSVISCALE.H"
#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "sdk/AUDIO_2/802BF300.H"
#include "SYSTEM/802BA5F0_22.H"
#include "sdk/os.h"

#if !(defined(VERSION_EU))
/* osCreateViManager, drafted from ultralib src/io/vimgr.c (2.0I: no __additional_scanline). */

typedef struct OSThread OSThread;







extern OSThread D_80148850;
extern OSMesgQueue D_80149A80;
extern OSMesg D_80149AA0[5];


extern void osSetEventMesg(s32 event, OSMesgQueue *mq, OSMesg msg);
extern s32 func_802BADA0_de(OSThread *t);
extern void func_802BB5F0_de(OSThread *t, s32 pri);

extern void osStartThread(OSThread *t);

void func_802BA350_de(s32 pri)
{
    u32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (D_800D4420.active) {
        return;
    }
    func_802BB9F8_de();
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
    myPri = func_802BADA0_de(0);

    if (myPri < pri) {
        oldPri = myPri;
        func_802BB5F0_de(0, pri);
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
        func_802BB5F0_de(0, oldPri);
    }
}
#endif
