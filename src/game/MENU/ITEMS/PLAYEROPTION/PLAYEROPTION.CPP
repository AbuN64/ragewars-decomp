#include "include_asm.h"
#include "MENU/HOLDERRECAT1CV2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/NODERECAT2A8.H"
#include "FRONTEND/8040B45C_22.H"
#include "SYSTEM/80265370.H"

/* Replaces the option halfword g_gamePackedOptions with what Menu_AdjustValue returns for the second argument,
   that halfword, 0x10, 0, 0x100 and 0, then stores its low byte in the byte after it, or 0xFF when
   the value is 0xFF or more. Returns zero. */

extern s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32);

/* Replaces the byte at offset 0x79 of the second argument's owner settings (or the defaults D_80146302) with what Menu_AdjustValue returns for the second argument, that byte, 8, 8, 0xF8 and 0, and returns zero. */









extern struct MenuSettings D_801462C8;

#if defined(VERSION_EU)
/* Points an option field at the settings byte 0x79 of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D35F8 for zero and otherwise the text D_800E2244 formatted with D_800DE758_de for a positive or D_800EEDE0 for a negative step four bytes before the length Pak_CountLineChars reports, returning zero. */
#elif defined(VERSION_EU_X)
/* Points an option field at the settings byte 0x79 of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D35F8 for zero and otherwise the text D_800DDC28 formatted with D_800DE758_de for a positive or D_800EEDE0 for a negative step four bytes before the length Pak_CountLineChars reports, returning zero. */
#else
/* Points an option field at the settings byte 0x79 of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D35F8 for zero and otherwise the text D_800D35FC_de formatted with D_800DE758_de for a positive or D_800DE760 for a negative step four bytes before the length Pak_CountLineChars reports, returning zero. */
#endif


#if defined(VERSION_EU)
extern char *D_800E2244;
#elif defined(VERSION_EU_X)
extern char *D_800DDC28;
#else
#endif


#if defined(VERSION_EU) || defined(VERSION_EU_X)
#else
#endif

extern s32 Pak_CountLineChars(struct Field *);


/* Replaces the byte at offset 0x7A of the second argument's owner settings (or the defaults D_80146302) with what Menu_AdjustValue returns for the second argument, that byte, 8, 8, 0xF8 and 0, and returns zero. Adapted from Items_AdjustPlayerOption79 with the settings byte 0x7A changed. */










#if defined(VERSION_EU)
extern char *D_800E2264;
#elif defined(VERSION_EU_X)
extern char *D_800DDC40;
#else
#endif

/* Points a field's text at D_800D7634 when the byte at offset 0x82 of the settings the second argument's owner holds, or of the defaults D_80146302 without an owner, is one, and at D_800D7638 otherwise, returning zero. Adapted from Pak_UpdateOwnerModeText with the settings lookup of Items_TogglePlayerFlag82 and the texts D_800D7634 and D_800D7638 changed, and a zero result local declared first to give the owner and settings pointers the cartridge's registers. */












/* Toggles the byte at offset 0x82 of the settings the object at offset 0x5D8 of the second
   argument's owner holds, or of the defaults D_80146302 when there is no owner, and returns zero. */








/* Counts the timer D_80154100 down by D_800D2988 without passing zero, then sets bit 24 of the flag word at offset 8 of a record unless Defs_GetMemorySize reports 0x400000, in which case the bit is cleared, stores what func_8040C3BC_de returns at offset 0x14 and returns zero. Adapted from Pak_UpdateScreenModeAvailability with the timer countdown added, Defs_GetMemorySize called without arguments and bit 24 instead of bit 23 changed. */


extern f32 D_80154100;

extern f32 D_800D2988;

extern s32 Defs_GetMemorySize(void);

extern s32 Frontend_GetScreenModePalette();




s32 Items_AdjustPackedGameOption(void *first, void *second) {
    u16 *option = &g_gamePackedOptions;
    u8 limited;

    *option = Menu_AdjustValue(second, *option, 0x10, 0, 0x100, 0);
    limited = 0xFF;
    if (*option < 0xFF) {
        limited = ((u8 *) option)[1];
    }
    ((u8 *) option)[2] = limited;
    return 0;
}

