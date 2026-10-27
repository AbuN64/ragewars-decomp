#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/os.h"

/* 802C0390_2.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802BB294_de_padding_BBE94[12] = { 0xAF, 0xB0, 0x00, 0x10, 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB4, 0x00, 0x20 };
#endif

/* 802C0250.CPP */
extern void func_802BC36C_de(void *arg0);
extern s32 __osPopThread(OSMesgQueue *arg0);
extern void osStartThread(s32 arg0);

extern OSThread_s *D_800D5270;

s32 func_802BB160_de(OSMesgQueue *messageQueue, void *message, s32 waitMode) {
    u32 saved;
    s32 index;

    saved = __osDisableInt();
    while (messageQueue->validCount >= messageQueue->msgCount) {
        if (waitMode != 1) {
            __osRestoreInt(saved);
            return -1;
        }
        D_800D5270->state = 8;
        func_802BC36C_de(&messageQueue->fullqueue);
    }

    index = (messageQueue->first + messageQueue->msgCount - 1) % messageQueue->msgCount;
    messageQueue->first = index;
    messageQueue->msg[index] = message;
    messageQueue->validCount++;
    if (*messageQueue->mtqueue != 0) {
        osStartThread(__osPopThread(messageQueue));
    }
    __osRestoreInt(saved);
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BB1C4[3] = {
    0x00010008, 0x00000009, 0x43506C61,
};
#endif
