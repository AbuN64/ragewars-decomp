#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Sets or clears bit 1 of the flag halfword at offset 0x12 of a record according to the second
   argument. */


void func_8040E900_de(struct Widget_func_8040E67C_de *record, int enable) {
    if (enable) {
        record->flags |= 1;
    } else {
        record->flags &= ~1;
    }
}
