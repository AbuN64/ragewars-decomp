#include "span_16E000/code_80444030.h"
#include "types.h"

/* Clears the word held in D_80154100. */
extern s32 D_80154100;

void func_804441E4_de(void) {
    D_80154100 = 0;
}
