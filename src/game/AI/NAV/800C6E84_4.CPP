#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_US)
#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2188[2] = {
    0x8FB10014, 0x8FB00010,
};
#endif
#if defined(VERSION_US)
char rodata_unresolved_800C2188[8] =
    "e\011m_mOri";
#endif
#endif
