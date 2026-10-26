#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "MENU/PAK/80444EC0_13.H"
extern void Defs_FormatIntegerValue(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM_3/80265370.H"

s32 Pak_FormatVolumeSlotOne(struct Field *field) {
    s32 step = (D_801462C8.volume[1] - 0x80) / 8;
    char *text;

    if (step == 0) {
        field->text = D_800D7DD0;
    } else if (step == 15) {
        field->text = D_800D7DCC;
    } else if (step == -16) {
        field->text = D_800D7DC8;
    } else if (step > 0) {
        field->text = D_800D7DD4;
        text = field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EEE10, step);
    } else {
        field->text = D_800D7DD4;
        text = field->text[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EEE18, step);
    }
    return 0;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Points a field's text at one of D_800D7DD0, D_800D7DCC or D_800D7DC8 when the option byte D_801462E1 measured from 0x80 in steps of eight is zero, fifteen or minus sixteen, and otherwise at D_800D7DD4 with the step formatted into it, returning zero. Adapted from Pak_UpdateThirdVolumeLabel with D_801462E2 changed to D_801462E1 and the text slots D_800D7DD8..D_800D7DE4 changed to D_800D7DC8..D_800D7DD4. */

extern char *D_800D7DD4;
extern s32 Pak_CountLineChars(struct Field *);

s32 Pak_FormatVolumeSlotOne(struct Field *field) {
    s32 step = (D_801462C8.volume[1] - 0x80) / 8;
    char *text;

    if (step == 0) {
        field->text = &D_800D7DD0;
    } else if (step == 15) {
        field->text = &D_800D7DCC;
    } else if (step == -16) {
        field->text = &D_800D7DC8;
    } else if (step > 0) {
        field->text = &D_800D7DD4;
        text = *field->text;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_pakFormatSpacedInt2, step);
    } else {
        field->text = &D_800D7DD4;
        text = *field->text;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_pakFormatSpacedInt3, step);
    }
    return 0;
}
#endif
