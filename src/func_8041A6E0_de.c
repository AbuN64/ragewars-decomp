#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Returns the word at offset 0x50 of a record. */
s32 func_8041A6E0_de(s32 *record) {
    return record[0x50 / 4];
}
