#include "COMMON/UNUSED.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/ACTORRECAT260.H"
#include "SYSTEM_3/80265370.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EED80[];

#else
#endif
/* Formats the halfword D_801422DA holds for the player func_8022A5A0_de identifies from the owner at offset
   0x1C of the second argument, player records being 150 bytes apart, into a field's text with the
   format D_800DE700 four bytes before the length func_80441FE8_de reports. Returns zero. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct LocalizedInputState D_80145040;
#else
extern char D_80145040[];
#endif

extern char D_800DE700[];
extern s32 func_8022A5A0_de(void *, unsigned int);
extern s32 func_80441FE8_de(LayeredText *);

s32 func_80443AB0_de(LayeredText *field, struct MenuRules *holder) {

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    struct LocalizedInputState *players = &D_80145040;
    s32 player = func_8022A5A0_de(players, holder->locked);
#else
    s32 player = func_8022A5A0_de(D_80145040, holder->locked);
#endif

    s32 value = D_801422DA[player * 75];
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
