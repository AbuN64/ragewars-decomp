#include "include_asm.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
INCLUDE_ASM("ovl_80400000", func_804476B8_de);
#endif

#if defined(VERSION_EU)
unsigned char D_auto_func_80447818_de_padding_1BEA78[8] = { 0x8C, 0x82, 0x01, 0xCC, 0x14, 0x40, 0x00, 0x03 };
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", func_80447818_de_padding_1AD818);
#endif
