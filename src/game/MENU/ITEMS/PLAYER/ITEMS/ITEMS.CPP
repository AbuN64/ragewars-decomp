#include "include_asm.h"

#if defined(VERSION_DE)
const unsigned int k_ItemsHalfWords[1] = {
    0x3F000000,
};
#endif

#if defined(VERSION_DE)
char k_ItemsEncodedBytes[8] =
    "  %02d\000\000";
#endif
