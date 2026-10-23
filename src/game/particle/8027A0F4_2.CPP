#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "particle/8027A0F4.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

/* Reports an actor to the active collision state D_801041F0 when that state is of kind 1: an actor whose owner is a kind 1 object flagged 0x300000 is reported with bit 8, 4 or 0x10 for each of three type groups its type belongs to, and otherwise an actor whose descriptor is of kind 1 or 4 is reported with bit 0x80, 0x40 or 0x100 for the same groups, each through func_80278D78_de. */







extern func_8024E8F0_S1 *D_801041F0;

extern void func_80278D78_de(func_8024E8F0_S1 *state, s32 bits, Actor_func_8027B428_de *actor);

static inline s32 is_group_a(Actor_func_8027B428_de *actor) {
    switch (actor->type) {
        case 2:
        case 0x56:
        case 0x111:
        case 0x126:
            return 1;
    }
    return 0;
}

static inline s32 is_group_b(Actor_func_8027B428_de *actor) {
    switch (actor->type) {
        case 5:
        case 6:
        case 7:
        case 9:
        case 0x11:
        case 0x13:
        case 0x1A:
        case 0x101:
        case 0x110:
            return 1;
    }
    return 0;
}

static inline s32 is_group_c(Actor_func_8027B428_de *actor) {
    switch (actor->type) {
        case 8:
        case 0xD:
        case 0x12:
            return 1;
    }
    return 0;
}

void func_8027ABF4_de(AccelSteeringObj *arg0) {
    AccelSteeringVec delta, direction;
    AccelSteeringVec *velocity;
    f32 accel, length, limit;

    if (arg0->target != 0 && arg0->distance > 1.0f) {
        Particle_SteerToward(arg0, &arg0->target->point);
        return;
    }
    accel = func_802B2350(arg0->link->params->accel);
    if (accel != 0.0f) {
        do {
            direction = arg0->direction;
            func_80271F9C_de(&delta, &direction, accel);
            velocity = &arg0->velocity;
            func_80271F34_de(velocity, velocity, &delta);
        } while (0);
        length = func_802B72B0_de(arg0->velocity.x * arg0->velocity.x + arg0->velocity.y * arg0->velocity.y + arg0->velocity.z * arg0->velocity.z);
        limit = func_802B2350(arg0->link->params->limit);
        if (accel > 0.0f) {
            if (!(limit < length)) goto done;
        } else {
            if (!(length < limit)) goto done;
        }
        func_80271F9C_de(velocity, &direction, limit);
done:;
    }
    func_80279DD0_de(arg0, 1.0f);
}

