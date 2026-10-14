#include "span_1000/code_802646F4.h"
/** Clear the global word at VRAM 0x8010FC40. */
extern int D_8010BC40;

void func_80264B7C_de(void) {
    D_8010BC40 = 0;
}
