#include "include_asm.h"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_2.H"
#include "AUDIO_3/802BEC10.H"

extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);



s32 func_802B9B20_de(s32 arg0, s32 *arg1) {
    u32 status;

    if (arg1 == 0) {
        func_802BAC50_de(&D_800C7970_de, &D_800C7974_de, 0x3D);
    }
    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *arg1 = *(s32 *)(D_80000308 | arg0 | 0xA0000000);
    return 0;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802B9AE4);
#endif
