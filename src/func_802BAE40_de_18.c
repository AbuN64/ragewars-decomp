#include "span_1000/code_802BB15C.h"
#include "types.h"






extern OSThread_s *D_800D5270;
extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);
extern void func_802BC36C_de(void *);
extern void *func_802BC558_de(void *);
extern void func_802BB750_de(void *);

s32 func_802BB2A0_de(OSMesgQueue *queue, void **message, s32 block)
{
    u32 mask = func_802BCF30_de();

    while (queue->validCount == 0) {
        if (!block) {
            __osRestoreInt(mask);
            return -1;
        }
        D_800D5270->state = 8;
        func_802BC36C_de(&queue->mtqueue);
    }

    if (message != 0) {
        *message = queue->msg[queue->first];
    }
    queue->first = (queue->first + 1) % queue->msgCount;
    queue->validCount--;
    if (*queue->fullqueue != 0) {
        func_802BB750_de(func_802BC558_de(&queue->fullqueue));
    }
    __osRestoreInt(mask);
    return 0;
}

