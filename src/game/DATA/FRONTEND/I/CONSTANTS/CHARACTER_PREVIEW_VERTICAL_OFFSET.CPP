#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned char D_src_80515f28[3] = {
    0x42, 0x20, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int g_characterPreviewVerticalOffsetUsRev1[1] = {
    0x42200000,
};
#endif
