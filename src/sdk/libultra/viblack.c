#include "include_asm.h"
#include "COMMON/EXTERNS_17.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/libgultra/viblack.h"
#include "sdk/os.h"

extern void *D_800D4414;

void osViBlack(s32 arg0) {
    u32 temp_a0;
    u16 *ptr;
    u16 v;

    temp_a0 = func_802BCF30_de();
    if (arg0 & 0xFF) {
        ptr = (u16 *)D_800D4414;
        v = *ptr | 0x20;
    } else {
        ptr = (u16 *)D_800D4414;
        v = *ptr & 0xFFDF;
    }
    *ptr = v;
    __osRestoreInt(temp_a0);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA13C[1] = {
    0x4F666673,
};
#endif
