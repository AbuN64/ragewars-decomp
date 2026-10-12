#include "span_1000/code_8027302C.h"
#include "types.h"







void func_802739C4_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.x;
    m->right.x = (cos_v * a) + (neg_sin * m->forward.x);
    m->forward.x = (sin_v * a) + (cos_v * m->forward.x);

    a = m->right.y;
    m->right.y = (cos_v * a) + (neg_sin * m->forward.y);
    m->forward.y = (sin_v * a) + (cos_v * m->forward.y);

    a = m->right.z;
    m->right.z = (cos_v * a) + (neg_sin * m->forward.z);
    m->forward.z = (sin_v * a) + (cos_v * m->forward.z);
}
