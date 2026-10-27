#include "include_asm.h"

const char g_pakSingleSaveBlockName[18] = "Single Save Block";

#if defined(VERSION_US)
unsigned short rodata_unresolved_800DBA22[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned short rodata_unresolved_800E85B2[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU)
unsigned short rodata_unresolved_800ED3F2[1] = {
    0x0000,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800DCD72[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800E0DA2[1] = {
    0x0000,
};
#endif
