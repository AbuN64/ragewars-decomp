#include "include_asm.h"
#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_2.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/EXTERNS_21.H"
#include "SYSTEM_2/8025E280.H"
#include "COMMON/ITEMRECAT20V1.H"

/* 80444EC0_15.CPP */
#if !defined(VERSION_US)
/* Shows the fixed sound value text when D_800E63B8 is zero. Otherwise
 * formats its current value into the alternate text (the current menu
 * language's line in the EU builds), two bytes before the line length
 * reported by the text item helper. */
extern s32 Pak_CountLineChars(LayeredText *);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* The menu language byte; read as an array element, which keeps the read after the text store. */
extern u8 g_languageIndex[];
extern char D_800EEE20[];
#define VALUE_TEXT D_800E4154
#define VALUE_FORMAT D_800EEE20
#else
#define VALUE_TEXT ((u8 **)&D_800D3DC0)
#define VALUE_FORMAT D_800DE7B0_de
#endif

s32 Pak_FormatMusicPreview(LayeredText *field) {
    char *text;
    if (D_800E63B8 == 0) {
        field->text = &D_800D3DBC;
    } else {
        field->text = VALUE_TEXT;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = (char *)field->text[g_languageIndex[0]];
#else
        text = (char *)*VALUE_TEXT;
#endif
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 2),
                        VALUE_FORMAT, D_800E63B8);
    }
    return 0;
}
#endif

/* 80444EC0_16.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)

s32 Pak_OpenMusicPreviewMenu(void *first, void *second, void *third) {
    func_8025E3A8_de();
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E384_de();
    func_8025E29C_de(1);
    D_800E63B4 = 1;
    func_802649FC_de();
    Pak_AllocateMenu(third, second, D_00451094);
    return 1;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Restarts sound: calls func_8025E3A8_de, records what func_8025E2C4_de returns in D_800E63B0, passes
   D_800E63B8 to func_8025E2D4_de, calls func_8025E384_de and func_8025E29C_de with 1, sets D_800E63B4,
   calls func_802649FC_de and then Pak_AllocateMenu with the third argument, the second and D_451F58.
   Returns one. */

s32 Pak_OpenMusicPreviewMenu(void *first, void *second, void *third) {
    func_8025E3A8_de();
    D_800E63B0 = func_8025E2C4_de();
    func_8025E2D4_de(D_800E63B8);
    func_8025E384_de();
    func_8025E29C_de(1);
    D_800E63B4 = 1;
    func_802649FC_de();
    Pak_AllocateMenu(third, second, D_00451094);
    return 1;
}
#endif

/* 80444EC0_17.CPP */
#if defined(VERSION_US_REV1)
/* Toggles the owner at offset 0x1C of the second argument between states 1 and 2 through its word
   at 0x5D0, leaving any other state alone; returns zero. */

s32 Pak_ToggleOwnerMode(void *unused, struct Holder *holder) {
    struct OwnerRecAt5D0 *owner = holder->owner;

    if (owner == 0) {
        return 0;
    }
    if (owner->value == 1) {
        owner->value = 2;
    } else if (owner->value == 2) {
        owner->value = 1;
    }
    return 0;
}

/* Points a field's text at D_800E6090 when the owner at offset 0x1C of the second argument has its
   word at 0x5D0 equal to one, and at D_800E60AC otherwise; returns zero, doing nothing without an
   owner. */

s32 Pak_UpdateOwnerModeText(struct FieldRecAt14 *field, struct Holder *holder) {
    if (holder->owner == 0) {
        return 0;
    }
    if (holder->owner->value == 1) {
        field->text = D_800E6090;
    } else {
        field->text = D_800E60AC;
    }
    return 0;
}

/* Replaces D_800D0EBC with what Pak_AdjustValue returns for the second argument, D_800D0EBC, 1, 0, 1 and 1,
   and returns zero. */
extern s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Pak_AdjustOwnerNotificationOption(void *first, void *second) {
    D_800D0EBC = Pak_AdjustValue(second, D_800D0EBC, 1, 0, 1, 1);
    return 0;
}
#endif
