#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/OBJECTLINKS1458.H"
#include "FX/8020F6E0.H"
#include "TYPES.H"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", func_8020F6E0_eu);
#endif
#endif

#if defined(VERSION_DE) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", func_8020F6C0_de);
#endif

#if !(defined(VERSION_DE) || defined(VERSION_EU)) || ((defined(VERSION_DE) || defined(VERSION_EU)) && defined(NON_MATCHING))
/* Fuzzy draft for de and eu: the other versions' body under the de/eu name. */
#if defined(VERSION_DE)
#define Fx_UpdateTargetSelection func_8020F6C0_de
#elif defined(VERSION_EU)
#define Fx_UpdateTargetSelection func_8020F6E0_eu

#endif
#ifdef NON_MATCHING
typedef struct TrackingTarget {
    u8 pad0[8];
    CVector3 position;
    u8 pad14[0xEC];
    u32 flags;
    u8 pad104[0xD4];
    Player *player;
} TrackingTarget;

typedef struct TargetSelection {
    Player *player;
    u8 pad04[0x34];
    s32 count;
    TrackingTarget *targets[10];
    TrackingTarget *target;
    void *routeObject;
    s32 enabled[10];
    s32 distances[10];
    u8 padBC[0x160];
    s32 state;
    u8 pad220[0x38];
    CVector3 targetPosition;
    u8 pad264[0x28];
    TrackingTarget *preferred;
} TargetSelection;

typedef struct TargetTeamProfile {
    u8 pad0[0x92];
    u8 team;
} TargetTeamProfile;

extern s32 D_801468C4;
extern void *func_8020993C_de(void *);
extern f32 func_802726F8_de(void *, void *);
extern s32 func_80209A94_de(void *);
extern s32 func_8020F93C_de(void *);
extern s32 func_8020F984_de(void *);

static inline TrackingTarget *setSelectedTarget(TargetSelection *self, TrackingTarget *target) {
    self->target = target;
    return target;
}

/* NON_MATCHING: 7 aligned edits / 140 ROM words; remaining: first alternate-copy scheduling and indexed-target tail sharing. */
s32 Fx_UpdateTargetSelection(void *object) {
    TargetSelection *self = object;
    CVector3 *position;
    Player *linked;
    Player *alternate;
    f32 linkedDistance;
    f32 alternateDistance;
    s32 index;
    TrackingTarget *target;

    position = func_8020993C_de(self);
    if (self->target != 0) {
        linked = self->target->player;
        if (linked->health == 0) {
            self->target = 0;
        }
        if (linked->reactionFlags & 0x20) {
            self->target = 0;
        }
        if (D_801468C4 != 0) {
            if (((TargetTeamProfile *)self->player->profile)->team ==
                ((TargetTeamProfile *)linked->profile)->team) {
                self->target = 0;
            }
        }
        if (self->target != 0) {
            linked = self->target->player;
            linkedDistance = func_802726F8_de(position, &linked->pos);
        } else {
            linked = 0;
            linkedDistance = 0.0f;
        }
    } else {
        linked = 0;
        linkedDistance = 0.0f;
    }
    if (self->preferred != 0 && (self->preferred->flags & 0x300000)) {
        alternate = self->preferred->player;
        alternateDistance = func_802726F8_de(position, &alternate->pos);
    } else {
        alternate = 0;
        alternateDistance = 0.0f;
    }
    /* The range limit is the first float; unk4 is the adjacent -1 sentinel. */
    if (func_80209A94_de(self) == 0 || linked == 0) {
        if (func_8020F93C_de(self) == 0) {
            self->target = 0;
            return 1;
        }
        if (alternate != 0 && func_8020F8F0_de((ObjRecAt28C *)self) != 0) {
            self->target = (TrackingTarget *)alternate;
            self->targetPosition.x = alternate->pos.x;
            target = (TrackingTarget *)alternate;
            goto copyRest;
        } else {
            index = func_8020F984_de(self);
            target = setSelectedTarget(self, self->targets[index]);
        }
    } else if (alternate != 0 && alternateDistance <= linkedDistance) {
        self->target = (TrackingTarget *)alternate;
        self->targetPosition.x = alternate->pos.x;
        target = (TrackingTarget *)alternate;
        goto copyRest;
    } else {
        index = func_8020F984_de(self);
        if (index != -1 && (f32)self->distances[index] < linkedDistance) {
            target = setSelectedTarget(self, self->targets[index]);
        } else if (self->state == 1 && *(f32 *)&D_800C21F0_eu_x < linkedDistance) {
            self->target = 0;
            return 1;
        } else {
            target = self->target;
        }
    }
    self->targetPosition.x = target->position.x;
copyRest:
    self->targetPosition.y = target->position.y;
    self->targetPosition.z = target->position.z;
    return 1;
}
#else
INCLUDE_ASM("span_1000", Fx_UpdateTargetSelection);
#endif
#endif

/* Returns 1 when one of the object's ten entries at 0x3C matches its current value at 0x28C and the
   paired flag at 0x6C is set, and 0 otherwise or when the current value is zero. */

int func_8020F8F0_de(ObjRecAt28C *obj) {
    int i;

    if (obj->current == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (obj->keys[i] == obj->current && obj->flags[i] != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_8020F93C_de(void *arg0)
{
  s32 var_a1;
  s32 var_v1;
  ObjRecAt28C *var_a0;
  var_a0 = arg0;
  var_a1 = 0;
  if ((var_a0->count) == 0)
  {
    return 0;
  }
  var_v1 = 0;
  do
  {
    if (((var_a0->keys[var_v1]) != 0) && ((var_a0->flags[var_v1]) != 0))
    {
      var_a1 += 1;
    }
    var_v1 += 1;
  }
  while (var_v1 < 0xA);
  return var_a1;
}


s32 func_8020F984_de(void *self) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f1;
    s32 count;
    s32 mask;
    s32 var_a1;
    s32 i;
    ObjRecAt28C *var_a0;

    var_a0 = self;
    var_a1 = -1;
    var_f1 = D_800C21F0_eu_x.unk4;
    i = 0;
    if (var_a0->count > 0) {
        mask = 0x300000;
        temp_f2 = var_f1;
        count = var_a0->count;
        do {
            struct Actor_func_80214DD4_de *actor = (struct Actor_func_80214DD4_de *)var_a0->keys[i];
            if ((actor->flags100 & mask) &&
                ((temp_f0 = (f32)var_a0->distances[i], temp_f0 < var_f1) ||
                 (var_f1 == temp_f2)) &&
                (var_a0->flags[i] != 0)) {
                var_f1 = temp_f0;
                var_a1 = i;
            }
            i += 1;
        } while (i < count);
    }
    return var_a1;
}
