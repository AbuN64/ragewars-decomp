#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80271B18.h"
#include "types.h"








void func_80272B38_de(void *arg0, void *arg1, void *arg2) {
    Matrix *m = arg0;
    Vec3 *v = arg1;
    Vec3 *out = arg2;

    out->x = (m->m[0] * v->x)
                       + (m->m[4] * v->y)
                       + (m->m[8] * v->z);
    out->y = (m->m[1] * v->x)
                       + (m->m[5] * v->y)
                       + (m->m[9] * v->z);
    out->z = (m->m[2] * v->x)
                       + (m->m[6] * v->y)
                       + (m->m[10] * v->z);
}
