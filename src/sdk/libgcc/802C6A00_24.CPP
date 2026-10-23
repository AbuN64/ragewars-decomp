#include "include_asm.h"

#define L_cmpdi2
#include "libgcc2.inc.c"

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_802C1B58[2] = {
    0x41F00000, 0x3F7D70A4,
};
#endif
