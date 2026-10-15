#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Orders two records by the unsigned halfword at offset 0x14, returning the difference in the
   shape a sort comparator uses. */


int func_8040F570_de(struct Field_u16_14 *a, struct Field_u16_14 *b) {
    return a->value - b->value;
}
