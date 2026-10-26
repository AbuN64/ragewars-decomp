#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/os.h"

extern OSThread_s *D_800D5270;
extern void func_802BC36C_de(void *);
extern void *__osPopThread(void *);
extern void osStartThread(void *);

s32 osRecvMesg(OSMesgQueue *queue, OSMesg *message, s32 block)
{
    u32 mask = __osDisableInt();

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
        osStartThread(__osPopThread(&queue->fullqueue));
    }
    __osRestoreInt(mask);
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BB2F4[3] = {
    0x0800F200, 0x69000000, 0x02000500,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802BB2A0_de_padding_BC2A4[1] = {
    0x00000000,
};
#endif
