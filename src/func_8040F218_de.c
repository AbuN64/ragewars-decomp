#include "span_16E000/code_8040F1E0.h"
#include "types.h"

/* Stores four values into the consecutive words at offsets 0x2C to 0x38 of a record. */


void func_8040F218_de(struct QuadRecAt2C *record, s32 first, s32 second, s32 third, s32 fourth) {
    record->values[0] = first;
    record->values[1] = second;
    record->values[2] = third;
    record->values[3] = fourth;
}
