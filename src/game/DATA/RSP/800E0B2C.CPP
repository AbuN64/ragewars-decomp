#include "include_asm.h"

const char g_cinemaDirectoryText[17] = {
    0x43, 0x69, 0x6E, 0x65, 0x6D, 0x61, 0x20, 0x44, 0x69, 0x72, 0x65, 0x63, 0x74, 0x6F, 0x72, 0x79,
    0x00,
};

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DB7BD[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E834D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800ED18D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DCB0D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E0B3D[3] = {
    0x00, 0x00, 0x00,
};
#endif
