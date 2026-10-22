#include "include_asm.h"
#include "COMMON/NAME.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_func_8043F52C_de_800E2460);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", func_8043F52C_de);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
u32 func_80265350_de(void);
int func_802934F8_de(void);
u8 *func_8043F290(TextBoundsText *);
f32 func_804422F0_de(u8 *, f32, f32);
void *func_80442A58_de(s8 *);
extern s32 D_800E28D4;
extern s32 D_800E28D0;
extern f32 D_800DE448;
extern f32 D_800E247C;
extern f32 D_800DE450_de;
extern f32 D_800E2484;
extern f32 D_800DE458;
extern f32 D_800E248C;
extern TextBoundsFont D_800E1E24_de[];

static __inline__ TextBoundsFont *textBoundsFont(TextBoundsText *text) {
    s32 style = 0;
    switch ((u32)text->flags & 0x3FE0) {
    case 0x20: style = 0; break;
    case 0x40: style = 1; break;
    case 0x80: style = 2; break;
    case 0x100: style = 3; break;
    case 0x200: style = 4; break;
    case 0x400: style = 5; break;
    case 0x800: style = 6; break;
    case 0x1000: style = 7; break;
    case 0x2000: style = 8; break;
    default: style = 0; break;
    }
    return &D_800E1E24_de[style];
}

/* Measures a text item into its metrics: size by kind (glyph run, image, three-part composite, box), then the scaled screen
 * rectangle from the item position (284 x 222 virtual screen). */
void func_8043F52C_de(TextBoundsText *text, TextBoundsMetrics *metrics) {
    TextBoundsText part;
    TextBoundsMetrics first, second, third;
    TextBoundsData *data;
    TextBoundsFont *font;
    TextBoundsRecord23 *box;
    u8 *string;
    s32 count, width;
    f32 size, w, boxW, boxH, sx, sy, x, y;

    data = func_80442A58_de(text->descriptor->unk_44);
    metrics->scaleY = D_800DE428;
    metrics->scaleX = D_800DE428;
    switch (text->mode) {
    case 0:
    case 5:
        font = textBoundsFont(text);
        if (font->kind == 0) {
            size = font->width;
            if (text->mode == 5) {
                string = func_8043F290(text);
            } else {
                string = ((u8 **)text->text)[0];
            }
            w = func_804422F0_de(string, size, size);
        } else {
            count = 0;
            if (text->mode == 5) {
                string = func_8043F290(text);
            } else {
                string = ((u8 **)text->text)[0];
            }
            while (string != 0 && *string != 0 && *string != '\n') {
                string++;
                count++;
            }
            w = count * font->width;
        }
        metrics->width = w;
        if (text->flags & 0x08000000) {
            metrics->height = D_800E28D4 * D_800DE448;
        } else if (font->kind == 2 && D_800E28D4 >= 223) {
            metrics->height = (font->height + D_800E247C) * D_800E28D4 * D_800DE450_de;
        } else {
            metrics->height = font->height * D_800E28D4 * D_800DE450_de;
        }
        metrics->width = metrics->width * D_800E28D0 / 284;
        break;
    case 4:
        font = textBoundsFont(text);
        metrics->width = font->width;
        metrics->height = font->height * D_800E28D4 * D_800E2484;
        break;
    case 1:
        if ((func_802934F8_de() != 0 && (text->flags & 0x40000000)) ||
            (D_801462E5 != 0 && text->flags < 0 && func_80265350_de() == 0x400000)) {
            metrics->width = 284;
            metrics->height = 222;
        } else {
            func_802AA950_de((s32)text->text, 0, &metrics->width, &metrics->height);
        }
        if ((text->flags & 0x10000000) && (boxW = metrics->width) != 0.0f && (boxH = metrics->height) != 0.0f) {
            sx = data->unk_29C / boxW;
            sy = data->unk_2A0 / boxH;
        } else {
            sx = D_800E28D0 * D_800DE458;
            sy = D_800E28D4 * D_800E248C;
        }
        metrics->scaleX = sx;
        metrics->scaleY = sy;
        break;
    case 2:
        first = *metrics;
        part = *text;
        part.mode = 0;
        func_8043F52C_de(&part, &first);
        second = *metrics;
        part = *text;
        part.mode = 1;
        part.text = 0;
        func_8043F52C_de(&part, &second);
        third = *metrics;
        part = *text;
        part.mode = 1;
        part.text = 0;
        func_8043F52C_de(&part, &third);
        width = second.width + third.width;
        if (width < first.width) {
            width = first.width;
        }
        metrics->width = width;
        metrics->height = first.height + second.height + (third.height - second.height) / 2;
        break;
    case 3:
        box = text->text;
        metrics->width = box->unk_24 * data->unk_29C / D_800E28D0;
        metrics->height = box->unk_28 * data->unk_2A0 / D_800E28D4;
        break;
    default:
        metrics->width = 1;
        metrics->height = 1;
        break;
    }
    x = text->x * D_800E28D0 / 284;
    if (!(text->flags & 0x8000)) {
        if (text->flags & 0x4000) {
            metrics->left = metrics->right + x;
        } else {
            metrics->left = x;
        }
    }
    metrics->right = metrics->left + metrics->width * metrics->scaleX;
    y = text->y * D_800E28D4 / 222;
    if (!(text->flags & 0x20000)) {
        if (text->flags & 0x10000) {
            metrics->top = metrics->bottom + y;
        } else {
            metrics->top = y;
        }
    }
    metrics->bottom = metrics->top + metrics->height * metrics->scaleY;
}
#endif
