#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "TYPES.H"

extern OSThread_s *D_800D5270;

extern void func_802BC36C_de(void *queue_data);

extern void *func_802BC558_de(OSMesgQueue *queue);

extern void func_802BB750_de(void *value);

s32 func_802BB420_de(OSMesgQueue *queue, s32 entry, s32 mode) {
    extern void __osRestoreInt(s32 value);
    extern s32 func_802BCF30_de(void);
    s32 saved;

    saved = func_802BCF30_de();
    while (queue->validCount >= queue->msgCount) {
        if (mode != 1) {
            __osRestoreInt(saved);
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
    __osRestoreInt(saved);
    return 0;
}
