#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040A83C.h"
#include "stddef.h"
/* Select the status text and right-align its nonblank characters. */
#include "types.h"
s32 func_80441FE8_de(void *); /* extern */
extern u8 D_8014B494[];
extern s32 D_80153774;
extern s32 D_800D2478; /* const */
extern s32 D_800D2480; /* const */
s32 func_8040A83C_us(struct Object_func_80442064_de *arg0) {
    s8 *temp_s0;
    s8 *temp_s0_2;
    s32 var_s1;
    s32 var_v1;
    s32 space;
    s32 var_v1_2;
    s8 *var_v0;
    u8 *var_a1;
    u8 *var_s0;
    u8 temp_v0;
    var_s1 = 8;
    if (D_80153774 != 0) {
        arg0->source = &D_800D2478;
    } else {
        arg0->source = &D_800D2480;
        var_a1 = &D_8014B49B;
        while (*var_a1-- == 0x20 && var_s1 != 0) var_s1--;
        temp_s0 = *arg0->source;
        temp_s0 = temp_s0 + (func_80441FE8_de(arg0) - 8);
        space = 0x20;
        var_v1 = 7;
        var_v0 = temp_s0 + 7;
        do {
            *var_v0 = space;
            var_v1 -= 1;
            var_v0 -= 1;
        } while (var_v1 >= 0);
        temp_s0 = temp_s0 + (8 - var_s1);
        var_v1_2 = 0;
        if (var_s1 > 0) {
            do {
                temp_v0 = D_8014B494[var_v1_2];
                var_v1_2 += 1;
                *(u8 *)temp_s0 = temp_v0;
                temp_s0 += 1;
            } while (var_v1_2 < var_s1);
        }
    }
    return 0;
}
