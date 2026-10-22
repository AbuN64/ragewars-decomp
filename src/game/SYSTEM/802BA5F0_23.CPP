#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "COMMON/EXTERNS_3.H"
#include "SDK/AUDIO_2/802BF300.H"
#include "SDK/AUDIO_2/802BFA00.H"

#if defined(VERSION_EU)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_11.H"
#include "COMMON/NODERECAT1C.H"
void func_802BB550_de(s32 event, OSMesgQueue *queue, void *message);
s32 func_802BADA0_de(OSThread_s *thread);
void func_802BB5F0_de(OSThread_s *thread, s32 priority);
void func_802BAC90_de(OSThread_s *thread, s32 id, void (*entry)(void *), void *arg, void *stack, s32 priority);
void func_802BB750_de(OSThread_s *thread);
extern OSThread_s D_80148850;
extern struct OSMesgQueue D_80149A80;
extern void *D_80149AA0[5];
extern u64 D_8014ED10_de[0x200];

void func_802BA5F0_eu(s32 arg0) {
    s32 temp_v0;
    s32 var_s3;
    u32 temp_v0_2;

    if (D_800D4420.active == 0) {
        var_s3 = -1;
        func_802BB9F8_de();
        osCreateMesgQueue(&D_80149A80, D_80149AA0, 5);
        D_80149AC0.hdr.type = 0xD;
        D_80149AC0.hdr.pri = 0;
        D_80149AC0.hdr.retQueue = 0;
        D_80149AE0.hdr.type = 0xE;
        D_80149AE0.hdr.pri = 0;
        D_80149AE0.hdr.retQueue = 0;
        func_802BB550_de(7, &D_80149A80, &D_80149AC0);
        func_802BB550_de(3, &D_80149A80, &D_80149AE0);
        temp_v0 = func_802BADA0_de(0);
        if (temp_v0 < arg0) {
            var_s3 = temp_v0;
            func_802BB5F0_de(0, arg0);
        }
        temp_v0_2 = func_802BCF30_de();
        D_800D4420.active = 1;
        D_800D4420.cmdQueue = &D_80149A80;
        D_800D4420.evtQueue = &D_80149A80;
        D_800D4420.thread = &D_80148850;
        D_800D4420.acsQueue = 0;
        D_800D4420.dma = 0;
        D_800D4420.edma = 0;
        func_802BAC90_de(&D_80148850, 0, D_002BA4C0, &D_800D4420, D_8014ED10_de + sizeof(D_8014ED10_de) / sizeof(D_8014ED10_de[0]), arg0);
        func_802BA210_de();
        func_802BB750_de(&D_80148850);
        __osRestoreInt(temp_v0_2);
        if (var_s3 != -1) {
            func_802BB5F0_de(0, var_s3);
        }
    }
}
#endif

/* viMgrMain, drafted from ultralib src/io/vimgr.c: the VI manager thread swaps the video context on
   each retrace, posts the client's retrace message every retraceCount retraces, advances the
   64-bit OS time, and runs timer interrupts. retrace is its static u16. */

extern u16 D_80148840;

extern struct __OSViContext *func_802BA640_de(void);

extern u32 func_802BCF00_de(void);
extern void func_802BB8B0_de(void);

static inline u16 *viRetrace(void)
{
    return &D_80148840;
}

void func_802BA4C0_de(struct OSDevMgr *arg)
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
    vc = func_802BA640_de();
    retraceInit = &D_80148840;
    *retraceInit = vc->retraceCount;
    if (*retraceInit == 0) {
        *retraceInit = 1;
    }
    dm = arg;

    while (1) {
        func_802BB2A0_de(dm->evtQueue, (OSMesg *)&mb, 1);
        switch (mb->hdr.type) {
            case 13:
                func_802BA910_de();
                if (--*viRetrace() == 0) {
                    vc = func_802BA640_de();
                    if (vc->msgq != 0) {
                        func_802BB420_de(vc->msgq, vc->msg, 0);
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
                func_802BB8B0_de();
                break;
            default:
                break;
        }
    }
}
