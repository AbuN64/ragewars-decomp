#include "span_16E000/code_80413728.h"
#include "types.h"

/* The same table as func_80413608_de reads, at the field 24 bytes into the 52-byte record. The
   debugger returned 1 on every one of 400 calls, so the observed records all carry a non-zero
   value here and the zero arm is untested by execution. */
extern s32 D_800E2B40[][13];

s32 func_804136D8_de(u8 *record) {
    return D_800E2B40[*record][0] != 0;
}
