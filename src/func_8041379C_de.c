#include "span_16E000/code_80413728.h"
#include "types.h"

/* Copies record i of the 52-byte table D_800E2B20 into the destination. */


extern struct Format D_800E2B20[];

void func_8041379C_de(s32 index, struct Format *out) {
    *out = D_800E2B20[index];
}
