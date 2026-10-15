#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Copies image src into dst when they differ, then fixes dst's pixel rows through func_80419490_de when a paletted image has more than 0x800 bytes of pixels or a true-color image more than 0x1000; returns zero. */

typedef struct Image Image;

extern s32 func_80413480_de(Image *dst, Image *src);
extern s32 func_8041369C_de(Image *image);
extern s32 func_804136A8_de(Image *image);
extern void func_80419490_de(Image *image);

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
        func_80419490_de(src);
    }
    return 0;
}

extern int D_800E32F0;

void func_804196C8_de(int value) {
    D_800E32F0 = value;
}
