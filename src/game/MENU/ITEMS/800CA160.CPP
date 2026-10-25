#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X)
const char D_8044B7C0_CAD60[37] =
    "CScene__Construct: BLLevelData Index\000";
#endif
#if defined(VERSION_US)
const char D_8044B7C0_CAD60[40] =
    "CScene__Construct: BLLevelData Index\000\000\000\000";
#endif
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C5385[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C5345[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C5095[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned char g_constructBlLevelDataIndex[37] = {
    0x43, 0x53, 0x63, 0x65, 0x6E, 0x65, 0x5F, 0x5F, 0x43, 0x6F, 0x6E, 0x73, 0x74, 0x72, 0x75, 0x63,
    0x74, 0x3A, 0x20, 0x42, 0x4C, 0x4C, 0x65, 0x76, 0x65, 0x6C, 0x44, 0x61, 0x74, 0x61, 0x20, 0x49,
    0x6E, 0x64, 0x65, 0x78, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA185[3] = {
    0x00, 0x00, 0x00,
};
#endif
