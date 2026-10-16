#include "common/types_1dc8418c21db.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_80271B18.h"

static inline void normalizeProjectionNormal(Vec3 *normal) {
    f32 length;
    f32 inverse;
    length = func_802B72B0_de(normal->x * normal->x + normal->y * normal->y + normal->z * normal->z);
    if (length != 0.0f) {
        inverse = D_800C48B0_de / length;
        normal->x *= inverse;
        normal->y *= inverse;
        normal->z *= inverse;
    }
}

static inline void projectionCross(Vec3 *normal, Vec3 *a, Vec3 *b) {
    normal->x = a->y * b->z - a->z * b->y;
    normal->y = a->z * b->x - a->x * b->z;
    normal->z = a->x * b->y - a->y * b->x;
}

static inline void projectionScale(Vec3 *out, Vec3 *normal, f32 projection) {
    out->x = normal->x * projection;
    out->y = normal->y * projection;
    out->z = normal->z * projection;
}

Vec3 *func_8027229C_de(Vec3 *out, Vec3 *value, Vec3 *a, Vec3 *b) {
    Vec3 normal;
    Vec3 projected;
    f32 length;
    f32 projection;
    projectionCross(&normal, a, b);
    normalizeProjectionNormal(&normal);
    projection = value->x * normal.x + value->y * normal.y + value->z * normal.z;
    projectionScale(&projected, &normal, projection);
    *out = projected;
    return out;
}
