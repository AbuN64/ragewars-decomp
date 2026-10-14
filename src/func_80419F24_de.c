#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Copies the byte at offset 0x83 of an object into offset 0x10 of the object at 0x78, and clears
   the pending word at 0x84 that func_80419F18_de sets and func_80419F38_de tests. */




void func_80419F24_de(struct SourceRecAt84 *source) {
    struct Resource_func_80419E54_de *target = source->target;
    u8 value = source->value;

    source->pending = 0;
    target->value = value;
}
