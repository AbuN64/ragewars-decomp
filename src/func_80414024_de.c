#include "span_16E000/code_80413728.h"
#include "types.h"

/* Loads the 24-bit big-endian value at index D_80153C60 of the three-byte array D_80153C64 points
   to into D_80153C68. */
extern s32 D_80153C60;
extern u8 *D_80153C64;
extern s32 D_80153C68;

void func_80414024_de(void) {
    D_80153C68 = (D_80153C64[D_80153C60 * 3] << 16) | (D_80153C64[D_80153C60 * 3 + 1] << 8) |
                 D_80153C64[D_80153C60 * 3 + 2];
}
