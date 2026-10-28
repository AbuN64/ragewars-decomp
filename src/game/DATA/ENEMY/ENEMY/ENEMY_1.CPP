#include "include_asm.h"

#if defined(VERSION_US)
unsigned int rodata_unresolved_800CD2EC[1] = {
    0x5F454D41,
};
#endif

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
extern char D_auto_rodata_unresolved_800C65C8[];
unsigned int rodata_unresolved_800CE98C[1] = {
    (unsigned int)D_auto_rodata_unresolved_800C65C8 + 0x18,
};
#endif
#endif

#if defined(VERSION_EU)
#if defined(VERSION_EU)
unsigned short rodata_unresolved_800CDFBC[2] = {
    0x8011, 0x04F8,
};
#endif
#endif
