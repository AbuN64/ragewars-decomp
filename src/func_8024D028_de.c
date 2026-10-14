#include "common/unused.h"
#include "span_1000/code_8024D018.h"
#include "types.h"

/* Builds a 4x4 transform from a rotation quaternion (x, y, z, w) and a translation, with a zero fourth column and the corner set to the constant at D_800C8CA0. */



void func_8024D028_de(f32 *m, f32 *q, f32 *t)
{
    f32 x = q[0];
    f32 xx = x * x;
    f32 y = q[1];
    f32 yy = y * y;
    f32 z = q[2];
    f32 zz = z * z;
    f32 w = q[3];
    f32 ww = w * w;
    f32 x2 = x + x;
    f32 xy = x2 * y;
    f32 w2 = w + w;
    f32 wz = w2 * z;
    f32 xz = x2 * z;
    f32 wy = w2 * y;
    f32 wx = w2 * x;
    f32 yz = (y + y) * z;

    m[0] = ww + xx - yy - zz;
    m[1] = xy + wz;
    m[2] = xz - wy;
    m[4] = xy - wz;
    m[5] = ww - xx + yy - zz;
    m[6] = yz + wx;
    m[8] = xz + wy;
    m[9] = yz - wx;
    m[10] = ww - xx - yy + zz;
    m[12] = t[0];
    m[13] = t[1];
    m[14] = t[2];
    m[3] = 0.0f;
    m[7] = 0.0f;
    m[11] = 0.0f;
    m[15] = D_800C8CA0;
}

extern int func_802784C0_de(int a, int b, void *c, int d, int e, void *f);
extern void func_80253E64_de(int a, int **b, int c);




void func_8024D108_de(void *arg0, int **arg1) {
    struct LevelActor *object = arg0;
    int *deref1;
    int deref2;
    int ret;

    deref1 = *arg1;
    deref2 = *deref1;
    ret = func_802784C0_de(deref2, 0, object->padE8, object->fieldB4, 1, arg0);
    func_80253E64_de(0, arg1, ret);
}
