#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8027302C.h"
#include "types.h"



extern f32 D_800C99F0;




void func_80273760_de(void *arg0, f32 arg1) {
    struct Mtx *m = arg0;
    f32 sin_v;
    f32 cos_v;
    f32 zero;
    f32 one;

    sin_v = func_802B7130_de(arg1);
    zero = (f32) 0;
    one = D_800C99F0;
    m->right.z = zero;
    m->forward.x = zero;
    m->up.z = zero;
    m->forward.y = zero;
    m->m32 = zero;
    m->m31 = zero;
    m->m30 = zero;
    m->m23 = zero;
    m->m13 = zero;
    m->m03 = zero;
    m->forward.z = one;
    m->m33 = one;
    cos_v = func_802B6560_de(arg1);
    m->up.y = cos_v;
    m->right.x = cos_v;
    m->up.x = -sin_v;
    m->right.y = sin_v;
}
