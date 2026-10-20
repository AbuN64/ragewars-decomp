#include "include_asm.h"

#if defined(VERSION_EU_X)
extern void func_8041B110_de(int id);

int func_8043AD30_eu_x(void) { func_8041B110_de(0x3DE); func_8041B110_de(0x3DF); return 0; }
#endif
