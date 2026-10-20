#include "include_asm.h"

#if defined(VERSION_EU_X)
extern void func_8041B110_de(int id);

int func_80429C50_eu_x(void) { func_8041B110_de(0x1DD); func_8041B110_de(0x1DE); return 0; }
#endif

#if defined(VERSION_EU_X)
INCLUDE_ASM("ovl_80400000", func_80429C78_eu_x);
#endif
