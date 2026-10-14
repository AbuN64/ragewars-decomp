#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"
#include "math_helpers.h"

extern f32 func_802B72B0_de(f32);
extern f32 func_802745D0_de(f32);
extern f32 D_800C4838_de;
extern f32 D_800C483C_de;
extern f32 D_800C4840_de;
extern f32 D_800C4844_de;


f32 func_80271AA8_de(Vec3 *direction) {
    f32 x = direction->x;
    f32 z = direction->z;
    f32 length = x * x + z * z;
    f32 angle;
    if (length == 0.0f) {
        return 0.0f;
    }
    length = func_802B72B0_de(length);
    if (length == 0.0f) {
        return 0.0f;
    }
    if (RW_ABS(x) < RW_ABS(z)) {
        x /= length;
        x = RW_MAX_GT(D_800C483C_de, RW_MIN(x, D_800C4838_de));
        angle = func_802745D0_de(x);
        angle = (z < 0.0f ? angle : -angle) - D_800C4840_de;
    } else {
        z /= length;
        z = RW_MAX_GT(D_800C4848_de, RW_MIN(z, D_800C4844_de));
        angle = func_802745D0_de(-z);
        angle = x < 0.0f ? angle : -angle;
    }
    return angle;
}
