#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Stores 1 in D_80153778 and 0 in D_80153770. */
extern s32 D_80153778;
extern s32 D_80153770;

void func_8040B7F8_de(void) {
    D_80153778 = 1;
    D_80153770 = 0;
}
