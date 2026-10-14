#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80245980.h"
/** Clear the word at offset 0x100 in the active object. */
extern char *D_800E2830;




void func_80245A10_de(void) {
    struct Shared_Actor *base = D_800E2830;
    base->weaponFlags = 0;
}
