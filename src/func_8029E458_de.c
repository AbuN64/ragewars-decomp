#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029EB74.h"


/** Cross product of two vectors, written through a local temp to allow aliasing with out. */
void func_8029E458_de(Vec3 *out, Vec3 *a, Vec3 *b) {
    Vec3 tmp;

    tmp.x = (a->y * b->z) - (a->z * b->y);
    tmp.y = (a->z * b->x) - (a->x * b->z);
    tmp.z = (a->x * b->y) - (a->y * b->x);
    *out = tmp;
}
