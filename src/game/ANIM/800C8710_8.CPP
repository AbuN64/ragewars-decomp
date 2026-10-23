#include "include_asm.h"

#if defined(VERSION_EU)
const unsigned int D_8023EF00_C93D0[2] = {
    0xBF800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
const char rodata_unresolved_800C3618[8] =
    "_t\004.eosT";
#endif

#if defined(VERSION_EU_X)
const unsigned int rodata_unresolved_800C39D8[2] = {
    0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C3998[2] = {
    0x3463FFFF, 0x02A61021,
};
#endif

#if defined(VERSION_DE)
const unsigned int rodata_unresolved_800C36E8[2] = {
    0x0023F858, 0x0023F880,
};
#endif


#if defined(VERSION_US_REV1)
const unsigned int rodata_unresolved_800C87D8[2] = {
    0x3F800000, 0x3F800000,
};
#endif
