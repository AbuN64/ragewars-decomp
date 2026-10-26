#include "COMMON/RESOURCELOADSTATE.H"
#include "WORLD/8022E938.H"
#include "TYPES.H"
#include "RESMGR/802A0888.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "WORLD/8022E938_5.H"
#include "include_asm.h"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "WEAPONS/8022F3E8_2.H"

void Player_SetProfileValue14(void *arg0, unsigned char arg1);
void Player_SetProfileValue15(void *object, unsigned char value);
void Player_SetProfileValue16(void *object, unsigned char value);
void Player_SetProfileProgress(void *arg0, int arg1);
void Player_SetProfileSlotValue(ObjCode8022E938 *obj, int index, char value);
void Player_SetAchievementFlag7(Profile *record, s32 achievementIndex);
void Player_SetAchievementFlag2F(Profile *player, s32 achievementIndex);






void Player_InitializeProfile(void *arg0) {
    u8 *object = (u8 *)arg0;
    s32 i;
    u8 *cursor;

    XPlus_FillMemory((s32)object, 0, 8);
    object[0xE] = 0;
    Player_SetProfileValue14(object, 0);
    Player_SetProfileValue15(object, 0);
    Player_SetProfileValue16(object, 0);
    Player_SetProfileProgress(object, 0);
    Player_SetProfileSlotValue(object, 0, 2);
    Player_SetProfileSlotValue(object, 1, 2);
    Player_SetProfileSlotValue(object, 2, 2);
    Player_SetProfileSlotValue(object, 3, 2);
    Player_SetProfileSlotValue(object, 4, 2);
    Player_SetProfileSlotValue(object, 5, 2);
    Player_SetProfileSlotValue(object, 6, 2);
    Player_SetProfileSlotValue(object, 7, 2);
    Player_SetProfileSlotValue(object, 8, 2);
    Player_SetProfileSlotValue(object, 9, 2);
    Player_SetProfileSlotValue(object, 0xA, 2);
    Player_SetProfileSlotValue(object, 0x11, 2);
    Player_SetProfileSlotValue(object, 0x12, 2);
    object[0x17] = 0;
    object[0xF] = 0;
    ((ObjCode8022E938 *)object)->totals[2] = 0;
    ((ObjCode8022E938 *)object)->totals[0] = 0;
    ((ObjCode8022E938 *)object)->totals[1] = 0;
    object[0x25] = 0;
    ((ObjCode8022E938 *)object)->state = 0;
    object[0xC] = 0;
    ((ObjCode8022E938 *)object)->fieldD = -1;
    XPlus_FillMemory((s32)((char *)object + 0x26), 0, 0x24);
    XPlus_FillMemory((s32)((char *)object + 0x7D), 0, 1);
    XPlus_FillMemory((s32)((char *)object + 0x51), 0, 3);
    XPlus_FillMemory((s32)((char *)object + 0x125), 0, 0x64);
    Player_SetAchievementFlag7((s32)object, 0);
    Player_SetAchievementFlag7((s32)object, 5);
    Player_SetAchievementFlag7((s32)object, 7);
    XPlus_FillMemory((s32)((char *)object + 0x57), 0, 0x14);
    XPlus_FillMemory((s32)((char *)object + 0x54), 0, 3);
    XPlus_FillMemory((s32)((char *)object + 0x4A), 0, 7);
    XPlus_FillMemory((s32)((char *)object + 0x78), 0, 1);
    XPlus_FillMemory((s32)((char *)object + 0x79), 0, 2);
    Player_SetAchievementFlag2F((s32)object, 0);
    Player_SetAchievementFlag2F((s32)object, 2);
    Player_SetAchievementFlag2F((s32)object, 3);
    Player_SetAchievementFlag2F((s32)object, 4);
    XPlus_FillMemory((s32)((char *)object + 0x7B), 0, 2);
    XPlus_FillMemory((s32)((char *)object + 0x7E), 0, 5);
    XPlus_FillMemory((s32)((char *)object + 0x88), 0, 5);
    XPlus_FillMemory((s32)((char *)object + 0x8D), 0, 5);
    XPlus_FillMemory((s32)((char *)object + 0x83), 0, 5);
    i = 0x23;
    cursor = object + 0x8C;
    do {
        ((ObjCode8022E938 *)object)->counters[i] = 0;
        i--;
        cursor -= 4;
    } while (i >= 0);
    XPlus_FillMemory((s32)((char *)object + 0x124), 0, 1);
    object[0x18A] = 1;
    object[0x18B] = 0x86;
    object[0x189] = 0;
    object[0x18C] = 0x84;
    object[0x18D] = 0;
}

