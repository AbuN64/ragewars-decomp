#include "span_16E000/code_80443868.h"
#include "span_16E000/code_8043F69C.h"
#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"
#include "span_16E000/code_804453C4.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
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

extern s16 D_801422DE[];
extern char D_800DE700[];
extern s32 func_8022A5A0_de(void *, unsigned int);
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_80443998_de(Item_func_80441FE8_de *field, struct MenuRules *holder) {

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    struct LocalizedInputState *players = &D_80145040;
    s32 player = func_8022A5A0_de(players, holder->locked);
#else
    s32 player = func_8022A5A0_de(D_80145040, holder->locked);
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
