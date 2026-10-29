#include "sdk/thread_queue.h"
#include "include_asm.h"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "sdk/os.h"

/* 802C0390_4.CPP */
#if defined(VERSION_DE)
unsigned char g_RecvmesgTrailingBytes[12] = { 0xAF, 0xB0, 0x00, 0x10, 0xAF, 0xBF, 0x00, 0x14, 0x0C, 0x0A, 0xF3, 0xC8 };
#endif

/* recvmesg.c */
extern OSThread_s *g_osRunningThread;
extern void func_802BC36C_de(void *);

s32 osRecvMesg(OSMesgQueue *queue, OSMesg *message, s32 block)
{
    u32 mask = __osDisableInt();

    while (queue->validCount == 0) {
        if (!block) {
            __osRestoreInt(mask);
            return -1;
        }
        g_osRunningThread->state = 8;
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
unsigned int k_RecvmesgEncodedWords[3] = {
    0x0800F200, 0x69000000, 0x02000500,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802BB2A0_de_padding_BC2A4[1] = {
    0x00000000,
};
#endif
