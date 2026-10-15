#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"

extern OSThread_s *D_800D5270;

extern void func_802BC36C_de(void *queue_data);

extern void *func_802BC558_de(OSMesgQueue *queue);

extern void func_802BB750_de(void *value);

extern struct IntPair D_80149B10[];

s32 func_802BB420_de(OSMesgQueue *queue, s32 entry, s32 mode) {
    extern void func_802BCF50_de(s32 value);
    extern s32 func_802BCF30_de(void);
    s32 saved;

    saved = func_802BCF30_de();
    while (queue->validCount >= queue->msgCount) {
        if (mode != 1) {
            func_802BCF50_de(saved);
            return -1;
        }
        D_800D5270->state = 8;
        func_802BC36C_de(&queue->fullqueue);
    }
    queue->msg[(queue->first + queue->validCount) % queue->msgCount] = entry;
    queue->validCount++;
    if (*queue->mtqueue != 0) {
        func_802BB750_de(func_802BC558_de(queue));
    }
    func_802BCF50_de(saved);
    return 0;
}

void func_802BB550_de(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_802BCF50_de(u32);
    extern u32 func_802BCF30_de(void);
    u32 temp_v0;
    struct IntPair *e;

    temp_v0 = func_802BCF30_de();
    ;
    (&D_80149B10[arg0])->field_0 = arg1;
    (*(&D_80149B10[arg0])).field_4 = arg2;
    func_802BCF50_de(temp_v0);
}
