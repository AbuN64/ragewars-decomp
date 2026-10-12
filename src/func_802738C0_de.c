#include "span_1000/code_8027302C.h"
#include "types.h"







void func_802738C0_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.y;
    m->right.y = (a * cos_v) + (m->right.z * neg_sin);
    m->right.z = (a * sin_v) + (m->right.z * cos_v);

    a = m->up.y;
    m->up.y = (a * cos_v) + (m->up.z * neg_sin);
    m->up.z = (a * sin_v) + (m->up.z * cos_v);

    a = m->forward.y;
    m->forward.y = (a * cos_v) + (m->forward.z * neg_sin);
    m->forward.z = (a * sin_v) + (m->forward.z * cos_v);

    a = m->m31;
    m->m31 = (a * cos_v) + (m->m32 * neg_sin);
    m->m32 = (a * sin_v) + (m->m32 * cos_v);
}
