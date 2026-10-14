#include "span_1000/code_8027451C.h"
#include "types.h"






f32 func_802749B4_de(f32 arg0, f32 arg1) {
    f32 var_f0;
    f32 var_f14;

    var_f14 = arg1;
    if (var_f14 < D_800C4978_de) {
        do {
            var_f14 += *(&D_800C4978_de + 1);
        } while (var_f14 < D_800C4978_de);
    }
    if (D_800C4980_de < var_f14) {
        do {
            var_f14 -= *(&D_800C4980_de + 1);
        } while (D_800C4980_de < var_f14);
    }
    var_f0 = arg0 - var_f14;
    if (var_f0 < D_800C4988_de) {
        do {
            var_f0 += *(&D_800C4988_de + 1);
        } while (var_f0 < D_800C4988_de);
    }
    if (D_800C4990_de < var_f0) {
        do {
            var_f0 -= *(&D_800C4990_de + 1);
        } while (D_800C4990_de < var_f0);
    }
    return -var_f0;
}
