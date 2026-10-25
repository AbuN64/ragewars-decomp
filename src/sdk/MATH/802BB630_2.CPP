#include "include_asm.h"

#if defined(VERSION_US)
const unsigned int D_auto_rodata_func_802B6560_de_800C7738[15] = {
    0xBFC55554, 0xBC83656D, 0x3F8110ED, 0x3804C2A0, 0xBF29F6FF, 0xEEA56814, 0x3EC5DBDF, 0x0E314BFE,
    0x3FD45F30, 0x6DC9C883, 0x400921FB, 0x50000000, 0x3E6110B4, 0x611A6263, 0x00000000,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
char rodata_unresolved_800C7774[12] =
    "audio/reverb";
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_800C7774[1] = {
    0x00000000,
};
#endif
#endif
