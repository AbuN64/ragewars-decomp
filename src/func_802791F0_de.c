#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80279208.h"



/** Set flag 0x10000 in the word at offset 0x100. */
void func_802791F0_de(void *object) {
    Shared_Actor *actor = object;
    actor->weaponFlags |= 0x10000;
}
