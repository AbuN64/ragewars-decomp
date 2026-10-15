#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80290980.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"
/* Draws the scrolling text lines from the current line index, fading each in with alpha sixteen times its distance below the top edge (capped at 255) and spacing lines ten 222ths of the screen height apart until past the bottom; the top edge is a zero-valued local, which keeps 0.0f in one saved register as the cartridge does. */





extern void func_802AAB7C_de(char *, f32, f32, f32, f32, s32, s32, s32);



void func_80290E6C_de(void) {
    s32 line;
    f32 y;
    char *text;
    f32 fade;
    s32 alpha;
    f32 top;

    top = 0.0f;
    line = D_8011B9F0;
    y = D_80146CB8;
    func_802A84F8_de();
    func_802A8800_de();
    func_802AAB68_de(1.0f, 1.0f);
    do {
        #if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = D_800D3E14_de[D_801462C8.language][line];
#else
        text = D_800D3E14_de[0][line];
#endif
        if (text != 0) {
            fade = top;
            if (!(y < top)) {
                if (!(16.0f < y)) {
                    if (!(y < top)) {
                        fade = y * 16.0f;
                    }
                } else {
                    fade = 256.0f;
                }
            }
            if (fade > 255.0f) {
                fade = 255.0f;
            }
            alpha = fade;
            func_802AAB3C_de(0xFF, 0xFF, 0xFF, alpha, alpha, alpha);
            if (y >= top) {
                func_802AAB7C_de(text, (f32)(D_800E28D0 * 14 / 284), (f32)(s32)y,
                              D_800E28D0 * 0.0028169013f, D_800E28D4 * 0.0045045046f, 1, alpha,
                              D_80147150);
            }
            line++;
        }
        y += D_800E28D4 * 0.045045048f;
    } while (y <= D_800E28D4);
}
