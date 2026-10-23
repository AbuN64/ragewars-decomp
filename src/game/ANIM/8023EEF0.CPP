#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "TYPES.H"

#if !(defined(VERSION_EU))
extern f32 func_8024D398_de(void *);
extern f32 func_8024E420_de(void *);
extern f32 Particle_GetActorHeight(void *);
extern void func_80242550_de(void *, void *);
extern void func_80242288_de(void *, void *);
extern s32 func_802AB400_de(void *, void *);
extern void func_80271FC8_de(CVector3 *, f32, CVector3 *, CVector3 *);
extern s32 func_8023E8D4_de(void *, void *, s32);
extern s32 func_8023E178_de(void *, CVector3 *, f32, f32, f32, s32, void *, s32);
/* Hand C from us-rev1 8023EEF0..8023F42C.
 * The query is read-only (0x30 bytes); contact storage is local (0xDC).
 * Floor/ceiling crossings use opposite signed height tests. Their normal
 * constants are -1/+1 in all five ROMs (us-rev1 ROM 0xC93D0/0xC93D4). */
static inline f32 Anim_GetContactRadius(struct Query *sweep, f32 actorRadius) {
    return sweep->radius + actorRadius;
}

static inline s8 Anim_GetSurfaceKind(LevelActor *entity) {
    if (entity->definition->gate & 0x80) return 2;
    return 7;
}

void Anim_TestEntityContact(ActorMotion *motion, struct Query *sweep, LevelActor *entity) {
    LevelActor *owner;
    MotionSurface *surface;
    f32 bounds[4];
    CVector3 point;
    CVector3 normal;
    BoxContactPolygon contact;
    f32 entityX;
    f32 entityZ;
    f32 radius;
    f32 bottom;
    f32 top;
    f32 ownerX;
    f32 ownerZ;
    f32 time;
    f32 deltaX;
    f32 deltaZ;
    s32 special;

    entityX = entity->position0.x;
    entityZ = entity->position0.z;
    radius = func_8024D398_de(entity);
    bounds[0] = entityX - radius;
    bounds[2] = entityX + radius;
    bounds[1] = entityZ - radius;
    bounds[3] = entityZ + radius;
    if (!(bounds[0] < sweep->maxX && sweep->minX < bounds[2] &&
          bounds[1] < sweep->maxZ && sweep->minZ < bounds[3])) {
        return;
    }
    special = 0;
    owner = motion->actor;
    surface = motion->surface;
    if (owner->kind == 1 && owner->definition->kind == 2) {
        if (entity->kind == owner->kind) {
            func_80242550_de(motion, entity);
        }
        return;
    }
    if (entity->kind == 1 && entity->definition->kind == 2) {
        if (owner->kind == entity->kind) {
            func_80242288_de(motion, entity);
        }
        return;
    }
    if (entity->kind == 3) {
        if (func_802AB400_de(entity, owner) == 0) {
            return;
        }
        special = 1;
    }
    contact.type = 7;
    contact.response = 0.0f;
    contact.count = 0;
    contact.flags = 0;
    contact.valid = 1;
    contact.actor = (BoxContactActor *)entity;
    contact.index = -1;
    bottom = entity->position0.y + func_8024E420_de(entity);
    top = Particle_GetActorHeight(entity) + bottom;
    if (sweep->flag != 0) {
        normal.x = normal.z = 0.0f;
    }
    ownerX = owner->position0.x;
    ownerZ = owner->position0.z;
    radius = Anim_GetContactRadius(sweep, radius);
    if (sweep->flag != 0) {
        if (motion->velocity.y != 0.0f) {
            if (sweep->top1 <= bottom && bottom < sweep->top2) {
                time = (bottom - sweep->top1) / motion->velocity.y;
                if (time < motion->blend) {
                    func_80271FC8_de(&point, time, &owner->position0, &motion->end);
                    deltaX = entityX - point.x;
                    deltaZ = entityZ - point.z;
                    if (deltaX * deltaX + deltaZ * deltaZ < radius * radius) {
                        contact.kind = 7;
                        contact.point = point;
                        contact.normal.x = 0.0f;
                        contact.normal.z = 0.0f;
                        contact.normal.y = -1.0f;
                        func_8023E8D4_de(motion, &contact, 1);
                    }
                }
            }
            if (top <= sweep->bottom1 && sweep->bottom2 < top) {
                time = (top - sweep->bottom1) / motion->velocity.y;
                if (time < motion->blend) {
                    func_80271FC8_de(&point, time, &owner->position0, &motion->end);
                    deltaX = entityX - point.x;
                    deltaZ = entityZ - point.z;
                    if (deltaX * deltaX + deltaZ * deltaZ < radius * radius) {
                        if (surface->enabled == 1) {
                            contact.kind = surface->enabled;
                        } else {
                            contact.kind = Anim_GetSurfaceKind(entity);
                        }
                        contact.point = point;
                        contact.normal.x = 0.0f;
                        contact.normal.z = 0.0f;
                        contact.normal.y = 1.0f;
                        func_8023E8D4_de(motion, &contact, 1);
                    }
                }
            }
        }
    }
    contact.kind = special != 0 ? 7 : surface->enabled;
    func_8023E178_de(motion, &entity->position0, radius,
                    top - sweep->bottom, bottom - sweep->top, 1, &contact, 1);
    if (special != 0 && *(LevelActor **)((u8 *)motion + 0x104) != entity &&
        sweep->bottom1 <= top && bottom < sweep->top1) {
        deltaX = entityX - ownerX;
        deltaZ = entityZ - ownerZ;
        if (deltaX * deltaX + deltaZ * deltaZ < radius * radius) {
            contact.t = 0.0f;
            contact.normal.x = 0.0f;
            contact.normal.y = 0.0f;
            contact.normal.z = 0.0f;
            contact.hit = motion->start;
            *(BoxContactPolygon *)&motion->collisionState = contact;
        }
    }
}
#endif
#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_8023EF14);
#endif

typedef struct Query Query;
/* Queries the registered entities an object may collide with: when the object's shape is enabled and is
 * not the null shape, a query holds the object's radius, its vertical span and that span offset by the
 * shape heights at 0x48 and 0x54, its horizontal bounds widened by the radius and the shape's 0x400 flag;
 * then Anim_TestEntityContact is run for every entity other than the object itself, except type 1 entities without
 * a body at 0x174 when the shape is flagged 1 and type 3 entities when the shape is not flagged 0x20. */







extern Shape D_80100170;
extern void Anim_TestEntityContact(ActorMotion *, Query *, LevelActor *);






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
        Anim_TestEntityContact(obj, &query, entity);
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
