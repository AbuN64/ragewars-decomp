#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C5634[3] = {
    0x3162FFFF, 0x00031C00, 0x00621825,
};
#endif
#if defined(VERSION_EU_X)
char rodata_unresolved_800C5634[12] =
    ".ACCLAIM.NET";
#endif
#endif
