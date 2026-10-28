#include "include_asm.h"

/* DATA_800D2930.CPP */
/* ROM-grounded data: rodata/writable/800D2930 */
unsigned int D_blob_phase2_412ea4b78cfe71296b58[1] = {
    0x00000001,
};

/* DATA_800D2934.CPP */
#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800D2934[7] = {
    0x00000000, 0x00000000, 0x3FC00000, 0x00000000, 0x41700000, 0x0000FF00, 0x00000014,
};
#endif
#if defined(VERSION_EU)
unsigned short rodata_unresolved_800D2934[14] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x3FC0, 0x0000, 0x0000, 0x0000, 0x4170, 0x0000, 0x0000, 0xFF00,
    0x8011, 0x00B0,
};
#endif
#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800D2934[7] = {
    0x00000000, 0x00000000, 0x3FC00000, 0x00000000, 0x41700000, 0x0000FF00, 0x00000000,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_800D2934[7] = {
    0x00000000, 0x00000000, 0x3FC00000, 0x00000000, 0x41700000, 0x0000FF00, 0x4852494E,
};
#endif
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
} g_emacText = {
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
