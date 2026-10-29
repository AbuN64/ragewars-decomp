#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_createDataZeroWords[1] = {
    0x00000000,
};

#if defined(VERSION_US)
char data_unresolved_800D3044[28] =
    "REBORN_PLANT\000\000\000\000LAGequR\000\000\365\024\000";
#endif

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
unsigned short data_unresolved_800DFBD4[14] = {
    0x8000, 0x0000, 0x0004, 0x0008, 0x000C, 0x0012, 0x0000, 0x0000, 0x002C, 0x0035, 0x003F, 0x004B,
    0x0059, 0x0069,
};
#endif
#endif

#if defined(VERSION_EU)
char data_unresolved_800E4A14[28] =
    "mantids\000warp\000\000\000\000rimagen's li";
#endif

#if defined(VERSION_DE)
unsigned int data_unresolved_800D4394[7] = {
    0x3F7FFFEF, 0xBF7FFFEF, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
#endif
