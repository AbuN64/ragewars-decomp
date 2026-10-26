#include "TYPES.H"
#include "ANIM/MEASUREDRECAT8V3.H"
#include "COMMON/MEASURED_STORAGE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OUTPUT.H"
#include "ANIM/RAY180.H"
#include "stddef.h"

s32 GraphU64_InterpolateVector(CVector3 *, u32, void *, void *);

/* Tests a point against every edge plane of a polygon. */


 /* extern */
void GraphU64_CrossVectors(f32 *, void *, f32 *);

s32 func_802412D0_de(void *poly, void *start, void *segmentEnd, f32 *outputFraction) {
    extern void GraphU64_SubtractVectors(f32 *, void *, void *);
    f32 segmentDirection[3];
    f32 planeToStart[3];
    f32 normalDotDirection;
    f32 hitFraction;
    s32 result;

    if (((struct MeasuredRecAt8V3 *)(poly))->value == 0) {
        return 0;
    }
    GraphU64_SubtractVectors(segmentDirection, segmentEnd, start);
    normalDotDirection = (((struct MeasuredRecAt48V1 *)(poly))->value * segmentDirection[0]) + (((struct Measured *)(poly))->value * segmentDirection[1]) + (((struct Measured_func_802412D0_de_48a8d17d95e2 *)(poly))->value * segmentDirection[2]);
    result = 0;
    if (!(normalDotDirection >= (f32)0)) {
        GraphU64_SubtractVectors(planeToStart, start, poly + 0x18);
        result = 1;
        hitFraction = -((((struct MeasuredRecAt48V1 *)(poly))->value * planeToStart[0]) + (((struct Measured *)(poly))->value * planeToStart[1]) + (((struct Measured_func_802412D0_de_48a8d17d95e2 *)(poly))->value * planeToStart[2])) / normalDotDirection;
    } else {
        hitFraction = D_800C3740_de;
    }
    *outputFraction = hitFraction;
    return result;
}

s32 func_802413C8_de(void *contactPlane, void *segmentStart, void *segmentEnd, void *outputPoint) {
    extern void GraphU64_SubtractVectors(f32 *, void *, void *);
    f32 segmentDirection[3];
    f32 planeToStart[3];
    f32 hitFraction;
    f32 normalDotDirection;
    s32 intersectsPlane;

    if (((struct MeasuredRecAt8V3 *)(contactPlane))->value == 0) {
        intersectsPlane = 0;
    } else {
        GraphU64_SubtractVectors(segmentDirection, segmentEnd, segmentStart);
        normalDotDirection = (((struct MeasuredRecAt48V1 *)(contactPlane))->value * segmentDirection[0]) + (((struct Measured *)(contactPlane))->value * segmentDirection[1]) + (((struct Measured_func_802412D0_de_48a8d17d95e2 *)(contactPlane))->value * segmentDirection[2]);
        intersectsPlane = 0;
        if (normalDotDirection >= (f32)0) {
            hitFraction = D_800C3744_de;
        } else {
            GraphU64_SubtractVectors(planeToStart, segmentStart, contactPlane + 0x18);
            intersectsPlane = 1;
            hitFraction = -((((struct MeasuredRecAt48V1 *)(contactPlane))->value * planeToStart[0]) + (((struct Measured *)(contactPlane))->value * planeToStart[1]) + (((struct Measured_func_802412D0_de_48a8d17d95e2 *)(contactPlane))->value * planeToStart[2])) / normalDotDirection;
        }
    }
    if (intersectsPlane != 0) {
        GraphU64_InterpolateVector(outputPoint, *(u32 *)&hitFraction, segmentStart, segmentEnd);
        return 1;
    }
    return 0;
}

/* extern */
s32 func_802414F4_de(func_80204468_S3 *poly, void *testPoint) {
    void GraphU64_SubtractVectors(f32 *, void *, void *);
    f32 edgePlaneNormal[3];
    f32 edgeVector[3];
    f32 vertexToPoint[3];
    s32 vertexTotal;
    void *vertexCursor;
    s32 remainingEdges;
    void *previousVertex;
    vertexTotal = ((Polygon_func_8023E8D4_de *)poly)->vertexCount;
    if (vertexTotal == 1) {
        return 1;
    }
    previousVertex = (char *)poly + ((vertexTotal * 0xC) + 0xC);
    vertexCursor = ((Polygon_func_8023E8D4_de *)poly)->vertices;
    remainingEdges = vertexTotal;
    remainingEdges = remainingEdges - 1;
    for (; remainingEdges != -1; vertexCursor += 0xC, remainingEdges--) {
        GraphU64_SubtractVectors(edgeVector, vertexCursor, previousVertex);
        GraphU64_CrossVectors(edgePlaneNormal, &((Polygon_func_8023E8D4_de *)poly)->normal, edgeVector);
        GraphU64_SubtractVectors(vertexToPoint, testPoint, previousVertex);
        previousVertex = vertexCursor;
        if (edgePlaneNormal[0]*vertexToPoint[0]+edgePlaneNormal[1]*vertexToPoint[1]+edgePlaneNormal[2]*vertexToPoint[2] > 0.0f) return 0;
    }
    return 1;
}

s32 func_80241614_de(void *poly, void *point, f32 radius, void *testPoint) {
    CVector3 *first = point;
    CVector3 *second = testPoint;
    f32 dx = first->x - second->x;
    f32 dz = first->z - second->z;
    s32 result = 1;
    if (!((dx * dx + dz * dz) <= (radius * radius))) {
        result = 0;
    }
    return result;
}

/* Tests whether a point lies inside an object's four-sided footprint: for each edge of the corners at 0x18 it checks the side the point falls on in the x-z plane, walking the edges in reverse when the winding value at 0x4C is negative. */





s32 func_80241668_de(Footprint *fp, CVector3 *p)
{
    s32 i;
    CVector3 *a;
    CVector3 *b;
    f32 ax;

    for (i = 0; i < 4; i++) {
        if (fp->winding < 0.0f) {
            b = &fp->corner[i];
            a = &fp->corner[(i + 1) & 3];
        } else {
            a = &fp->corner[i];
            b = &fp->corner[(i + 1) & 3];
        }
        ax = a->x;
        if (0.0f < (b->z - a->z) * (p->x - ax) + (ax - b->x) * (p->z - a->z)) {
            return 0;
        }
    }
    return 1;
}

f32 func_80241728_de(void *query, f32 x, f32 z) {
    CVector3 normal;
    CVector3 point;

    normal = ((SurfaceHit *)query)->normal;
    if (normal.y == 0.0f) {
        return ((SurfaceHit *)query)->point.y;
    }
    point = ((SurfaceHit *)query)->point;
    return (((point.z - z) * normal.z) + ((point.x - x) * normal.x) + (point.y * normal.y)) / normal.y;
}
