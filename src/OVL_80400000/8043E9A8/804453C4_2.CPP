#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A8A94.h"
#include "span_16E000/code_804453C4.h"
#include "TYPES.H"

/* Draws a menu spinner: during the first half of its blink period (the timer of its D_800E63C0 entry up to the float after D_800E2810) it fills a two-pixel white bar under the digit its value selects, placed from the item's x at 0x14 by the character width func_80442DDC_de reports scaled to the screen, with the style's alpha at 0x30 and 0x34, through func_802AA9F4_de and func_802A7DE4_de; then draws the item through func_8044208C_de. */








extern Spinner D_800E63C0[];



extern s32 func_8022A5A0_de(char *, s32);
extern func_802077F4_S2 *func_80442DDC_de(void *, s32);

extern void func_8044208C_de(void *, ItemRecAt20V1 *, void *, Style_func_80445BC0_de *);

void func_80445BC0_de(void *menu, ItemRecAt20V1 *item, void *arg2, Style_func_80445BC0_de *style) {
    s32 i;
    f32 width;
    f32 alpha;
    s32 x;
    unsigned int bits;

    i = func_8022A5A0_de(&D_80145040, style->id);
    if (D_800E63C0[i].timer <= *(&D_800E2810 + 1)) {
        width = func_80442DDC_de(menu, 0)->unk4 * (f32)D_800E28D0 * D_800DE7C8_de;
        x = (f32)item->x + (f32)D_800E63C0[i].value * width;
        D_800E1E20 = -1;
        alpha = style->alpha * (style->fade * (64.0f));
        func_802AA9F4_de();
        func_802A7DE4_de(x, item->y - 2, (f32)x + width, item->y, 0, 0, 0xFF, 0xFF, 0xFF,
                      (u8)(bits = !((2147483648.0f) <= alpha) ? (s32)alpha : (bits = (s32)(alpha - (2147483648.0f))) | 0x80000000));
    }
    func_8044208C_de(menu, item, arg2, style);
}
