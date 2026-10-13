#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"
#include "types.h"



extern f32 D_800C48C8_de[];






void func_80272A10_de(void *arg0, void *arg1, Vec3 *arg2) {
    Matrix *m = arg0;
    Vec3 *v = arg1;
    f32 w;
    f32 scale;

    arg2->x = (m->m[0] * v->x)
                       + (m->m[4] * v->y)
                       + (m->m[8] * v->z)
                       + m->m[12];
    arg2->y = (m->m[1] * v->x)
                       + (m->m[5] * v->y)
                       + (m->m[9] * v->z)
                       + m->m[13];
    arg2->z = (m->m[2] * v->x)
                       + (m->m[6] * v->y)
                       + (m->m[10] * v->z)
                       + m->m[14];
    w = (m->m[3] * v->x)
        + (m->m[7] * v->y)
        + (m->m[11] * v->z)
        + m->m[15];
    if (w != 0.0f) {
        scale = D_800C48C8_de[1] / w;
        arg2->x = arg2->x * scale;
        arg2->y = arg2->y * scale;
        arg2->z = arg2->z * scale;
    }
}
