#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Sets D_80153780 to one; func_8040A490_de clears it. */
extern s32 D_80153780;

void func_8040A47C_de(void) {
    D_80153780 = 1;
}
