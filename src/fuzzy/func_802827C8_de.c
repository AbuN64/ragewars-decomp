#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct DraftPair827C8 { s32 a, b; } DraftPair827C8;
typedef struct DraftActions827C8 {
    DraftPair827C8 params[14]; u16 animation[14], effect[14], sound[14];
} DraftActions827C8;
typedef struct DraftModel827C8 { u8 pad[0x18]; DraftActions827C8 *actions; } DraftModel827C8;
typedef struct DraftActor827C8 {
    u8 pad[4]; u16 type; u8 pad6[2]; Vec3 position;
    u8 pad14[0x48]; u32 flags; u8 pad60[0xB8]; DraftModel827C8 *model;
    u8 pad11C[0x10]; s32 owner; s32 *refs; u8 pad134[4]; s32 effect;
    u8 pad13C[0x94]; s8 animation; u8 pad1D1[8]; u8 linked;
    u8 pad1DA[0xA]; void *list; u8 pad1E8[4]; struct DraftActor827C8 *next;
} DraftActor827C8;
typedef struct DraftWorld827C8 { u8 pad[0xFC00]; u8 freeList[0x14], activeList[0x14], padFC28[0x14]; DraftActor827C8 *actors; } DraftWorld827C8;
extern char D_801379C0, D_8013B1A8;
extern void func_80265E10_de(void *, void *, s32, s32, Vec3, DraftPair827C8);
extern void func_80279B40_de(void *, s32, s32, s32), func_80279A00_de(void *), func_80284178_de(void *);
extern void func_802A42F4_de(void *, void *), func_80255ED8_de(void *, void *), func_80255CB8_de(void *, void *);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32), func_8025DF34_de(s32);
void func_802827C8_de(DraftWorld827C8 *world, s32 owner)
{
  DraftActor827C8 *actor;
  DraftActor827C8 *next;
  DraftActions827C8 *actions;
  DraftModel827C8 *model;
  DraftPair827C8 params;
  unsigned long animation;
  u16 effect;
  u16 sound;
  s32 count = 0;
  s32 index;
  actor = world->actors;
  while (actor)
  {
    next = actor->next;
    if (((actor->type == 0x41E) && (actor->flags & 0x100)) && (actor->owner == owner))
    {
      model = actor->model;
      actor->flags &= ~0x100;
      index = (func_80284068_de(actor)) ? (12) : (10);
      actions = model->actions;
      animation = actions->animation[index];
      effect = actions->effect[index];
      params = actions->params[index];
      sound = model->actions->sound[index];
      if (effect != 0xFFFF)
      {
        func_80265E10_de(actor, actor, effect, -1, actor->position, params);
      }
      if (animation != 0xFFFF)
      {
        func_80279B40_de(actor, animation, actor->animation, 1);
      }
      if (sound != 0xFFFF)
      {
        func_8025DE54_de((s16) sound, actor->position, 0, -1);
      }
      actor->flags |= 0x100;
      if (!(actor->flags & 0x800))
      {
        func_80279A00_de(actor);
        if (actor->linked)
        {
          func_80284178_de(actor);
          func_802A42F4_de(&D_801379C0, actor);
        }
        if (actor->effect)
        {
          func_80268C7C_de(&D_8013B1A8, actor->effect);
          actor->effect = 0;
        }
        if (actor->refs)
        {
          --(*actor->refs);
        }
        actor->flags &= 0xFDFFFEFF;
        func_80255ED8_de(actor->list, actor);
        actor->list = 0;
        func_80255CB8_de(world->freeList, actor);
        if (actor->flags & 0x1000000)
        {
          func_80255ED8_de(world->activeList, actor);
        }
      }
      count++;
    }
    actor = next;
  }

  if (count)
  {
    func_8025DF34_de(0x91A);
    func_8025DF34_de(0x91A);
  }
}
