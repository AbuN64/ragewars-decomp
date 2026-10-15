#ifndef SHARED_TEXT_RENDER_H
#define SHARED_TEXT_RENDER_H
#include "span_16E000/code_8040C780.h"

/* Text widget payload following the common widget bounds and transform. */
typedef struct TextWidget {
    char pad0[0x12];
    u16 flags;
    char pad14[0x18];
    u8 font, style, fontAlt, styleAlt, fontSelected, styleSelected;
    u16 align;
    s32 stringId;
    u8 *text;
} TextWidget;

/* One queued glyph, with resolved position, dimensions and packed colour. */
typedef struct TextSprite {
    s32 color;
    f32 x, y, width, height;
    u16 glyph;
    u16 pad16;
} TextSprite;
/* Arena allocator, also used as a pointer-returning API by func_80419430_de. */
extern void *func_802A15E4_de(s32 size);
#endif
