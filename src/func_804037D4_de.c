#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80400000.h"
#include "types.h"

/* Sets the word at offset 0xB4 of the object D_800E2830 points to. */


extern struct Shared_Effect *D_800E2830;

void func_804037D4_de(void) {
    D_800E2830->state = 1;
}
