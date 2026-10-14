#include "span_1000/code_80256220.h"
#include "types.h"
/* Receives read requests, transfers and acknowledges each one. The timer-message
 * handling belongs to the separate US-rev1 routine, which this item does not contain. */

extern s32 func_802BB2A0_de(void *, void *, s32);
extern s32 func_802BB420_de(void *, void *, s32);
extern void func_802BD280_de(void *, s32);
extern s32 func_802B9A40_de(s32, u32, void *, u32);
extern void func_802BCF70_de(void *, s32);
extern void func_80256688_de(void *, void *);

void func_8025657C_de(CartridgeReadWorker *worker) {
    CartridgeReadRequest *request;
    void *done;

    for (;;) {
        func_802BB2A0_de(&worker->requestQueueStorage, &request, 1);
        func_802BD280_de(request->buffer, request->size);
        func_802B9A40_de(0, request->devAddr, request->buffer, request->size);
        func_802BB2A0_de(&worker->completionQueueStorage, &done, 1);
        func_802BCF70_de(request->buffer, request->size);
        if (request->replyQueue != 0) {
            func_802BB420_de(request->replyQueue, request->replyMsg, 1);
        }
        func_80256688_de(worker, request);
    }
}
