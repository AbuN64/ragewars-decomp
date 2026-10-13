#include "common/unused.h"
#include "shared/motion_step.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023EEF0.h"
#include "types.h"

typedef struct Query Query;
/* Queries the registered entities an object may collide with: when the object's shape is enabled and is
 * not the null shape, a query holds the object's radius, its vertical span and that span offset by the
 * shape heights at 0x48 and 0x54, its horizontal bounds widened by the radius and the shape's 0x400 flag;
 * then func_8023EF00_de is run for every entity other than the object itself, except type 1 entities without
 * a body at 0x174 when the shape is flagged 1 and type 3 entities when the shape is not flagged 0x20. */







extern Shape D_80100170;
extern EntityTable D_8011FE88;
extern void func_8023EF00_de(void *, Query *, u8 *);






void func_8023F43C_de(char *obj) {
    Query query;
    Query *q;
    MotionSurface *shape;
    void *self;
    s32 count;
    s32 i;
    u8 *entity;
    EntityTable *table;
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
    count = table->count;
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
        entity = table->entities[i];
        if (entity == self) {
            continue;
        }
        switch (*entity) {
        case 2:
            break;
        case 1:
            if ((shape->flags & 1) && ((Actor_func_8024A7A0_de *)entity)->active == 0) {
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

void func_8023F644_de(void *arg0, f32 *arg1)
{
  f32 *new_var;
  f32 temp;
  f32 value;
  s32 *new_var2;
  f32 bound;
  new_var2 = &((ActorMotion *)arg0)->surface->flags;
  ((Query *)arg1)->radius = ((ActorMotion *)arg0)->radius;
  ((Query *)arg1)->flag = (*new_var2) & 0x400;
  temp = ((ActorMotion *)arg0)->bottom;
  ((Query *)arg1)->bottom = temp;
  new_var = &((ActorMotion *)arg0)->height;
  ((Query *)arg1)->top = temp + (*new_var);
  ((Query *)arg1)->bottom1 = (((ActorMotion *)arg0)->start.y) + ((Query *)arg1)->bottom;
  ((Query *)arg1)->top1 = (((ActorMotion *)arg0)->start.y) + ((Query *)arg1)->top;
  ((Query *)arg1)->bottom2 = (((ActorMotion *)arg0)->end.y) + ((Query *)arg1)->bottom;
  ((Query *)arg1)->top2 = (((ActorMotion *)arg0)->end.y) + ((Query *)arg1)->top;
  value = ((ActorMotion *)arg0)->end.x;
  bound = ((ActorMotion *)arg0)->start.x;
  if (!(value <= bound))
  {
    value = bound;
  }
  ((Query *)arg1)->minX = value - ((Query *)arg1)->radius;
  value = ((ActorMotion *)arg0)->end.x;
  bound = ((ActorMotion *)arg0)->start.x;
  if (!(bound <= value))
  {
    value = bound;
  }
  ((Query *)arg1)->maxX = value + ((Query *)arg1)->radius;
  value = ((ActorMotion *)arg0)->end.z;
  bound = ((ActorMotion *)arg0)->start.z;
  if (!(value <= bound))
  {
    value = bound;
  }
  ((Query *)arg1)->minZ = value - ((Query *)arg1)->radius;
  value = ((ActorMotion *)arg0)->end.z;
  bound = ((ActorMotion *)arg0)->start.z;
  if (!(bound <= value))
  {
    value = bound;
  }
  ((Query *)arg1)->maxZ = value + ((Query *)arg1)->radius;
}
