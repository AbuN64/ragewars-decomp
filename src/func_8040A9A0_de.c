#include "common/unused.h"
#include "span_16E000/code_8043F69C.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"

/* Formats the score into the last four characters of the item's text and returns zero.
   PAL items select their text using the current language. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern u16 D_8015D48C;
extern char D_800ED414[];
#else
extern u16 D_8014D48C;
extern char D_800DCD94_de[];
#endif
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A9A0_de(Item_func_80441FE8_de *field) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    s32 value = D_8015D48C;
    char *text = (char *)field->text[D_80152789];

    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800ED414, value);
#else
    s32 value = D_8014D48C;
    char *text = (char *)*field->text;

    func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DCD94_de, value);
#endif
    return 0;
}
