#include "span_1000/code_80256220.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80255BEC.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"

extern void func_802BB550_de(s32 arg0, s32 arg1, s32 arg2);

extern void func_802A001C_de(s32 arg0, s32 arg1, s32 arg2);

extern void func_802BAC90_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_802BB750_de(s32 arg0);

extern char D_0025657C;

extern Chunk *func_8025661C_de(void *arg0);

extern s32 func_802BB160_de(void *arg0, void *arg1, s32 arg2);

typedef struct Queue Queue;

extern s32 func_802BB160_de(void *, void *, s32);

extern s32 func_802BB420_de(void *, s32, s32);

void func_80256280_de(s32 arg0, s32 arg1) {
    extern void osCreateMesgQueue(s32 arg0, s32 arg1, s32 arg2);
    s32 s0;
    s32 s1;

    osCreateMesgQueue(arg0 + 0x230, arg0 + 0x248, 0x200);
    s0 = arg0 + 0xA48;
    osCreateMesgQueue(s0, arg0 + 0xA60, 1);
    func_802BB550_de(8, s0, 0x7D1);
    func_80255CA0_de(arg0 + 0x5068, 0x18, 0x1C);
    func_80255CA0_de(arg0 + 0x507C, 0x18, 0x1C);
    s1 = 0;
    s0 = 0xE68;
    do {
        ((struct func_80204468_S3 *) (arg0 + s0))->unk14 = 0;
        func_80255D14_de(arg0 + 0x5068, arg0 + s0);
        s1 += 1;
        s0 += 0x20;
    } while (s1 < 0x210);
    func_802A001C_de(arg0 + 0xA68, arg1, 0x400);
    func_802BAC90_de(arg0, arg1, &D_0025657C, arg0, arg0 + 0xE68, D_800CD8C4_de);
    func_802BB750_de(arg0);
}

void func_8025637C_de(struct CartridgeReadWorker *arg0, u32 arg1, s32 arg2, void *arg3) {
    extern void osCreateMesgQueue(void *arg0, s32 arg1, s32 arg2);
    char queue[0x18];
    s32 queue_init;
    s32 completed;
    s32 remaining;
    s32 length;
    Chunk *chunk;

    osCreateMesgQueue(queue, (s32) &queue_init, 1);
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

void func_80256454_de(struct CartridgeReadWorker *arg0, u32 source, s32 length, void *destination,
                   Queue *queue, s32 value, s32 direct) {
    s32 remaining;
    s32 chunk_length;
    Chunk *chunk;

    if (direct != 0) {
        chunk = func_8025661C_de(arg0);
        if (chunk != 0) {
            chunk->source = source;
            chunk->destination = destination;
            chunk->length = length;
            chunk->queue = queue;
            chunk->value = value;
            func_802BB160_de(&arg0->requestQueueStorage, chunk, 1);
        }
    } else {
        remaining = length;
        do {
            chunk = func_8025661C_de(arg0);
            chunk_length = 0x2000;
            if (chunk == 0) {
                break;
            }
            chunk->source = source + (length - remaining);
            chunk->destination = (char *)destination + (length - remaining);
            if ((u32)remaining < 0x2001U) {
                chunk_length = remaining;
            }
            remaining -= chunk_length;
            chunk->length = chunk_length;
            if (remaining != 0) {
                chunk->queue = 0;
                chunk->value = 0;
            } else {
                chunk->queue = queue;
                chunk->value = value;
            }
            func_802BB420_de(&arg0->requestQueueStorage, (s32)chunk, 1);
        } while ((chunk != 0) && (remaining != 0));
    }
}
