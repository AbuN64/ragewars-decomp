#include "span_16E000/code_80412270.h"
#include "types.h"

/* Returns the halfword at offset 0x2 of a record. It is one of a run of accessors from
   func_80413660_de to func_80413690_de that return the halfwords at offsets 2 to 0xA in turn. */
s16 func_80413660_de(s16 *record) {
    return record[0x2 / 2];
}
