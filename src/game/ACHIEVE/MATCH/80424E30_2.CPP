#include "include_asm.h"
#include "COMMON/LONE/D_800E4680.H"
#include "COMMON/LONE/D_80152789.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RECRECAT4.H"
#include "COMMON/STATERECAT91.H"
#include "ACHIEVE/80424E30_2.H"
#include "COMMON/PLAYERPROFILES.H"
extern s32 Player_GetLevelProgress(Profile *, s32);

/* Applies event *D_800E4680 to player record D_80102B00[index] once per D_8015402C: when that bit
   of the record's current slot flags is already set it returns -1; otherwise it sets the bit and,
   for an event code below 58, dispatches through jtbl_800E1790 to the effect for that code and
   returns the code plus 5000 (5001 when the second effect's test clears bit 0), or -1 for a code
   the table marks unknown. The dispatch and return sit in a one-pass loop; that weighting gives
   the result its saved register ahead of the key pointer, as the cartridge has it. */





extern s32 Defs_TestBit(u8 *, s32);

extern void Defs_SetBitValue(u8 *, s32, s32);

extern void Player_IncrementLevelProgress(Profile *, s32);

extern void Player_SetAchievementFlag2F(Profile *, s32);

extern void Player_SetAchievementFlagByIndex(Profile *, s32);

extern void Player_AddTenToProfileValue14(Profile *);

extern void Player_AddFiftyToProfileValue15(Profile *);

extern void Player_AddFiftyToProfileValue16(Profile *);

extern void Player_AdvanceProfileProgress(Profile *);

/* Returns the message text for an event result from Match_ApplyLevelCompletionReward: for results 5001 to 5057 the
   text pointer jtbl_800DD848 selects for the result, where result 5002 picks between two texts by
   bit 0 of func_8022F454_de for the first player's current slot; zero for any other result. The
   dispatch and return sit in a one-pass loop, whose weighting gives the text its register as the
   cartridge has it. */




#if defined(VERSION_EU)
#elif defined(VERSION_EU_X)
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

