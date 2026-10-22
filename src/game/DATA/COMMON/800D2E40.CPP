#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", rodata_unresolved_800D2E40);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int D_blob_945ad6e50c70b61397fd[6] = {
    0x800D2CB0, 0x800D2CD8, 0x800D2D00, 0x800D2D78, 0x800D2DF0, 0x800D2E18,
};
#endif
