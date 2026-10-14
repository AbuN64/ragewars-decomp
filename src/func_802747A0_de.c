#include "span_1000/code_8027451C.h"
#include "types.h"

extern f32 D_800D2988;

f32 func_802747A0_de(f32 arg0, f32 arg1) {
    f32 zero;

    zero = 0.0f;
    if (zero < arg0) {
        arg0 -= arg1 * D_800D2988;
        if (arg0 < zero) {
            arg0 = zero;
        }
    } else if (arg0 < zero) {
        arg0 += arg1 * D_800D2988;
        if (zero < arg0) {
            arg0 = zero;
        }
    }
    return arg0;
}
