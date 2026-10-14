#include "span_16E000/code_80413728.h"
#include "types.h"

/* Loads the byte at offset D_80153C78 of the buffer D_80153C7C points to into both D_80153C80 and
   D_80153C60. */
extern u8 *D_80153C7C;
extern s32 D_80153C78;
extern s32 D_80153C80;
extern s32 D_80153C60;

void func_80414138_de(void) {
    s32 value = D_80153C7C[D_80153C78];

    D_80153C80 = value;
    D_80153C60 = value;
}
