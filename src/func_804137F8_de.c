#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "types.h"
/* Reads the pixel at (x, y) of the current image D_80153D54 as a 0xAARRGGBB colour: seeks to
   x + y * width through the format's seek hook D_80153CD8, fetches through D_80153CD0 and converts
   the value with the format's channel masks and shifts like func_804139E0_de. */



extern func_8022BECC_S2 *D_80153D54;
extern s32 D_80153C78;
extern void (*D_80153CD8)(s32 offset);
extern u32 D_80153C68;
extern u32 D_8014DA00;
extern u32 D_8014DA04;
extern u32 D_8014DA08;
extern u32 D_8014DA0C;




extern void (*D_80153CD0)(void);

u32 func_804137F8_de(s32 x, s32 y) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    D_80153C78 = x + y * D_80153D54->unk8;
    D_80153CD8(D_80153C78);
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
