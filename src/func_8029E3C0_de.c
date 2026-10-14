#include "span_1000/code_8029EB74.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);

void func_8029E3C0_de(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 sum;

    sum = ((dx * dx) + (dy * dy)) + (dz * dz);
    if (!(((dx * dx) + (dy * dy)) + (dz * dz) <= 0.0f)) {
        sum = dz;
        func_802B72B0_de(((dx * dx) + (dy * dy)) + (sum * sum));
    }
}