s32 Items_AdjustPlayerOption79(void *first, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->option79 = Menu_AdjustValue(holder, settings->option79, 8, 8, 0xF8, 0);
    return 0;
}

s32 Items_FormatPlayerOption79Step(struct Field *field, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;
    s32 step;
    char *text;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    step = (settings->option79 - 128) / 8;
    if (step == 0) {
        field->text = &D_800D35F8;
    } else if (step > 0) {
#if defined(VERSION_EU)
        field->text = &D_800E2244;
#elif defined(VERSION_EU_X)
        field->text = &D_800DDC28;
#else
        field->text = &D_800D35FC_de;
#endif
        text = 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
field->text[D_801462C8.language]
#else
*field->text
#endif
;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800DE758_de, step);
    } else {
#if defined(VERSION_EU)
        field->text = &D_800E2244;
#elif defined(VERSION_EU_X)
        field->text = &D_800DDC28;
#else
        field->text = &D_800D35FC_de;
#endif
        text = 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
field->text[D_801462C8.language]
#else
*field->text
#endif
;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EEDE0, step);
#else
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_fmtSpaceDec3, step);
#endif
    }
    return 0;
}

s32 Items_AdjustPlayerOption7A(void *first, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->option7A = Menu_AdjustValue(holder, settings->option7A, 8, 8, 0xF8, 0);
    return 0;
}

s32 Items_FormatPlayerOption7AStep(struct Field *field, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;
    s32 step;
    char *text;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    step = (settings->option7A - 128) / 8;
    if (step == 0) {
        field->text = &D_800D3600;
    } else if (step > 0) {
#if defined(VERSION_EU)
        field->text = &D_800E2264;
#elif defined(VERSION_EU_X)
        field->text = &D_800DDC40;
#else
        field->text = &D_800D3604_de;
#endif
        text = 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
field->text[D_801462C8.language]
#else
*field->text
#endif
;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800DE758_de, step);
    } else {
#if defined(VERSION_EU)
        field->text = &D_800E2264;
#elif defined(VERSION_EU_X)
        field->text = &D_800DDC40;
#else
        field->text = &D_800D3604_de;
#endif
        text = 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
field->text[D_801462C8.language]
#else
*field->text
#endif
;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800EEDE0, step);
#else
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_fmtSpaceDec3, step);
#endif
    }
    return 0;
}

s32 Items_SelectPlayerFlag82Text(struct FieldRecAt14 *field, struct ActorRecAt1C *holder) {
    s32 result = 0;
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0) {
        settings = holder->owner->settings;
    }
    if (settings->flag82 == 1) {
        field->text = D_800D7634;
    } else {
        field->text = D_800D7638;
    }
    return result;
}

s32 Items_TogglePlayerFlag82(void *unused, struct ActorRecAt1C *holder) {
    struct PlayerOptions *settings = &D_80146302;

    if (holder->owner != 0) {
        settings = holder->owner->settings;
    }
    if (settings->flag82 == 1) {
        settings->flag82 = 0;
    } else {
        settings->flag82 = 1;
    }
    return 0;
}

s32 Items_UpdateScreenModeMenuItem(struct RecordRecAt14 *record) {
    D_80154100 -= D_800D2988;
    if (D_80154100 <= 0.0f) {
        D_80154100 = 0.0f;
    }
    if (Defs_GetMemorySize() != 0x400000) {
        record->flags |= 0x1000000;
    } else {
        record->flags &= ~0x1000000;
    }
    record->value = Frontend_GetScreenModePalette();
    return 0;
}

s32 Items_RequestScreenModeFade(void) {
    if (D_80154100 == 0.0f) {
        Frontend_StartScreenModeFade();
        D_80154100 = (18.0f);
        D_80146848 = (u8)D_800E28D8;
    }
    return 0;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned short rodata_shared_800EEE10[3] = {
    0x2020, 0x2532, 0x6400,
};
#endif
