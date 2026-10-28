#include "include_asm.h"

/* AUDIOMGR_INIT_1.CPP */
#if defined(VERSION_US)
char rodata_unresolved_800C3DF8[8] =
    "iMsgT\000\000@";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C41B8[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4178[2] = {
    0x95820000, 0x00021027,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3EC8[2] = {
    0x3F000000, 0x42FE0000,
};
#endif

/* AUDIOMGR_INIT_2.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C8FB8 */
unsigned int D_blob_1eb8152a6d4b206e5713[2] = {
    0x3F800000, 0x3F800000,
};
#endif
