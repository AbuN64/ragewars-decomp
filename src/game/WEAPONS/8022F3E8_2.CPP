#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "WEAPONS/8022F3E8_2.H"

extern void Particle_ScaleVector(void *, void *, f32);

extern void func_80272CB0_de(void *, f32, f32, f32);

extern void func_802732D0_de(char *, f32 *);

extern void Weapons_BuildPlayerViewTransform(char *, Matrix *);

extern void Weapons_BuildPlayerOrientation(char *object, CQuatern *output);

extern void func_80274244_de(void *, void *);

extern void func_80273448_de(char *, f32, f32, f32);

extern void func_80273D6C_de(void *);

extern void func_8026F620_de(void *, void *, void *);

extern s32 func_80265650_de(void *, s32);
extern void func_80265688_de(u8 *, s32, s32);
void func_8022F4BC_de(Profile *player, s32 arg1) {
    func_80265688_de(&player->achievementFlags[0x2F], arg1, 1);
}

s32 func_8022F4DC_de(u8 *arg0, s32 arg1)
{
  if (arg1 == 0x10)
  {
    return 1;
  }
  if (arg1 == 0x11)
  {
    if (arg1 || arg0)
    {
      return 1;
    }
    else
    {
      return 1;
    }
  }
  return func_80265650_de(arg0 + 0x79, arg1);
}

void func_8022F514_de(Profile *player, s32 arg1) {
    u8 *var_a0;
    s32 var_a1 = arg1;

    switch (var_a1) {
    case 16:
        var_a0 = &player->achievementFlags[0x2E];
        var_a1 = 0;
        break;
    case 17:
        var_a0 = &player->achievementFlags[0x2E];
        var_a1 = 1;
        break;
    default:
        var_a0 = &player->achievementFlags[0x31];
        break;
    }
    func_80265688_de(var_a0, var_a1, 1);
}

s32 func_8022F55C_de(Profile *profile, s32 arg1) {
    u8 *var_a0;
    s32 index = arg1;

    switch (index) {
    case 16:
        var_a0 = &profile->achievementFlags[0x2E];
        index = 0;
        break;
    case 17:
        var_a0 = &profile->achievementFlags[0x2E];
        index = 1;
        break;
    default:
        var_a0 = &profile->achievementFlags[0x31];
        break;
    }
    return func_80265650_de(var_a0, index);
}

void func_8022F5A4_de(Profile *record, s32 arg1) {
    func_80265688_de(&record->achievementFlags[7], arg1, 1);
}

/** Thin wrapper forwarding an offset argument to func_80265650_de. */
void func_8022F5C4_de(Profile *record, s32 index) {
    func_80265650_de(&record->achievementFlags[7], index);
}

void func_8022F5E0_de(char *arg0) {
    CVector3 position;
    Matrix sp20;
    CVector3 sp60;
    CVector3 sp70;
    Matrix sp80;
    Matrix spC0;
    CQuatern sp100;
    char *object;
    char *orientation;

    object = ((ObjectLinks1DC *)(arg0))->unk_1D8;
    sp70 = ((struct ObjectState44 *) D_800D052C[((ObjectState630 *) object)->unk_62E])->unk_38;
    if (D_800CA040_de != 0) {
        sp70.x = -sp70.x;
    }
    if (D_800CA044 != 0) {
        sp70.y = -sp70.y;
    }
    if (D_800CA048 != 0) {
        sp70.z = -sp70.z;
    }
    Particle_ScaleVector(&sp60, &((ObjectLinks1DC *)(arg0))->unk_50, 0.1f);
    func_80272CB0_de(&sp80, sp60.x, sp60.y, sp60.z);
    Particle_ScaleVector(&sp70, &sp70, -10.24f);
    if (((ObjectState630 *)(object))->unk_5DC.v0 != 0) {
        func_802732D0_de(((ObjectState630 *)(object))->unk_5DC.v1 + 0x160, &position);
        func_80274244_de((CQuatern *)(((ObjectState630 *)(object))->unk_5DC.v1 + 0x140),
                      &sp20);
    } else {
        Weapons_BuildPlayerViewTransform(object, &spC0);
        Weapons_BuildPlayerOrientation(object, &sp100);
        func_802732D0_de((char *)&spC0, &position);
        func_80274244_de(&sp100, &sp20);
    }
    orientation = arg0 + 0x74;
    func_80273448_de(&sp80, sp70.x, sp70.y, sp70.z);
    func_80273D6C_de(&sp80);
    func_8026F620_de((Matrix *)orientation, &sp80, &sp20);
    func_80273448_de((Matrix *)orientation, position.x, position.y, position.z);
}
