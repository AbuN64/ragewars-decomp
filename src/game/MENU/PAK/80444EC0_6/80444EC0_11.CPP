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
#include "SYSTEM_3/80265370.H"

#if defined(VERSION_DE) || defined(VERSION_US_REV1) || defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#define VOLUME_BYTE D_801462C8.volume[0]
#else
#define VOLUME_BYTE D_801462C8.volume[0]
#endif
/* Selects a localized volume label and formats an intermediate value.
 * DE/US-rev1 source and proofs remain preserved separately. */

/* Points a field's text at one of D_800D3D94, D_800D3D90 or D_800D3D8C when the option byte D_801462E0 measured from 0x80 in steps of eight is zero, fifteen or minus sixteen, and otherwise at D_800D3D98 with the step formatted into it, returning zero. Adapted from Pak_UpdateThirdVolumeLabel with D_801462E2 changed to D_801462E0 and the text slots D_800D7DD8..D_800D7DE4 changed to D_800D3D8C..D_800D3D98. */



extern s32 Pak_CountLineChars(LayeredText *);

s32 Pak_UpdateFirstVolumeLabel(LayeredText *field) {
    s32 step = (VOLUME_BYTE - 0x80) / 8;
    char *text;

    if (step == 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40A4;
#else
        field->text = &D_800D3D94;
#endif
    } else if (step == 15) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E4094;
#else
        field->text = &D_800D3D90;
#endif
    } else if (step == -16) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E4084;
#else
        field->text = &D_800D3D8C;
#endif
    } else if (step > 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40B4;
        text = (char *)field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EEE10, step);
#else
        field->text = (u8 **)&D_800D3D98;
        text = (char *)*field->text;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_pakFormatSpacedInt2, step);
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40B4;
        text = (char *)field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EEE18, step);
#else
        field->text = (u8 **)&D_800D3D98;
        text = (char *)*field->text;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_pakFormatSpacedInt3, step);
#endif
    }
    return 0;
}

#endif
