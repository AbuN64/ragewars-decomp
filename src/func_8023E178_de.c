#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
/* Tests a ray against a vertical cylinder: projects the center onto the ray's horizontal direction from 0x44,
 * finds the entry parameter from the radius, accepts it under the same rules as func_8023E8D4_de, places the
 * hit with func_80271FC8_de and optionally rejects hits above the top or below the bottom; when kept, the
 * polygon record takes the hit as its point with a horizontal normal away from the center and becomes the
 * ray's nearest hit. Adapted from func_8023E8D4_de with its static acceptance helper.
 */







extern f32 D_800C3690_de[];

extern s32 func_802412D0_de(Polygon_func_8023E178_de *, Vec3 *, Vec3 *, f32 *);
extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);
extern f32 func_802B72B0_de(f32);

static inline s32 accepts(Ray_func_8023E178_de *ray, Polygon_func_8023E178_de *poly) {
    if (poly->t <= 0.0f) {
        if (poly->kind == 7) {
            return 0;
        }
        if ((u32)(poly->type - 5) < 2) {
            return 0;
        }
        if (poly->t * ray->slack < -(D_800D0648 * D_800C3690_de[2])) {
            return 0;
        }
    }
    if (poly->t >= ray->nearest.t) {
        return 0;
    }
    return 1;
}

s32 func_8023E178_de(Ray_func_8023E178_de *ray, Vec3 *center, f32 radius, f32 top, f32 bottom, s32 clip, Polygon_func_8023E178_de *poly, s32 keep) {
    Vec3 delta;
    Vec3 dir;
    Vec3 perp;
    f32 len;
    f32 inv;
    f32 along;
    f32 disc;

    delta.x = center->x - ray->start.x;
    delta.z = center->z - ray->start.z;
    if (delta.x * ray->dir.x + delta.z * ray->dir.z < 0.0f) {
        return 0;
    }
    len = func_802B72B0_de(ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z);
    if (len == 0.0f) {
        return 0;
    }
    inv = D_800C3690_de[1] / len;
    dir.x = ray->dir.x * inv;
    dir.z = ray->dir.z * inv;
    along = delta.x * dir.x + delta.z * dir.z;
    perp.x = delta.x - dir.x * along;
    perp.z = delta.z - dir.z * along;
    disc = radius * radius - (perp.x * perp.x + perp.z * perp.z);
    if (!(disc > 0.0f)) {
        return 0;
    }
    poly->t = (along - func_802B72B0_de(disc)) * inv;
    if (accepts(ray, poly) != 0) {
        func_80271FC8_de(&poly->hit, poly->t, &ray->start, &ray->end);
        if (clip != 0 && (poly->hit.y > top || poly->hit.y < bottom)) {
            return 0;
        }
        if (keep != 0) {
            poly->flag = 1;
            poly->point = poly->hit;
            poly->normal.x = poly->point.x - center->x;
            poly->normal.y = 0.0f;
            poly->normal.z = poly->point.z - center->z;
            ray->nearest = *poly;
        }
        return 1;
    }
    return 0;
}
