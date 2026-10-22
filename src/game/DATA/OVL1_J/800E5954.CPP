#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", D_src_9d8a2047);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_004397D8[];
extern char D_00439808[];
extern char D_004398D0[];
extern char D_00439910[];
extern char D_00439930[];
extern char D_004396C0[];
unsigned int D_blob_066f15793e1923b9ad70[21] = {
    0x00000E08, 0x00000018, (unsigned int)D_00439808, 0x00000E06, 0x00000018, (unsigned int)D_004396C0, 0x00000E03, 0x00000018,
    (unsigned int)D_004397D8, 0x00000001, 0x00000018, (unsigned int)D_00439930, 0x00000002, 0x00000018, (unsigned int)D_00439910, 0x0000000A,
    0x00000018, (unsigned int)D_004398D0, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E0608);
#endif
