#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80400000.h"
#include "types.h"

/* Returns the byte size of a block holding a 0x30-byte header and a 36-byte record for every entry
   counted at offset 4 of the two lists func_8028FDB4_de returns for an object with zero and with
   two. */


extern struct IntPair *func_8028FDB4_de(void *, s32);

s32 func_80403B70_de(void *object) {
    struct IntPair *first = func_8028FDB4_de(object, 0);
    struct IntPair *second = func_8028FDB4_de(object, 2);
    s32 size = first->field_4 * 36;

    return size + second->field_4 * 36 + 0x30;
}
