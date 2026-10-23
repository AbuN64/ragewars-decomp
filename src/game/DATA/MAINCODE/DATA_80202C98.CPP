#include "include_asm.h"

#if defined(VERSION_US)
char rodata_unresolved_80202C98[8] =
    "yObjectT";
#endif

#if defined(VERSION_DE)
/* ROM-grounded data for de; supplied-list member has no us-rev1 placement. */
unsigned int D_blob_9ace5635f896c825499f[2] = {
    0x5B735181, 0xB703BE02,
};
#endif
