#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", func_8043E2D8_de);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
#include "COMMON/SHARED_MENUSELECTION.H"


#include "COMMON/GAMEPLAY_MOVEMENT.H"


#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/PLAYERSETTINGS.H"

struct Field;

extern char *D_800D7670[];
extern char *D_800D3648_de[];
extern char *D_800D364C_de[];
extern char *D_800D3650_de[];
extern char *D_800D3654[];
extern char *D_800D3658[];
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_auto_800E2364[];
extern char D_800EE970[];
#else
extern char D_800DE2F0[];
#endif
extern s32 Pak_CountLineChars(struct Field *);

s32 func_8043E2D8_de(struct Field *field, Shared_MenuHandle *holder) {
    s32 value = holder->owner->views5D8.view5D8_9.profile->quantity;
    char *text;

    if (value == 0) {
        field->text = D_800D3654;
    } else if (value == 10) {
        field->text = D_800D3658;
    } else {
        switch (holder->selection->index) {
        case 0:
        default:
#if defined(VERSION_EU) || defined(VERSION_EU_X)
            field->text = D_auto_800E2364;
#else
            field->text = D_800D7670;
#endif
            break;
        case 1:
            field->text = D_800D3648_de;
            break;
        case 2:
            field->text = D_800D364C_de;
            break;
        case 3:
            field->text = D_800D3650_de;
            break;
        }
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = field->text[g_languageIndex];
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 2), D_800EE970, value);
#else
        text = *field->text;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 2), D_800DE2F0, value);
#endif
    }
    return 0;
}
#endif
