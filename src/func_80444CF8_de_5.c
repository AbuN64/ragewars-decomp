#include "span_16E000/code_80444030.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"
#include "common/unused.h"
#include "span_16E000/code_8040B45C.h"

/* Replaces the option halfword D_801462DC with what func_804423BC_de returns for the second argument,
   that halfword, 0x10, 0, 0x100 and 0, then stores its low byte in the byte after it, or 0xFF when
   the value is 0xFF or more. Returns zero. */

extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

/* Replaces the byte at offset 0x79 of the second argument's owner settings (or the defaults D_80146302) with what func_804423BC_de returns for the second argument, that byte, 8, 8, 0xF8 and 0, and returns zero. */









extern struct MenuSettings D_801462C8;

#if defined(VERSION_EU)
/* Points an option field at the settings byte 0x79 of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D35F8 for zero and otherwise the text D_800E2244 formatted with D_800DE758_de for a positive or D_800EEDE0 for a negative step four bytes before the length func_80441FE8_de reports, returning zero. */
#elif defined(VERSION_EU_X)
/* Points an option field at the settings byte 0x79 of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D35F8 for zero and otherwise the text D_800DDC28 formatted with D_800DE758_de for a positive or D_800EEDE0 for a negative step four bytes before the length func_80441FE8_de reports, returning zero. */
#else
/* Points an option field at the settings byte 0x79 of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D35F8 for zero and otherwise the text D_800D35FC_de formatted with D_800DE758_de for a positive or D_800DE760 for a negative step four bytes before the length func_80441FE8_de reports, returning zero. */
#endif


#if defined(VERSION_EU)
extern char *D_800E2244;
#elif defined(VERSION_EU_X)
extern char *D_800DDC28;
#else
#endif


#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EEDE0[];
#else
#endif

extern s32 func_80441FE8_de(struct Field *);

extern void func_802658E4_de(char *, char *, s32);

/* Replaces the byte at offset 0x7A of the second argument's owner settings (or the defaults D_80146302) with what func_804423BC_de returns for the second argument, that byte, 8, 8, 0xF8 and 0, and returns zero. Adapted from func_80444988_de with the settings byte 0x7A changed. */










#if defined(VERSION_EU)
extern char *D_800E2264;
#elif defined(VERSION_EU_X)
extern char *D_800DDC40;
#else
#endif

/* Points a field's text at D_800D7634 when the byte at offset 0x82 of the settings the second argument's owner holds, or of the defaults D_80146302 without an owner, is one, and at D_800D7638 otherwise, returning zero. Adapted from func_80446000_us_rev1 with the settings lookup of func_80444C34_de and the texts D_800D7634 and D_800D7638 changed, and a zero result local declared first to give the owner and settings pointers the cartridge's registers. */












/* Toggles the byte at offset 0x82 of the settings the object at offset 0x5D8 of the second
   argument's owner holds, or of the defaults D_80146302 when there is no owner, and returns zero. */








/* Counts the timer D_80154100 down by D_800D2988 without passing zero, then sets bit 24 of the flag word at offset 8 of a record unless func_80265350_de reports 0x400000, in which case the bit is cleared, stores what func_8040C3BC_de returns at offset 0x14 and returns zero. Adapted from func_80445590_de with the timer countdown added, func_80265350_de called without arguments and bit 24 instead of bit 23 changed. */


extern f32 D_80154100;

extern f32 D_800D2988;

extern s32 func_80265350_de(void);

extern s32 func_8040C3BC_de();




s32 func_80444920_de(void *first, void *second) {
    u16 *option = &D_801462DC;
    u8 limited;

    *option = func_804423BC_de(second, *option, 0x10, 0, 0x100, 0);
    limited = 0xFF;
    if (*option < 0xFF) {
        limited = ((u8 *) option)[1];
    }
    ((u8 *) option)[2] = limited;
    return 0;
}

s32 func_80444988_de(void *first, struct Holder_func_80444988_de *holder) {
    extern struct Settings_func_80444988_de D_80146302;
    struct Settings_func_80444988_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->value = func_804423BC_de(holder, settings->value, 8, 8, 0xF8, 0);
    return 0;
}

s32 func_804449EC_de(struct Field *field, struct Holder_func_80444988_de *holder) {
    extern struct Settings_func_80444988_de D_80146302;
    struct Settings_func_80444988_de *settings = &D_80146302;
    s32 step;
    char *text;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    step = (settings->value - 128) / 8;
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
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE758_de, step);
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
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EEDE0, step);
#else
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE760, step);
#endif
    }
    return 0;
}

s32 func_80444AB8_de(void *first, struct Holder_func_80444AB8_de *holder) {
    extern struct Settings_func_80444AB8_de D_80146302;
    struct Settings_func_80444AB8_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    settings->value = func_804423BC_de(holder, settings->value, 8, 8, 0xF8, 0);
    return 0;
}

s32 func_80444B1C_de(struct Field *field, struct Holder_func_80444AB8_de *holder) {
    extern struct Settings_func_80444AB8_de D_80146302;
    struct Settings_func_80444AB8_de *settings = &D_80146302;
    s32 step;
    char *text;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    step = (settings->value - 128) / 8;
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
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE758_de, step);
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
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800EEDE0, step);
#else
        func_802658E4_de(text + (func_80441FE8_de(field) - 4), D_800DE760, step);
#endif
    }
    return 0;
}

s32 func_80444BE8_de(struct FieldRecAt14 *field, struct HolderRecAt1CV2 *holder) {
    extern struct Settings_func_80444BE8_de D_80146302;
    s32 result = 0;
    struct Settings_func_80444BE8_de *settings = &D_80146302;

    if (holder->owner != 0) {
        settings = holder->owner->settings;
    }
    if (settings->flag == 1) {
        field->text = D_800D7634;
    } else {
        field->text = D_800D7638;
    }
    return result;
}

s32 func_80444C34_de(void *unused, struct HolderRecAt1CV2 *holder) {
    extern struct Settings_func_80444BE8_de D_80146302;
    struct Settings_func_80444BE8_de *settings = &D_80146302;

    if (holder->owner != 0) {
        settings = holder->owner->settings;
    }
    if (settings->flag == 1) {
        settings->flag = 0;
    } else {
        settings->flag = 1;
    }
    return 0;
}

s32 func_80444C68_de(struct RecordRecAt14 *record) {
    D_80154100 -= D_800D2988;
    if (D_80154100 <= 0.0f) {
        D_80154100 = 0.0f;
    }
    if (func_80265350_de() != 0x400000) {
        record->flags |= 0x1000000;
    } else {
        record->flags &= ~0x1000000;
    }
    record->value = func_8040C3BC_de();
    return 0;
}

s32 func_80444CF8_de(void) {
    if (D_80154100 == 0.0f) {
        func_8040C2F8_de();
        D_80154100 = (18.0f);
        D_80146848 = D_800E28DB;
    }
    return 0;
}
