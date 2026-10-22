#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_c44120b0);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_002A2DE4[];
extern char D_002A2E20[];
extern char D_002A2E5C[];
extern char D_002A2EC0[];
extern char D_002A2F3C[];
extern char D_002A2FB8[];
extern char D_002A2FE8[];
extern char D_002A306C[];
unsigned int D_blob_d848dcdc763fca17debc[27] = {
    0x00000E07, 0x00007530, (unsigned int)D_002A2DE4, 0x0000000F, 0x00007530, (unsigned int)D_002A2E20, 0x00000010, 0x00007530,
    (unsigned int)D_002A2E5C, 0x00000008, 0x00007530, (unsigned int)D_002A2EC0, 0x00000007, 0x00007530, (unsigned int)D_002A2F3C, 0x00000E03,
    0x00007530, (unsigned int)D_002A306C, 0x0000000B, 0x00007530, (unsigned int)D_002A2FB8, 0x00000E08, 0x00007530, (unsigned int)D_002A2FE8,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
