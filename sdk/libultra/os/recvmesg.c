#include "../../include/thread_queue.h"
#include "include_asm.h"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include <ultra64.h>
#include <PR/os_internal_reg.h>
#include <PR/os_internal_si.h>

/* 802C0390_4.CPP */

/* recvmesg.c */
extern OSThread *__osRunningThread;
extern void __osEnqueueAndYield(void *);

s32 osRecvMesg(OSMesgQueue *queue, OSMesg *message, s32 block)
{
    u32 mask = __osDisableInt();

    while (queue->validCount == 0) {
        if (!block) {
            __osRestoreInt(mask);
            return -1;
        }
        __osRunningThread->state = 8;
        __osEnqueueAndYield(&queue->mtqueue);
    }

    if (message != 0) {
        *message = queue->msg[queue->first];
    }
    queue->first = (queue->first + 1) % queue->msgCount;
    queue->validCount--;
    if (queue->fullqueue->next != 0) {
        osStartThread(__osPopThread(&queue->fullqueue));
    }
    __osRestoreInt(mask);
    return 0;
}


#if defined(VERSION_EU_X)
unsigned int func_802BB2A0_de_padding_BC2A4[1] = {
    0x00000000,
};
#endif
