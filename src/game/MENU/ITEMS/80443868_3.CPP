#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ACTORRECAT260.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"
extern void Defs_FormatIntegerValue(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "SYSTEM_3/80265370.H"
extern Shared_MenuData D_80145040;
extern s16 g_playerResultScoreFields[];

s32 Items_FormatPlayerResultScore(LayeredText *field, struct MenuRules *holder) {
    Shared_MenuData *players = &D_80145040;
    s32 player = Player_GetPlayerIndex(players, holder->locked);
    s32 value = g_playerResultScoreFields[player * 75];
    char *text = (char *)field->text[players->game.language];
    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EED80, value);
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EED80[];

#else
#endif
/* Formats the halfword g_playerResultScoreFieldsDe holds for the player func_8022A5A0_de identifies from the owner at offset
   0x1C of the second argument, player records being 150 bytes apart, into a field's text with the
   format D_800DE700 four bytes before the length Pak_CountLineChars reports. Returns zero. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct LocalizedInputState D_80145040;
#else
extern char D_80145040[];
#endif

extern char g_fmtDec4Pad[];
extern s32 Player_GetPlayerIndex(void *, unsigned int);
extern s32 Pak_CountLineChars(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 Items_FormatPlayerResultScore(LayeredText *field, struct MenuRules *holder) {

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    struct LocalizedInputState *players = &D_80145040;
    s32 player = Player_GetPlayerIndex(players, holder->locked);
#else
    s32 player = Player_GetPlayerIndex(D_80145040, holder->locked);
#endif

    s32 value = D_801462C8.playerSettings[player].resultScore;
    char *text =

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        (char *)field->text[players->language];
#else
        (char *)*field->text;
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EED80, value);
#else
    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_fmtDec4Pad, value);
#endif
    return 0;
}

#endif
#endif
