#include "span_16E000/code_80413728.h"
#include "types.h"
/* Reads the pixel at index as a 0xAARRGGBB colour: stores the index for the current format's fetch
   hook D_80153CD0, then extracts each channel of the fetched value with the format's channel mask
   and signed shift (a negative shift scales up) and packs alpha, red, green and blue, using 0xFF
   for alpha when the format has no alpha mask. */

extern s32 D_80153C60;
extern u32 D_80153C68;
extern u32 D_8014DA00;
extern u32 D_8014DA04;
extern u32 D_8014DA08;
extern u32 D_8014DA0C;




extern void (*D_80153CD0)(void);

u32 func_804139E0_de(s32 index) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    D_80153C60 = index;
    D_80153CD0();
    if (D_8014DA20 < 0) {
        r = (D_80153C68 & D_8014DA00) << -D_8014DA20;
    } else {
        r = (D_80153C68 & D_8014DA00) >> D_8014DA20;
    }
    if (D_8014DA24 < 0) {
        g = (D_80153C68 & D_8014DA04) << -D_8014DA24;
    } else {
        g = (D_80153C68 & D_8014DA04) >> D_8014DA24;
    }
    if (D_8014DA28 < 0) {
        b = (D_80153C68 & D_8014DA08) << -D_8014DA28;
    } else {
        b = (D_80153C68 & D_8014DA08) >> D_8014DA28;
    }
    if (D_8014DA2C < 0) {
        a = (D_80153C68 & D_8014DA0C) << -D_8014DA2C;
    } else {
        a = (D_80153C68 & D_8014DA0C) >> D_8014DA2C;
    }
    if (D_8014DA0C == 0) {
        a = 0xFF;
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}
