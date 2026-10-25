#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/ACTORRECAT260.H"
extern void func_802658E4_de(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "SYSTEM_3/80265370.H"
extern Shared_MenuData D_80145040;
extern s16 D_801522DC[];
extern char D_800EED80[];

s32 func_80443A24_de(LayeredText *field, struct MenuRules *holder) {
    Shared_MenuData *players = &D_80145040;
    s32 player = Weapons_GetPlayerIndex(players, holder->locked);
    s32 value = D_801522DC[player * 75];
    char *text = (char *)field->text[players->game.language];
    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EED80, value);
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Formats the halfword D_801422DC holds for the player func_8022A5A0_de identifies from the owner at offset
   0x1C of the second argument, player records being 150 bytes apart, into a field's text with the
   format D_800DE700 four bytes before the length func_80441FE8_de reports. Returns zero. */

extern char D_80145040[];
extern char g_fmtDec4Pad[];
extern s32 Weapons_GetPlayerIndex(void *, unsigned int);
extern s32 func_80441FE8_de(LayeredText *);

s32 func_80443A24_de(LayeredText *field, struct Holder *holder) {
    s32 player = Weapons_GetPlayerIndex(D_80145040, (u32)holder->owner);
    s32 value = D_801462C8.playerSettings[player].score;
    char *text = (char *)*field->text;

    func_802658E4_de(text + (func_80441FE8_de(field) - 4), g_fmtDec4Pad, value);
    return 0;
}
#endif
