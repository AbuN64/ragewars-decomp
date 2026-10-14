#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BA23C.h"
#include "common/unused.h"
#include "types.h"

/* viMgrMain, drafted from ultralib src/io/vimgr.c: the VI manager thread swaps the video context on
   each retrace, posts the client's retrace message every retraceCount retraces, advances the
   64-bit OS time, and runs timer interrupts. retrace is its static u16. */

typedef void *OSMesg;
extern u16 D_80148840;

extern struct __OSViContext *func_802BA640_de(void);

extern s32 func_802BB2A0_de(Opaque_OSMesgQueue *mq, OSMesg *msg, s32 flag);
extern s32 func_802BB420_de(Opaque_OSMesgQueue *mq, OSMesg msg, s32 flag);
extern u32 func_802BCF00_de(void);
extern void func_802BB8B0_de(void);

static inline u16 *viRetrace(void)
{
    return &D_80148840;
}

void func_802BA4C0_de(void *arg)
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
    dm = (struct OSDevMgr *)arg;

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
