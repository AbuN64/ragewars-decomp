#include "span_16E000/code_80413728.h"
#include "types.h"

/* Stores the three bytes D_80153C75, D_80153C76 and D_80153C77 as entry D_80153C6C of the
   three-byte array D_80153C70 points to. */
extern s32 D_80153C6C;
extern u8 *D_80153C70;

extern u8 D_80153C76;


void func_804140BC_de(void) {
    D_80153C70[D_80153C6C * 3] = D_80153C75;
    D_80153C70[D_80153C6C * 3 + 1] = D_80153C76;
    D_80153C70[D_80153C6C * 3 + 2] = D_80153C77;
}
