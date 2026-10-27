#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ANIMATION.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_42.H"

/* Copies image src into dst when they differ, then fixes dst's pixel rows through Gfx_SwizzleImage when a paletted image has more than 0x800 bytes of pixels or a true-color image more than 0x1000; returns zero. */

typedef struct Image Image;

extern s32 Frontend_GetImagePaletteByteCount(Image *image);
extern s32 Frontend_GetImagePixelByteCount(Image *image);
extern void Gfx_SwizzleImage(Image *image);

s32 Smp_CopyAndSwizzleImage(Image *dst, Image *src) {
    s32 palette;
    s32 size;
    s32 fix;

    if (dst != src) {
        Frontend_CopyOwnedImage(dst, src);
    }
    src = dst;
    palette = Frontend_GetImagePaletteByteCount(src);
    size = Frontend_GetImagePixelByteCount(src);
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


void Smp_SetImageStateWord(int value) {
    D_800E32F0 = value;
}
