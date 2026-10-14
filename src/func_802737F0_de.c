#include "span_1000/code_8027302C.h"
#include "types.h"







void func_802737F0_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->up.x;
    m->up.x = (cos_v * a) + (sin_v * m->forward.x);
    m->forward.x = (neg_sin * a) + (cos_v * m->forward.x);

    a = m->up.y;
    m->up.y = (cos_v * a) + (sin_v * m->forward.y);
    m->forward.y = (neg_sin * a) + (cos_v * m->forward.y);

    a = m->up.z;
    m->up.z = (cos_v * a) + (sin_v * m->forward.z);
    m->forward.z = (neg_sin * a) + (cos_v * m->forward.z);
}
