#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_romLookupTableText[15] =
    "ROMLookupTable\000";
#endif

#if defined(VERSION_US_REV1)
const unsigned char k_DefsReadresourcewordEncodedBytes[15] = {
    0x52, 0x4F, 0x4D, 0x4C, 0x6F, 0x6F, 0x6B, 0x75, 0x70, 0x54, 0x61, 0x62, 0x6C, 0x65, 0x00,
};
#endif
