#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ACTORRECAT260.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"
extern void func_802658E4_de(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "SYSTEM_3/80265370.H"
extern Shared_MenuData D_80145040;
extern s16 D_801522DE[];

s32 func_80443998_de(LayeredText *field, struct MenuRules *holder) {
    Shared_MenuData *players = &D_80145040;
    s32 player = Weapons_GetPlayerIndex(players, holder->locked);
    s32 value = D_801522DE[player * 75];
    char *text = (char *)field->text[players->game.language];
    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EED80, value);
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EED80[];

#else
#endif
/* Formats the halfword D_801422DE holds for the player func_8022A5A0_de identifies from the owner at offset
   0x1C of the second argument, player records being 150 bytes apart, into a field's text with the
   format D_800DE700 four bytes before the length func_80441FE8_de reports. Returns zero. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct LocalizedInputState D_80145040;
#else
extern char D_80145040[];
#endif

extern char D_800DE700[];
extern s32 Weapons_GetPlayerIndex(void *, unsigned int);
extern s32 func_80441FE8_de(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_80443998_de(LayeredText *field, struct MenuRules *holder) {

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    struct LocalizedInputState *players = &D_80145040;
    s32 player = Weapons_GetPlayerIndex(players, holder->locked);
#else
    s32 player = Weapons_GetPlayerIndex(D_80145040, holder->locked);
#endif

    s32 value = D_801422DE[player * 75];
    char *text =

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        (char *)field->text[players->language];
#else
        (char *)*field->text;
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EED80, value);
#else
    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE700, value);
#endif
    return 0;
}

#endif
#endif
