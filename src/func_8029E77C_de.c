#include "span_1000/code_8029EB74.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);


void func_8029E77C_de(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 magnitude_squared;
    f32 magnitude;
    f32 x;
    f32 z;

    x = arg0[0];
    z = arg0[2];
    x *= x;
    z *= z;
    x += z;
    magnitude_squared = x;
    if (magnitude_squared <= 0.0f) {
        magnitude = 0.0f;
    } else {
        magnitude = func_802B72B0_de(magnitude_squared);
    }
    *arg2 = func_8029C044_de(arg0[0], arg0[2]);
    *arg1 = -func_8029C044_de(arg0[1], magnitude);
}
