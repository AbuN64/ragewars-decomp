#include "span_16E000/code_80412270.h"
#include "types.h"

/* Returns the first byte of a record; func_80413608_de, which follows it, reads the same byte. */
u8 func_804135FC_de(u8 *record) {
    return record[0];
}
