#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_6d0863ff);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char D_0042BD40[];
extern char D_0042D6AC[];
extern char D_0042D6DC[];
extern char D_0042D870[];
extern char D_0042D968[];
extern char D_0042DA84[];
extern char D_0042DAA4[];
extern char D_0042DAE8[];
unsigned int D_blob_f87b2dd9d8e138119cb9[27] = {
    0x00000E08, 0x00000011, (unsigned int)D_0042D870, 0x00000E06, 0x00000011, (unsigned int)D_0042BD40, 0x00000E03, 0x00000011,
    (unsigned int)D_0042D6AC, 0x00000002, 0x00000011, (unsigned int)D_0042DA84, 0x00000001, 0x00000011, (unsigned int)D_0042D968, 0x00000E0A,
    0x00000011, (unsigned int)D_0042D6DC, 0x00000005, 0x00000011, (unsigned int)D_0042DAA4, 0x00000006, 0x00000011, (unsigned int)D_0042DAE8,
    0x00000000, 0x00000000, 0x00000000,
};
#endif
