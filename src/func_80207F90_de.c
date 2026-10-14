#include "common/types_8fd754e1e915.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80207ABC.h"

/** Set flags 0x2100 in the word at offset 0x100. */
void func_80207F90_de(void *object) {
    Player *arg0 = object;
    arg0->weaponFlags |= 0x2100;
}
