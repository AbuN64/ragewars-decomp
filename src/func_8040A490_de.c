#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Clears the word held in D_80153780. */
extern s32 D_80153780;

void func_8040A490_de(void) {
    D_80153780 = 0;
}
