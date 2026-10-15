#include "span_16E000/code_80444EC0.h"
#include "span_16E000/code_8043F69C.h"
#include "common/unused.h"
#include "span_C76B0/data.h"

#include "common/types_1dc8418c21db.h"
#include "types.h"
#include "shared/gameplay_sound_table.h"

/* Selects a localized volume label and formats an intermediate value.
 * DE/US-rev1 source and proofs remain preserved separately. */

/* Points a field's text at one of D_800D3D94, D_800D3D90 or D_800D3D8C when the option byte D_801462E0 measured from 0x80 in steps of eight is zero, fifteen or minus sixteen, and otherwise at D_800D3D98 with the step formatted into it, returning zero. Adapted from func_80445AB8 with D_801462E2 changed to D_801462E0 and the text slots D_800D7DD8..D_800D7DE4 changed to D_800D3D8C..D_800D3D98. */



extern s32 func_80441FE8_de(LayeredText *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_804451D0_de(LayeredText *field) {
    s32 step = (D_801462E0[0] - 0x80) / 8;
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
        text = (char *)field->text[D_80152789];
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EEE10, step);
#else
        field->text = (u8 **)&D_800D3D98;
        text = (char *)*field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800E27E0, step);
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40B4;
        text = (char *)field->text[D_80152789];
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EEE18, step);
#else
        field->text = (u8 **)&D_800D3D98;
        text = (char *)*field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800E27E8, step);
#endif
    }
    return 0;
}

#endif
