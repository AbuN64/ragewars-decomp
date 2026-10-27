#include "include_asm.h"

const char g_statObjectIndexText[] = "stat object index"
#if defined(VERSION_EU_X)
    "\000\000"
#endif
;

#if defined(VERSION_US)
unsigned short rodata_unresolved_800C3D9E[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU)
unsigned short rodata_unresolved_800C411E[1] = {
    0x0000,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800C3E6E[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800C8F5E[1] = {
    0x0000,
};
#endif
