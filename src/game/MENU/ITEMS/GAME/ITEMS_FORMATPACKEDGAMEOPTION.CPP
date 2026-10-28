#include "SYSTEM/80265370.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU/HOLDERRECAT1CV2.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM/80265370.H"

s32 Items_FormatPackedGameOption(LayeredText *field) {
    char *text;
    s32 value = D_801462C8.packedOptions >> 4;

    if (value == 0) {
        field->text = D_800D35EC;
    } else if (value == 16) {
        field->text = D_800D35F0;
    } else {
        field->text = (u8 **)&D_800D35F4;
        text = (char *)field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 2), g_fmtDec2Pad, value);
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Shows D_800D35EC in a field when the top twelve bits of g_gamePackedOptions are zero, D_800D35F0 when they are sixteen, and otherwise points the field at D_800D35F4 and formats their value into it with D_800DE750_de two bytes before the length Menu_CountLineChars reports, returning zero. Adapted from Pak_FormatMusicPreview with the value taken from the top twelve bits of the halfword g_gamePackedOptions, a second fixed text for sixteen, and the texts and format changed. */




extern s32 Menu_CountLineChars(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 Items_FormatPackedGameOption(LayeredText *field) {
    char *text;
    s32 value = D_801462C8.packedOptions >> 4;

    if (value == 0) {
        field->text = D_800D35EC;
    } else if (value == 16) {
        field->text = D_800D35F0;
    } else {
        field->text = (u8 **)&D_800D35F4;
        text = (char *)*(u8 **)&D_800D35F4;
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 2), g_fmtDec2Pad, value);
    }
    return 0;
}

#endif
#endif
