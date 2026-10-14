#include "span_16E000/code_80411B68.h"
#include "types.h"

/* Clears the word held in D_800E2AC0. */
extern s32 D_800E2AC0;

void func_80411F28_de(void) {
    D_800E2AC0 = 0;
}
