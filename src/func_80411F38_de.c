#include "span_16E000/code_80411B68.h"
#include "types.h"

/* Stores its argument in D_800E2AC4; func_80411F28_de, before it, clears D_800E2AC0. */
extern s32 D_800E2AC4;

void func_80411F38_de(s32 value) {
    D_800E2AC4 = value;
}
