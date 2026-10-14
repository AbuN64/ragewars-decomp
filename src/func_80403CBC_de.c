#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Looks up the object at offset 4 of the structure D_800E2830 points to through func_8028FDB4_de
   with zero, then looks up the result again with the argument, and returns that. */


extern struct Field_void_4 *D_800E2830;
extern void *func_8028FDB4_de(void *, s32);

void *func_80403CBC_de(s32 key) {
    return func_8028FDB4_de(func_8028FDB4_de(D_800E2830->value, 0), key);
}
