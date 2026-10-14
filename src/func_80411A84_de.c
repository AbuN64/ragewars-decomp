#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Returns the halfword at offset 0xA of entry i in the 28-byte record table D_80153C10 points
   to; func_80411A84_de and func_80411AA8_de read offsets 0xA and 0xC. */


extern struct RecordRecAtCV4 *D_80153C10;

s16 func_80411A84_de(s32 index) {
    return D_80153C10[index].a;
}
