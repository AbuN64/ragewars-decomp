#include "span_16E000/code_80412270.h"
#include "types.h"
/* Copies image src into dst: releases dst's owned pixel data (flag 1) and palette (flag 2, when it
   has entries), clears it and copies src's header, drops a palette pointer without entries, marks
   the copies owned, then allocates and copies the pixel data (size from func_804136A8_de) and, when
   src has a palette, the palette (size from func_8041369C_de). Returns 1 when an allocation fails,
   leaving dst cleared, otherwise 0. */



extern void func_802547E4_de(void *p);
extern void func_802A0748_de(void *p, s32 c, s32 n);
extern s32 func_804136A8_de(Image_func_80413480_de *image);
extern s32 func_8041369C_de(Image_func_80413480_de *image);
extern void *func_8025305C_de(s32 size);
extern void func_802A0724_de(void *dst, void *src, s32 n);

s32 func_80413480_de(Image_func_80413480_de *dst, Image_func_80413480_de *src) {
    s32 size;

    if (dst->flags & 1) {
        func_802547E4_de(dst->pixels);
    }
    if ((dst->flags & 2) && dst->paletteCount > 0) {
        func_802547E4_de(dst->palette);
    }
    func_802A0748_de(dst, 0, 0x20);
    *dst = *src;
    if (dst->paletteCount == 0) {
        dst->palette = 0;
    }
    dst->flags = 1;
    if (dst->palette != 0) {
        dst->flags = 3;
    }
    size = func_804136A8_de(src);
    if ((dst->pixels = func_8025305C_de(size)) == 0) {
        return 1;
    }
    func_802A0724_de(dst->pixels, src->pixels, size);
    if (src->paletteCount != 0) {
        size = func_8041369C_de(src);
        if ((dst->palette = func_8025305C_de(size)) == 0) {
            func_802547E4_de(dst->pixels);
            func_802A0748_de(dst, 0, 0x20);
            return 1;
        }
        func_802A0724_de(dst->palette, src->palette, size);
    }
    return 0;
}
