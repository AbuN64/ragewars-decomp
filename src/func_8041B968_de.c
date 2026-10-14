#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"

/* Stores a value into the word at offset 0x6C of an object; func_8041CE18_de uses it to set that word
   to one on the object held at offset 4 of the structure D_800E3590 points to. */


void func_8041B968_de(struct Object6C *object, s32 value) {
    object->value = value;
}
