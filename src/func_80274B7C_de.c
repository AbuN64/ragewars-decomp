#include "span_1000/code_8027451C.h"
#include "types.h"














/** Copy two 3-vectors, then derive an edge vector, its z-component twice, and a negated x. */
void func_80274B7C_de(void *arg0, void *arg1, void *arg2) {
    GeometryEdge *dst = arg0;
    Vec3 *a = arg1;
    Vec3 *b = arg2;
    f32 zdiff;

    dst->start = *a;
    dst->end = *b;
    dst->direction.x = b->x - a->x;
    dst->direction.y = b->y - a->y;
    zdiff = b->z - a->z;
    dst->normal.y = 0.0f;
    dst->normal.z = -dst->direction.x;
    dst->direction.z = zdiff;
    dst->normal.x = zdiff;
}
