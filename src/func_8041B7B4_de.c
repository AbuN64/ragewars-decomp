#include "span_16E000/code_8041B020.h"
#include "types.h"

/* Stores a value into entry i of the word array at offset 0x5C of an object; func_8041B7FC_de reads
   the parallel array at offset 0x4C. */


void func_8041B7B4_de(struct SlotsRecAt5CV1 *object, s32 index, s32 value) {
    object->values[index] = value;
}
