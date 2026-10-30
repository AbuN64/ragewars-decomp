#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "../../include/libgultra/viblack.h"
#include "../../include/os.h"

extern void *__osViNext;

void osViBlack(s32 blackEnabled) {
    u32 savedInterruptMask;
    u16 *ptr;
    u16 v;

    savedInterruptMask = __osDisableInt();
    if (blackEnabled & 0xFF) {
        ptr = (u16 *)__osViNext;
        v = *ptr | 0x20;
    } else {
        ptr = (u16 *)__osViNext;
        v = *ptr & 0xFFDF;
    }
    *ptr = v;
    __osRestoreInt(savedInterruptMask);
}

#if defined(VERSION_US)
unsigned int k_ViblackEncodedWords[1] = {
    0x4F666673,
};
#endif
