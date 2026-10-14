/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "common/unused.h"
#include "types.h"
#include "span_1000/code_80256220.h"
/* Cartridge read thread loop: waits on the manager's request queue; a 0xBEEFDEAD message arms a
 * periodic timer that posts 0xDEADBEEF, a 0xDEADBEEF tick runs func_802AF990_us_rev1 when func_802955C8_us_rev1
 * reports work, and any other message is a read request whose buffer is invalidated, read from the
 * device through func_802B9A40_de, awaited on the completion queue, flushed, acknowledged to its reply
 * queue when one is given and finally retired through func_80256688_de. */





extern s32 func_802BB2A0_de(void *, void *, s32);
extern s32 func_802BB420_de(void *, void *, s32);
extern void func_802BB6C0_de(void *, u64, u64, void *, void *);
extern int func_802955C8_us_rev1(void);
extern void func_802AF990_us_rev1(void);
extern void func_802BD280_de(void *, s32);
extern s32 func_802B9A40_de(s32, u32, void *, u32);
extern void func_802BCF70_de(void *, s32);
extern void func_80256688_de(s32, void *);



void func_8025651C_us_rev1(s32 arg0) {
    struct OSTimer_s timer;
    struct CartridgeReadRequest *request;
    void *done;

    for (;;) {
        func_802BB2A0_de(&((struct CartridgeReadWorker *)(arg0))->requestQueueStorage, &request, 1);
        if (request == (struct CartridgeReadRequest *)0xBEEFDEAD) {
            func_802BB6C0_de(&timer, 0, 0x393870, &((struct CartridgeReadWorker *)(arg0))->requestQueueStorage, (void *)0xDEADBEEF);
        } else if (request == (struct CartridgeReadRequest *)0xDEADBEEF) {
            if (func_802955C8_us_rev1() != 0) {
                func_802AF990_us_rev1();
            }
        } else {
            func_802BD280_de(request->buffer, request->size);
            func_802B9A40_de(0, request->devAddr, request->buffer, request->size);
            func_802BB2A0_de(&((struct CartridgeReadWorker *)(arg0))->completionQueueStorage, &done, 1);
            func_802BCF70_de(request->buffer, request->size);
            if (request->replyQueue != 0) {
                func_802BB420_de(request->replyQueue, request->replyMsg, 1);
            }
            func_80256688_de(arg0, request);
        }
    }
}
