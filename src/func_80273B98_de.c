#include "span_1000/code_8027302C.h"
#include "types.h"







void func_80273B98_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.x;
    m->right.x = (cos_v * a) + (sin_v * m->up.x);
    m->up.x = (neg_sin * a) + (cos_v * m->up.x);

    a = m->right.y;
    m->right.y = (cos_v * a) + (sin_v * m->up.y);
    m->up.y = (neg_sin * a) + (cos_v * m->up.y);

    a = m->right.z;
    m->right.z = (cos_v * a) + (sin_v * m->up.z);
    m->up.z = (neg_sin * a) + (cos_v * m->up.z);
}
