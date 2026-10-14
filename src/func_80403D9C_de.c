#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"

/* Walks three lookups through func_8028FDB4_de from the object at offset 4 of the structure
   D_800E2830 points to: first with zero, then with the argument, and returns the third lookup, with 1. */


extern struct Field_void_4 *D_800E2830;
extern void *func_8028FDB4_de(void *, s32);

void *func_80403D9C_de(s32 key) {
    return func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->value, 0), key), 1);
}
