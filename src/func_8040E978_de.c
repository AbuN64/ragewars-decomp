#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Stores two halfwords at offsets 0x14 and 0x16 of a record, a pair set together. */


void func_8040E978_de(struct Pair14 *record, s16 first, s16 second) {
    record->first = first;
    record->second = second;
}
