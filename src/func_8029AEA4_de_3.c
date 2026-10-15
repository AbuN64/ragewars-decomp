#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029BBA0.h"
#include "types.h"
/* Clips a polygon of n vertices against the plane a*x + b*y + c*z + d >= 0 (Sutherland-Hodgman): walks each edge from the previous vertex, copies inside vertices to the output, and where an edge crosses the plane emits the intersection point (the edge midpoint when the edge is nearly parallel to the plane), storing the output count and returning whether any intersection was emitted. */



s32 func_8029C4A0_de(Vec3 *out, s32 *outCount, Vec3 *in, s32 n, f32 a, f32 b, f32 c, f32 d) {
    Vec3 delta;
    Vec3 *prev;
    Vec3 *point;
    Vec3 *cur;
    s32 count;
    s32 clipped;
    s32 i;
    s32 prevInside;
    s32 inside;
    f32 dot;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 t;

    count = 0;
    clipped = 0;
    *outCount = 0;
    if (n == 0) {
        return 0;
    }
    prev = &in[n - 1];
    prevInside = prev->x * a + prev->y * b + prev->z * c + d >= 0.0f;
    for (i = 0; i < n; i++) {
        cur = &in[i];
        inside = cur->x * a + cur->y * b + cur->z * c + d >= 0.0f;
        if (prevInside) {
            *out++ = *prev;
            count++;
        }
        if (prevInside != inside) {
            dx = cur->x - prev->x;
            delta.x = dx;
            dx = a * delta.x;
            dy = cur->y - prev->y;
            delta.y = dy;
            dy = b * delta.y;
            dz = cur->z - prev->z;
            delta.z = dz;
            dz = c * delta.z;
            dot = dx + dy + dz;
            dist = a * prev->x + b * prev->y + c * prev->z + d;
            clipped = 1;
            point = out++;
            count++;
            dist = -dist;
            if (dot < 0.001f && (t = 0.5f, -0.001f < dot)) {
            } else {
                t = dist / dot;
            }
            point->x = prev->x + t * delta.x;
            point->y = prev->y + t * delta.y;
            point->z = prev->z + t * delta.z;
        }
        prev = cur;
        prevInside = inside;
    }
    *outCount = count;
    return clipped;
}
