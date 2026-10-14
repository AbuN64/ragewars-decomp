#include "span_16E000/code_80405DC0.h"
#include "types.h"
#include "stddef.h"
/* Finds the first available controller slot and caches its index. */
void func_80404E28_de(s32); /* extern */
s32 func_80404F04_de(s32); /* extern */
void func_80409744_de(void) {
    s32 var_s0;
    s32 var_s1;
    s32 unavailable;
    if (D_800E28C8 == -1) {
        var_s0 = 0;
        var_s1 = 0;
    unavailable = -2;
loop_2:
        func_80404E28_de(var_s0);
        if (func_80404F04_de(var_s0) == unavailable) {
            var_s0 += 1;
            if (var_s0 >= 4) {
                var_s0 = 0;
            }
            var_s1 += 1;
            if (var_s1 < 4) {
                goto loop_2;
            }
        }
        if (var_s1 == 4) {
            var_s0 = -1;
        }
        D_800E28C8 = var_s0;
    }
}
/* Returns whether D_800E28C8 holds anything other than -1. */
s32 func_804097D4_de(void) {
    return D_800E28C8 != -1;
}
/* Clears the word held in D_800E28C0. */
extern s32 D_800E28C0;
void func_804097E8_de(void) {
    D_800E28C0 = 0;
}
