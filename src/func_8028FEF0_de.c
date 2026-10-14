#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8028FC98.h"
#include "types.h"

void *func_8028FEF0_de(int *arg0, int *arg1) {
    *arg1 = arg0[0] * arg0[1];
    return &((ResidentDataChunk *)(arg0))->data[0];
}

/* Transposes the byte matrix after its eight-byte dimensions header and optionally copies the result back. */


extern void func_802BD3A0_de(void *, void *, s32);



void func_8028FF0C_de(void *arg0, void *arg1, s32 arg2)
{
  char *data = &((ResidentDataChunk *)(arg0))->data[0];
  s32 temp_a2;
  int first_column;
  s32 temp_t0;
  s32 var_a0;
  s32 var_a1;
  s32 var_v1;
  u8 *temp_v0;
  u8 *var_a3;
  first_column = 0;
  func_802BD3A0_de(arg1, arg0, 8);
  var_a3 = arg1 + 8;
  temp_a2 = ((struct Shape_func_802764D4_de_2 *) arg0)->field_4;
  temp_t0 = ((struct Shape_func_802764D4_de_2 *) arg0)->field_0;
  var_a1 = first_column;
  if (temp_a2 > first_column)
  {
    do
    {
      var_a0 = 0;
      if (temp_t0 > 0)
      {
        var_v1 = var_a1;
        do
        {
          temp_v0 = data + var_v1;
          var_v1 += temp_a2;
          var_a0 += 1;
          *var_a3 = *temp_v0;
          var_a3 += 1;
        }
        while (var_a0 < temp_t0);
      }
      var_a1 += 1;
    }
    while (var_a1 < temp_a2);
  }
  if (arg2 != 0)
  {
    func_802BD3A0_de(arg0, arg1, (temp_a2 * temp_t0) + 8);
  }
}

/* Spawns a pooled object and registers its bounds and height. */


void func_80246184_de(void *);
f32 func_8024D284_de(void *);
s32 func_8028B21C_de(void *, s32);
s32 func_8028C198_de(void *, s32);
void func_8028C6D4_de(void *, Vec3 *, void *);
void func_80290950_de(void *, void *);
extern struct ActorDefinitionHeader D_8011B200;
extern struct ActorDefinitionHeader D_8011B388;

extern u8 D_801462E5;
extern s32 D_800CD764_de[];










void *func_8028FFD0_de(char *arg0, s32 *arg1, s32 arg2, Vec3 rotation, Vec3 position, s32 arg9, f32 arg10)
{
  Vec3 center;
  s32 temp_v0;
  f32 far_z;
  s32 temp_v1_2;
  char *temp_s0;
  char *temp_v1;
  if (((*D_800CD764_de) == 0) || ((temp_v0 = func_8028B21C_de(&D_8011FE88, arg2), temp_v0 == (-1))))
  {
    return 0;
  }
  if ((((WorldRecAt3C08 *)(arg0))->free) == 0)
  {
    func_80290950_de(arg0, ((WorldRecAt3C08 *)(arg0))->tail);
  }
  temp_s0 = ((WorldRecAt3C08 *)(arg0))->free;
  temp_v1 = ((WorldRecAt3C08 *)(arg0))->head;
  ((WorldRecAt3C08 *)(arg0))->free = (void *) (((Actor_func_80290238_de *)(temp_s0))->next);
  if (temp_v1 != 0)
  {
    ((Actor_func_80290238_de *)(temp_v1))->prev = temp_s0;
  }
  { char *next = ((WorldRecAt3C08 *)(arg0))->head;
  ((Actor_func_80290238_de *)(temp_s0))->prev = 0;
  ((Actor_func_80290238_de *)(temp_s0))->next = next; }
  ((WorldRecAt3C08 *)(arg0))->head = temp_s0;
  if ((((WorldRecAt3C08 *)(arg0))->tail) == 0)
  {
    ((WorldRecAt3C08 *)(arg0))->tail = temp_s0;
  }
  ((Actor_func_80290238_de *)(temp_s0))->state = (s32) ((((Actor_func_80290238_de *)(temp_s0))->state) | 1);
  func_80246184_de(temp_s0);
  ((Actor_func_80290238_de *)(temp_s0))->lifetime = 0;
  temp_v1_2 = func_8028C198_de(&D_8011FE88, temp_v0);
  ((Actor_func_80290238_de *)(temp_s0))->counter = arg1;
  if (arg1 != 0)
  {
    *arg1 += 1;
  }
  if (D_801462E5 != 0)
  {
    ((Actor_func_80290238_de *)(temp_s0))->definition = &D_8011B200;
  }
  else
  {
    ((Actor_func_80290238_de *)(temp_s0))->definition = &D_8011B388;
  }
  ((Actor_func_80290238_de *)(temp_s0))->lifetime = arg10;
  ((Actor_func_80290238_de *)(temp_s0))->lifetimeState = 0;
  ((Actor_func_80290238_de *)(temp_s0))->model = temp_v0;
  position.y += 10.24f;
  ((Actor_func_80290238_de *)(temp_s0))->position = position;
  ((Actor_func_80290238_de *)(temp_s0))->angle = 0;
  ((Actor_func_80290238_de *)(temp_s0))->angleState = 0;
  ((Actor_func_80290238_de *)(temp_s0))->collisionState = 0;
  ((Actor_func_80290238_de *)(temp_s0))->collisionScale = 1.0f;
  ((Actor_func_80290238_de *)(temp_s0))->collisionFlags = 0;
  ((Actor_func_80290238_de *)(temp_s0))->minX = (f32) (position.x - 81.92f);
  ((Actor_func_80290238_de *)(temp_s0))->minY = (f32) (position.y - 81.92f);
  ((Actor_func_80290238_de *)(temp_s0))->minZ = (f32) (position.z - 81.92f);
  ((Actor_func_80290238_de *)(temp_s0))->maxX = (f32) (position.x + 81.92f);
  ((Actor_func_80290238_de *)(temp_s0))->maxY = (f32) (position.y + 81.92f);
  far_z = position.z;
  ((Actor_func_80290238_de *)(temp_s0))->resource = temp_v1_2;
  ((Actor_func_80290238_de *)(temp_s0))->animation = -1;
  ((Actor_func_80290238_de *)(temp_s0))->frame = 0;
  ((Actor_func_80290238_de *)(temp_s0))->frameState = 0;
  ((Actor_func_80290238_de *)(temp_s0))->owner = arg9;
  ((Actor_func_80290238_de *)(temp_s0))->boundsState = 0;
  ((Actor_func_80290238_de *)(temp_s0))->flags = 0x1A;
  ((Actor_func_80290238_de *)(temp_s0))->maxZ = (f32) (far_z + 81.92f);
  ((Actor_func_80290238_de *)(temp_s0))->rotation = rotation;
  ((Actor_func_80290238_de *)(temp_s0))->effectState = 0;
  center.x = ((Actor_func_80290238_de *)(temp_s0))->position.x;
  center.y = (((Actor_func_80290238_de *)(temp_s0))->position.y) + (func_8024D284_de(temp_s0) * 0.5f);
  center.z = ((Actor_func_80290238_de *)(temp_s0))->position.z;
  func_8028C6D4_de(&D_8011FE88, &center, (char *)temp_s0 + 0x1A8);
  return temp_s0;
}

