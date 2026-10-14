#include "span_16E000/code_80412270.h"
#include "types.h"

/* Returns the word in the 52-byte record D_800E2B2C selected by the first byte of a record. */
extern s32 D_800E2B2C[];

s32 func_80413634_de(u8 *record) {
    return D_800E2B2C[record[0] * 13];
}
