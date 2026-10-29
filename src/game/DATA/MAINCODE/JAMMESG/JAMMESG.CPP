#include "sdk/thread_queue.h"
#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/os.h"

/* 802C0390_2.CPP */
#if defined(VERSION_DE)
unsigned char g_JammesgTrailingBytes[12] = { 0xAF, 0xB0, 0x00, 0x10, 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB4, 0x00, 0x20 };
#endif

/* 802C0250.CPP */
extern void func_802BC36C_de(void *threadQueue);

extern OSThread_s *g_osRunningThread;

s32 osJamMesg(OSMesgQueue *messageQueue, void *message, s32 waitMode) {
    u32 saved;
    s32 index;

    saved = __osDisableInt();
    while (messageQueue->validCount >= messageQueue->msgCount) {
        if (waitMode != 1) {
            __osRestoreInt(saved);
            return -1;
        }
        g_osRunningThread->state = 8;
        func_802BC36C_de(&messageQueue->fullqueue);
    }

    index = (messageQueue->first + messageQueue->msgCount - 1) % messageQueue->msgCount;
    messageQueue->first = index;
    messageQueue->msg[index] = message;
    messageQueue->validCount++;
    if (*messageQueue->mtqueue != 0) {
        osStartThread(__osPopThread(&messageQueue->mtqueue));
    }
    __osRestoreInt(saved);
    return 0;
}

#if defined(VERSION_US)
unsigned int k_JammesgEncodedWords[3] = {
    0x00010008, 0x00000009, 0x43506C61,
};
#endif
