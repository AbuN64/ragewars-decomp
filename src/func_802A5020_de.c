#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"






extern f32 D_80115DEC;
extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern f32 func_802B72B0_de(f32);
extern void func_80271F9C_de(Vec3 *out, Vec3 *in, f32 scale);




Vector4f *func_802A5020_de(Vector4f *out, u32 bx, u32 by, u32 bz) {
    Vec3 axis;
    Vec3 cross;
    Vector4f result;
    f32 one;
    f32 magnitude;
    f32 angle;
    f32 trig;

    one = D_800C5E88_de;
    axis.x = 0.0f;
    axis.y = one;
    axis.z = 0.0f;
    func_80272018_de(&cross, &axis, (Vec3 *)&bx);

    magnitude = func_802B72B0_de((cross.x * cross.x) +
                              (cross.y * cross.y) +
                              (cross.z * cross.z));
    if (magnitude == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = one;
    } else {
        func_80271F9C_de(&cross, &cross, one / magnitude);
        angle = func_802745D0_de((axis.x * *(f32 *)&bx) +
                              (axis.y * *(f32 *)&by) +
                              (axis.z * *(f32 *)&bz));
        angle *= ((struct func_802077F4_S2 *) ((f32 *) (&D_800C5E88_de)))->unk4;
        trig = func_802B7130_de(angle);
        result.x = cross.x * trig;
        result.y = cross.y * trig;
        result.z = cross.z * trig;
        D_80115DEC = trig;
        result.w = func_802B6560_de(angle);
    }
    *out = result;
    return out;
}
