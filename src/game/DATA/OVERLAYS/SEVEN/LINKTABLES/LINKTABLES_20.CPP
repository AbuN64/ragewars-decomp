#include "include_asm.h"

/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int D_blob_06e2da2b617a617ebeb3[1] = {
    0x003FFF01,
};

#if defined(VERSION_US)
unsigned int data_unresolved_800D3F0C[1] = {
    0x52445F4C,
};
#endif

#if defined(VERSION_EU)
#if defined(VERSION_EU)
extern char D_auto_rodata_unresolved_800C6588[];
unsigned int data_unresolved_800E58DC[1] = {
    (unsigned int)D_auto_rodata_unresolved_800C6588 + 0x18,
};
#endif
#endif

#if defined(VERSION_DE)
#if defined(VERSION_DE)
extern char D_blob_73f39d5b3aba05ce9b42[];
unsigned int data_unresolved_800D525C[1] = {
    (unsigned int)D_blob_73f39d5b3aba05ce9b42,
};
#endif
#endif
