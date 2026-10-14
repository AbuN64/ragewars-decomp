#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80277444.h"
#include "types.h"

/* Clears bits 0x2000 and 0x100 of the flag word at offset 0x100 of an object. */


void func_80278F68_de(struct Actor_func_8024A7A0_de *object) {
    object->flags &= ~0x2000;
    object->flags &= ~0x100;
}
