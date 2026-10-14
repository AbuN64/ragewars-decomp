#include "span_1000/code_802BA13C.h"
#include "types.h"

extern void *D_800D4414;
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

void func_802BA1B0_de(s32 arg0) {
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
    func_802BCF50_de(temp_a0);
}
