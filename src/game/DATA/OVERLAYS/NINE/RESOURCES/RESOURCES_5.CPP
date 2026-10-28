#include "include_asm.h"

/* 800E4EBC_2.CPP */
/* ROM-grounded data: rodata/writable/800E4EF0 */
unsigned int D_blob_phase2_aa4dbfd938acb198f6de[1] = {
    0x00000000,
};

/* 800E4EF4.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_8e351802[23] = {
    0x00000E06, 0x00000015, 0x004291D0, 0x00000E03, 0x00000015, 0x004296F4, 0x00000E0A, 0x00000015,
    0x00429724, 0x00000002, 0x00000015, 0x004298F8, 0x00000001, 0x00000015, 0x004297F8, 0x0000000A,
    0x00000015, 0x0042972C, 0x00000008, 0x0000036A, 0x00429970, 0x00000007, 0x0000036A,
};
#endif
#if defined(VERSION_EU)
unsigned int D_src_8e351802[27] = {
    0x00000E06, 0x00000015, 0x00429D30, 0x00000E03, 0x00000015, 0x0042A2B0, 0x00000E0A, 0x00000015,
    0x0042A2E0, 0x00000002, 0x00000015, 0x0042A4B4, 0x00000001, 0x00000015, 0x0042A3B4, 0x0000000A,
    0x00000015, 0x0042A2E8, 0x00000008, 0x0000036E, 0x0042A52C, 0x00000007, 0x0000036E, 0x0042A508,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_8e351802[27] = {
    0x00000E06, 0x00000015, 0x00429E80, 0x00000E03, 0x00000015, 0x0042A400, 0x00000E0A, 0x00000015,
    0x0042A430, 0x00000002, 0x00000015, 0x0042A604, 0x00000001, 0x00000015, 0x0042A504, 0x0000000A,
    0x00000015, 0x0042A438, 0x00000008, 0x00000372, 0x0042A67C, 0x00000007, 0x00000372, 0x0042A658,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_004293B0[];
extern char D_004298D4[];
extern char D_00429904[];
extern char D_0042990C[];
extern char D_004299D8[];
extern char D_00429AD8[];
extern char D_00429B2C[];
extern char D_00429B50[];
unsigned int D_blob_e06be6e89292420b3d0c[27] = {
    0x00000E06, 0x00000015, (unsigned int)D_004293B0, 0x00000E03, 0x00000015, (unsigned int)D_004298D4, 0x00000E0A, 0x00000015,
    (unsigned int)D_00429904, 0x00000002, 0x00000015, (unsigned int)D_00429AD8, 0x00000001, 0x00000015, (unsigned int)D_004299D8, 0x0000000A,
    0x00000015, (unsigned int)D_0042990C, 0x00000008, 0x0000036E, (unsigned int)D_00429B50, 0x00000007, 0x0000036E, (unsigned int)D_00429B2C,
    0x00000000, 0x00000000, 0x00000000,
};
#endif

/* 800E0F00.CPP */
#if defined(VERSION_DE)
unsigned short D_auto_rodata_writable_800E0F00[] = {
    0x0042, 0x994C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
#if defined(VERSION_DE)
    0x0329,
#endif
};
#endif

#if !(defined(VERSION_US_REV1))
/* bytes live in the preceding array */
#endif
