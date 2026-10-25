#include "SOUND/TRIPLERECAT8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/PROBE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"

extern void func_8024E79C_de(void *arg0, TripleRecAt8 t, void *arg4, s32 *arg5, s32 arg6, s32 arg7);

extern f32 Anim_GetPolygonHeight(struct Node75 *node, f32 x, f32 z);

extern void Weapons_ComputeTargetOffset(void *arg0, void *arg1, void *arg2);

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
float Sound_GetActorTerritoryRadius(void *object) {
    Actor_u1 *actor = object;
    Resource_u1 *nested = actor->resource;
    if (nested->kind == 1) {
        return nested->value3C;
    }
    return 0.0f;
}

void func_8024E59C_de(void *actor, void *arg1, void *arg2) {
    CVector3 *source = arg1;
    CVector3 *output = arg2;
    TripleRecAt8 t;
    s32 sp30;

    t.a = source->x;
    t.b = 0;
    t.c = source->z;
    func_8024E79C_de(actor, t, arg2, &sp30, 0, 0);
    output->y = Anim_GetPolygonHeight((struct Node75 *)sp30, output->x, output->z);
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
int func_8024E62C_de(void *levelActor) {
    LevelActor *actor = levelActor;
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
float func_8024E678_de(Shared_Func80243A80Actor *object, s32 mode) {
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

void func_8024E6D8_de(u8 *arg0, void *vector) {
    OffsetResult offset;

    if (*arg0 == 1) {
        Weapons_ComputeTargetOffset(arg0, arg0 + 0x170, &offset);
        *(CVector3 *)vector = offset.first;
        return;
    }
    *(s32 *)vector = 0;
    ((Triple *)vector)->y = 0;
    ((Triple *)vector)->z = 0;
}

f32 func_8024E73C_de(u8 *arg0) {
    OffsetResult offset;
    if (*arg0 == 1) {
        Weapons_ComputeTargetOffset(arg0, arg0 + 0x170, &offset);
        return offset.height;
    }
    return 0.0f;
}

/** Return the low three mode bits when the record type is one. */
int func_8024E778_de(void *levelActor) {
    LevelActor *actor = levelActor;
    if (actor->kind == 1) {
        return actor->motionState & 7;
    }
    return 0;
}
