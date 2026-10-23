#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1AD4[1] = {
    0x00000000,
};
#endif
#if defined(VERSION_US)
char rodata_unresolved_800C1AD4[12] =
    "SwooshVertex";
#endif
#endif
