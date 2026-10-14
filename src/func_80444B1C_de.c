#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
extern struct MenuSettings D_801462C8;
#include "types.h"

#if defined(VERSION_EU)
/* Points an option field at the settings byte 0x7A of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D3600 for zero and otherwise the text D_800E2264 formatted with D_800DE758_de for a positive or D_800EEDE0 for a negative step four bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_804449EC_de with the byte 0x7A and the texts D_800D3600 and D_800E2264 changed. */
#elif defined(VERSION_EU_X)
/* Points an option field at the settings byte 0x7A of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D3600 for zero and otherwise the text D_800DDC40 formatted with D_800DE758_de for a positive or D_800EEDE0 for a negative step four bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_804449EC_de with the byte 0x7A and the texts D_800D3600 and D_800DDC40 changed. */
#else
/* Points an option field at the settings byte 0x7A of the holder's owner settings (or the defaults D_80146302) as a signed offset from 128 in steps of eight, using the text D_800D3600 for zero and otherwise the text D_800D3604_de formatted with D_800DE758_de for a positive or D_800DE760 for a negative step four bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_804449EC_de with the byte 0x7A and the texts D_800D3600 and D_800D3604_de changed. */
#endif









extern struct Settings_func_80444AB8_de D_80146302;
extern char *D_800D3600;
#if defined(VERSION_EU)
extern char *D_800E2264;
#elif defined(VERSION_EU_X)
extern char *D_800DDC40;
#else
extern char *D_800D3604_de;
#endif
extern char D_800DE758_de[];
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EEDE0[];
#else
extern char D_800DE760[];
#endif
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_80444B1C_de(struct Field *field, struct Holder_func_80444AB8_de *holder) {
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
