#include "include_asm.h"
#include "MENU/PAK_LOAD.H"

#if defined(VERSION_DE)
extern char *D_auto_800D3770, *D_auto_800D3774, *D_auto_800D3778, *D_auto_800D377C, *D_auto_800D3780, *D_auto_800D3784;
extern char *D_auto_800D3788, *D_auto_800D378C, *D_auto_800D3790, *D_auto_800D3794, *D_auto_800D3798, *D_auto_800D379C;
typedef struct { char pad0[0x14]; char **text; } Func_80408AD0_Obj;
/* Copies the 12-byte rank label chosen by the value D_8014D48C (banded 0, 50, 150, 300, 500, 800, 1300, 2000, 3000, 4500, 6500, 9999) into the text 8 bytes in; returns zero. */
s32 Snapshot_UpdateThresholdLabel(Func_80408AD0_Obj *arg0) {
    u32 v = D_8014D488.values[2];
    char *src = 0;
    char *dst;
    s32 i;
    if (v < 50) src = D_auto_800D3770;
    else if (v >= 50 && v < 150) src = D_auto_800D3774;
    else if (v >= 150 && v < 300) src = D_auto_800D3778;
    else if (v >= 300 && v < 500) src = D_auto_800D377C;
    else if (v >= 500 && v < 800) src = D_auto_800D3780;
    else if (v >= 800 && v < 1300) src = D_auto_800D3784;
    else if (v >= 1300 && v < 2000) src = D_auto_800D3788;
    else if (v >= 2000 && v < 3000) src = D_auto_800D378C;
    else if (v >= 3000 && v < 4500) src = D_auto_800D3790;
    else if (v >= 4500 && v < 6500) src = D_auto_800D3794;
    else if (v >= 6500 && v < 9999) src = D_auto_800D3798;
    else if ((s32)v >= 9999) src = D_auto_800D379C;
    dst = *arg0->text;
    dst += 8;
    if (src != 0) {
        i = 0;
        do { *dst++ = *src++; i++; } while (i < 12);
    }
    return 0;
}
#endif
