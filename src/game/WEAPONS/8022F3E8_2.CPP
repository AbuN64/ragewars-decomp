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

extern void MatrixFromQuaternion(void *, void *);

extern void TranslateMatrix(char *, f32, f32, f32);

extern void SwapMatrixUpForward(void *);

extern void Rsp_MultiplyAffineMatrices(void *, void *, void *);

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
    Matrix worldMatrix;
    CVector3 scaledOffset;
    CVector3 handOffset;
    Matrix offsetMatrix;
    Matrix viewMatrix;
    CQuatern viewOrientation;
    char *object;
    char *orientation;

    object = ((ObjectLinks1DC *)(arg0))->unk_1D8;
    handOffset = ((struct ObjectState44 *) D_800D052C[((ObjectState630 *) object)->unk_62E])->unk_38;
    if (D_800CA040_de != 0) {
        handOffset.x = -handOffset.x;
    }
    if (D_800CA044 != 0) {
        handOffset.y = -handOffset.y;
    }
    if (D_800CA048 != 0) {
        handOffset.z = -handOffset.z;
    }
    Particle_ScaleVector(&scaledOffset, &((ObjectLinks1DC *)(arg0))->unk_50, 0.1f);
    func_80272CB0_de(&offsetMatrix, scaledOffset.x, scaledOffset.y, scaledOffset.z);
    Particle_ScaleVector(&handOffset, &handOffset, -10.24f);
    if (((ObjectState630 *)(object))->unk_5DC.v0 != 0) {
        func_802732D0_de(((ObjectState630 *)(object))->unk_5DC.v1 + 0x160, &position);
        MatrixFromQuaternion((CQuatern *)(((ObjectState630 *)(object))->unk_5DC.v1 + 0x140),
                      &worldMatrix);
    } else {
        Weapons_BuildPlayerViewTransform(object, &viewMatrix);
        Weapons_BuildPlayerOrientation(object, &viewOrientation);
        func_802732D0_de((char *)&viewMatrix, &position);
        MatrixFromQuaternion(&viewOrientation, &worldMatrix);
    }
    orientation = arg0 + 0x74;
    TranslateMatrix(&offsetMatrix, handOffset.x, handOffset.y, handOffset.z);
    SwapMatrixUpForward(&offsetMatrix);
    Rsp_MultiplyAffineMatrices((Matrix *)orientation, &offsetMatrix, &worldMatrix);
    TranslateMatrix((Matrix *)orientation, position.x, position.y, position.z);
}
