#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OUTPUT.H"
#include "TYPES.H"
#include "ENGINE/UNICOL/PLANE.H"

/* Tests a swept sphere against a polygon: shifts the ray from 0x44 to 0x50 back along the polygon normal by
 * the radius (plus an optional offset), intersects the shifted ray with the polygon's plane through
 * func_802412D0_de under the same acceptance rules as func_8023E8D4_de, requires the shifted hit point to pass
 * Plane_TestPointNearPolygon at that radius, then places the hit on the unshifted ray and optionally keeps the polygon
 * as the ray's nearest hit. Adapted from func_8023E8D4_de with its static acceptance helper.
 */







extern f32 D_800C3690_de;

extern s32 func_802412D0_de(Polygon *, CVector3 *, CVector3 *, f32 *);
extern void GraphU64_InterpolateVector(CVector3 *, f32, CVector3 *, CVector3 *);
extern void GraphU64_ScaleVector(CVector3 *, CVector3 *, f32);
extern void GraphU64_AddVec3(CVector3 *, CVector3 *, CVector3 *);

static inline s32 accepts(CapsuleSweep *ray, Polygon *poly) {
    if (poly->t <= 0.0f) {
        if (poly->kind == 7) {
            return 0;
        }
        if ((u32)(poly->type - 5) < 2) {
            return 0;
        }
        if (poly->t * ray->slack < -(D_800D0648 * D_800C3690_de)) {
            return 0;
        }
    }
    if (poly->t >= ray->nearest.t) {
        return 0;
    }
    return 1;
}

s32 func_8023DF70_de(CapsuleSweep *ray, CVector3 *offset, f32 radius, Polygon *poly, s32 keep) {
    CVector3 start;
    CVector3 end;
    CVector3 shift;
    CVector3 hit;

    if (offset != 0) {
        GraphU64_ScaleVector(&shift, &poly->normal, -radius);
        GraphU64_AddVec3(&shift, &shift, offset);
    } else {
        shift.x = 0.0f;
        shift.y = 0.0f;
        shift.z = 0.0f;
    }
    GraphU64_AddVec3(&start, &ray->start, &shift);
    GraphU64_AddVec3(&end, &ray->end, &shift);
    if (func_802412D0_de(poly, &start, &end, &poly->t) == 0) {
        return 0;
    }
    if (accepts(ray, poly) == 0) {
        return 0;
    }
    GraphU64_InterpolateVector(&hit, poly->t, &start, &end);
    if (Plane_TestPointNearPolygon(poly, &hit, radius) == 0) {
        return 0;
    }
    GraphU64_InterpolateVector(&poly->hit, poly->t, &ray->start, &ray->end);
    if (keep != 0) {
        ray->nearest = *poly;
    }
    return 1;
}
