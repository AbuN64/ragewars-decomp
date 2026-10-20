#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_8e351802);
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
