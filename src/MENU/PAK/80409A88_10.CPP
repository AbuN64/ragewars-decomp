#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/ITEMRECAT24.H"
#include "stddef.h"

#if defined(VERSION_US) || defined(VERSION_US_REV1) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#define func_8040A83C_us func_8040AB70_eu
#endif
/* Select the status text and right-align its nonblank characters. */
#include "TYPES.H"
#include "COMMON/UNUSED.H"
s32 func_80441FE8_de(void *); /* extern */
 /* const */
 /* const */
s32 func_8040A83C_us(struct Field *arg0) {
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
        arg0->text = &D_800D2478;
    } else {
        arg0->text = &D_800D2480;
        var_a1 = &D_8014B49B;
        while (*var_a1-- == 0x20 && var_s1 != 0) var_s1--;
        temp_s0 = *arg0->text;
        temp_s0 = temp_s0 + (func_80441FE8_de(arg0) - 8);
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
#ifdef NON_MATCHING
extern s32 D_80153774;
extern char D_800D2484[], D_800D37D0[];
extern char D_800D26A4[], D_800D26A8[], D_800D26BC[], D_800D26C4[], D_800D26C8[];
extern s8 D_8014D490;
s32 func_8040A928_us(struct Field *arg0) {
    char *src;
    char *dst;
    s32 i;
    if (D_80153774 != 0) {
        arg0->text = (char **)D_800D37D0;
    } else {
        arg0->text = (char **)D_800D2484;
        switch (D_8014D490) {
        case 2:
            src = D_800D26C4;
            break;
        case 3:
            src = D_800D26BC;
            break;
        case 5:
            src = D_800D26A8;
            break;
        case 14:
            src = D_800D26C8;
            break;
        default:
            src = D_800D26A4;
            break;
        }
        dst = *arg0->text + (func_80441FE8_de(arg0) - 11);
        for (i = 0; i < 11; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8040A928_us);
#endif
#endif
