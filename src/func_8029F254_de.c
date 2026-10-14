#include "span_1000/code_8029F3A8.h"
#include "span_1000/code_8029F3A8.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "types.h"



void func_8029F254_de(struct MatrixF *arg0, Vec3 *arg1, f32 arg2) {
    f32 sine;
    f32 cosine;
    f32 cosine_value;
    f32 one;
    f32 one_minus_cosine;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 txx;
    f32 txy;
    f32 txz;
    f32 tyy;
    f32 tyz;
    f32 tzz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 zero;

    func_8029BBB0_de(arg2, &sine, &cosine);
    cosine_value = cosine;
    one = D_800C5CCC_de;
    one_minus_cosine = one - cosine_value;
    tx = one_minus_cosine * arg1->x;
    ty = one_minus_cosine * arg1->y;
    tz = one_minus_cosine * arg1->z;
    txx = tx * arg1->x;
    txy = tx * arg1->y;
    txz = tx * arg1->z;
    tyy = ty * arg1->y;
    tyz = ty * arg1->z;
    tzz = tz * arg1->z;
    sx = sine * arg1->x;
    sy = sine * arg1->y;
    sz = sine * arg1->z;
    zero = 0.0f;
    arg0->m[3][2] = zero;
    arg0->m[3][1] = zero;
    arg0->m[3][0] = zero;
    arg0->m[2][3] = zero;
    arg0->m[1][3] = zero;
    arg0->m[0][3] = zero;
    arg0->m[3][3] = one;
    arg0->m[0][0] = txx + cosine_value;
    arg0->m[0][1] = txy + sz;
    arg0->m[0][2] = txz - sy;
    arg0->m[1][0] = txy - sz;
    arg0->m[1][1] = tyy + cosine_value;
    arg0->m[1][2] = tyz + sx;
    arg0->m[2][0] = txz + sy;
    arg0->m[2][1] = tyz - sx;
    arg0->m[2][2] = tzz + cosine_value;
}
