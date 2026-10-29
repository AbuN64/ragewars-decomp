#include "COMMON/RESOURCELOADSTATE.H"
#include "WORLD/PLAYERAI_RESPAWNFRAGTAGPLAYER.H"
#include "TYPES.H"
#include "RESMGR/X_PLUS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "WORLD/PLAYERPROFILE.H"
#include "include_asm.h"
#include "COMMON/WEAPON_MARKER_AND_PROFILE_VIEWS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/GEOMETRY_BLEND_AND_INSTANCE_VIEWS.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "WEAPONS/PLAYER_BUILDWEAPONHANDTRANSFORM.H"

void Player_SetProfileValue14(void *profileStorage, unsigned char value);
void Player_SetProfileValue15(void *object, unsigned char value);
void Player_SetProfileValue16(void *object, unsigned char value);
void Player_SetProfileProgress(void *profileStorage, int progress);
void Player_SetProfileSlotValue(ObjCode8022E938 *obj, int index, char value);
void Player_SetAchievementFlag7(Profile *record, s32 achievementIndex);
void Player_SetAchievementFlag2F(Profile *player, s32 achievementIndex);






void Player_InitializeProfile(void *profileStorage) {
    u8 *object = (u8 *)profileStorage;
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

extern u8 g_localPlayerProfiles[];
extern u8 g_profileSlotResetWord[];
extern s8 g_profileSlotResetFlags[];
extern s8 g_profileSlotIndices[];
extern s8 g_profileSlotEnabledFlags[];
extern s8 g_profileSlotSettingsByte7B[];
extern s8 g_profileSlotSettingsByte7D[];
extern s8 g_profileSlotSettingsByte79[];
extern s8 g_profileSlotSettingsByte7A[];
extern s8 g_profileSlotSettingsByte82[];
extern u8 g_playerSettings[];
extern s32 g_profileSlotNameFormat;

void Player_InitializeProfile(void *profileStorage);
extern void XStdio_FormatBuffer(void *destination, s32 format, s32 value);

void Player_InitializeProfileSlot(s32 profileSlot) {
    s32 offset;
    u8 *entry;
    u8 *config;

    offset = profileSlot * 0x190;
    entry = g_localPlayerProfiles + offset;
    Player_InitializeProfile(entry);
    *(s32 *)(g_profileSlotResetWord + offset) = 0;
    g_profileSlotIndices[offset] = profileSlot;
    g_profileSlotResetFlags[offset] = 0;
    g_profileSlotEnabledFlags[offset] = 1;
    XStdio_FormatBuffer(entry, g_profileSlotNameFormat, profileSlot + 1);
    config = g_playerSettings + profileSlot * 0x96;
    g_profileSlotSettingsByte7B[offset] = config[0x7B];
    g_profileSlotSettingsByte7D[offset] = config[0x7D];
    g_profileSlotSettingsByte79[offset] = config[0x79];
    g_profileSlotSettingsByte7A[offset] = config[0x7A];
    g_profileSlotSettingsByte82[offset] = config[0x82];
}

void Player_SetProfileValue14(void *profileStorage, unsigned char value) {
    ((ObjCode8022E938 *)profileStorage)->value14 = value;
}

/** Advance the byte at offset 0x14 by ten. */
void Player_AddTenToProfileValue14(void *object) {
    ((ObjCode8022E938 *)object)->value14 += 10;
}

/** Read the byte at object offset 0x14. */
unsigned char Player_GetProfileValue14(ObjCode8022E938 *profileStorage) {
    return profileStorage->value14;
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

unsigned char Player_GetProfileValue15(ObjCode8022E938 *profileStorage) {
    return profileStorage->value15;
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

void Player_SetProfileProgress(void *profileStorage, int progress) {
    ((ObjCode8022E938 *)profileStorage)->progress = progress;
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

extern void Graphu64_ScaleVector(void *, void *, f32);

extern void Graphu64_BuildScaleMatrix(void *, f32, f32, f32);

extern void Graphu64_GetMatrixTranslation(char *, f32 *);

extern void Player_BuildPlayerViewTransform(char *, Matrix *);

extern void Player_BuildPlayerOrientation(char *object, CQuatern *output);

extern void MatrixFromQuaternion(void *, void *);

extern void TranslateMatrix(char *, f32, f32, f32);

extern void SwapMatrixUpForward(void *);

extern void Graphu64_MultiplyAffineMatrices(void *, void *, void *);

extern s32 Defs_TestBit(void *, s32);
extern void Defs_SetBitValue(u8 *, s32, s32);
void Player_SetAchievementFlag2F(Profile *player, s32 achievementIndex) {
    Defs_SetBitValue(&player->achievementFlags[0x2F], achievementIndex, 1);
}

s32 Player_HasProfileUnlockFlag(u8 *profileBytes, s32 unlockIndex)
{
  if (unlockIndex == 0x10)
  {
    return 1;
  }
  if (unlockIndex == 0x11)
  {
    if (unlockIndex || profileBytes)
    {
      return 1;
    }
    else
    {
      return 1;
    }
  }
  return Defs_TestBit(profileBytes + 0x79, unlockIndex);
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

s32 Player_GetProfileAchievementFlag(Profile *profile, s32 achievementIndex) {
    u8 *achievementBits;
    s32 index = achievementIndex;

    switch (index) {
    case 16:
        achievementBits = &profile->achievementFlags[0x2E];
        index = 0;
        break;
    case 17:
        achievementBits = &profile->achievementFlags[0x2E];
        index = 1;
        break;
    default:
        achievementBits = &profile->achievementFlags[0x31];
        break;
    }
    return Defs_TestBit(achievementBits, index);
}

void Player_SetAchievementFlag7(Profile *record, s32 achievementIndex) {
    Defs_SetBitValue(&record->achievementFlags[7], achievementIndex, 1);
}

/** Tests bit index of the profile achievement flags at +7 (the character unlocks). */
s32 Player_TestAchievementFlag7(Profile *record, s32 index) {
    return Defs_TestBit(&record->achievementFlags[7], index);
}

void Player_BuildWeaponHandTransform(char *weaponActor) {
    CVector3 position;
    Matrix worldMatrix;
    CVector3 scaledOffset;
    CVector3 handOffset;
    Matrix offsetMatrix;
    Matrix viewMatrix;
    CQuatern viewOrientation;
    char *object;
    char *orientation;

    object = ((PlayerProfileAttachmentView *)(weaponActor))->unk_1D8;
    handOffset = ((struct WeaponHandOffsetView *) g_weaponInfoByType[((PlayerProfileWeaponView *) object)->unk_62E])->unk_38;
    if (g_weaponHandMirrorX != 0) {
        handOffset.x = -handOffset.x;
    }
    if (g_weaponHandMirrorY != 0) {
        handOffset.y = -handOffset.y;
    }
    if (g_weaponHandMirrorZ != 0) {
        handOffset.z = -handOffset.z;
    }
    Graphu64_ScaleVector(&scaledOffset, &((PlayerProfileAttachmentView *)(weaponActor))->unk_50, 0.1f);
    Graphu64_BuildScaleMatrix(&offsetMatrix, scaledOffset.x, scaledOffset.y, scaledOffset.z);
    Graphu64_ScaleVector(&handOffset, &handOffset, -10.24f);
    if (((PlayerProfileWeaponView *)(object))->unk_5DC.v0 != 0) {
        Graphu64_GetMatrixTranslation(((PlayerProfileWeaponView *)(object))->unk_5DC.v1 + 0x160, &position);
        MatrixFromQuaternion((CQuatern *)(((PlayerProfileWeaponView *)(object))->unk_5DC.v1 + 0x140),
                      &worldMatrix);
    } else {
        Player_BuildPlayerViewTransform(object, &viewMatrix);
        Player_BuildPlayerOrientation(object, &viewOrientation);
        Graphu64_GetMatrixTranslation((char *)&viewMatrix, &position);
        MatrixFromQuaternion(&viewOrientation, &worldMatrix);
    }
    orientation = weaponActor + 0x74;
    TranslateMatrix(&offsetMatrix, handOffset.x, handOffset.y, handOffset.z);
    SwapMatrixUpForward(&offsetMatrix);
    Graphu64_MultiplyAffineMatrices((Matrix *)orientation, &offsetMatrix, &worldMatrix);
    TranslateMatrix((Matrix *)orientation, position.x, position.y, position.z);
}
