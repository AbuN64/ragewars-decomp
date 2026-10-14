#include "span_1000/code_80271B18.h"
#include "types.h"



extern f32 func_802B72B0_de(f32);


f32 func_802725FC_de(f32 *arg0) {
    f32 y;
    f32 zero;
    f32 x;
    f32 z;
    f32 magnitude_squared;
    f32 ratio;

    y = arg0[1];
    zero = 0.0f;
    x = arg0[0];
    z = arg0[2];
    if (y == zero) {
        return zero;
    }
    magnitude_squared = (x * x) + (y * y) + (z * z);
    if (magnitude_squared == zero) {
        return zero;
    }
    ratio = y / func_802B72B0_de(magnitude_squared);
    if (ratio < *(&D_800C48B0_de + 1)) {
        return zero;
    }
    if (D_800C48B8_de < ratio) {
        goto return_zero;
    }
    return func_802745D0_de(ratio) - *(&D_800C48B8_de + 1);

return_zero:
    return zero;
}
