#include "SYSTEM/80265370.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/ACTORRECAT260.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "SYSTEM/80265370.H"
extern Shared_MenuData D_80145040;
extern s16 g_playerRewardScoreFields[];

s32 Player_FormatPlayerRewardScore(LayeredText *field, struct MenuRules *holder) {
    Shared_MenuData *players = &D_80145040;
    s32 player = Player_GetPlayerIndex(players, holder->locked);
    s32 value = g_playerRewardScoreFields[player * 75];
    char *text = (char *)field->text[players->game.language];
    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EED80, value);
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Formats the halfword g_playerRewardScoreFieldsDe holds for the player func_8022A5A0_de identifies from the owner at offset
   0x1C of the second argument, player records being 150 bytes apart, into a field's text with the
   format D_800DE700 four bytes before the length Pak_CountLineChars reports. Returns zero. */

extern char D_80145040[];
extern char g_fmtDec4Pad[];
extern s32 Player_GetPlayerIndex(void *, unsigned int);
extern s32 Pak_CountLineChars(LayeredText *);

s32 Player_FormatPlayerRewardScore(LayeredText *field, struct Holder *holder) {
    s32 player = Player_GetPlayerIndex(D_80145040, (u32)holder->owner);
    s32 value = D_801462C8.playerSettings[player].score;
    char *text = (char *)*field->text;

    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_fmtDec4Pad, value);
    return 0;
}
#endif
