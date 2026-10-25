#include "COMMON/FRUSTUM.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/80296FF8_6.H"

/** Clear the global word at VRAM 0x800D2B00. */

void System_ResetTextureCache(void) {
    D_800CD890 = 0;
}


/** Replace the global state word. */
void System_SetTextureEffect(unsigned int value) {
    D_800CD894_de = value;
}
