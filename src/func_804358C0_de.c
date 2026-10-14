#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Returns the index of the first of four 400-byte records in D_80102B08 whose byte at offset 4
   equals the second argument and whose first word equals the first, or -1 when none does. */


extern struct RecordRecAtD D_80102B08[];

s32 func_804358C0_de(s32 id, s32 kind) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_80102B08[i].kind == kind && D_80102B08[i].id == id) {
            return i;
        }
    }
    return -1;
}