extern u8 D_80102B00[];
extern u8 D_80102B08[];
extern s8 D_800FEB0C[];
extern s8 D_80102B0D[];
extern s8 D_800FEB0E[];
extern s8 D_80102C89[];
extern s8 D_800FEC8A[];
extern s8 D_800FEC8B[];
extern s8 D_800FEC8C[];
extern s8 D_800FEC8D[];
extern u8 g_playerSettings[];
extern s32 D_800D34E0;

void Player_InitializeProfile(void *arg0);
extern void XStdio_FormatBuffer(void *arg0, s32 arg1, s32 arg2);

void Player_InitializeProfileSlot(s32 arg0) {
    s32 offset;
    u8 *entry;
    u8 *config;

    offset = arg0 * 0x190;
    entry = D_80102B00 + offset;
    Player_InitializeProfile(entry);
    *(s32 *)(D_80102B08 + offset) = 0;
    D_80102B0D[offset] = arg0;
    D_800FEB0C[offset] = 0;
    D_800FEB0E[offset] = 1;
    XStdio_FormatBuffer(entry, D_800D34E0, arg0 + 1);
    config = g_playerSettings + arg0 * 0x96;
    D_80102C89[offset] = config[0x7B];
    D_800FEC8A[offset] = config[0x7D];
    D_800FEC8B[offset] = config[0x79];
    D_800FEC8C[offset] = config[0x7A];
    D_800FEC8D[offset] = config[0x82];
}

void Player_SetProfileValue14(void *arg0, unsigned char arg1) {
    ((ObjCode8022E938 *)arg0)->value14 = arg1;
}

/** Advance the byte at offset 0x14 by ten. */
void Player_AddTenToProfileValue14(void *object) {
    ((ObjCode8022E938 *)object)->value14 += 10;
}

/** Read the byte at object offset 0x14. */
unsigned char Player_GetProfileValue14(ObjCode8022E938 *arg0) {
    return arg0->value14;
}

/** Store a byte in the object field at offset 0x15. */
void Player_SetProfileValue15(void *object, unsigned char value) {
    ((ObjCode8022E938 *)object)->value15 = value;
}

int Player_AddFiftyToProfileValue15(void *player) {
    int v = ((ObjCode8022E938 *)player)->value15 + 0x32;
    ((ObjCode8022E938 *)player)->value15 = (unsigned char)v;
    return v;
}

unsigned char Player_GetProfileValue15(ObjCode8022E938 *arg0) {
    return arg0->value15;
}

/** Store the supplied byte at offset 0x16. */
void Player_SetProfileValue16(void *object, unsigned char value) {
    ((ObjCode8022E938 *)object)->value16 = value;
}

int Player_AddFiftyToProfileValue16(void *player) {
    int v = ((ObjCode8022E938 *)player)->value16 + 0x32;
    ((ObjCode8022E938 *)player)->value16 = (unsigned char)v;
    return v;
}

/** Read the object byte at offset 0x16. */
unsigned char Player_GetProfileValue16(ObjCode8022E938 *object) {
    return object->value16;
}

void Player_SetProfileProgress(void *arg0, int arg1) {
    ((ObjCode8022E938 *)arg0)->progress = arg1;
}

/** Advance the word at offset 0x10 by 0x500. */
void Player_AdvanceProfileProgress(void *object) {
    ((ObjCode8022E938 *)object)->progress += 0x500;
}

/** Return the word stored at offset 0x10. */
unsigned int Player_GetProfileProgress(ObjCode8022E938 *object) {
    return object->progress;
}

/* Stores a byte into the object's slot table at 0x18: indices 0 to 10 directly, 17 and 18 into
   slots 11 and 12, and other indices are ignored. */


void Player_SetProfileSlotValue(ObjCode8022E938 *obj, int index, char value) {
    if (index == 17) {
        goto is17;
    }
    if (index < 18) {
        goto below18;
    }
    if (index == 18) {
        goto is18;
    }
    return;
below18:
    if (index >= 11) {
        return;
    }
    if (index < 0) {
        return;
    }
    goto store;
is18:
    index = 12;
    goto store;
is17:
    index = 11;
store:
    obj->slots[index] = value;
}

/* Increments the object's byte counter for a slot in the table at 0x18: indices 0 to 10 directly,
   17 and 18 as slots 11 and 12, and other indices are ignored. */


void Player_IncrementLevelProgress(Profile *obj, int index) {
    if (index == 17) {
        goto is17;
    }
    if (index < 18) {
        goto below18;
    }
    if (index == 18) {
        goto is18;
    }
    return;
below18:
    if (index >= 11) {
        return;
    }
    if (index < 0) {
        return;
    }
    goto store;
is18:
    index = 12;
    goto store;
is17:
    index = 11;
store:
    obj->levelProgress[index]++;
}

