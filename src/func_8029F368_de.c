#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029F3A8.h"
#include "types.h"



extern void func_8029C6A8_de(void *arg0, void *arg2);




void func_8029F368_de(void *arg0, Vec3 *arg1, void *arg2, Vec3 *arg3) {
    Matrix *m = arg0;

    func_8029C6A8_de(arg0, arg2);

    m->m[0] = m->m[0] * arg1->x;
    m->m[1] = m->m[1] * arg1->x;
    m->m[2] = m->m[2] * arg1->x;
    m->m[4] = m->m[4] * arg1->y;
    m->m[5] = m->m[5] * arg1->y;
    m->m[6] = m->m[6] * arg1->y;
    m->m[8] = m->m[8] * arg1->z;
    m->m[9] = m->m[9] * arg1->z;
    m->m[10] = m->m[10] * arg1->z;
    m->m[12] = m->m[12] + arg3->x;
    m->m[13] = m->m[13] + arg3->y;
    m->m[14] = m->m[14] + arg3->z;
}
