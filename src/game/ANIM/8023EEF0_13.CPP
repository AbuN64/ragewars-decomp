#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"

extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);

/* Hand C from the 0x3C8-byte MIPS body. Each vector callee writes three
 * contiguous floats; scalar stack fragments are not independent integers.
 * The projection limit is 1.0 in all five original ROMs. */
s32 Anim_TestPointNearPolygon(void *polygonAddress, void *pointAddress, f32 radius) {
    Polygon *polygon = polygonAddress;
    CVector3 *point = pointAddress;
    CVector3 *previous;
    CVector3 *current;
    CVector3 edge;
    CVector3 outside;
    CVector3 delta;
    f32 radiusSquared;
    f32 projection;
    f32 lengthSquared;
    f32 factor;
    s32 remaining;

    if (polygon->vertexCount == 0 || polygon->vertexCount == 1) {
        return 1;
    }
    previous = polygon->vertices + polygon->vertexCount - 1;
    current = polygon->vertices;
    radiusSquared = radius * radius;
    remaining = polygon->vertexCount;
    while (remaining > 0) {
        func_80271F68_de(&edge, current, previous);
        func_80272018_de(&outside, &polygon->normal, &edge);
        func_80271F68_de(&delta, point, previous);
        if (outside.x * delta.x + outside.y * delta.y + outside.z * delta.z > 0.0f) {
            if (!(radius > 0.0f)) {
                return 0;
            }
            projection = edge.x * delta.x + edge.y * delta.y + edge.z * delta.z;
            if ((u32)(polygon->type - 3) < 2U) {
                if (projection > 0.0f) {
                    lengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
                    if (!(lengthSquared <= projection)) {
                        func_80271F9C_de(&edge, &edge, projection / lengthSquared);
                    }
                    func_80271F68_de(&delta, &delta, &edge);
                }
            } else {
                lengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
                factor = projection / lengthSquared;
                if (factor < 0.0f) {
                    if (factor < -radius / func_802B72B0_de(lengthSquared)) {
                        return 0;
                    }
                } else if (1.0f < factor &&
                           1.0f + radius / func_802B72B0_de(lengthSquared) < factor) {
                    return 0;
                }
                func_80271F9C_de(&edge, &edge, factor);
                func_80271F68_de(&delta, &delta, &edge);
            }
            if (radiusSquared < delta.x * delta.x + delta.y * delta.y + delta.z * delta.z) {
                return 0;
            }
        }
        previous = current;
        current++;
        remaining--;
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", Anim_TestPointNearPolygon);
#endif
