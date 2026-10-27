#include "COMMON/PACKED.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "FX_2/80271B18.H"

/* Returns whether a polygon counts as a wall: without flag 0x2000 it returns its flag 8, and otherwise it takes the polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one) and returns whether the normal's upward component is at most D_800C9AD8. */







extern Triangle *D_800CD3E8;

extern Triangle *D_800CD3EC;





extern void GraphU64_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);

extern void GraphU64_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


static inline void edge(CVector3 *out, CVector3 *a, CVector3 *b) {
    GraphU64_SubtractVectors(out, a, b);
}

static inline void normalize_copy(CVector3 *out, CVector3 *in) {
    *out = *in;
    GraphU64_NormalizeVec3(out);
}

s32 Region_TestPolygonSlopeFlag(Triangle *polygon) {
    CVector3 up;
    CVector3 normal;
    CVector3 edge0;
    CVector3 edge1;

    if (polygon == 0) {
        return 0;
    }
    if (!(polygon->flags & 0x2000)) {
        return polygon->flags & 8;
    }
    up.x = 0.0f;
    up.y = *(&D_800C49E0_de + 1);
    up.z = 0.0f;
    if (polygon != D_800CD3EC) {
        if (polygon == 0) {
            *(s32 *)&D_80115E10 = 0;
            D_80111D54 = *(&D_800C49E0_de + 1);
            D_80111D58 = 0;
        } else if (polygon != D_800CD3E8) {
            edge(&edge0, polygon->vertices[1], polygon->vertices[0]);
            edge(&edge1, polygon->vertices[2], polygon->vertices[1]);
            GraphU64_CrossVectors(&D_80115E10, &edge0, &edge1);
        }
        D_800CD3E8 = polygon;
        normalize_copy(&D_80115E20, &D_80115E10);
    }
    normal = D_80115E20;
    D_800CD3EC = polygon;
    if (normal.x * up.x + normal.y * up.y + normal.z * up.z <= D_800C9AD8) {
        return 1;
    }
    return 0;
}

void Region_ComputePointBounds(f32 *pointBounds, s32 pointCount, CVector3 *pointCursor)
{
    s32 i;

    i = 0;
    if (pointCount != 0) {
        pointBounds[0] = pointCursor->x;
        pointBounds[1] = pointCursor->y;
        pointBounds[2] = pointCursor->z;
        pointBounds[3] = pointCursor->x;
        pointBounds[4] = pointCursor->y;
        pointCount -= 1;
        pointBounds[5] = pointCursor->z;
        pointCursor += 1;

        if (pointCount > 0) {
bounds_loop:
                {
                    f32 value = pointCursor->x;
                    f32 bound = pointBounds[0];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    pointBounds[0] = value;
                }

                {
                    f32 value = pointCursor->y;
                    f32 bound = pointBounds[1];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    pointBounds[1] = value;
                }

                {
                    f32 value = pointCursor->z;
                    f32 bound = pointBounds[2];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    pointBounds[2] = value;
                }

                {
                    f32 value = pointCursor->x;
                    f32 bound = pointBounds[3];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    pointBounds[3] = value;
                }

                {
                    f32 value = pointCursor->y;
                    f32 bound = pointBounds[4];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    pointBounds[4] = value;
                }

                {
                    f32 value = pointCursor->z;
                    f32 bound = pointBounds[5];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    pointBounds[5] = value;
                }

                i += 1;
                pointCursor += 1;
            if (i < pointCount) goto bounds_loop;
        }
    }
}