s32 Match_ApplyLevelCompletionReward(s32 index) {
    s32 result = -1;
    Profile *player = &D_80102B00[index];
    s32 *key = &D_8015402C;
    u32 code;

    if (Defs_TestBit(&player->achievementFlags[0xDB + player->slot * 5], *key) != 0) {
        goto done;
    }
    Defs_SetBitValue(&player->achievementFlags[0xDB + player->slot * 5], *key, 1);
    code = *D_800E4680;
    result = code + 5000;
    do {
        if (code >= 58) {
            goto unknown;
        }
        switch (code) {
        case 0: goto unknown;
        case 1: goto effect_0;
        case 2: goto effect_1;
        case 3: goto effect_2;
        case 4: goto effect_3;
        case 5: goto effect_4;
        case 6: goto effect_5;
        case 7: goto effect_6;
        case 8: goto effect_7;
        case 9: goto effect_8;
        case 10: goto effect_9;
        case 11: goto effect_10;
        case 12: goto effect_11;
        case 13: goto effect_12;
        case 14: goto effect_13;
        case 15: goto effect_14;
        case 16: goto effect_15;
        case 17: goto effect_16;
        case 18: goto effect_17;
        case 19: goto effect_18;
        case 20: goto effect_19;
        case 21: goto effect_20;
        case 22: goto effect_21;
        case 23: goto effect_22;
        case 24: goto effect_23;
        case 25: goto effect_24;
        case 26: goto effect_25;
        case 27: goto effect_26;
        case 28: goto effect_27;
        case 29: goto effect_28;
        case 30: goto effect_29;
        case 31: goto effect_30;
        case 32: goto unknown;
        case 33: goto effect_31;
        case 34: goto effect_32;
        case 35: goto unknown;
        case 36: goto unknown;
        case 37: goto effect_33;
        case 38: goto unknown;
        case 39: goto unknown;
        case 40: goto unknown;
        case 41: goto unknown;
        case 42: goto unknown;
        case 43: goto unknown;
        case 44: goto unknown;
        case 45: goto unknown;
        case 46: goto unknown;
        case 47: goto unknown;
        case 48: goto unknown;
        case 49: goto unknown;
        case 50: goto unknown;
        case 51: goto unknown;
        case 52: goto done;
        case 53: goto effect_34;
        case 54: goto unknown;
        case 55: goto unknown;
        case 56: goto unknown;
        case 57: goto effect_35;
        }
    effect_0:
        Player_IncrementLevelProgress(player, player->slot);
        Player_IncrementLevelProgress(player, player->slot);
        goto done;
    effect_1:
        Player_IncrementLevelProgress(player, player->slot);
        if ((Player_GetLevelProgress(player, player->slot) & 1) == 0) {
            result = 5001;
        }
        goto done;
    effect_2:
        Player_SetAchievementFlag2F(player, 4);
        goto done;
    effect_3:
        Player_SetAchievementFlagByIndex(player, 2);
        goto done;
    effect_4:
        Player_SetAchievementFlag2F(player, 14);
        goto done;
    effect_5:
        Player_SetAchievementFlagByIndex(player, 6);
        goto done;
    effect_6:
        Player_SetAchievementFlag2F(player, 7);
        goto done;
    effect_7:
        Player_SetAchievementFlagByIndex(player, 16);
        goto done;
    effect_8:
        Player_SetAchievementFlagByIndex(player, 5);
        goto done;
    effect_9:
        Player_SetAchievementFlagByIndex(player, 17);
        goto done;
    effect_10:
        Player_SetAchievementFlag2F(player, 6);
        goto done;
    effect_11:
        Player_SetAchievementFlagByIndex(player, 14);
        goto done;
    effect_12:
        Player_SetAchievementFlagByIndex(player, 4);
        goto done;
    effect_13:
        Player_SetAchievementFlag2F(player, 12);
        goto done;
    effect_14:
        Player_SetAchievementFlag2F(player, 10);
        goto done;
    effect_15:
        Player_AddTenToProfileValue14(player);
        goto done;
    effect_16:
        Player_SetAchievementFlagByIndex(player, 8);
        goto done;
    effect_17:
        Player_SetAchievementFlag2F(player, 8);
        goto done;
    effect_18:
        Player_SetAchievementFlag2F(player, 15);
        goto done;
    effect_19:
        Player_SetAchievementFlagByIndex(player, 11);
        goto done;
    effect_20:
        Player_SetAchievementFlagByIndex(player, 10);
        goto done;
    effect_21:
        Player_SetAchievementFlagByIndex(player, 3);
        goto done;
    effect_22:
        Player_AddFiftyToProfileValue16(player);
        goto done;
    effect_23:
        Player_AddFiftyToProfileValue15(player);
        goto done;
    effect_24:
        Player_SetAchievementFlag2F(player, 13);
        goto done;
    effect_25:
        Player_SetAchievementFlag2F(player, 9);
        goto done;
    effect_26:
        Player_SetAchievementFlagByIndex(player, 1);
        goto done;
    effect_27:
        Player_SetAchievementFlagByIndex(player, 9);
        goto done;
    effect_28:
        Player_SetAchievementFlagByIndex(player, 7);
        goto done;
    effect_29:
        Player_SetAchievementFlagByIndex(player, 13);
        goto done;
    effect_30:
        Player_SetAchievementFlag2F(player, 5);
        goto done;
    effect_31:
        Player_SetAchievementFlag2F(player, 1);
        goto done;
    effect_32:
        Player_SetAchievementFlagByIndex(player, 0);
        goto done;
    effect_33:
        Player_SetAchievementFlag2F(player, 11);
        goto done;
    effect_34:
        player->count++;
        goto done;
    effect_35:
        Player_AdvanceProfileProgress(player);
        goto done;
    unknown:
        result = -1;
    done:
        return result;
    } while (0);
}

