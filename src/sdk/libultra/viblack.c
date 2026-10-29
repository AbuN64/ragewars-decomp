#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/libgultra/viblack.h"
#include "sdk/os.h"

extern void *g_nextVideoInterfaceContext;

void osViBlack(s32 blackEnabled) {
    u32 savedInterruptMask;
    u16 *ptr;
    u16 v;

    savedInterruptMask = __osDisableInt();
    if (blackEnabled & 0xFF) {
        ptr = (u16 *)g_nextVideoInterfaceContext;
        v = *ptr | 0x20;
    } else {
        ptr = (u16 *)g_nextVideoInterfaceContext;
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
