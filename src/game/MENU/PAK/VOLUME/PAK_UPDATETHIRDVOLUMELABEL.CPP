#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_80152789.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/GAMEPLAY_SOUND_TABLE.H"
#include "SYSTEM/80265370.H"

#if defined(VERSION_DE) || defined(VERSION_US_REV1) || defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#define VOLUME_BYTE D_801462C8.volume[2]
#else
#define VOLUME_BYTE D_801462C8.volume[2]
#endif
/* Shows one of three fixed volume texts for steps zero, fifteen and minus
 * sixteen from the option byte D_801462E2. Other steps are formatted into
 * the alternate text with the positive or negative format. */



extern s32 Menu_CountLineChars(LayeredText *);

s32 Pak_UpdateThirdVolumeLabel(LayeredText *field) {
    s32 step = (VOLUME_BYTE - 0x80) / 8;
    char *text;

    if (step == 0) {
        field->text = &D_800D3DB4;
    } else if (step == 15) {
        field->text = &D_800D3DB0;
    } else if (step == -16) {
        field->text = &D_800D7DD8;
    } else if (step > 0) {
        field->text = (u8 **)&D_800D7DE4;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = (char *)field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 4), D_800EEE10, step);
#else
        text = (char *)*field->text;
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 4), g_pakFormatSpacedInt2, step);
#endif
    } else {
        field->text = (u8 **)&D_800D7DE4;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = (char *)field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 4), D_800EEE18, step);
#else
        text = (char *)*field->text;
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 4), g_pakFormatSpacedInt3, step);
#endif
    }
    return 0;
}

#endif
