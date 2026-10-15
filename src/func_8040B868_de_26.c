#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Stores two bytes at offsets 0x2C and 0x2D of a record, a pair set together. */


void func_8040F1FC_de(struct Pair2C *record, u8 first, u8 second) {
    record->first = first;
    record->second = second;
}
