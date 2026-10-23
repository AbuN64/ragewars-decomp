#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802A6174_CBC48[2] = {
    0x3C23D70A, 0x3E95CBEC,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A6174_CBC48_us_rev1.c */
const unsigned int D_blob_51ff0f3c72ea18e42a95[2] = {
    0x3C23D70A, 0x3E95CBEC,
};
#endif