/* Updates a world's active actors: counts each actor's lifetime down by the frame time and expires it when the lifetime runs out or when its bounds leave the world box D_801031F0 (unless it is flagged 0x200); an expired active actor loses its active bit, decrements its owner's counter and moves from the active list to the free list, and every other actor is updated through func_80290424_de. */






extern Box D_801031F0;
extern f32 D_800D2988;
extern void func_80290424_de(Actor_func_80290238_de *actor);

void func_80290238_de(WorldRecAt3C08 *world) {
    Actor_func_80290238_de *actor;
    Actor_func_80290238_de *next;
    s32 expired;
    f32 lifetime;

    next = world->head;
    if (next == 0) {
        return;
    }
    do {
        actor = next;
        next = actor->next;
        expired = 0;
        if (actor->lifetime > 0.0f) {
            lifetime = actor->lifetime - D_800D2988;
            actor->lifetime = lifetime;
            if (lifetime <= 0.0f) {
                expired = 1;
            }
        }
        if (!((D_801031F0.max.x > actor->minX) && (D_801031F0.min.x < actor->maxX) &&
              (D_801031F0.max.z > actor->minZ) && (D_801031F0.min.z < actor->maxZ) &&
              (D_801031F0.max.y > actor->minY) && (D_801031F0.min.y < actor->maxY))) {
            if (!(actor->flags & 0x200)) {
                expired = 1;
            }
        }
        if (expired) {
            if (actor->state & 1) {
                actor->state &= ~1;
                if (actor->counter != 0) {
                    (*actor->counter)--;
                }
                if (actor->prev != 0) {
                    actor->prev->next = actor->next;
                }
                if (actor->next != 0) {
                    actor->next->prev = actor->prev;
                }
                if (world->head == actor) {
                    world->head = actor->next;
                }
                if (world->tail == actor) {
                    world->tail = actor->prev;
                }
                actor->next = world->free;
                actor->prev = 0;
                world->free = actor;
            }
        } else {
            func_80290424_de(actor);
        }
    } while (next != 0);
}

extern struct ActorDefinitionHeader D_8011B388;




void func_80290408_de(void *arg0) {
    ((Actor_func_80290238_de *)(arg0))->definition = &D_8011B388;
    ((Actor_func_80290238_de *)(arg0))->active = 3;
    ((Actor_func_80290238_de *)(arg0))->state = 0;
}
