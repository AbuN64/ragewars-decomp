#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OUTPUT.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "ANIM/8023DF60_3.H"

extern f32 func_80241728_de(struct Query *, f32, f32);

extern f32 Math_Sqrtf(f32);

extern void GraphU64_ScaleVector(void *, void *, f32);


/* Tests a ray against a polygon: intersects the ray from 0x44 to 0x50 with the polygon's plane through
 * func_802412D0_de and accepts a parameter nearer than the ray's current nearest hit, also allowing a slightly negative
 * one (above -D_800D0648 * D_800C87C0 scaled by the ray's 0x80 factor) except for kind 7 and types 5 and
 * 6; the hit point is then placed with GraphU64_InterpolateVector and must lie inside the polygon (func_802414F4_de). On a
 * hit the polygon record is optionally kept as the ray's nearest hit at 0xB0. */









extern s32 func_802412D0_de(Polygon_func_8023E8D4_de *, CVector3 *, CVector3 *, f32 *);

extern void GraphU64_InterpolateVector(CVector3 *, f32, CVector3 *, CVector3 *);

extern s32 func_802414F4_de(Polygon_func_8023E8D4_de *, CVector3 *);

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

void func_8023E6EC_de(SegmentCode8023A284 *segment, struct Query *query) {
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

    start = func_80241728_de(query, segment->x0, segment->y0);
    span = (func_80241728_de(query, segment->x1, segment->y1) + (D_800D0640[1] * 10.24f)) - start;
    dx = segment->x1 - segment->x0;
    dy = segment->y1 - segment->y0;
    flat = (dx * dx) + (dy * dy);
    total = flat + (span * span);
    if (total == 0.0f) {
        segment->height = start;
        return;
    }
    share = Math_Sqrtf(flat / total);
    node = segment->node;
    nx = segment->x0 + (share * (segment->x1 - segment->x0));
    segment->height = start + (share * span);
    segment->x1 = nx;
    segment->y1 = segment->y0 + (share * (segment->y1 - segment->y0));
    limit = segment->limits->value;
    target = node;
    if (1.0f < limit) {
        fade = 0.0f;
    } else {
        fade = 1.0f - limit;
    }
    GraphU64_ScaleVector(target, node, fade);
}

/** Thin wrapper around func_8023E854_de. */
void func_8023E838_de(void *contactInput) {
    func_8023E854_de(contactInput);
}

void func_8023E854_de(void *contactStorage) {
    struct Input *input = contactStorage;
    input->contactNormal.x = 0.0f;
    input->contactNormal.y = 0.0f;
    input->contactNormal.z = 0.0f;
}

s32 func_8023E864_de(struct Input *input, Polygon_func_8023E8D4_de *polygon) {
    s32 same;

    same = 0;
    if ((input->contactNormal.x == polygon->normal.x) &&
        (input->contactNormal.y == polygon->normal.y) &&
        (input->contactNormal.z == polygon->normal.z)) {
        same = 1;
    }
    return same;
}

/** Copy three words from offsets 0x48..0x50 to offsets 0x18C..0x194. */
void func_8023E8B4_de(void *contactStorage, void *polygonStorage) {
    ObjRecAt48 *arg1_record = polygonStorage;
    ObjRecAt18C *arg0_record = contactStorage;
    arg0_record->unk18C = arg1_record->unk48;
}

s32 func_8023E8D4_de(CapsuleSweep *ray, Polygon_func_8023E8D4_de *poly, s32 keep) {
    if (func_802412D0_de(poly, &ray->start, &ray->end, &poly->t) == 0) {
        return 0;
    }
    if (accepts(ray, poly) == 0) {
        return 0;
    }
    GraphU64_InterpolateVector(&poly->hit, poly->t, &ray->start, &ray->end);
    if (func_802414F4_de(poly, &poly->hit) == 0) {
        return 0;
    }
    if (keep != 0) {
        ray->nearest = *poly;
    }
    return 1;
}