void func_8027AD4C_de(Shared_Particle *arg0)
{
  CVector3 sp10;
  CVector3 sp20;
  CVector3 sp30;
  CVector3 sp40;
  CVector3 sp50;
  CQuatern sp60;
  CQuatern sp70;
  CQuatern sp80;
  Matrix sp90;
  CVector3 spD0;

  CVector3 spE0;
  CVector3 *nearby_position; 
  CVector3 *temp_s2_2;
  f32 temp_f0;
  f32 temp_f0_10;
  CVector3 *new_var;
  f32 temp_f0_11;
  f32 temp_f0_2;
  f32 temp_f0_3;
  f32 temp_f0_4;
  f32 temp_f0_5;
  f32 temp_f0_6;
  f32 temp_f0_7;
  f32 temp_f0_8;
  f32 temp_f0_9;
  f32 temp_f12;
  f32 temp_f12_2;
  f32 temp_f12_3;
  f32 temp_f1;
  f32 temp_f1_2;
  f32 temp_f1_3;
  f32 temp_f1_4;
  f32 temp_f1_5;
  f32 temp_f20;
  f32 nearby_height;
  f32 nearby_scale;
  f32 nearby_random_max;
  f32 tracking_min;
  f32 tracking_max;
  f32 temp_f20_2;
  f32 temp_f20_3;
  f32 temp_f20_4;
  f32 var_f2;
  s32 temp_v1;
  void *temp_a0;
  func_8027ADBC_S3 *temp_s0;
  void *temp_s0_2; 
  func_8027ADBC_S6 *temp_s0_4;
  void *temp_s0_5;
  void *temp_s2; 
  void *var_a0;
  SharedRecAt16E0V2 *var_s0;
  temp_v1 = arg0->inst.type;
  if (temp_v1 == 0x127)
  {
    goto block_26;
  }
  if (temp_v1 < 0x128)
  {
    if (temp_v1 == 46)
    {
      goto block_46;
    }
    if (temp_v1 < 47)
    {
      if (temp_v1 == 11)
      {
        goto block_24;
      }
      if (temp_v1 == 14)
      {
        goto block_26;
      }
      goto block_common;
    }
    if (temp_v1 >= 97)
    {
      goto block_common;
    }
    if (temp_v1 >= 95)
    {
      goto block_26;
    }
    goto block_common;
  }
  if (temp_v1 == 0x414)
  {
    goto block_540;
  }
  if (temp_v1 < 0x415)
  {
    if (temp_v1 == 0x129)
    {
      goto block_24;
    }
    if (temp_v1 == 0x3EC)
    {
      goto block_26;
    }
    goto block_common;
  }
  if (temp_v1 == 0x42D)
  {
    goto block_540;
  }
  if (temp_v1 == 0x4B4)
  {
    goto block_26;
  }
  goto block_common;
  block_46:
  var_a0 = D_80145060.actorList;

  if (var_a0 != ((void *) 0))
  {
    nearby_position = &sp20;
    temp_s2 = (void *) (&arg0->inst.velocity.x);
    do { 
      nearby_scale = D_800C4BCC_de;
      nearby_random_max = D_800C4BD0_de;
    } while (0);
    var_s0 = var_a0;
    do
    {
      nearby_height = var_s0->unk70;
      sp20 = var_s0->pos;
      sp20.y += nearby_height;
      sp20.y += Particle_GetActorHeight(var_a0) * nearby_scale;
      func_80271F68_de(&sp10, nearby_position, &arg0->inst.pos);
      temp_f20 = func_802B72B0_de(((sp10.x * sp10.x) + (sp10.y * sp10.y)) + (sp10.z * sp10.z));
      if (temp_f20 < D_800C4BD4_de)
      {
        temp_f20 = D_800C4BDC_de - (temp_f20 * D_800C4BD8_de);
        sp10.x *= temp_f20 * func_80274A90_de(nearby_scale, nearby_random_max);
        sp10.y *= temp_f20 * func_80274A90_de(nearby_scale, nearby_random_max);
        sp10.z *= temp_f20 * func_80274A90_de(nearby_scale, nearby_random_max);
        func_80271F68_de(temp_s2, temp_s2, &sp10);
      }
      var_a0 = var_s0->unk16E0;
      var_s0 = var_a0;
    }
    while (var_a0 != ((void *) 0));
  }
  temp_s0 = arg0->target;
  temp_f0_2 = func_8024E420_de(temp_s0);
  sp20 = temp_s0->pos;
  sp20.y += temp_f0_2;
  func_80271F68_de(&sp10, &sp20, &arg0->inst.pos);
  tracking_min = D_800C4BE0_de;
  tracking_max = D_800C4BE4_de;
  sp10.x *= func_80274A90_de(tracking_min, tracking_max);
  sp10.y *= func_80274A90_de(tracking_min, tracking_max);
  sp10.z *= func_80274A90_de(tracking_min, tracking_max);
  temp_s0_2 = (void *) (&arg0->inst.velocity.x);
  func_80271F34_de(temp_s0_2, temp_s0_2, &sp10);
#if defined(VERSION_EU)
  func_80272748_de(temp_s0_2, func_802AD520_eu((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk12));
#else
  func_80272748_de(temp_s0_2, func_802B2350((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk12));
#endif
  return;
  block_24:
  func_8027A084_de(arg0);

  return;
  block_540:
  Particle_SteerHoming(arg0);

  return;
  block_26:
  func_80228DC4_de(&D_80145040, arg0);

#if defined(VERSION_EU)
  temp_f0_3 = func_802AD520_eu((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk10);
#else
  temp_f0_3 = func_802B2350((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk10);
#endif
  if (temp_f0_3 != 0.0f)
  {
    temp_s0_2 = &spD0; 
    spE0 = arg0->direction;
    func_80271F9C_de(temp_s0_2, &spE0, temp_f0_3);
    temp_s0_2 = (void *) (&arg0->inst.velocity.x);
    func_80271F34_de(temp_s0_2, temp_s0_2, &spD0);
    temp_f1 = arg0->inst.velocity.x;
    temp_f0_4 = arg0->inst.velocity.y;
    temp_f12 = arg0->inst.velocity.z;
    temp_f20_2 = func_802B72B0_de(((temp_f1 * temp_f1) + (temp_f0_4 * temp_f0_4)) + (temp_f12 * temp_f12));
#if defined(VERSION_EU)
    temp_f0_5 = func_802AD520_eu((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk12);
#else
    temp_f0_5 = func_802B2350((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk12);
#endif
    if (temp_f0_3 > 0.0f)
    {
      if (!(temp_f0_5 < temp_f20_2))
      {
        goto after_special_clamp;
      }
    }
    else
      if (!(temp_f20_2 < temp_f0_5))
    {
      goto after_special_clamp;
    }
    func_80271F9C_de(temp_s0_2, &spE0, temp_f0_5);
    after_special_clamp:
    ;

    ;
  }
  func_80279DD0_de(arg0, 1.0f);
  return;
  block_common:
  temp_s0_4 = arg0->target;

  temp_a0 = arg0->desc;
  if (((temp_s0_4 != ((void *) 0)) && (arg0->desc->flags & 0x40000)) && (((BallisticParamsHolder *)arg0->desc)->unkE != 0))
  {
    temp_f0_6 = func_8024E420_de(temp_s0_4);
    sp20 = temp_s0_4->pos;
    sp20.y += temp_f0_6;
    sp20.y += Particle_GetActorHeight(temp_s0_4) * D_800C4BE8_de;
    func_80271F68_de(&sp40, &sp20, &arg0->inst.pos);
    func_8027207C_de(&sp40);
    func_80271818_de(&sp70, &sp40);
    temp_s2_2 = &arg0->direction;
    func_80271818_de(&sp60, temp_s2_2);
    sp30 = arg0->direction;
    func_8027207C_de(&sp30);
    temp_f1_3 = arg0->inst.velocity.x;
    temp_f0_7 = arg0->inst.velocity.y;
    temp_f12_2 = arg0->inst.velocity.z;
    temp_f20_3 = func_802B72B0_de(((temp_f1_3 * temp_f1_3) + (temp_f0_7 * temp_f0_7)) + (temp_f12_2 * temp_f12_2));
    temp_f0_8 = func_802745D0_de(((sp30.x * sp40.x) + (sp30.y * sp40.y)) + (sp30.z * sp40.z));
    temp_f1_4 = ((f32) ((BallisticParamsHolder *)arg0->desc)->unkE) * D_800C4BEC_de;
    var_f2 = D_800C4BF0_de;
    if (temp_f1_4 < temp_f0_8)
    {
      var_f2 = temp_f1_4 / temp_f0_8;
    }
    func_80270CD0_de(&sp80, var_f2, &sp60, &sp70);
    func_80274244_de(&sp80, &sp90);
    sp50.x = 0;
    sp50.y = 0;
    sp50.z = D_800C4BF4_de;
    new_var = temp_s2_2;
    func_80272898_de(&sp90, &sp50, new_var);
    func_80271F9C_de(&arg0->inst.velocity.x, new_var, temp_f20_3);
  }
  if (!(arg0->flags & 0x70000))
  {
#if defined(VERSION_EU)
    temp_f0_9 = func_802AD520_eu((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk10);
#else
    temp_f0_9 = func_802B2350((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk10);
#endif
    if (temp_f0_9 != 0.0f)
    {
      temp_s0_2 = &spD0; 
    spE0 = arg0->direction;
      func_80271F9C_de(temp_s0_2, &spE0, temp_f0_9);
      temp_s0_2 = (void *) (&arg0->inst.velocity.x);
      func_80271F34_de(temp_s0_2, temp_s0_2, &spD0);
      temp_f1_5 = arg0->inst.velocity.x;
      temp_f0_10 = arg0->inst.velocity.y;
      temp_f12_3 = arg0->inst.velocity.z;
      temp_f20_4 = func_802B72B0_de(((temp_f1_5 * temp_f1_5) + (temp_f0_10 * temp_f0_10)) + (temp_f12_3 * temp_f12_3));
#if defined(VERSION_EU)
      temp_f0_11 = func_802AD520_eu((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk12);
#else
      temp_f0_11 = func_802B2350((s32) ((BallisticParamsHolder *)arg0->desc)->unk30->unk12);
#endif
      if (temp_f0_9 > 0.0f)
      {
        if (!(temp_f0_11 < temp_f20_4))
        {
          goto after_normal_clamp;
        }
      }
      else
        if (!(temp_f20_4 < temp_f0_11))
      {
        goto after_normal_clamp;
      }
      func_80271F9C_de(temp_s0_2, &spE0, temp_f0_11);
      after_normal_clamp:
      ;

      ;
    }
  }
  if (!(arg0->flags & 0x30000))
  {
    func_80279DD0_de(arg0, 1.0f);
  }
}

void func_8027B428_de(Actor_func_8027B428_de *actor) {
    func_8024E8F0_S1 *owner;

    if (D_801041F0 == 0 || D_801041F0->unk0 != 1) {
        return;
    }
    owner = actor->owner;
    if (owner != 0 && owner->unk0 == 1 && (owner->unk100 & 0x300000)) {
        if (is_group_a(actor)) {
            func_80278D78_de(D_801041F0, 8, actor);
        }
        if (is_group_b(actor)) {
            func_80278D78_de(D_801041F0, 4, actor);
        }
        if (is_group_c(actor)) {
            func_80278D78_de(D_801041F0, 0x10, actor);
        }
    } else if (actor->descriptor->field_0 == 1 || actor->descriptor->field_0 == 4) {
        if (is_group_a(actor)) {
            func_80278D78_de(D_801041F0, 0x80, actor);
        }
        if (is_group_b(actor)) {
            func_80278D78_de(D_801041F0, 0x40, actor);
        }
        if (is_group_c(actor)) {
            func_80278D78_de(D_801041F0, 0x100, actor);
        }
    }
}
