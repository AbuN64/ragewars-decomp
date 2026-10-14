#include "span_16E000/code_80444030.h"
#include "span_16E000/code_8043F69C.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "span_16E000/code_804453C4.h"

/* Shows D_800D35EC in a field when the top twelve bits of D_801462DC are zero, D_800D35F0 when they are sixteen, and otherwise points the field at D_800D35F4 and formats their value into it with D_800DE750_de two bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_80445ECC with the value taken from the top twelve bits of the halfword D_801462DC, a second fixed text for sixteen, and the texts and format changed. */


extern u8 *D_800D35EC[];
extern u8 *D_800D35F0[];


extern char D_800DE750_de[];
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8044488C_de(Item_func_80441FE8_de *field) {
    char *text;
    s32 value = D_801462DC >> 4;

    if (value == 0) {
        field->text = D_800D35EC;
    } else if (value == 16) {
        field->text = D_800D35F0;
    } else {
        field->text = (u8 **)&D_800D35F4;
        text = (char *)*(u8 **)&D_800D35F4;
        func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DE750_de, value);
    }
    return 0;
}

#endif
