#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Sets the word at offset 0x84 of an object to one. */


void func_80419F18_de(struct StateBlock *object) {
    object->unk84 = 1;
}
