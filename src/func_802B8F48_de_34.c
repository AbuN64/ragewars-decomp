#include "span_1000/code_802B8DD0.h"
#include "common/unused.h"
#include "types.h"

extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);
extern s32 D_800C7970_de;
extern s32 D_800C7974_de;



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
