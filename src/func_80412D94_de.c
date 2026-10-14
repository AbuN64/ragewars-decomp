#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80412270.h"
#include "types.h"
/* Converts a packed pixel value from format `from` to format `to` of the format table D_800E2B20:
   decodes the value to 0xAARRGGBB with the source format's channel masks and signed shifts, splits
   it into channels and re-encodes them with the destination format's shifts and masks. */



extern PixelFormat D_800E2B20[];

static inline u32 decode(u32 value, PixelFormat *format) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    if (format->shift[0] < 0) {
        r = (value & format->mask[0]) << -format->shift[0];
    } else {
        r = (value & format->mask[0]) >> format->shift[0];
    }
    if (format->shift[1] < 0) {
        g = (value & format->mask[1]) << -format->shift[1];
    } else {
        g = (value & format->mask[1]) >> format->shift[1];
    }
    if (format->shift[2] < 0) {
        b = (value & format->mask[2]) << -format->shift[2];
    } else {
        b = (value & format->mask[2]) >> format->shift[2];
    }
    if (format->shift[3] < 0) {
        a = (value & format->mask[3]) << -format->shift[3];
    } else {
        a = (value & format->mask[3]) >> format->shift[3];
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}

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

u32 func_80412D94_de(u32 value, s32 from, s32 to) {
    return encode(decode(value, &D_800E2B20[from]), &D_800E2B20[to]);
}
