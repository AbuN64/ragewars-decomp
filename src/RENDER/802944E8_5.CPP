#include "include_asm.h"
#include "COMMON/OBJRECAT26DD8.H"
#include "RENDER/802944E8_5.H"

/** Perform the no-op callback at VRAM 0x80294ABC. */
void func_80294AA8_de(void) {
}

#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_802949A0_us);
#endif
