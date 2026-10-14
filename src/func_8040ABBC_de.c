#include "span_16E000/code_8040A83C.h"
#include "types.h"

/* Stores 9 in the state word D_80153788 and one in D_80153758; func_8040ABA0_de stores 9 and zero. */
extern s32 D_80153788;
extern s32 D_80153758;

void func_8040ABBC_de(void) {
    D_80153788 = 9;
    D_80153758 = 1;
}
