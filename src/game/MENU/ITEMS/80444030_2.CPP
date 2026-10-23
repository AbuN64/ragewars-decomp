#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned char rodata_shared_800EEE18[5] = {
    0x20, 0x25, 0x33, 0x64, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E9FDD[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800EEE1D[3] = {
    0x00, 0x00, 0x00,
};
#endif
