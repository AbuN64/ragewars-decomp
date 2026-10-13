#include "span_1000/code_80271B18.h"
#include "types.h"

extern f32 func_802B72B0_de(f32 arg0);

f32 func_802726F8_de(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    return func_802B72B0_de((dx * dx) + (dy * dy) + (dz * dz));
}
