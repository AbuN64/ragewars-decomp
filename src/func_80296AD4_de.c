#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80296014.h"
#include "types.h"





static inline s32 func_80297AD4_anyInside(Vec3 *points, s32 count, f32 *plane) {
    s32 i;
    s32 inside = 0;

    for (i = 0; i < count; i++) {
        if (plane[0] * points[i].x + plane[1] * points[i].y + plane[2] * points[i].z <= plane[3]) {
            inside = 1;
            break;
        }
    }
    return inside;
}

/* Returns 1 when every frustum plane except plane two has at least one of the points on its inner side. */
s32 func_80296AD4_de(Frustum *frustum, s32 count, Vec3 *points) {
    s32 p;
    f32 *plane;

    for (p = 0; p < 6; p++) {
        if (p == 2) {
            continue;
        }
        plane = frustum->planes[p];
        if (!func_80297AD4_anyInside(points, count, plane)) {
            return 0;
        }
    }
    return 1;
}
