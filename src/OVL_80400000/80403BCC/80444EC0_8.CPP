#include "span_16E000/code_80444EC0.h"
#include "span_16E000/code_8043F69C.h"
#include "common/unused.h"
#include "span_C76B0/data.h"

#include "common/types_1dc8418c21db.h"
#include "TYPES.H"
#include "shared/gameplay_sound_table.h"

/* Shows one of three fixed volume texts for steps zero, fifteen and minus
 * sixteen from the option byte D_801462E2. Other steps are formatted into
 * the alternate text with the positive or negative format. */



extern s32 func_80441FE8_de(LayeredText *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445AB8(LayeredText *field) {
    s32 step = (D_801462E2 - 0x80) / 8;
    char *text;

    if (step == 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40A4;
#else
        field->text = &D_800D3DB4;
#endif
    } else if (step == 15) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E4094;
#else
        field->text = &D_800D3DB0;
#endif
    } else if (step == -16) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E4084;
#else
        field->text = &D_800D7DD8;
#endif
    } else if (step > 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40B4;
        text = (char *)field->text[D_80152789];
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EEE10, step);
#else
        field->text = (u8 **)&D_800D7DE4;
        text = (char *)*field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800E27E0, step);
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text = D_800E40B4;
        text = (char *)field->text[D_80152789];
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EEE18, step);
#else
        field->text = (u8 **)&D_800D7DE4;
        text = (char *)*field->text;
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800E27E8, step);
#endif
    }
    return 0;
}

#endif
