#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
/* Tests a ray's horizontal segment against a rectangle (min x/z at 0 and 4, max x/z at 8 and 12): a start
 * point inside gives parameter 0; otherwise the crossing of the x edge facing the start is tried first and
 * then the z edge, each accepted when nearer than the ray's current nearest hit at 0x17C and landing within
 * the other axis's extent (using the ray's direction at 0x5C/0x64); the accepted parameter is stored and 1
 * is returned, 0 when the segment misses. */







s32 func_8023DDC4_de(Ray *ray, Vector4f *rect, f32 *t) {
    Vec3 *start;
    Vec3 *end;
    f32 a;
    f32 b;
    f32 param;
    Vec3 hit;

    start = &ray->start;
    end = &ray->end;
    if (rect->z >= start->x && rect->w >= start->z && rect->x <= start->x && rect->y <= start->z) {
        *t = 0.0f;
        return 1;
    }
    a = start->x;
    b = end->x;
    if (a != b) {
        if (a < b) {
            param = (rect->x - a) / (b - a);
        } else {
            param = (a - rect->z) / (a - b);
        }
        if (param < ray->nearest) {
            hit.z = start->z + param * ray->dir.z;
            if (rect->y <= hit.z && hit.z <= rect->w) {
                *t = param;
                return 1;
            }
        }
    }
    a = start->z;
    b = end->z;
    if (a == b) {
        return 0;
    }
    if (a < b) {
        param = (rect->y - a) / (b - a);
    } else {
        param = (a - rect->w) / (a - b);
    }
    if (!(param < ray->nearest)) {
        return 0;
    }
    hit.x = start->x + param * ray->dir.x;
    if (rect->x <= hit.x && hit.x <= rect->z) {
        *t = param;
        return 1;
    }
    return 0;
}
