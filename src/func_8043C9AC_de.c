#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A8A94.h"
#include "span_166000/code_80426310.h"
#include "types.h"









extern Triple_func_802683E0_de D_800E5CA0;

extern s32 D_800E28D0;
extern s32 D_800E1E20;

extern func_802077F4_S2 *func_80442DDC_de(void *, s32);

extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_8044208C_de(void *, ItemRecAt20V1 *, void *, Style_func_8043C9AC_de *);

/* Draws the D_800E5CA0 spinner: during the first part of its blink period it fills a two-pixel white bar below the item under the digit its value selects, placed from the item's x by the character width func_80442DDC_de reports scaled to the screen, with the style's alpha, through func_802AA9F4_de and func_802A7DE4_de; then draws the item through func_8044208C_de. */
void func_8043C9AC_de(void *menu, ItemRecAt20V1 *item, void *arg2, Style_func_8043C9AC_de *style) {
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
