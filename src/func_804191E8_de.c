#include "span_16E000/code_804143D8.h"
#include "types.h"

/* Clears the word held in D_800E32E4. */
extern s32 D_800E32E4;

void func_804191E8_de(void) {
    D_800E32E4 = 0;
}
