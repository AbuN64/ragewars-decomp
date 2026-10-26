#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ANIMATION.H"
#include "TYPES.H"

/* Copies image src into dst when they differ, then fixes dst's pixel rows through Gfx_SwizzleImage when a paletted image has more than 0x800 bytes of pixels or a true-color image more than 0x1000; returns zero. */

typedef struct Image Image;

extern s32 func_80413480_de(Image *dst, Image *src);
extern s32 func_8041369C_de(Image *image);
extern s32 func_804136A8_de(Image *image);
extern void Gfx_SwizzleImage(Image *image);

s32 func_80419640_de(Image *dst, Image *src) {
    s32 palette;
    s32 size;
    s32 fix;

    if (dst != src) {
        func_80413480_de(dst, src);
    }
    src = dst;
    palette = func_8041369C_de(src);
    size = func_804136A8_de(src);
    fix = 0;
    if (palette > 0) {
        fix = size > 0x800;
    }
    if (palette == 0 && size > 0x1000) {
        fix = 1;
    }
    if (fix) {
        Gfx_SwizzleImage(src);
    }
    return 0;
}


void func_804196C8_de(int value) {
    D_800E32F0 = value;
}
