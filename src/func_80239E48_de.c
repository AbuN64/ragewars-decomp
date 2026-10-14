#include "span_1000/code_802393F4.h"
#include "types.h"

extern u32 func_802337D0_de(s32);

s32 func_80239E48_de(s32 arg0) {
    s32 var_v1;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_v0;

    temp_s1 = func_802337D0_de(arg0 + 0x18);
    temp_s0 = func_802337D0_de(arg0 + 0x2C);
    temp_v0 = func_802337D0_de(arg0 + 0x40);
    var_v1 = 0;
    if ((temp_s1 != 0) && (temp_s0 != 0)) {
        var_v1 = temp_v0 > 0U;
    }
    return var_v1;
}
