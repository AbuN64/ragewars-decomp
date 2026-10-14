#include "span_1000/code_8025A3EC.h"
#include "types.h"




f32 func_8025C10C_de(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 distSq = (dx * dx) + (dy * dy) + (dz * dz);
    if (D_800D0D10 <= distSq) {
        return 0.0f;
    }
    return D_800C3F88_de - (distSq / D_800D0D10);
}
