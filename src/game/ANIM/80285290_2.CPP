#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"
#include "stddef.h"
#include "ANIM/80285290_2.H"

/* Sorts fixed-stride records by selecting a maximum and swapping it to the end. */
void func_802854B4_de(u32 arg0, u32 arg1, s32 width, s32 (*arg3)(u32, u32), void (*arg4)(u32, u32)) {
    u32 var_a0;
    u32 var_s0;
    u32 var_s1;
    u32 var_s2;
    var_s2 = arg1;
    if (arg0 < var_s2) {
        var_s0 = arg0 + width;
        do {
            do { var_s1 = arg0; } while (0);
            if (var_s2 >= var_s0) {
                var_a0 = var_s0;
                do {
                    if (arg3(var_a0, var_s1) > 0) {
                        var_s1 = var_s0;
                    }
                    var_s0 += width;
                    var_a0 = var_s0;
                } while (var_s2 >= var_s0);
            }
            arg4(var_s1, var_s2);
            var_s2 -= width;
            var_s0 = arg0 + width;
        } while (arg0 < var_s2);
    }
}
