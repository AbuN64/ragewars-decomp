#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU/HOLDERRECAT1CV2.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"
extern void func_802658E4_de(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM_3/80265370.H"
extern u8 *D_800D35EC[];
extern u8 *D_800D35F0[];
extern char D_800DE750_de[];

s32 func_8044488C_de(LayeredText *field) {
    char *text;
    s32 value = D_801462C8.packedOptions >> 4;

    if (value == 0) {
        field->text = D_800D35EC;
    } else if (value == 16) {
        field->text = D_800D35F0;
    } else {
        field->text = (u8 **)&D_800D35F4;
        text = (char *)field->text[D_801462C8.language];
        func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DE750_de, value);
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Shows D_800D35EC in a field when the top twelve bits of D_801462DC are zero, D_800D35F0 when they are sixteen, and otherwise points the field at D_800D35F4 and formats their value into it with D_800DE750_de two bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_80445ECC with the value taken from the top twelve bits of the halfword D_801462DC, a second fixed text for sixteen, and the texts and format changed. */




extern s32 func_80441FE8_de(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8044488C_de(LayeredText *field) {
    char *text;
    s32 value = D_801462C8.packedOptions >> 4;

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
#endif
