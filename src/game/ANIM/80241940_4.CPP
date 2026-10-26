#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_14.H"
#include "ANIM/RAY180.H"
#include "ANIM/802412C0_12.H"
#include "WEAPONS/80213ED4_5.H"
#include "RENDER_4/8028FD2C_6.H"

extern s32 func_8023E8D4_de(void *, s32 *, s32);

extern void Plane_BuildBoxFace0(s32 *, void *);

extern void Plane_BuildBoxFace1(s32 *, void *);

extern void Plane_BuildBoxFace2(s32 *, void *);

extern void Plane_BuildBoxFace3(s32 *, void *);

extern void Plane_BuildBoxFace4(s32 *, void *);

extern void Plane_BuildBoxFace5(s32 *, void *);

s32 func_8023E178_de(void *, void *, f32, s32, f32, s32, s32 *, s32);

s32 func_8023EA44_de(void *, s32 *, void *, f32, s32);

void Plane_BuildBoxFace0(s32 *, void *);

void Plane_BuildBoxFace1(s32 *, void *);

/* Gathers the pieces a ray sweeps through: for each entry of the counted table in D_8011CD20 whose
 * rectangle, grown by the ray's radius, overlaps the ray's rectangle and is hit by it, each visible element
 * of the entry's resource whose grown box overlaps the ray's box and is hit is recorded with its hit
 * parameter (at most 128). The hits are sorted and, while nearer than the ray's current nearest hit, each
 * is handed to func_80243874_de with a context holding the ray, its look-at matrix and segment spacing. */
extern struct {
    char pad0[0x5AC];
    s32 count;
    EntryC entries[1];
} D_8011CD20;

extern s32 func_8023DAA0_de(Ray180 *, Box *, f32 *);

extern s32 func_8023DDC4_de(Ray180 *, CQuatern *, f32 *);

extern void func_80243874_de(ContextB0 *);

extern void func_802852C0_de(char *, u32, u32, void *, void *);

s32 func_80242920_de(void *ray, void *arg1, void *corners, s32 *quad) {
    s32 result;

    result = 0;
    if (((struct FloatState68 *) ray)->unk_60 > 0.0f) {
        *quad = 2;
        Plane_BuildBoxFace1(quad, corners);
        result = func_8023E8D4_de(ray, quad, 1);
    }
    if ((((struct FloatState68 *) ray)->unk_5C != 0.0f) || (((struct FloatState68 *) ray)->unk_64 != 0.0f)) {
        *quad = 3;
        Plane_BuildBoxFace2(quad, corners);
        result |= func_8023E8D4_de(ray, quad, 1);
        Plane_BuildBoxFace3(quad, corners);
        result |= func_8023E8D4_de(ray, quad, 1);
        Plane_BuildBoxFace4(quad, corners);
        result |= func_8023E8D4_de(ray, quad, 1);
        Plane_BuildBoxFace5(quad, corners);
        result |= func_8023E8D4_de(ray, quad, 1);
    }
    if (((struct FloatState68 *) ray)->unk_60 < 0.0f) {
        *quad = 9;
        Plane_BuildBoxFace0(quad, corners);
        result |= func_8023E8D4_de(ray, quad, 1);
    }
    return result;
}

s32 func_80242A94_de(void *ray, void *platform, void *corners, s32 *contactPolygon) {
    f32 radius;
    s32 hitFound;
    void *point;

    hitFound = 0;
    point = platform + 8;
    radius = ((struct FloatState20 *) ((struct ObjRecAt18V5 *) platform)->unk18)->unk_1C + ((struct FloatState68_2 *) ray)->unk_C;
    if ((((struct FloatState68_2 *) ray)->unk_5C != 0.0f) || (((struct FloatState68_2 *) ray)->unk_64 != 0.0f)) {
        *contactPolygon = 3;
        hitFound = func_8023E178_de(ray, point, radius, ((struct ObjRecAt34 *) corners)->unk4, ((struct ObjRecAt34 *) corners)->unk34, 1, contactPolygon, 1);
    }
    if (((struct FloatState68_2 *) ray)->unk_60 > 0.0f) {
        *contactPolygon = 2;
        Plane_BuildBoxFace1(contactPolygon, corners);
        hitFound |= func_8023EA44_de(ray, contactPolygon, point, radius, 1);
    }
    if (((struct FloatState68_2 *) ray)->unk_60 < 0.0f) {
        *contactPolygon = 9;
        Plane_BuildBoxFace0(contactPolygon, corners);
        hitFound |= func_8023EA44_de(ray, contactPolygon, point, radius, 1);
    }
    return hitFound;
}

