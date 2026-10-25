#include "COMMON/EXTERNS_18.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TEXTURE/80256220.H"
#include "TYPES.H"
#include "sdk/os.h"

#if !(defined(VERSION_US_REV1))
/* Receives read requests, transfers and acknowledges each one. The timer-message
 * handling belongs to the separate US-rev1 routine, which this item does not contain. */

extern void func_802BD280_de(void *, s32);
extern s32 func_802B9A40_de(s32, u32, void *, u32);
extern void func_802BCF70_de(void *, s32);
extern void func_80256688_de(void *, CartridgeReadRequest *);

void func_8025657C_de(CartridgeReadWorker *worker) {
    CartridgeReadRequest *request;
    void *done;

    for (;;) {
        osRecvMesg(&worker->requestQueueStorage, &request, 1);
        func_802BD280_de(request->buffer, request->size);
        func_802B9A40_de(0, request->devAddr, request->buffer, request->size);
        osRecvMesg(&worker->completionQueueStorage, &done, 1);
        func_802BCF70_de(request->buffer, request->size);
        if (request->replyQueue != 0) {
            osSendMesg(request->replyQueue, request->replyMsg, 1);
        }
        func_80256688_de(worker, request);
    }
}
#endif
