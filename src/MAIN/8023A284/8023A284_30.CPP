#include "span_1000/code_8023A284.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/box_contact.h"
#include "shared/legacy_collision_actor.h"
#include "shared/motion_step.h"
#include "shared/world.h"
#include "span_1000/code_8023D370.h"
#include "span_C76B0/data.h"
#include "TYPES.H"

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

extern World *D_80103FCC;

extern void *func_8028B2F8_de(Shared_World *, u16 *);

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

void func_8023EBD4_de(void)
{
  D_80103FCC->unk100 = (D_80103FCC->state = (D_80103FCC->unkC4 = (D_80103FCC->unkB0 = (D_80103FCC->unk9C = (D_80103FCC->unk88 = (D_80103FCC->unk0 = 0))))));
}

void func_8023EBFC_de(ActorMotion *arg0, MotionContactResult *arg1) {
    s32 temp_a1;
    s32 temp_v1;

    temp_v1 = arg0->flags & ~0xE00;
    arg0->flags = temp_v1;
    temp_a1 = arg1->flags;
    if (temp_a1 & 0x20000000) {
        arg0->flags = temp_v1 | 0x200;
        return;
    }
    if (temp_a1 & 0x40000000) {
        arg0->flags = temp_v1 | 0x400;
        return;
    }
    if (temp_a1 < 0) {
        arg0->flags = temp_v1 | 0x800;
    }
}

void func_8023EC54_de(ActorMotion *arg0, MotionContactResult *arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = arg0->flags;
    if (temp_v1 & 0x1000) {
        arg0->flags = temp_v1 & ~0x2000;
    }
    temp_v0 = arg0->flags;
    temp_v1_2 = temp_v0 & 0xFFFC7FFF;
    arg0->flags = temp_v1_2;
    if (temp_v0 & 0x7000) {
        temp_a1 = arg1->material;
        switch (temp_a1) {
        case 8:
            arg0->flags = temp_v1_2 | 0x10000;
            return;
        case 7:
            arg0->flags = temp_v1_2 | 0x8000;
            break;
        }
    }
}

void func_8023ECBC_de(void *arg0, u16 *arg1)
{
  char *o = (char *) arg0;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 var_v0;
  void *temp_v0;
  temp_v1 = ((Shared_Func80243A80Frame *)o)->sp54;
  if (temp_v1 & 0x1000)
  {
    ((Shared_Func80243A80Frame *)o)->sp54 = temp_v1 & (~0x2000);
  }
  temp_v1_2 = ((Shared_Func80243A80Frame *)o)->sp54;
  ((Shared_Func80243A80Frame *)o)->sp54 = temp_v1_2 & 0xFFFC7FFF;
  if (temp_v1_2 & 0x7000)
  {
    temp_v0 = func_8028B2F8_de(&D_8011FE88, arg1);
    if (temp_v0 != 0)
    {
      if ((((ModelBlend *)temp_v0)->collisionFlags) & 0x400000)
      {
        ;
        ((Shared_Func80243A80Frame *)o)->sp54 = (((Shared_Func80243A80Frame *)o)->sp54) | 0x8000;
      }
      else
        if ((((ModelBlend *)temp_v0)->materialFlags) & 0x80)
      {
        var_v0 = (((Shared_Func80243A80Frame *)o)->sp54) | 0x10000;
        ((Shared_Func80243A80Frame *)o)->sp54 = var_v0;
      }
    }
  }
}

s32 func_8023ED64_de(BoxContactRay *arg0, BoxContactPolygon *arg1) {
    f32 temp_f2;
    s32 var_v0;

    temp_f2 = arg1->t;
    if (temp_f2 <= 0.0f) {
        if (arg1->kind == 7) {
            return 0;
        }
        if ((u32) (arg1->type - 5) < 2) {
            return 0;
        }
        if ((temp_f2 * arg0->slack) < -(D_800D0648 * D_800C36D8_de)) {
            return 0;
        }
    }
    var_v0 = 0;
    {
        f32 b = arg1->t;
        if (!(arg0->nearest.t <= b)) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
