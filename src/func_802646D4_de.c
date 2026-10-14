#include "span_1000/code_802646F4.h"
#include "types.h"

extern u8 D_8010FBE3[];

s32 func_802646D4_de(s32 arg0) {
    s32 var_a1;
    s32 var_v1;

    var_a1 = 0;
    var_v1 = 0;
loop_1:
    if (((D_8010FBE3[var_v1 * 4] >> 3) ^ 1) & 1) {
        var_a1 += 1;
    }
    if ((var_a1 - 1) != arg0) {
        var_v1 += 1;
        if (var_v1 >= 4) {
            return -1;
        }
        goto loop_1;
    }
    return var_v1;
}
