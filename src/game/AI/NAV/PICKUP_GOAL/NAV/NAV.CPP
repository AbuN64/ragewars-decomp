#include "include_asm.h"

/* 800C1EE8.CPP */
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1EE8[2] = {
    0x0020F01C, 0x0020F028,
};
#endif

#if defined(NON_MATCHING) && defined(VERSION_DE)
unsigned int D_auto_rodata_unresolved_800C1EE8[10] = {
    0x0020F01C, 0x0020F028, 0x0020EFC8, 0x0020F00C, 0x0020F01C, 0x0020F028, 0x0020F034, 0x0020F068,
    0x0020F078, 0x0020F088,
};
#endif

/* 800C6E84_4.CPP */
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

/* 800C6FD8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C6FD8 */
unsigned int D_blob_ce67763740f72ea855ff[2] = {
    0x3F800000, 0x3F800000,
};
#endif
