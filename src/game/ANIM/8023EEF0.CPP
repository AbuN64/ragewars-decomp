#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "TYPES.H"

#if !(defined(VERSION_EU))
#ifdef NON_MATCHING
#define HIT_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
typedef struct HitEventCopy { u8 bytes[0xDC]; } HitEventCopy;
typedef struct HitPoint { f32 x; f32 y; f32 z; } HitPoint;
extern f32 D_800C36E0_de, D_800C36E4_de;
extern f32 func_8024D398_de();
extern f32 func_8024E420_de();
extern f32 Particle_GetActorHeight();
extern void func_80242550_de();
extern void func_80242288_de();
extern s32 func_802AB400_de();
extern void func_80271FC8_de();
extern void func_8023E8D4_de();
extern void func_8023E178_de();
void func_8023EF00_de(void *selfArg, struct Query *boundsArg, u8 *obj) {
    u8 *self = selfArg;
    u8 *bounds = boundsArg;
    u8 event[0xDC];
    HitPoint point;
    f32 box[4];
    u8 *owner;
    u8 *config;
    f32 objX = HIT_FIELD(obj, f32, 8);
    f32 objZ = HIT_FIELD(obj, f32, 0x10);
    f32 radius;
    f32 bottom;
    f32 top;
    f32 ownerX;
    f32 ownerZ;
    f32 t;
    f32 dx;
    f32 dz;
    f32 reach;
    s32 special = 0;
    s32 kind;
    radius = func_8024D398_de(obj);
    box[0] = objX - radius;
    box[1] = objZ - radius;
    box[2] = objX + radius;
    box[3] = objZ + radius;
    if (!(box[0] < HIT_FIELD(bounds, f32, 0x24) && HIT_FIELD(bounds, f32, 0x1C) < box[2] &&
          box[1] < HIT_FIELD(bounds, f32, 0x28) && HIT_FIELD(bounds, f32, 0x20) < box[3])) {
        return;
    }
    owner = HIT_FIELD(self, u8 *, 0);
    config = HIT_FIELD(self, u8 *, 0x40);
    if (HIT_FIELD(owner, u8, 0) == 1 && HIT_FIELD(HIT_FIELD(owner, u8 *, 0x18), s32, 0) == 2) {
        if (HIT_FIELD(obj, u8, 0) == HIT_FIELD(owner, u8, 0)) {
            func_80242550_de(self, obj);
        }
        return;
    }
    if (HIT_FIELD(obj, u8, 0) == 1 && HIT_FIELD(HIT_FIELD(obj, u8 *, 0x18), s32, 0) == 2) {
        if (HIT_FIELD(owner, u8, 0) == HIT_FIELD(obj, u8, 0)) {
            func_80242288_de(self, obj);
        }
        return;
    }
    if (HIT_FIELD(obj, u8, 0) == 3) {
        if (func_802AB400_de(obj, owner) == 0) {
            return;
        }
        special = 1;
    }
    HIT_FIELD(event, s32, 0) = 7;
    HIT_FIELD(event, s32, 4) = 0;
    HIT_FIELD(event, s32, 0xC) = 0;
    HIT_FIELD(event, s32, 0x10) = 0;
    HIT_FIELD(event, s32, 0x14) = 1;
    HIT_FIELD(event, u8 *, 0x54) = obj;
    HIT_FIELD(event, s32, 0x58) = -1;
    bottom = HIT_FIELD(obj, f32, 0xC) + func_8024E420_de(obj);
    top = bottom + Particle_GetActorHeight(obj);
    if (HIT_FIELD(bounds, s32, 0x2C) != 0) {
        HIT_FIELD(bounds, f32, 0x48) = 0;
    }
    ownerX = HIT_FIELD(owner, f32, 8);
    ownerZ = HIT_FIELD(owner, f32, 0x10);
    reach = HIT_FIELD(bounds, f32, 0) + radius;
    if (HIT_FIELD(bounds, s32, 0x2C) != 0 && HIT_FIELD(self, f32, 0x60) != 0.0f) {
        if (HIT_FIELD(bounds, f32, 0xC) <= bottom && bottom < HIT_FIELD(bounds, f32, 0x14)) {
            t = (bottom - HIT_FIELD(bounds, f32, 0xC)) / HIT_FIELD(self, f32, 0x60);
            if (t < HIT_FIELD(self, f32, 0x17C)) {
                func_80271FC8_de(&point, t, owner + 8, self + 0x50);
                dx = objX - point.x;
                dz = objZ - point.z;
                if (dx * dx + dz * dz < reach * reach) {
                    HIT_FIELD(event, s32, 8) = 7;
                    HIT_FIELD(event, HitPoint, 0x18) = point;
                    HIT_FIELD(event, s32, 0x48) = 0;
                    HIT_FIELD(event, s32, 0x50) = 0;
                    HIT_FIELD(event, f32, 0x4C) = D_800C36E0_de;
                    func_8023E8D4_de(self, event, 1);
                }
            }
        }
        if (HIT_FIELD(bounds, f32, 0x10) <= top && top < HIT_FIELD(bounds, f32, 0x18)) {
            t = (top - HIT_FIELD(bounds, f32, 0x10)) / HIT_FIELD(self, f32, 0x60);
            if (t < HIT_FIELD(self, f32, 0x17C)) {
                func_80271FC8_de(&point, t, owner + 8, self + 0x50);
                dx = objX - point.x;
                dz = objZ - point.z;
                if (dx * dx + dz * dz < reach * reach) {
                    kind = HIT_FIELD(config, s8, 4);
                    if (kind == 1) {
                        HIT_FIELD(event, s32, 8) = kind;
                    } else {
                        HIT_FIELD(event, s32, 8) = (HIT_FIELD(HIT_FIELD(obj, u8 *, 0x18), u32, 4) & 0x80) ? 2 : 7;
                    }
                    HIT_FIELD(event, HitPoint, 0x18) = point;
                    HIT_FIELD(event, s32, 0x48) = 0;
                    HIT_FIELD(event, s32, 0x50) = 0;
                    HIT_FIELD(event, f32, 0x4C) = D_800C36E4_de;
                    func_8023E8D4_de(self, event, 1);
                }
            }
        }
    }
    if (special != 0) {
        HIT_FIELD(event, s32, 8) = 7;
    } else {
        HIT_FIELD(event, s32, 8) = HIT_FIELD(config, s8, 4);
    }
    func_8023E178_de(self, obj + 8, radius, top - HIT_FIELD(bounds, f32, 4), bottom - HIT_FIELD(bounds, f32, 8), 1, event, 1);
    if (special != 0 && HIT_FIELD(self, u8 *, 0x104) != obj && HIT_FIELD(bounds, f32, 0x10) <= top && bottom < HIT_FIELD(bounds, f32, 0xC)) {
        dx = objX - ownerX;
        dz = objZ - ownerZ;
        if (dx * dx + dz * dz < reach * reach) {
            HIT_FIELD(event, s32, 0x48) = 0;
            HIT_FIELD(event, s32, 0x4C) = 0;
            HIT_FIELD(event, s32, 0x50) = 0;
            *(HitEventCopy *)(self + 0xB0) = *(HitEventCopy *)event;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8023EF00_de);
#endif
#endif
#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_8023EF14);
#endif

typedef struct Query Query;
/* Queries the registered entities an object may collide with: when the object's shape is enabled and is
 * not the null shape, a query holds the object's radius, its vertical span and that span offset by the
 * shape heights at 0x48 and 0x54, its horizontal bounds widened by the radius and the shape's 0x400 flag;
 * then func_8023EF00_de is run for every entity other than the object itself, except type 1 entities without
 * a body at 0x174 when the shape is flagged 1 and type 3 entities when the shape is not flagged 0x20. */







extern Shape D_80100170;
extern void func_8023EF00_de(void *, Query *, u8 *);






void func_8023F43C_de(char *obj) {
    Query query;
    Query *q;
    MotionSurface *shape;
    void *self;
    s32 count;
    s32 i;
    u8 *entity;
    Shared_World *table;
    f32 radius;
    f32 bound;

    shape = ((ActorMotion *)obj)->surface;
    if (shape->enabled == 0 || shape == (void *)&D_80100170) {
        return;
    }
    table = &D_8011FE88;
    q = &query;
    radius = ((ActorMotion *)obj)->radius;
    self = ((ActorMotion *)obj)->actor;
    q->radius = radius;
    count = table->interactiveCount;
    q->flag = shape->flags & 0x400;
    q->bottom = ((ActorMotion *)obj)->bottom;
    q->top = q->bottom + ((ActorMotion *)obj)->height;
    q->bottom1 = ((ActorMotion *)obj)->start.y + q->bottom;
    q->top1 = ((ActorMotion *)obj)->start.y + q->top;
    q->bottom2 = ((ActorMotion *)obj)->end.y + q->bottom;
    q->top2 = ((ActorMotion *)obj)->end.y + q->top;
    bound = ((ActorMotion *)obj)->end.x;
    if (!(bound <= ((ActorMotion *)obj)->start.x)) {
        bound = ((ActorMotion *)obj)->start.x;
    }
    q->minX = bound - radius;
    bound = ((ActorMotion *)obj)->end.x;
    if (!(((ActorMotion *)obj)->start.x <= bound)) {
        bound = ((ActorMotion *)obj)->start.x;
    }
    q->maxX = bound + radius;
    bound = ((ActorMotion *)obj)->end.z;
    if (!(bound <= ((ActorMotion *)obj)->start.z)) {
        bound = ((ActorMotion *)obj)->start.z;
    }
    q->minZ = bound - radius;
    bound = ((ActorMotion *)obj)->end.z;
    if (!(((ActorMotion *)obj)->start.z <= bound)) {
        bound = ((ActorMotion *)obj)->start.z;
    }
    q->maxZ = bound + radius;
    for (i = 0; i < count; i++) {
        entity = (u8 *)table->interactive[i];
        if (entity == self) {
            continue;
        }
        switch (*entity) {
        case 2:
            break;
        case 1:
            if ((shape->flags & 1) && ((LevelActor *)entity)->active == 0) {
                continue;
            }
            break;
        case 3:
            if (!(shape->flags & 0x20)) {
                continue;
            }
            break;
        }
        func_8023EF00_de(obj, &query, entity);
    }
}

void func_8023F644_de(ActorMotion *arg0, f32 *arg1)
{
  f32 *new_var;
  f32 temp;
  f32 value;
  s32 *new_var2;
  f32 bound;
  new_var2 = &arg0->surface->flags;
  ((Query *)arg1)->radius = arg0->radius;
  ((Query *)arg1)->flag = (*new_var2) & 0x400;
  temp = arg0->bottom;
  ((Query *)arg1)->bottom = temp;
  new_var = &arg0->height;
  ((Query *)arg1)->top = temp + (*new_var);
  ((Query *)arg1)->bottom1 = (arg0->start.y) + ((Query *)arg1)->bottom;
  ((Query *)arg1)->top1 = (arg0->start.y) + ((Query *)arg1)->top;
  ((Query *)arg1)->bottom2 = (arg0->end.y) + ((Query *)arg1)->bottom;
  ((Query *)arg1)->top2 = (arg0->end.y) + ((Query *)arg1)->top;
  value = arg0->end.x;
  bound = arg0->start.x;
  if (!(value <= bound))
  {
    value = bound;
  }
  ((Query *)arg1)->minX = value - ((Query *)arg1)->radius;
  value = arg0->end.x;
  bound = arg0->start.x;
  if (!(bound <= value))
  {
    value = bound;
  }
  ((Query *)arg1)->maxX = value + ((Query *)arg1)->radius;
  value = arg0->end.z;
  bound = arg0->start.z;
  if (!(value <= bound))
  {
    value = bound;
  }
  ((Query *)arg1)->minZ = value - ((Query *)arg1)->radius;
  value = arg0->end.z;
  bound = arg0->start.z;
  if (!(bound <= value))
  {
    value = bound;
  }
  ((Query *)arg1)->maxZ = value + ((Query *)arg1)->radius;
}
