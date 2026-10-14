#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"
/* Returns the distance from point p to the segment from a to b: the offset of p from a is reduced by
 * its projection onto the segment direction, clamped to the segment ends, before taking the length. */



extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern f32 func_802B72B0_de(f32);

f32 func_80241840_de(Vec3 *a, Vec3 *b, Vec3 *p) {
    Vec3 offset;
    Vec3 dir;
    f32 value;
    f32 len;

    func_80271F68_de(&offset, p, a);
    func_80271F68_de(&dir, b, a);
    value = dir.x * offset.x + dir.y * offset.y + dir.z * offset.z;
    if (!(value < 0.0f)) {
        len = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
        if (!(len <= value)) {
            func_80271F9C_de(&dir, &dir, value / len);
        }
        func_80271F68_de(&offset, &offset, &dir);
    }
    value = offset.x * offset.x + offset.y * offset.y + offset.z * offset.z;
    return func_802B72B0_de(value);
}
