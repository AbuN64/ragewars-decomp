#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", D_src_846838ea);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_004374F0[];
extern char D_004375C4[];
extern char D_004375F4[];
extern char D_00437624[];
extern char D_00437754[];
extern char D_00437790[];
unsigned int D_blob_40f898484c78241666ba[21] = {
    0x00000E08, 0x00000009, (unsigned int)D_00437624, 0x00000E06, 0x00000009, (unsigned int)D_004374F0, 0x00000E07, 0x00000009,
    (unsigned int)D_004375F4, 0x00000E03, 0x00000009, (unsigned int)D_004375C4, 0x00000001, 0x00000009, (unsigned int)D_00437790, 0x00000002,
    0x00000009, (unsigned int)D_00437754, 0x00000000, 0x00000000, 0x00000000,
};
#endif
