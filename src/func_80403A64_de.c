#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80400000.h"
#include "types.h"

/* Returns the first word of what func_8028FDB4_de gives for the object at offset 4 of the structure
   D_800E2830 points to, asked with zero. */


extern struct Field_void_4 *D_800E2830;
extern s32 *func_8028FDB4_de(void *, s32);

s32 func_80403A64_de(void) {
    return *func_8028FDB4_de(D_800E2830->value, 0);
}
