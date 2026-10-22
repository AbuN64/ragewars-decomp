#include "include_asm.h"

const unsigned int D_auto_rodata_shared_800C6AB0[10] = {
    0x00201650, 0x002015B4, 0x002015BC, 0x002015E4, 0x002015F0, 0x002015FC, 0x00201604, 0x00201628,
    0x00201638, 0x00201648,
};

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C1918);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C1C88);
#endif
