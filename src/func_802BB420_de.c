#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"





extern OSThread_s *D_800D5270;
extern s32 func_802BCF30_de(void);
extern void func_802BCF50_de(s32 value);
extern void func_802BC36C_de(void *queue_data);
extern void *func_802BC558_de(OSMesgQueue *queue);
extern void func_802BB750_de(void *value);

s32 func_802BB420_de(OSMesgQueue *queue, s32 entry, s32 mode) {
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
