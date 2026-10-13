#include "span_1000/code_80256220.h"
#include "types.h"



extern void func_802BAC60_de(void *arg0, s32 arg1, s32 arg2);
extern Chunk *func_8025661C_de(void *arg0);
extern s32 func_802BB160_de(void *arg0, void *arg1, s32 arg2);
extern void func_802BB2A0_de(void *, void *, s32);




void func_8025637C_de(struct CartridgeReadWorker *arg0, u32 arg1, s32 arg2, void *arg3) {
    char queue[0x18];
    s32 queue_init;
    s32 completed;
    s32 remaining;
    s32 length;
    Chunk *chunk;

    func_802BAC60_de(queue, (s32) &queue_init, 1);
    remaining = arg2;
    do {
        chunk = func_8025661C_de(arg0);
        length = 0x2000;
        if (chunk == 0) {
            break;
        }
        chunk->source = arg1 + (arg2 - remaining);
        chunk->destination = (char *) arg3 + (arg2 - remaining);
        if ((u32) remaining < 0x2001U) {
            length = remaining;
        }
        chunk->length = length;
        chunk->queue = queue;
        func_802BB160_de(&arg0->requestQueueStorage, chunk, 1);
        func_802BB2A0_de(queue, &completed, 1);
        remaining -= length;
    } while (remaining != 0);
}