#include "COMMON/SHAREDPLAYER.H"

s32 Player_GetLevelProgress(Profile *obj, s32 index) {
    if (index == 17) {
        goto slot17;
    }
    if (index < 18) {
        goto lower;
    }
    if (index == 18) {
        goto slot18;
    }
    goto invalid;
lower:
    if (index >= 11) { goto invalid; }
    if (index < 0) { goto invalid; }
    goto load;
slot17:
    index = 11;
    goto load;
slot18:
    index = 12;
    goto load;
invalid:
    return 2;
load:
    return obj->levelProgress[index];
}

extern void GraphU64_ScaleVector(void *, void *, f32);

extern void GraphU64_BuildScaleMatrix(void *, f32, f32, f32);

extern void GraphU64_GetMatrixTranslation(char *, f32 *);

extern void Player_BuildPlayerViewTransform(char *, Matrix *);

extern void Player_BuildPlayerOrientation(char *object, CQuatern *output);

extern void MatrixFromQuaternion(void *, void *);

extern void TranslateMatrix(char *, f32, f32, f32);

extern void SwapMatrixUpForward(void *);

extern void GraphU64_MultiplyAffineMatrices(void *, void *, void *);

extern s32 Defs_TestBit(void *, s32);
extern void Defs_SetBitValue(u8 *, s32, s32);
void Player_SetAchievementFlag2F(Profile *player, s32 achievementIndex) {
    Defs_SetBitValue(&player->achievementFlags[0x2F], achievementIndex, 1);
}

s32 Player_HasProfileUnlockFlag(u8 *arg0, s32 arg1)
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
  return Defs_TestBit(arg0 + 0x79, arg1);
}

void Player_SetAchievementFlagByIndex(Profile *player, s32 achievementIndex) {
    u8 *achievementBits;
    s32 mappedAchievementIndex = achievementIndex;

    switch (mappedAchievementIndex) {
    case 16:
        achievementBits = &player->achievementFlags[0x2E];
        mappedAchievementIndex = 0;
        break;
    case 17:
        achievementBits = &player->achievementFlags[0x2E];
        mappedAchievementIndex = 1;
        break;
    default:
        achievementBits = &player->achievementFlags[0x31];
        break;
    }
    Defs_SetBitValue(achievementBits, mappedAchievementIndex, 1);
}

s32 Player_GetProfileAchievementFlag(Profile *profile, s32 arg1) {
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
    return Defs_TestBit(var_a0, index);
}

void Player_SetAchievementFlag7(Profile *record, s32 achievementIndex) {
    Defs_SetBitValue(&record->achievementFlags[7], achievementIndex, 1);
}

/** Tests bit index of the profile achievement flags at +7 (the character unlocks). */
s32 Player_TestAchievementFlag7(Profile *record, s32 index) {
    return Defs_TestBit(&record->achievementFlags[7], index);
}

void Player_BuildWeaponHandTransform(char *arg0) {
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
    GraphU64_ScaleVector(&scaledOffset, &((ObjectLinks1DC *)(arg0))->unk_50, 0.1f);
    GraphU64_BuildScaleMatrix(&offsetMatrix, scaledOffset.x, scaledOffset.y, scaledOffset.z);
    GraphU64_ScaleVector(&handOffset, &handOffset, -10.24f);
    if (((ObjectState630 *)(object))->unk_5DC.v0 != 0) {
        GraphU64_GetMatrixTranslation(((ObjectState630 *)(object))->unk_5DC.v1 + 0x160, &position);
        MatrixFromQuaternion((CQuatern *)(((ObjectState630 *)(object))->unk_5DC.v1 + 0x140),
                      &worldMatrix);
    } else {
        Player_BuildPlayerViewTransform(object, &viewMatrix);
        Player_BuildPlayerOrientation(object, &viewOrientation);
        GraphU64_GetMatrixTranslation((char *)&viewMatrix, &position);
        MatrixFromQuaternion(&viewOrientation, &worldMatrix);
    }
    orientation = arg0 + 0x74;
    TranslateMatrix(&offsetMatrix, handOffset.x, handOffset.y, handOffset.z);
    SwapMatrixUpForward(&offsetMatrix);
    GraphU64_MultiplyAffineMatrices((Matrix *)orientation, &offsetMatrix, &worldMatrix);
    TranslateMatrix((Matrix *)orientation, position.x, position.y, position.z);
}
