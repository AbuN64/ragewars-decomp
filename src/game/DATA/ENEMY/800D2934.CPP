#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", rodata_unresolved_800D2934);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
struct {
    unsigned int w0;
    unsigned char b1[4];
    unsigned int w2;
    unsigned char b3[4];
    unsigned int w4;
    unsigned char b5[4];
    unsigned int w6;
} D_blob_38f6b7b96c512dcc6c7e = {
    0x00000000,
    {
        0x00, 0x00, 0x00, 0x00,
    },
    0x3FC00000,
    {
        0x00, 0x00, 0x00, 0x00,
    },
    0x41700000,
    {
        0x00, 0x00, 0xFF, 0x00,
    },
    0x454D4143,
};
#endif