void func_80242BF0_de(Ray180 *ray) {
    Box box;
    CQuatern rect;
    ContextB0 ctx;
    Hit8 hits[128];
    f32 t;
    CVector3 *start;
    CVector3 *end;
    Hit8 *hit;
    EntryC *table;
    ModelF0 *model;
    ElementE8 *element;
    s32 count;
    s32 hitCount;
    s32 segments;
    s32 remaining;
    s32 i;
    s32 j;

    start = &ray->start;
    end = &ray->end;
    ctx.ray = ray;
    ctx.start = start;
    ctx.end = end;
    ctx.reach = ray->scale * ray->nearest + ray->radius;
    if (ray->spacing != 0.0f) {
        segments = ((2) > ((s32) (ray->length / ray->spacing) + 1) ? (2) : ((s32) (ray->length / ray->spacing) + 1));
        ctx.segments = segments;
        ctx.step = (ray->length - 2.0f * ray->spacing) / (f32) (segments - 1);
    } else {
        ctx.segments = 1;
        ctx.step = 1.0f;
    }
    hit = hits;
    hitCount = 0;
    table = D_8011CD20.entries;
    count = D_8011CD20.count;
    for (i = 0; i < count; i++) {
        rect.x = table[i].rect->x - ray->radius;
        rect.y = table[i].rect->y - ray->radius;
        rect.z = table[i].rect->z + ray->radius;
        rect.w = table[i].rect->w + ray->radius;
        if (ray->rect.x < rect.z && rect.x < ray->rect.z && ray->rect.y < rect.w &&
            rect.y < ray->rect.w && func_8023DDC4_de(ray, &rect, &t) != 0) {
            model = SetN64_GetPackSection(*table[i].resource, 0);
            remaining = model->count;
            element = model->elements;
            while (--remaining != -1) {
                if (hitCount >= 128) {
                    break;
                }
                if (!(element->flags & 0x10)) {
                    box.min.x = element->box.min.x - ray->radius;
                    box.min.y = element->box.min.y - ray->radius;
                    box.min.z = element->box.min.z - ray->radius;
                    box.max.x = element->box.max.x + ray->radius;
                    box.max.y = element->box.max.y + ray->radius;
                    box.max.z = element->box.max.z + ray->radius;
                    if (box.min.x < ray->box.max.x && ray->box.min.x < box.max.x && box.min.z < ray->box.max.z &&
                        ray->box.min.z < box.max.z && box.min.y < ray->box.max.y && ray->box.min.y < box.max.y &&
                        func_8023DAA0_de(ray, &box, &t) != 0) {
                        hitCount++;
                        hit->element = element;
                        hit->t = t;
                        hit++;
                    }
                }
                element++;
            }
        }
    }
    if (hitCount != 0) {
        func_8026F368_de(&ctx.matrix, start, end, &D_800CC3D0_de);
        func_802852C0_de((char *) hits, hitCount, sizeof(Hit8), D_00243850, D_00243814);
        hit = hits;
        for (j = 0; j < hitCount; j++, hit++) {
            if (!(hit->t < ray->nearest)) {
                break;
            }
            element = hit->element;
            ctx.element = element;
            ctx.kind = Weapons_GetImpactSlot(element);
            if (ctx.kind == 9) {
                ctx.isKind9 = 1;
            } else {
                ctx.isKind9 = 0;
            }
            func_80243874_de(&ctx);
        }
    }
}
