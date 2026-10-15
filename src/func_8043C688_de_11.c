#include "span_166000/code_80426310.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"

extern s32 D_800E28D0;

extern s32 D_800E1E20;

extern func_802077F4_S2 *func_80442DDC_de(void *, s32);

extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

extern void func_8044208C_de(void *, ItemRecAt20V1 *, void *, Style_func_8043C9AC_de *);

/* Steps the menu spinner in D_800E5CA0: advances its repeat timer by D_800D2988, wrapping at the second entry of D_800E2280, and while the menu is active (state 2) decrements its value above zero when func_80264388_de reports the decrease input, or else increments it below its maximum when func_802643A0_de reports the increase input, restarting the timer on a change. Returns zero. */






extern f32 D_800D2988;

extern f32 D_800E2280[];

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif

/* Shifts the input history, appends the current byte, and advances the history counters. */





extern s32 D_80154030;

/* Checks whether the input matches the indexed, XOR-masked reference string. */


s32 func_802BD400_de(u8 *);

extern u8 D_800E5CAC[0x64];

/* Draws the D_800E5CA0 spinner: during the first part of its blink period it fills a two-pixel white bar below the item under the digit its value selects, placed from the item's x by the character width func_80442DDC_de reports scaled to the screen, with the style's alpha, through func_802AA9F4_de and func_802A7DE4_de; then draws the item through func_8044208C_de. */
void func_8043C9AC_de(void *menu, ItemRecAt20V1 *item, void *arg2, Style_func_8043C9AC_de *style) {
    extern Triple_func_802683E0_de D_800E5CA0;
    f32 width;
    f32 alpha;
    s32 x;
    unsigned int bits;

    if (D_800E5CA0.y <= (6.0f)) {
        width = func_80442DDC_de(menu, 0)->unk4 * (f32)D_800E28D0 * (0.0035211266949772835f);
        x = (f32)item->x + (f32)D_800E5CA0.x * width;
        D_800E1E20 = -1;
        alpha = style->alpha * (style->fade * (128.0f));
        func_802AA9F4_de();
        func_802A7DE4_de(x, item->y, (f32)x + width, item->y + 2, 0, 0, 0xFF, 0xFF, 0xFF,
                      (u8)(bits = !((2147483648.0f) <= alpha) ? (s32)alpha : (bits = (s32)(alpha - (2147483648.0f))) | 0x80000000));
    }
    func_8044208C_de(menu, item, arg2, style);
}

s32 func_8043CB30_de(void *unused, MenuRecAt20V4 *menu) {
    extern Triple_func_802683E0_de D_800E5CA0;
    f32 t;

    t = D_800E5CA0.y + D_800D2988;
    D_800E5CA0.y = t;
    if (t >= D_800E2280[1]) {
        D_800E5CA0.y = t - D_800E2280[1];
    }
    if (menu->state == 2) {
        if (((s32 (*)(s32))func_80264388_de)(menu->input) != 0 && D_800E5CA0.x > 0) {
            D_800E5CA0.x--;
            D_800E5CA0.y = 0.0f;
        } else if (((s32 (*)(s32))func_802643A0_de)(menu->input) != 0) {
            if (D_800E5CA0.x < D_800E5CA0.z) {
                D_800E5CA0.x++;
                D_800E5CA0.y = 0.0f;
            }
        }
    }
    return 0;
}

/* Does nothing and returns 0. */

s32 func_8043CC08_de(void) {
    return 0;
}

s32 func_8043CC10_de(ObjRecAt14V2 *arg0) {
    extern InputHistory D_800E5CA0;
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
        *arg0->unk14[D_80152789];
#else
        **arg0->unk14;
#endif
    count = D_800E5CA0.count + 1;
    D_800E5CA0.value++;
    D_800E5CA0.count = count;
    D_800E5CA0.text[count] = 0;
    return 0;
}

s32 func_8043CCD0_de(void) {
    extern Shared_Entry D_800E5CA0;
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

s32 func_8043CD64_de(u8 *arg0) {
    /* FAKEMATCH: retain the input pointer across length and byte-check calls. */
    u8 *input = arg0;
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
