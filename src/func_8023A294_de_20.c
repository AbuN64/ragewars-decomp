#include "span_1000/code_8023A284.h"
#include "common/types_8a8189af7b05.h"
#include "shared/motion_step.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
#include "shared/func_8027AD4C_de_closed.h"

/* Tests a ray against a vertical cylinder: projects the center onto the ray's horizontal direction from 0x44,
 * finds the entry parameter from the radius, accepts it under the same rules as func_8023E8D4_de, places the
 * hit with func_80271FC8_de and optionally rejects hits above the top or below the bottom; when kept, the
 * polygon record takes the hit as its point with a horizontal normal away from the center and becomes the
 * ray's nearest hit. Adapted from func_8023E8D4_de with its static acceptance helper.
 */







extern f32 D_800C3690_de[];

extern s32 func_802412D0_de(Polygon_func_8023E178_de *, Vec3 *, Vec3 *, f32 *);

extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);


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

extern Output *D_80103FCC;

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

void func_8023E45C_de(Input *arg0) {
    {
        s32 type = arg0->type;
        s32 sw_type_value = type - 1;
        if ((unsigned int)sw_type_value > 8) {
            goto sw_type_default;
        }
        switch (sw_type_value) {
        case 0: goto sw_type_1;
        case 1: goto sw_type_1;
        case 2: goto sw_type_1;
        case 3: goto sw_type_1;
        case 4: goto sw_type_2;
        case 5: goto sw_type_6;
        case 6: goto sw_type_3;
        case 7: goto sw_type_4;
        case 8: goto sw_type_5;
        }
    }
    do {
    sw_type_1:
        D_80103FCC->instance0 = arg0->instance104;
        if (arg0->instance104 != 0) {
            D_80103FCC->instanceValue4 = arg0->instance104->field14;
        } else {
            D_80103FCC->instanceValue4 = 0;
        }
        D_80103FCC->vec8 = arg0->vec180;
        D_80103FCC->field14 = -1;
        break;
    sw_type_2:
        if (arg0->instance104 != 0) {
            D_80103FCC->fieldC4 = arg0->instance104->field14;
        } else {
            D_80103FCC->fieldC4 = 0;
        }
        D_80103FCC->vecC8 = arg0->vec180;
        D_80103FCC->fieldD4 = arg0->fieldBC;
        break;
    sw_type_3:
        D_80103FCC->instance0 = arg0->instance104;
        D_80103FCC->instanceValue4 = arg0->instance104->field14;
        D_80103FCC->vec8 = arg0->vec180;
        D_80103FCC->field14 = -1;
        break;
    sw_type_4:
        D_80103FCC->instance0 = arg0->instance104;
        D_80103FCC->instanceValue4 = arg0->instance104->field14;
        D_80103FCC->vec8 = arg0->vec180;
        D_80103FCC->field14 = arg0->field108;
        D_80103FCC->block18 = arg0->block10C;
        break;
    sw_type_5:
        D_80103FCC->instance88 = arg0->instance104;
        D_80103FCC->instanceValue8C = arg0->instance104->field14;
        D_80103FCC->vec90 = arg0->vec180;
        break;
    sw_type_6:
    sw_type_7:
    sw_type_8:
    sw_type_9:
        break;
    
    sw_type_default:;
    } while (0);
    D_80103FCC->vecF0 = arg0->vecF8;
    D_80103FCC->vecE4 = arg0->vec180;
    D_80103FCC->typeFC = arg0->type;
    D_80103FCC->field100 = arg0->fieldC0;
}

/* Stores a range and its parameters in a record: the low bound at 8, a count at 0xC, the high
   bound at 0x10 and a fourth value at 0x14, and at 0x18 the larger bound plus the pooled constant
   D_800C87B4. */




void func_8023E690_de(struct Range *range, f32 low, s32 count, f32 high, f32 extra) {
    f32 larger;

    range->count = count;
    range->low = low;
    range->high = high;
    range->extra = extra;
    larger = high;
    if (!(low <= high)) {
        larger = low;
    }
    range->limit = larger + D_800C87B4;
}

void func_8023E6D0_de(void *arg0, float arg1) {
    ActorMotion *motion = arg0;
    motion->bottom = 0.0f;
    motion->field08 = arg1;
    motion->radius = arg1;
    motion->height = arg1;
    motion->field18 = arg1;
}
