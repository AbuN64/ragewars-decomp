#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_ASM("ovl_80400000", func_80444F30_eu);
#endif

#if defined(VERSION_EU)
unsigned char D_auto_func_80444F9C_eu_padding_1BAF9C[4] = { 0x00, 0x00, 0x28, 0x21 };
#endif
