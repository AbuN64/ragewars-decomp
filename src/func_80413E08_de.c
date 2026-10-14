#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "types.h"
/* Encodes an 0xAARRGGBB color into a packed pixel value of entry `format` of the format table D_800E2B20, shifting each channel by its signed shift and masking it. */



extern PixelFormat D_800E2B20[];

static inline u32 encode(u32 color, PixelFormat *format) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (format->shift[0] < 0) {
        r = (r >> -format->shift[0]) & format->mask[0];
    } else {
        r = (r << format->shift[0]) & format->mask[0];
    }
    if (format->shift[1] < 0) {
        g = (g >> -format->shift[1]) & format->mask[1];
    } else {
        g = (g << format->shift[1]) & format->mask[1];
    }
    if (format->shift[2] < 0) {
        b = (b >> -format->shift[2]) & format->mask[2];
    } else {
        b = (b << format->shift[2]) & format->mask[2];
    }
    if (format->shift[3] < 0) {
        a = (a >> -format->shift[3]) & format->mask[3];
    } else {
        a = (a << format->shift[3]) & format->mask[3];
    }
    return r | g | b | a;
}

u32 func_80413E08_de(u32 color, s32 format) {
    return encode(color, &D_800E2B20[format]);
}