char *Match_GetResultText(s32 result) {
    Profile *player = D_80102B00;
    char *text = 0;

    if (result < 0) {
        return text;
    }
    switch (result) {
    case 5001:
        text = RW_LOCALIZED_TEXT(D_800D34E4, D_800E1DE4, D_800E1DE4, g_languageIndex);
        break;
    case 5002:
        if ((Player_GetLevelProgress(player, player->slot) & 1) == 0) {
            text = RW_LOCALIZED_TEXT(D_800D34EC, D_800E1E04, D_800E1E04, g_languageIndex);
        } else {
            text = RW_LOCALIZED_TEXT(D_800D34E8, D_800E1DF4, D_800E1DF4, g_languageIndex);
        }
        break;
    case 5004:
        text = RW_LOCALIZED_TEXT(D_800D3510, D_800E1E94, D_800E1E94, g_languageIndex);
        break;
    case 5005:
        text = RW_LOCALIZED_TEXT(D_800D3550, D_800E1F94, D_800E1F94_eu, g_languageIndex);
        break;
    case 5006:
        text = RW_LOCALIZED_TEXT(D_800D3564, D_800E1FE4, D_800E1FE4, g_languageIndex);
        break;
    case 5007:
        text = RW_LOCALIZED_TEXT(D_800D351C, D_800E1EC4, D_800E1EC4, g_languageIndex);
        break;
    case 5008:
        text = RW_LOCALIZED_TEXT(D_800D3528, D_800E1EF4, D_800E1EF4, g_languageIndex);
        break;
    case 5009:
        text = RW_LOCALIZED_TEXT(D_800D350C, D_800E1E84, D_800E1E84, g_languageIndex);
        break;
    case 5010:
        text = RW_LOCALIZED_TEXT(D_800D3524, D_800E1EE4, D_800E1EE4_eu, g_languageIndex);
        break;
    case 5011:
        text = RW_LOCALIZED_TEXT(D_800D3560, D_800E1FD4, D_800E1FD4_eu, g_languageIndex);
        break;
    case 5012:
        text = RW_LOCALIZED_TEXT(D_800D3554, D_800E1FA4, D_800E1FA4, g_languageIndex);
        break;
    case 5013:
        text = RW_LOCALIZED_TEXT(D_800D3568, D_800E1FF4, D_800E1FF4, g_languageIndex);
        break;
    case 5014:
        text = RW_LOCALIZED_TEXT(D_800D3544, D_800E1F64_eu, D_800E1F64_eu, g_languageIndex);
        break;
    case 5015:
        text = RW_LOCALIZED_TEXT(D_800D3514, D_800E1EA4_eu, D_800E1EA4_eu, g_languageIndex);
        break;
    case 5016:
        text = RW_LOCALIZED_TEXT(D_800D34F0, D_800E1E14, D_800E1E14, g_languageIndex);
        break;
    case 5017:
        text = RW_LOCALIZED_TEXT(D_800D3540, D_800E1F54_eu, D_800E1F54_eu, g_languageIndex);
        break;
    case 5018:
        text = RW_LOCALIZED_TEXT(D_800D353C, D_800E1F44_eu, D_800E1F44_eu, g_languageIndex);
        break;
    case 5019:
        text = RW_LOCALIZED_TEXT(D_800D354C, D_800E1F84_eu, D_800E1F84_eu, g_languageIndex);
        break;
    case 5020:
        text = RW_LOCALIZED_TEXT(D_800D3538, D_800E1F34_eu, D_800E1F34_eu, g_languageIndex);
        break;
    case 5021:
        text = RW_LOCALIZED_TEXT(D_800D3518, D_800E1EB4, D_800E1EB4, g_languageIndex);
        break;
    case 5022:
        text = RW_LOCALIZED_TEXT(D_800D3548, D_800E1F74_eu, D_800E1F74_eu, g_languageIndex);
        break;
    case 5023:
        text = RW_LOCALIZED_TEXT(D_800D34F8, D_800E1E34, D_800E1E34, g_languageIndex);
        break;
    case 5024:
        text = RW_LOCALIZED_TEXT(D_800D34F4, D_800E1E24_eu, D_800E1E24_eu, g_languageIndex);
        break;
    case 5025:
        text = RW_LOCALIZED_TEXT(D_800D356C, D_800E2004_eu, D_800DDA78, g_languageIndex);
        break;
    case 5026:
        text = RW_LOCALIZED_TEXT(D_800D352C, D_800E1F04_eu, D_800DD9B8, g_languageIndex);
        break;
    case 5027:
        text = RW_LOCALIZED_TEXT(D_800D355C, D_800E1FC4, D_800E1FC4_eu, g_languageIndex);
        break;
    case 5028:
        text = RW_LOCALIZED_TEXT(D_800D3530, D_800E1F14, D_800E1F14, g_languageIndex);
        break;
    case 5029:
        text = RW_LOCALIZED_TEXT(D_800D3520, D_800E1ED4, D_800E1ED4, g_languageIndex);
        break;
    case 5030:
        text = RW_LOCALIZED_TEXT(D_800D3570, D_800E2014, D_800E2014, g_languageIndex);
        break;
    case 5031:
        text = RW_LOCALIZED_TEXT(D_800D3508, D_800E1E74, D_800E1E74, g_languageIndex);
        break;
    case 5033:
        text = RW_LOCALIZED_TEXT(D_800D3558, D_800E1FB4_eu, D_800E1FB4_eu, g_languageIndex);
        break;
    case 5034:
        text = RW_LOCALIZED_TEXT(D_800D3574, D_800E2024, D_800DDA90, g_languageIndex);
        break;
    case 5037:
        text = RW_LOCALIZED_TEXT(D_800D3534, D_800E1F24, D_800E1F24, g_languageIndex);
        break;
    case 5057:
        text = RW_LOCALIZED_TEXT(D_800D34FC, D_800E1E44, D_800E1E44, g_languageIndex);
        break;
    case 5052:
        text = RW_LOCALIZED_TEXT(D_800D3500, D_800E1E54, D_800E1E54, g_languageIndex);
        break;
    case 5053:
        text = RW_LOCALIZED_TEXT(D_800D3504, D_800E1E64, D_800E1E64, g_languageIndex);
        break;
    default:
        break;
    }
    return text;
}
