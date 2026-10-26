#include "include_asm.h"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "TYPES.H"
#include "COMMON/MENU_UI_PROVIDERS.H"
extern Shared_Entry D_800E5CA0;
#include "GFX/TEXT/802A8A94_5.H"



extern func_802077F4_S2 *Pak_GetWidgetStyle(void *, s32);


extern void Pak_DrawLocalizedMenuItemText(void *, ItemRecAt20V1 *, void *, MenuStyle *);

/* Steps the menu spinner in D_800E5CA0: advances its repeat timer by D_800D2988, wrapping at the second entry of D_800E2280, and while the menu is active (state 2) decrements its value above zero when Control_IsLeftPressed reports the decrease input, or else increments it below its maximum when Control_IsRightPressed reports the increase input, restarting the timer on a change. Returns zero. */








#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

/* Shifts the input history, appends the current byte, and advances the history counters. */





extern s32 D_80154030;

/* Checks whether the input matches the indexed, XOR-masked reference string. */


s32 func_802BD400_de(u8 *);

extern u8 D_800E5CAC[0x64];

/* Draws the D_800E5CA0 spinner: during the first part of its blink period it fills a two-pixel white bar below the item under the digit its value selects, placed from the item's x by the character width func_80442DDC_de reports scaled to the screen, with the style's alpha, through OnScreen_SetupFillMode and OnScreen_DrawBevelBox; then draws the item through Pak_DrawLocalizedMenuItemText. */
void Menu_DrawTextEntryCursor(void *menu, ItemRecAt20V1 *item, void *third, MenuStyle *style) {
    f32 width;
    f32 alpha;
    s32 x;
    unsigned int bits;

    if (D_800E5CA0.timer <= (6.0f)) {
        width = Pak_GetWidgetStyle(menu, 0)->unk4 * (f32)D_800E28D0 * (0.0035211266949772835f);
        x = (f32)item->x + (f32)D_800E5CA0.value * width;
        D_800E1E20 = -1;
        alpha = style->alpha * (style->fade * (128.0f));
        OnScreen_SetupFillMode();
        OnScreen_DrawBevelBox(x, item->y, (f32)x + width, item->y + 2, 0, 0, 0xFF, 0xFF, 0xFF,
                      (u8)(bits = !((2147483648.0f) <= alpha) ? (s32)alpha : (bits = (s32)(alpha - (2147483648.0f))) | 0x80000000));
    }
    Pak_DrawLocalizedMenuItemText(menu, item, third, style);
}

s32 Menu_UpdateTextEntryCursor(void *unused, MenuRecAt20V4 *menu) {
    f32 t;

    t = D_800E5CA0.timer + D_800D2988;
    D_800E5CA0.timer = t;
    if (t >= D_800E2280[1]) {
        D_800E5CA0.timer = t - D_800E2280[1];
    }
    if (menu->state == 2) {
        if (((s32 (*)(s32))Control_IsLeftPressed)(menu->input) != 0 && D_800E5CA0.value > 0) {
            D_800E5CA0.value--;
            D_800E5CA0.timer = 0.0f;
        } else if (((s32 (*)(s32))Control_IsRightPressed)(menu->input) != 0) {
            if (D_800E5CA0.value < D_800E5CA0.count) {
                D_800E5CA0.value++;
                D_800E5CA0.timer = 0.0f;
            }
        }
    }
    return 0;
}

/* Does nothing and returns 0. */

s32 func_8043CC08_de(void) {
    return 0;
}

s32 Menu_InsertTextEntryCharacter(ObjRecAt14V2 *arg0) {
    s32 index;
    s32 count;

    D_80154030 = -1;
    D_800E5CA0.timer = 0;
    if (D_800E5CA0.count == 0x16) {
        return 0;
    }
    index = 0x16;
    if (D_800E5CA0.value < 0x16) {
        do {
            D_800E5CA0.text[index] = D_800E5CA0.text[index - 1];
            index--;
        } while (D_800E5CA0.value < index);
    }
    D_800E5CA0.text[D_800E5CA0.value] =
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        *arg0->unk14[g_languageIndex];
#else
        **arg0->unk14;
#endif
    count = D_800E5CA0.count + 1;
    D_800E5CA0.value++;
    D_800E5CA0.count = count;
    D_800E5CA0.text[count] = 0;
    return 0;
}

s32 Menu_DeletePreviousTextEntryCharacter(void) {
    s32 index;
    s32 next;

    D_80154030 = -1;
    D_800E5CA0.timer = 0;
    if (D_800E5CA0.count == 0) {
        return 0;
    }
    if (D_800E5CA0.value == 0) {
        return 0;
    }
    index = D_800E5CA0.value - 1;
    if (index < 0x17) {
        do {
            next = index + 1;
            D_800E5CA0.text[index] = D_800E5CA0.text[next];
            index = next;
        } while (index < 0x17);
    }
    D_800E5CA0.value--;
    D_800E5CA0.count--;
    return 0;
}

s32 Menu_CheckEncodedText(u8 *input) {
    s32 index = 0;

    if (func_802BD400_de(input) != func_802BD400_de(D_800E5CAC)) {
        return 0;
    }
    for (; index < func_802BD400_de(input); index++) {
        if ((input[index] ^ index) != D_800E5CAC[index]) {
            return 0;
        }
    }
    return 1;
}

#if defined(VERSION_US)
const unsigned int rodata_func_8043CB30_de_800DCF04[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_func_8043CB30_de_800E9A94[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_EU)
const unsigned int rodata_func_8043CB30_de_800EE8D4[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_func_8043CB30_de_800DE254[1] = {
    0x41700000,
};
#endif
