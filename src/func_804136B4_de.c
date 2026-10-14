#include "span_16E000/code_80413728.h"
#include "types.h"

/* Returns the word at offset 0x18 of a record. */
s32 func_804136B4_de(s32 *record) {
    return record[0x18 / 4];
}
