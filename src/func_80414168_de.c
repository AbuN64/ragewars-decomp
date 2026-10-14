#include "span_16E000/code_80413728.h"
#include "types.h"

/* Reads nibble D_80153C78 of the packed array D_80153C7C points to, the low nibble for odd indices
   and the high one for even, into both D_80153C80 and D_80153C60. */
extern s32 D_80153C78;
extern u8 *D_80153C7C;
extern s32 D_80153C80;
extern s32 D_80153C60;

void func_80414168_de(void) {
    s32 index = D_80153C78;
    s32 value;

    if (index & 1) {
        value = D_80153C7C[index >> 1] & 0xF;
    } else {
        value = D_80153C7C[index >> 1] >> 4;
    }
    D_80153C80 = value;
    D_80153C60 = value;
}
