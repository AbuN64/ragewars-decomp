#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"

extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);

/* 37 aligned edits / 242 ROM words; remaining: register allocation and return-branch sharing. */
/* Test the polygon half-planes and, outside an edge, the allowed radius.
 * Types 3 and 4 clamp projections to the segment; other types extend it. */
s32 Anim_TestPointNearPolygon(Polygon *polygon, CVector3 *point, f32 radius)
{
    CVector3 outside;
    CVector3 edge;
    CVector3 delta;
    CVector3 *previousVertex;
    CVector3 *vertex;
    f32 projection;
    f32 side;
    f32 limit;
    f32 lengthSquared;
    f32 radiusSquared;
    s32 remaining;

    if (polygon->vertexCount == 1) {
        return 1;
    }
    previousVertex = &polygon->vertices[polygon->vertexCount - 1];
    vertex = polygon->vertices;
    radiusSquared = radius * radius;
    remaining = polygon->vertexCount;
    if ((u32)(polygon->type - 3) < 2U) {
        while (--remaining != -1) {
            func_80271F68_de(&edge, vertex, previousVertex);
            func_80272018_de(&outside, &polygon->normal, &edge);
            func_80271F68_de(&delta, point, previousVertex);
            side = outside.x * delta.x + outside.y * delta.y + outside.z * delta.z;
            if (side > 0.0f) {
                if (!(radius > 0.0f)) {
                    return 0;
                }
                projection = edge.x * delta.x + edge.y * delta.y + edge.z * delta.z;
                if (projection > 0.0f) {
                    lengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
                    if (!(lengthSquared <= projection)) {
                        projection /= lengthSquared;
                        func_80271F9C_de(&edge, &edge, projection);
                    }
                    func_80271F68_de(&delta, &delta, &edge);
                }
                if (radiusSquared < delta.x * delta.x + delta.y * delta.y + delta.z * delta.z) {
                    return 0;
                }
            }
            previousVertex = vertex;
            vertex++;
        }
    } else {
        while (--remaining != -1) {
            func_80271F68_de(&edge, vertex, previousVertex);
            func_80272018_de(&outside, &polygon->normal, &edge);
            func_80271F68_de(&delta, point, previousVertex);
            side = outside.x * delta.x + outside.y * delta.y + outside.z * delta.z;
            if (side > 0.0f) {
                if (!(radius > 0.0f)) {
                    return 0;
                }
                projection = edge.x * delta.x + edge.y * delta.y + edge.z * delta.z;
                lengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
                projection /= lengthSquared;
                if (projection < 0.0f) {
                    limit = func_802B72B0_de(lengthSquared);
                    limit = -radius / limit;
                    if (projection < limit) {
                        return 0;
                    }
                } else if (1.0f < projection) {
                    limit = func_802B72B0_de(lengthSquared);
                    limit = 1.0f + radius / limit;
                    if (limit < projection) {
                        return 0;
                    }
                }
                func_80271F9C_de(&edge, &edge, projection);
                func_80271F68_de(&delta, &delta, &edge);
                if (radiusSquared < delta.x * delta.x + delta.y * delta.y + delta.z * delta.z) {
                    return 0;
                }
            }
            previousVertex = vertex;
            vertex++;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", Anim_TestPointNearPolygon);
#endif
