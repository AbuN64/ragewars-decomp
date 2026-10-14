#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80400000.h"
#include "types.h"

/* Calls func_8028FDB4_de on the object at offset 4 of the structure D_800E2830 points to, with 1. */


extern struct Field_void_4 *D_800E2830;
extern void *func_8028FDB4_de(void *, s32);

void *func_80403ADC_de(void) {
    return func_8028FDB4_de(D_800E2830->value, 1);
}
