#include "include_asm.h"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern u16 D_8014D48C;
extern char *D_auto_800D3770, *D_auto_800D3774, *D_auto_800D3778, *D_auto_800D377C, *D_auto_800D3780, *D_auto_800D3784;
extern char *D_auto_800D3788, *D_auto_800D378C, *D_auto_800D3790, *D_auto_800D3794, *D_auto_800D3798, *D_auto_800D379C;
typedef struct { char pad0[0x14]; char **text; } Func_80408AD0_Obj;
/* Copies the 12-byte rank label chosen by the value D_8014D48C (banded 0, 50, 150, 300, 500, 800, 1300, 2000, 3000, 4500, 6500, 9999) into the text 8 bytes in; returns zero. */
s32 func_80408AD0_de(Func_80408AD0_Obj *arg0) {
    u32 v = D_8014D48C;
    char *src = 0;
    char *dst;
    s32 i;
    if (v < 0x32) src = D_auto_800D3770;
    else if (v - 0x32 < 0x64) src = D_auto_800D3774;
    else if (v - 0x96 < 0x96) src = D_auto_800D3778;
    else if (v - 0x12C < 0xC8) src = D_auto_800D377C;
    else if (v - 0x1F4 < 0x12C) src = D_auto_800D3780;
    else if (v - 0x320 < 0x1F4) src = D_auto_800D3784;
    else if (v - 0x514 < 0x2BC) src = D_auto_800D3788;
    else if (v - 0x7D0 < 0x3E8) src = D_auto_800D378C;
    else if (v - 0xBB8 < 0x5DC) src = D_auto_800D3790;
    else if (v - 0x1194 < 0x7D0) src = D_auto_800D3794;
    else if (v - 0x1964 < 0xDAB) src = D_auto_800D3798;
    else if (v >= 0x270F) src = D_auto_800D379C;
    dst = *arg0->text + 8;
    if (src != 0) {
        for (i = 0; i < 12; i++) *dst++ = *src++;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80408AD0_de);
#endif
#endif
