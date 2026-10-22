#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", D_src_c64ed94a);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
extern char D_0042DBD0[];
extern char D_0042DCA8[];
extern char D_0042DCD8[];
extern char D_0042DDE4[];
extern char D_0042DEA4[];
extern char D_0042DEE0[];
extern char D_0042DF88[];
unsigned int D_blob_b69b6016e21f008919d7[24] = {
    0x00000E08, 0x0000001A, (unsigned int)D_0042DCD8, 0x00000E06, 0x0000001A, (unsigned int)D_0042DBD0, 0x00000E03, 0x0000001A,
    (unsigned int)D_0042DCA8, 0x00000002, 0x0000001A, (unsigned int)D_0042DEA4, 0x00000001, 0x0000001A, (unsigned int)D_0042DDE4, 0x00000008,
    0x0000001A, (unsigned int)D_0042DEE0, 0x00000007, 0x0000001A, (unsigned int)D_0042DF88, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800E00F4);
#endif
