#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E10E0 */
const unsigned char D_blob_phase2_e6036f2dfb04ad707672[3] = {
    0x72, 0x62, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBD63);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DBD64);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E88F3);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800E88F4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD0B3);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DD0B4);
#endif
