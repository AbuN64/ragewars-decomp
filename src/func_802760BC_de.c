#include "span_1000/code_8027451C.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80275E44.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);







f32 func_802760BC_de(void *arg0, s32 arg1) {
    Triangle *polygon = arg0;
    Vec3 *v0;
    Vec3 *v1;
    f32 dx, dz;
    f32 mag;
    f32 result;

    v1 = polygon->vertices[arg1];
    v0 = polygon->vertices[(arg1 + 1) % 3];
    dx = v0->x - v1->x;
    dz = v0->z - v1->z;
    mag = func_802B72B0_de((dx * dx) + (dz * dz));
    if (mag == 0.0f) {
        return 0.0f;
    }
    result = func_802745D0_de(dx / mag);
    if (!(dz < 0.0f)) {
        result = -result;
    }
    return result;
}
