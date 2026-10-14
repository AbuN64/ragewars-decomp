#include "span_16E000/code_80413728.h"
#include "types.h"

/* Stores the halfword D_80153C76 at index D_80153C6C of the halfword array D_80153C70 points to. */
extern s32 D_80153C6C;
extern u16 *D_80153C70;
extern u16 D_80153C76;

void func_8041406C_de(void) {
    D_80153C70[D_80153C6C] = D_80153C76;
}
