#include "span_1000/code_80296014.h"
#include "common/unused.h"

/** Clear the global word at VRAM 0x800D2B00. */

void func_80295FF4_de(void) {
    D_800CD890 = 0;
}


/** Replace the global state word. */
void func_80296004_de(unsigned int value) {
    D_800CD894_de = value;
}
