#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "types.h"




extern float D_800C49D8_de[];

extern float D_80115DEC;
extern void func_802750B0_de(Vec3 *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, float);
extern f32 func_802B72B0_de(f32);




Vector4f *func_80275688_de(Vector4f *out) {
    Vec3 a;
    Vec3 up;
    Vec3 axis;
    Vector4f result;
    float len;
    float angle;
    float scale;
    float one;

    func_802750B0_de(&a);
    one = D_800C49D8_de[1];
    up.x = 0;
    up.y = one;
    up.z = 0;
    func_80272018_de(&axis, &up, &a);
    len = func_802B72B0_de(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0) {
        result.z = 0;
        result.y = 0;
        result.x = 0;
        result.w = one;
    } else {
        func_80271F9C_de(&axis, &axis, one / len);
        angle = func_802745D0_de(up.x * a.x + up.y * a.y + up.z * a.z);
        angle *= D_800C49E0_de;
        scale = func_802B7130_de(angle);
        result.x = axis.x * scale;
        result.y = axis.y * scale;
        result.z = axis.z * scale;
        D_80115DEC = scale;
        result.w = func_802B6560_de(angle);
    }
    *out = result;
    return out;
}
