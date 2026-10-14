#include "span_16E000/code_80420E90.h"
#include "types.h"

/* Returns the word at offset 0x4 of a record. */
s32 func_80421E60_de(s32 *record) {
    return record[0x4 / 4];
}
