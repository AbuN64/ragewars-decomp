#include "common/types_1dc8418c21db.h"
extern f32 func_802B72B0_de(f32);
extern f32 D_800C48B0_de;

Vec3 *func_8027229C_de(Vec3 *out, Vec3 *value, Vec3 *a, Vec3 *b) {
    Vec3 normal;
    f32 length;
    f32 projection;
    normal.x = a->y * b->z - a->z * b->y;
    normal.y = a->z * b->x - a->x * b->z;
    normal.z = a->x * b->y - a->y * b->x;
    length = func_802B72B0_de(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    if (length != 0.0f) {
        length = D_800C48B0_de / length;
        normal.x *= length;
        normal.y *= length;
        normal.z *= length;
    }
    projection = value->x * normal.x + value->y * normal.y + value->z * normal.z;
    out->x = normal.x * projection;
    out->y = normal.y * projection;
    out->z = normal.z * projection;
    return out;
}
