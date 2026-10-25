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

#if (defined(VERSION_EU) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", func_80445AB8);
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1) || ((defined(VERSION_EU) || defined(VERSION_EU_X)) && defined(NON_MATCHING))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
extern char D_800EEE10[], D_800EEE18[];
#define VOLUME_BYTE D_801462C8.volume[2]
#else
#define VOLUME_BYTE D_801462C8.volume[2]
#endif
/* Shows one of three fixed volume texts for steps zero, fifteen and minus
 * sixteen from the option byte D_801462E2. Other steps are formatted into
 * the alternate text with the positive or negative format. */



extern s32 func_80441FE8_de(LayeredText *);

s32 func_80445AB8(LayeredText *field) {
    s32 step = (VOLUME_BYTE - 0x80) / 8;
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
