#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_3fb7e4b3[19] = {
    0x00000E08, 0x0000001B, 0x00421BEC, 0x00000E06, 0x0000001B, 0x00421AF0, 0x00000E03, 0x0000001B,
    0x00421BBC, 0x00000002, 0x0000001B, 0x00421D94, 0x00000001, 0x0000001B, 0x00421CE8, 0x00000000,
    0x00000000, 0x00000000, 0x004221F0,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_3fb7e4b3[19] = {
    0x00000E08, 0x0000001B, 0x004220EC, 0x00000E06, 0x0000001B, 0x00421FF0, 0x00000E03, 0x0000001B,
    0x004220BC, 0x00000002, 0x0000001B, 0x00422294, 0x00000001, 0x0000001B, 0x004221E8, 0x00000000,
    0x00000000, 0x00000000, 0x40013000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_3fb7e4b3[19] = {
    0x00000E08, 0x0000001B, 0x004220EC, 0x00000E06, 0x0000001B, 0x00421FF0, 0x00000E03, 0x0000001B,
    0x004220BC, 0x00000002, 0x0000001B, 0x00422294, 0x00000001, 0x0000001B, 0x004221E8, 0x00000000,
    0x00000000, 0x00000000, 0x00000007,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_00421B20[];
extern char D_00421BEC[];
extern char D_00421C1C[];
extern char D_00421D18[];
extern char D_00421DC4[];
unsigned int D_blob_5a30de177bdbcc6f9c51[18] = {
    0x00000E08, 0x0000001B, (unsigned int)D_00421C1C, 0x00000E06, 0x0000001B, (unsigned int)D_00421B20, 0x00000E03, 0x0000001B,
    (unsigned int)D_00421BEC, 0x00000002, 0x0000001B, (unsigned int)D_00421DC4, 0x00000001, 0x0000001B, (unsigned int)D_00421D18, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int data_unresolved_800DF0FC[1] = {
    0x0000002B,
};
#endif
