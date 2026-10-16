#include "span_1000/code_8023A284.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
#include "common/unused.h"


extern f32 func_80241728_de(struct Query *, f32, f32);

extern f32 func_802B72B0_de(f32);

extern void func_80271F9C_de(void *, void *, f32);


/* Tests a ray against a polygon: intersects the ray from 0x44 to 0x50 with the polygon's plane through
 * func_802412D0_de and accepts a parameter nearer than the ray's current nearest hit, also allowing a slightly negative
 * one (above -D_800D0648 * D_800C87C0 scaled by the ray's 0x80 factor) except for kind 7 and types 5 and
 * 6; the hit point is then placed with func_80271FC8_de and must lie inside the polygon (func_802414F4_de). On a
 * hit the polygon record is optionally kept as the ray's nearest hit at 0xB0. */









extern s32 func_802412D0_de(Polygon_func_8023E8D4_de *, Vec3 *, Vec3 *, f32 *);

extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);

extern s32 func_802414F4_de(Polygon_func_8023E8D4_de *, Vec3 *);

static inline s32 accepts(CapsuleSweep *ray, Polygon_func_8023E8D4_de *poly) {
    if (poly->t <= 0.0f) {
        if (poly->kind == 7) {
            return 0;
        }
        if ((u32)(poly->type - 5) < 2) {
            return 0;
        }
        if (poly->t * ray->slack < -(D_800D0648 * D_800C87C0)) {
            return 0;
        }
    }
    if (poly->t >= ray->nearest.t) {
        return 0;
    }
    return 1;
}

/* Clips a segment against a query: measures the heights of its two ends through func_80241728_de,
   raises the far end by D_800D0640[1] scaled to 10.24, and when the squared flat length plus the
   squared height difference is not zero, moves the far end to the fraction func_802B72B0_de returns
   for the flat share of that length, writing the interpolated height at 0x54 and position at 0x50
   and 0x58. The node at 0x74 is then faded by what is left of one after the limit at 0x10 of the
   record at 0x40, and not at all once that limit passes one. */

struct Query;

void func_8023E6EC_de(SegmentCode8023A284 *arg0, struct Query *arg1) {
    f32 start;
    f32 span;
    f32 flat;
    f32 total;
    f32 dx;
    f32 dy;
    f32 share;
    f32 limit;
    f32 nx;
    void *target;
    f32 fade;
    void *node;

    start = func_80241728_de(arg1, arg0->x0, arg0->y0);
    span = (func_80241728_de(arg1, arg0->x1, arg0->y1) + (D_800D0640[1] * 10.24f)) - start;
    dx = arg0->x1 - arg0->x0;
    dy = arg0->y1 - arg0->y0;
    flat = (dx * dx) + (dy * dy);
    total = flat + (span * span);
    if (total == 0.0f) {
        arg0->height = start;
        return;
    }
    share = func_802B72B0_de(flat / total);
    node = arg0->node;
    nx = arg0->x0 + (share * (arg0->x1 - arg0->x0));
    arg0->height = start + (share * span);
    arg0->x1 = nx;
    arg0->y1 = arg0->y0 + (share * (arg0->y1 - arg0->y0));
    limit = arg0->limits->value;
    target = node;
    if (1.0f < limit) {
        fade = 0.0f;
    } else {
        fade = 1.0f - limit;
    }
    func_80271F9C_de(target, node, fade);
}

/** Thin wrapper around func_8023E854_de. */
void func_8023E838_de(void *arg0) {
    func_8023E854_de(arg0);
}

void func_8023E854_de(void *arg0) {
    struct Input *input = arg0;
    input->contactNormal.x = 0.0f;
    input->contactNormal.y = 0.0f;
    input->contactNormal.z = 0.0f;
}

s32 func_8023E864_de(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if ((((struct Input *)arg0)->contactNormal.x == ((Polygon_func_8023E8D4_de *)arg1)->normal.x) &&
        (((struct Input *)arg0)->contactNormal.y == ((Polygon_func_8023E8D4_de *)arg1)->normal.y) &&
        (((struct Input *)arg0)->contactNormal.z == ((Polygon_func_8023E8D4_de *)arg1)->normal.z)) {
        var_v0 = 1;
    }
    return var_v0;
}

/** Copy three words from offsets 0x48..0x50 to offsets 0x18C..0x194. */
void func_8023E8B4_de(void *arg0, void *arg1) {
    ObjRecAt48 *arg1_record = arg1;
    ObjRecAt18C *arg0_record = arg0;
    arg0_record->unk18C = arg1_record->unk48;
}

s32 func_8023E8D4_de(CapsuleSweep *ray, Polygon_func_8023E8D4_de *poly, s32 keep) {
    if (func_802412D0_de(poly, &ray->start, &ray->end, &poly->t) == 0) {
        return 0;
    }
    if (accepts(ray, poly) == 0) {
        return 0;
    }
    func_80271FC8_de(&poly->hit, poly->t, &ray->start, &ray->end);
    if (func_802414F4_de(poly, &poly->hit) == 0) {
        return 0;
    }
    if (keep != 0) {
        ray->nearest = *poly;
    }
    return 1;
}
