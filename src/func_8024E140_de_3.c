#include "span_1000/code_8024E130.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/legacy_collision_actor.h"
#include "shared/level_actor.h"
#include "span_1000/code_8024D018.h"
#include "types.h"

extern void func_8024E79C_de(void *arg0, TripleRecAt8 t, void *arg4, s32 *arg5, s32 arg6, s32 arg7);

extern f32 func_80275DD4_de(struct Node75 *node, f32 x, f32 z);

extern void func_802165F8_de(void *arg0, void *arg1, void *arg2);

/** Return a nested float field when the nested record type is one, else zero. */
float func_8024E544_de(void *object) {
    Actor_u1 *actor = object;
    Resource_u1 *nested = actor->resource;
    if (nested->kind == 1) {
        return nested->value50;
    }
    return 0.0f;
}

/** Return a nested float field when the nested record type is one, else zero. */
float func_8024E570_de(void *object) {
    Actor_u1 *actor = object;
    Resource_u1 *nested = actor->resource;
    if (nested->kind == 1) {
        return nested->value3C;
    }
    return 0.0f;
}

void func_8024E59C_de(void *arg0, void *arg1, void *arg2) {
    Vec3 *source = arg1;
    Vec3 *output = arg2;
    TripleRecAt8 t;
    s32 sp30;

    t.a = source->x;
    t.b = 0;
    t.c = source->z;
    func_8024E79C_de(arg0, t, arg2, &sp30, 0, 0);
    output->y = func_80275DD4_de((struct Node75 *)sp30, output->x, output->z);
}

/** Return offset 0x34 only when the type byte at offset 0 is 1. */
int func_8024E610_de(void *arg0) {
    struct ItemCode8024E130 *item = arg0;
    if (item->kind == 1) {
        return (int)item->value;
    }
    return 0;
}

/** Return the low three mode bits when the record type is one. */
int func_8024E62C_de(void *arg0) {
    LevelActor *actor = arg0;
    if (actor->kind == 1) {
        return actor->motionState & 7;
    }
    return 0;
}

f32 func_8024E650_de(Shared_Func80243A80Actor *arg0)
{
  if ((arg0->type) != 1)
  {
    if (arg0)
    {
      return arg0->y;
    }
    else
    {
      return arg0->y;
    }
  }
  return arg0->groundY;
}

/** Select one of two float fields according to the leading byte. */
float func_8024E678_de(Shared_Func80243A80Actor *object) {
    if (object->type != 1) {
        return object->y;
    }
    return object->groundY;
}

void *func_8024E6A0_de(struct ItemCode8024E130 *item) {
    if (item->kind == 1 && item->value != 0 && (item->flags & 3) != 0) {
        return item->value;
    }
    return 0;
}

void func_8024E6D8_de(u8 *arg0, void *arg1) {
    Triple buf;
    char pad[0x30];

    if (*arg0 == 1) {
        func_802165F8_de(arg0, arg0 + 0x170, &buf);
        *(Triple *)arg1 = buf;
        return;
    }
    *(s32 *)arg1 = 0;
    ((Triple *)arg1)->y = 0;
    ((Triple *)arg1)->z = 0;
}

f32 func_8024E73C_de(u8 *arg0) {
    char buf[0x40];
    if (*arg0 == 1) {
        func_802165F8_de(arg0, arg0 + 0x170, buf);
        return ((struct FloatState3C *) buf)->unk_38;
    }
    return 0.0f;
}

/** Return the low three mode bits when the record type is one. */
int func_8024E778_de(void *arg0) {
    LevelActor *actor = arg0;
    if (actor->kind == 1) {
        return actor->motionState & 7;
    }
    return 0;
}
