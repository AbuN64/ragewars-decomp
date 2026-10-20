#include "include_asm.h"

#if defined(VERSION_US)
extern void func_8041B110_de(int id);

int func_80439F10_us(void) { func_8041B110_de(0x3DA); func_8041B110_de(0x3DB); return 0; }
#endif
