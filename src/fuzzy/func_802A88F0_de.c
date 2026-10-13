#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "span_1000/code_802A8A94.h"
#include "common/types_1dc8418c21db.h"
#include "shared/world.h"
#include "shared/func_802453D4_de_closed.h"
#include "span_16E000/code_8043F69C.h"

extern Gfx *D_80110634;
extern u8 D_801377C0[];
extern u8 D_801378C0[];
extern Node80253610 *func_8028BEAC_de(Shared_World *, s32, s32, s32);
extern void func_802AA1AC_de(Node80253610 *, s32, s16, s16, f32, f32, s32);
extern void func_80253754_de(void *, Node80253610 *);

void func_802A88F0_de(u8 *text, f32 x, f32 y, f32 width, f32 height, s32 shadow, s32 alpha, s32 language)
{
    FontStyle *style = &D_801376F8;
    Node80253610 *font;
    s32 special = 0;
    s32 resource;
    u8 ch, next, glyph;
    f32 advance, sx, sy, a, b;

    gDPPipeSync(D_80110634++);
    if (shadow) {
        gDPSetEnvColor(D_80110634++, 0, 0, 0, alpha);
        gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, 255);
        x += style->shadowX * (D_800E28D0 / 284);
        y += style->shadowY * (D_800E28D4 / 222);
    } else {
        gDPSetEnvColor(D_80110634++, style->envR, style->envG, style->envB, alpha);
        gDPSetPrimColor(D_80110634++, 0, 0, style->primR, style->primG, style->primB, 255);
    }
    switch (language) {
    default: case 0: resource = 2; break;
    case 1: resource = 1; special = 1; break;
    case 2: case 3: resource = 6; break;
    case 4: case 5: resource = 5; break;
    case 6: resource = 7; break;
    }
    font = func_8028BEAC_de(&D_8011FE88, resource, 0x10, 1);
    if (font) {
        while (text && (ch = *text) && ch != 10) {
            next = text[1];
            switch (language) {
            default: case 0:
                glyph = D_801378C0[ch];
                switch (D_80147150) {
                case 0: a = 24.0f; break;
                case 1: a = 12.0f; break;
                case 3: a = 6.0f; break;
                case 4: case 5: a = 16.0f; break;
                case 2: case 6: a = 8.0f; break;
                default: a = 1.0f; break;
                }
                switch (D_80147150) {
                case 0: b = 24.0f; break;
                case 1: b = 12.0f; break;
                case 3: b = 6.0f; break;
                case 4: case 5: b = 16.0f; break;
                case 2: case 6: b = 8.0f; break;
                default: b = 1.0f; break;
                }
                advance = func_8044222C_de(ch, next, a, b);
                break;
            case 1:
                glyph = D_801377C0[ch];
                switch (D_80147150) {
                case 0: advance = 24.0f; break;
                case 1: advance = 12.0f; break;
                case 3: advance = 6.0f; break;
                case 4: case 5: advance = 16.0f; break;
                case 2: case 6: advance = 8.0f; break;
                default: advance = 1.0f; break;
                }
                break;
            case 2:
                glyph = D_801377C0[ch];
                switch (D_80147150) {
                case 0: advance = 24.0f; break;
                case 1: advance = 12.0f; break;
                case 3: advance = 6.0f; break;
                case 4: case 5: advance = 16.0f; break;
                case 2: case 6: advance = 8.0f; break;
                default: advance = 1.0f; break;
                }
                break;
            case 3:
                glyph = D_801377C0[ch];
                switch (D_80147150) {
                case 0: advance = 24.0f; break;
                case 1: advance = 12.0f; break;
                case 3: advance = 6.0f; break;
                case 4: case 5: advance = 16.0f; break;
                case 2: case 6: advance = 8.0f; break;
                default: advance = 1.0f; break;
                }
                break;
            case 4:
                glyph = ch;
                if (ch == 255) glyph = 255;
                switch (D_80147150) {
                case 0: advance = 24.0f; break;
                case 1: advance = 12.0f; break;
                case 3: advance = 6.0f; break;
                case 4: case 5: advance = 16.0f; break;
                case 2: case 6: advance = 8.0f; break;
                default: advance = 1.0f; break;
                }
                break;
            case 5:
                glyph = ch;
                if (ch == 255) glyph = 255;
                switch (D_80147150) {
                case 0: advance = 24.0f; break;
                case 1: advance = 12.0f; break;
                case 3: advance = 6.0f; break;
                case 4: case 5: advance = 16.0f; break;
                case 2: case 6: advance = 8.0f; break;
                default: advance = 1.0f; break;
                }
                break;
            case 6:
                glyph = ch;
                if (ch == 255) glyph = 255;
                switch (D_80147150) {
                case 0: advance = 24.0f; break;
                case 1: advance = 12.0f; break;
                case 3: advance = 6.0f; break;
                case 4: case 5: advance = 16.0f; break;
                case 2: case 6: advance = 8.0f; break;
                default: advance = 1.0f; break;
                }
                break;
            }
            sx = width;
            sy = height;
            if (special && (glyph == 0x25 || glyph == 0x2B || glyph == 0x3D)) {
                sx = D_800E28D0 * (1.0f / 284.0f);
                sy = D_800E28D4 * (1.0f / 222.0f);
            }
            if (glyph != 255) {
                func_802AA1AC_de(font, glyph, (s16)x, (s16)y, sx, sy, 1);
            }
            x += advance * sx;
            text++;
        }
        func_80253754_de(0, font);
    }
}
