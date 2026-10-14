#include "span_16E000/code_80413728.h"
#include "types.h"

/* Copies D_80153C78 into both D_80153C80 and D_80153C60. Three consecutive functions,
   func_804141C0_de to func_80414200_de, have this same body. */
extern s32 D_80153C78;
extern s32 D_80153C80;
extern s32 D_80153C60;

void func_80414200_de(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}
