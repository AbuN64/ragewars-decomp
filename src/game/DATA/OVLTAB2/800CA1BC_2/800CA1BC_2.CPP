#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const char s_gamePersistentDataText[24] =
    "game persistent data\000\000\000\000";
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const char s_gamePersistentDataText[21] =
    "game persistent data\000";
#endif
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C5011[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C53D1[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C5391[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned char g_gamePersistentData[21] = {
    0x67, 0x61, 0x6D, 0x65, 0x20, 0x70, 0x65, 0x72, 0x73, 0x69, 0x73, 0x74, 0x65, 0x6E, 0x74, 0x20,
    0x64, 0x61, 0x74, 0x61, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA1D1[3] = {
    0x00, 0x00, 0x00,
};
#endif
