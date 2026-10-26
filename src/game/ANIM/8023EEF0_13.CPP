#include "TYPES.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
extern void GraphU64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);
/* Is `point` inside the polygon prism, or within `radius` of its edges?
 * Each edge's outward normal (normal x edge) splits off the outside half-space; a point outside an edge
 * passes only when its distance to that edge is at most `radius`. Types 3 and 4 measure the distance
 * to the edge segment (clamped at its end vertex); other types measure it to the edge line and let the
 * projection run past either end by at most `radius`. */
s32 Plane_TestPointNearPolygon(Polygon *polygon, CVector3 *point, f32 radius)
{
    CVector3 outward;
    CVector3 edge;
    CVector3 delta;
    CVector3 *previousVertex;
    CVector3 *vertex;
    f32 projection;
    f32 side;
    f32 lengthSquared;
    f32 radiusSquared;
    f32 limit;
    s32 remaining;

    if (polygon->vertexCount == 1) {
        return 1;
    }
    previousVertex = &polygon->vertices[polygon->vertexCount - 1];
    vertex = polygon->vertices;
    radiusSquared = radius * radius;
    remaining = polygon->vertexCount;
    if (polygon->type == 3 || polygon->type == 4) {
        for (; --remaining != -1; previousVertex = vertex++) {
            GraphU64_SubtractVectors(&edge, vertex, previousVertex);
            GraphU64_CrossVectors(&outward, &polygon->normal, &edge);
            GraphU64_SubtractVectors(&delta, point, previousVertex);
            side = outward.x * delta.x + outward.y * delta.y + outward.z * delta.z;
            if (side > 0.0f) {
                if (radius > 0.0f) {
                    projection = edge.x * delta.x + edge.y * delta.y + edge.z * delta.z;
                    if (projection > 0.0f) {
                        lengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
                        if (lengthSquared <= projection) {
                            GraphU64_SubtractVectors(&delta, &delta, &edge);
                        } else {
                            GraphU64_ScaleVector(&edge, &edge, projection / lengthSquared);
                            GraphU64_SubtractVectors(&delta, &delta, &edge);
                        }
                    }
                    if (!(radiusSquared < delta.x * delta.x + delta.y * delta.y + delta.z * delta.z)) {
                        continue;
                    }
                }
                return 0;
            }
        }
    } else {
        for (; --remaining != -1; previousVertex = vertex++) {
            GraphU64_SubtractVectors(&edge, vertex, previousVertex);
            GraphU64_CrossVectors(&outward, &polygon->normal, &edge);
            GraphU64_SubtractVectors(&delta, point, previousVertex);
            side = outward.x * delta.x + outward.y * delta.y + outward.z * delta.z;
            if (side > 0.0f) {
                if (radius > 0.0f) {
                    projection = edge.x * delta.x + edge.y * delta.y + edge.z * delta.z;
                    lengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
                    projection /= lengthSquared;
                    if (projection < 0.0f) {
                        limit = -radius / Math_Sqrtf(lengthSquared);
                        if (projection < limit) {
                            return 0;
                        }
                    } else if (1.0f < projection) {
                        limit = 1.0f + radius / Math_Sqrtf(lengthSquared);
                        if (limit < projection) {
                            return 0;
                        }
                    }
                    GraphU64_ScaleVector(&edge, &edge, projection);
                    GraphU64_SubtractVectors(&delta, &delta, &edge);
                    if (!(radiusSquared < delta.x * delta.x + delta.y * delta.y + delta.z * delta.z)) {
                        continue;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}
