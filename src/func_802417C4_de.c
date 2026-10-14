#include "span_1000/code_802412C0.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);


f32 func_802417C4_de(f32 *arg0) {
    f32 magnitude;
    f32 result;
    f32 zero;

    magnitude = func_802B72B0_de((arg0[18] * arg0[18]) + (arg0[20] * arg0[20]));
    zero = 0.0f;
    if (magnitude == zero) {
        return zero;
    }
    result = func_802745D0_de(arg0[20] / magnitude);
    if (!(zero < arg0[18])) {
        result = -result;
    }
    return result;
}
