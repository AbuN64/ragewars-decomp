#include "span_16E000/code_80413728.h"
#include "types.h"

/* Returns bit 1 of the flag byte at offset 1 of a record; func_80413714_de returns bit 0. */
u8 func_80413704_de(u8 *record) {
    return (record[1] >> 1) & 1;
}
