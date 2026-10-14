#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024D018.h"
#include "types.h"










extern f32 D_80115DEC;

extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *arg0);




Vector4f *func_8024D728_de(Vector4f *out, InputRecAt44 *input) {
    Vec3 source;
    Vec3 up;
    Vec3 axis;
    Vector4f result;
    f32 angle;
    f32 scale;
    int state;

    state = input->state;
    if (state == 0) {
        goto default_source;
    }
    if (state < 0) {
        goto default_source;
    }
    if (state < 4) {
        goto input_source;
    }
default_source:
    source.x = 0.0f;
    source.y = D_800C3C98_de;
    source.z = 0.0f;
    goto source_ready;
input_source:
    source = input->direction;
source_ready:

    up.x = 0.0f;
    up.y = D_800C3C9C_de;
    up.z = 0.0f;
    func_80272018_de(&axis, &up, &source);
    func_8027207C_de(&axis);

    angle = func_802745D0_de((up.x * source.x) +
                          (up.y * source.y) +
                          (up.z * source.z));
    angle *= D_800C3CA0_de;
    scale = func_802B7130_de(angle);
    result.x = axis.x * scale;
    result.y = axis.y * scale;
    result.z = axis.z * scale;
    D_80115DEC = scale;
    result.w = func_802B6560_de(angle);

    *out = result;
    return out;
}
