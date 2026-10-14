#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025C544.h"
#include "types.h"

/* Initialises a resource record with the resource, -1 at 4 and 0xC, zero at 8 and 0x14, 0x40 at 0x18, and at 0x1C the halfword func_802B2510_de returns for func_80258D40_de's result on the stored resource and D_800D0D78. Adapted from func_80205694_de with the two calls replaced by field stores and a nested call pair whose first argument is read back from the record. */


extern char D_800D0D78[];
extern void *func_80258D40_de(s32);
extern s16 func_802B2510_de(void *, void *);

void func_8025D158_de(struct Shape_typemap_110 *record, s32 resource) {
    record->field_0 = resource;
    record->field_4 = -1;
    record->field_C = -1;
    record->field_8 = 0;
    record->field_14 = 0;
    record->field_18 = 0x40;
    record->field_1C = func_802B2510_de(func_80258D40_de(record->field_0), D_800D0D78);
}
