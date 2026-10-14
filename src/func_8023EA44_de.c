#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
/* Tests a ray against a polygon with a radius: intersects the ray from 0x44 to 0x50 with the polygon's plane
 * through func_802412D0_de and accepts a parameter nearer than the ray's nearest hit, also allowing a slightly
 * negative one (above -D_800D0648 * D_800C87C0[1] scaled by the ray's 0x80 factor) except for kind 7 and
 * types 5 and 6; the hit point is then placed with func_80271FC8_de and tested against the polygon with the
 * given point and radius through func_80241614_de. On a hit the polygon record is optionally kept as the ray's
 * nearest hit. Adapted from func_8023E8D4_de with the radius test and the slack constant. */









extern s32 func_802412D0_de(Polygon_func_8023E8D4_de *, Vec3 *, Vec3 *, f32 *);
extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);
extern s32 func_80241614_de(Polygon_func_8023E8D4_de *, Vec3 *, f32, Vec3 *);




static inline s32 accepts(CapsuleSweep *ray, Polygon_func_8023E8D4_de *poly) {
    if (poly->t <= 0.0f) {
        if (poly->kind == 7) {
            return 0;
        }
        if ((u32)(poly->type - 5) < 2) {
            return 0;
        }
        if (poly->t * ray->slack < -(D_800D0648 * D_800C36D4_de)) {
            return 0;
        }
    }
    if (poly->t >= ray->nearest.t) {
        return 0;
    }
    return 1;
}

s32 func_8023EA44_de(CapsuleSweep *ray, Polygon_func_8023E8D4_de *poly, Vec3 *point, f32 radius, s32 keep) {
    if (func_802412D0_de(poly, &ray->start, &ray->end, &poly->t) == 0) {
        return 0;
    }
    if (accepts(ray, poly) == 0) {
        return 0;
    }
    func_80271FC8_de(&poly->hit, poly->t, &ray->start, &ray->end);
    if (func_80241614_de(poly, point, radius, &poly->hit) == 0) {
        return 0;
    }
    if (keep != 0) {
        ray->nearest = *poly;
    }
    return 1;
}
