#include "COMMON/FRUSTUM.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/80296FF8_6.H"

/** Clear the global word at VRAM 0x800D2B00. */

void func_80295FF4_de(void) {
    D_800CD890 = 0;
}


/** Replace the global state word. */
void func_80296004_de(unsigned int value) {
    D_800CD894_de = value;
}
