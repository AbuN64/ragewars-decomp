#include "COMMON/EXTERNS_18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "sdk/os.h"

extern OSThread_s *D_800D5270;

extern void func_802BC36C_de(void *queue_data);

extern void *__osPopThread(OSMesgQueue *queue);

extern void func_802BB750_de(void *value);

s32 osSendMesg(OSMesgQueue *queue, OSMesg entry, s32 mode) {
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
        func_802BB750_de(__osPopThread(queue));
    }
    __osRestoreInt(saved);
    return 0;
}
