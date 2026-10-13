#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8027302C.h"
#include "types.h"



extern f32 D_800C48F8_de;




void func_80273648_de(void *arg0, f32 arg1) {
    struct Mtx *m = arg0;
    f32 sin_v;
    f32 cos_v;
    f32 zero;
    f32 identity;

    sin_v = func_802B7130_de(arg1);
    zero = 0;
    identity = D_800C48F8_de;
    m->forward.y = -sin_v;
    m->up.z = sin_v;
    m->right.y = zero;
    m->up.x = zero;
    m->right.z = zero;
    m->forward.x = zero;
    m->m32 = zero;
    m->m31 = zero;
    m->m30 = zero;
    m->m23 = zero;
    m->m13 = zero;
    m->m03 = zero;
    m->m33 = identity;
    m->right.x = identity;
    cos_v = func_802B6560_de(arg1);
    m->forward.z = cos_v;
    m->up.y = cos_v;
}
