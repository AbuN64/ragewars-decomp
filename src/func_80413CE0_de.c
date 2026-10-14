#include "span_16E000/code_80413728.h"
#include "types.h"
/* Writes a 0xAARRGGBB colour to the pixel at index: splits the colour into channels (forcing alpha
   to 0xFF when the format has no alpha mask), shifts each channel by the format's signed shift
   (a negative shift scales down) and masks it into place, then stores the index and the packed
   value for the format's store hook D_80153CD4 and calls it. */

extern s32 D_80153C6C;
extern u32 D_80153C74;
extern u32 D_8014DA10;
extern u32 D_8014DA14;
extern u32 D_8014DA18;
extern u32 D_8014DA1C;




extern void (*D_80153CD4)(void);

void func_80413CE0_de(s32 index, u32 color) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (D_8014DA1C == 0) {
        a = 0xFF;
    }
    if (D_8014DA30 < 0) {
        r = (r >> -D_8014DA30) & D_8014DA10;
    } else {
        r = (r << D_8014DA30) & D_8014DA10;
    }
    if (D_8014DA34 < 0) {
        g = (g >> -D_8014DA34) & D_8014DA14;
    } else {
        g = (g << D_8014DA34) & D_8014DA14;
    }
    if (D_8014DA38 < 0) {
        b = (b >> -D_8014DA38) & D_8014DA18;
    } else {
        b = (b << D_8014DA38) & D_8014DA18;
    }
    if (D_8014DA3C < 0) {
        a = (a >> -D_8014DA3C) & D_8014DA1C;
    } else {
        a = (a << D_8014DA3C) & D_8014DA1C;
    }
    D_80153C6C = index;
    D_80153C74 = r | g | b | a;
    D_80153CD4();
}
