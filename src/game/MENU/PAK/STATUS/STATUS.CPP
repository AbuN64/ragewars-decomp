#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/ITEMRECAT24.H"
#include "stddef.h"
#include "MENU/80408CB0_10.H"
#include "MENU/PAK/PROFILE_PREVIEW_AND_LINE_TEXT.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"

#if !defined(VERSION_DE)
/* Select the status text and right-align its nonblank characters. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
 /* const */
 /* const */
s32 Status_FormatRightAlignedPreviewName(struct Field *item) {
    s8 *temp_s0;
    s8 *temp_s0_2;
    s32 var_s1;
    s32 var_v1;
    s32 space;
    s32 var_v1_2;
    s8 *var_v0;
    u8 *var_a1;
    u8 *var_s0;
    u8 temp_v0;
    var_s1 = 8;
    if (D_80153774 != 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E2984_eu;
#else
        item->text = &D_800D2478;
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E29A4;
#else
        item->text = &D_800D2480;
#endif
        var_a1 = &D_8014B49B;
        while (*var_a1-- == 0x20 && var_s1 != 0) var_s1--;
        temp_s0 = RW_LOCALIZED_TEXT(*item->text, item->text, item->text, g_languageIndex);
        temp_s0 = temp_s0 + (Menu_CountLineChars(item) - 8);
        space = 0x20;
        var_v1 = 7;
        var_v0 = temp_s0 + 7;
        do {
            *var_v0 = space;
            var_v1 -= 1;
            var_v0 -= 1;
        } while (var_v1 >= 0);
        temp_s0 = temp_s0 + (8 - var_s1);
        var_v1_2 = 0;
        if (var_s1 > 0) {
            do {
                temp_v0 = D_8014B494[var_v1_2];
                var_v1_2 += 1;
                *(u8 *)temp_s0 = temp_v0;
                temp_s0 += 1;
            } while (var_v1_2 < var_s1);
        }
    }
    return 0;
}
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
#if defined(VERSION_US_REV1) || defined(NON_MATCHING)
/* D_8014D490 is read through a struct view so the compiler keeps the load behind the preceding store. */
typedef struct { s8 value; } PakModeByte;
extern char *D_800D2484, *D_800D37D0;
extern char *D_800D26A4, *D_800D26A8, *D_800D26BC, *D_800D26C4, *D_800D26C8;
/* Select the pak status label and right-align its eleven characters. */
s32 Status_UpdateStatusText(struct Field *item) {
    char *src;
    char *dst;
    s32 i;
    if (D_80153774 != 0) {
        item->text = &D_800D37D0;
    } else {
        item->text = &D_800D2484;
        i = ((PakModeByte *)&D_8014D490)->value;
        switch (i) {
        case 0:
        case 1:
        case 4:
        default:
            src = D_800D26A4;
            break;
        case 5:
            src = D_800D26A8;
            break;
        case 3:
            src = D_800D26BC;
            break;
        case 2:
            src = D_800D26C4;
            break;
        case 14:
            src = D_800D26C8;
            break;
        }
        dst = *item->text;
        dst += Menu_CountLineChars(item) - 11;
        for (i = 0; i < 11; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Status_UpdateStatusText);
#endif
#endif
