#include "span_1000/code_80271B18.h"
#include "types.h"

extern f32 D_800C99B0[2];
extern f32 D_800C48C8_de;

void func_80272828_de(f32 *arg0) {
    f32 *var_a0;
    f32 *var_v1;
    f32 temp_f0;
    s32 var_a1;
    s32 var_a2;
    f32 maxVal;
    f32 minVal;

    maxVal = D_800C99B0[1];
    minVal = D_800C48C8_de;
    var_a0 = arg0;
    var_a2 = 0;
    do {
        var_a1 = 0;
        var_v1 = var_a0;
        do {
            temp_f0 = *var_v1;
            if (maxVal < temp_f0) {
                *var_v1 = maxVal;
            } else if (temp_f0 < minVal) {
                *var_v1 = minVal;
            }
            var_a1 += 1;
            var_v1 += 1;
        } while (var_a1 < 4);
        var_a2 += 1;
        var_a0 += 4;
    } while (var_a2 < 4);
}
