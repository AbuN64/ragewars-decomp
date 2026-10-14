#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
/* Tests a swept sphere against a polygon: shifts the ray from 0x44 to 0x50 back along the polygon normal by
 * the radius (plus an optional offset), intersects the shifted ray with the polygon's plane through
 * func_802412D0_de under the same acceptance rules as func_8023E8D4_de, requires the shifted hit point to pass
 * func_802406D0_de at that radius, then places the hit on the unshifted ray and optionally keeps the polygon
 * as the ray's nearest hit. Adapted from func_8023E8D4_de with its static acceptance helper.
 */







extern f32 D_800C3690_de;

extern s32 func_802412D0_de(Polygon *, Vec3 *, Vec3 *, f32 *);
extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern s32 func_802406D0_de(Polygon *, Vec3 *, f32);

static inline s32 accepts(Ray_func_8023DF70_de *ray, Polygon *poly) {
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

s32 func_8023DF70_de(Ray_func_8023DF70_de *ray, Vec3 *offset, f32 radius, Polygon *poly, s32 keep) {
    Vec3 start;
    Vec3 end;
    Vec3 shift;
    Vec3 hit;

    if (offset != 0) {
        func_80271F9C_de(&shift, &poly->normal, -radius);
        func_80271F34_de(&shift, &shift, offset);
    } else {
        shift.x = 0.0f;
        shift.y = 0.0f;
        shift.z = 0.0f;
    }
    func_80271F34_de(&start, &ray->start, &shift);
    func_80271F34_de(&end, &ray->end, &shift);
    if (func_802412D0_de(poly, &start, &end, &poly->t) == 0) {
        return 0;
    }
    if (accepts(ray, poly) == 0) {
        return 0;
    }
    func_80271FC8_de(&hit, poly->t, &start, &end);
    if (func_802406D0_de(poly, &hit, radius) == 0) {
        return 0;
    }
    func_80271FC8_de(&poly->hit, poly->t, &ray->start, &ray->end);
    if (keep != 0) {
        ray->nearest = *poly;
    }
    return 1;
}
