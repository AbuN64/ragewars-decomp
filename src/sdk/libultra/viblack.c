#include "include_asm.h"
#include "COMMON/EXTERNS_17.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/libgultra/viblack.h"
#include "sdk/os.h"

extern void *D_800D4414;

void osViBlack(s32 blackEnabled) {
    u32 savedInterruptMask;
    u16 *ptr;
    u16 v;

    savedInterruptMask = __osDisableInt();
    if (blackEnabled & 0xFF) {
        ptr = (u16 *)D_800D4414;
        v = *ptr | 0x20;
    } else {
        ptr = (u16 *)D_800D4414;
        v = *ptr & 0xFFDF;
    }
    *ptr = v;
    __osRestoreInt(savedInterruptMask);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA13C[1] = {
    0x4F666673,
};
#endif
