#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
#include "types.h"

/* Formats the word at offset 0x1C of the structure D_800E28BC points to, shifted down eight bits,
   into a field's text with the format D_800E0DA4, three bytes before the length func_80441FE8_de
   reports, and returns zero. */




extern struct MenuRules *D_800E28BC;
extern char D_800E0DA4[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A530_de(struct Field *field) {
    s32 value = D_800E28BC->locked >> 8;
    char *text =
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text[D_80152789];
#else
        *field->text;
#endif

    func_802658E4_de(text + (func_80441FE8_de(field) - 3), D_800E0DA4, value);
    return 0;
}
