#include "span_1000/code_802BA13C.h"
#include "TYPES.H"

extern void *D_800D4414;
extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);

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
