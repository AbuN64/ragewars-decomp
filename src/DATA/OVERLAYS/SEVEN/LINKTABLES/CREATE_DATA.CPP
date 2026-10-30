#include "TYPES.H"

#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
#if defined(VERSION_DE)
s32 g_createDataZeroWords = 0;
#endif
#if defined(VERSION_EU)
s32 g_createDataZeroWords = 0;
#endif
#if defined(VERSION_EU_X)
s32 g_createDataZeroWords = 0;
#endif
#if defined(VERSION_US)
s32 g_createDataZeroWords = 0;
#endif
#if defined(VERSION_US_REV1)
s32 g_createDataZeroWords = 0;
#endif

#if defined(VERSION_US)
char g_createDataTextFragment_us[28] =
    "REBORN_PLANT\000\000\000\000LAGequR\000\000\365\024\000";
#endif

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
unsigned short g_createDataOffsetTable_eu_x[14] = {
    0x8000, 0x0000, 0x0004, 0x0008, 0x000C, 0x0012, 0x0000, 0x0000, 0x002C, 0x0035, 0x003F, 0x004B,
    0x0059, 0x0069,
};
#endif
#endif

#if defined(VERSION_EU)
char g_createDataTextFragment_eu[28] =
    "mantids\000warp\000\000\000\000rimagen's li";
#endif

#if defined(VERSION_DE)
float g_createDataUnitRangeWords_de[7] = {
    0.999999f, -0.999999f, 1.0f, 0.0f, 0.0f, 0.0f,
    0.0f,
};
#endif
