#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Returns the word at offset 0x110 of a record. */
s32 func_8041AD04_de(s32 *record) {
    return record[0x110 / 4];
}
