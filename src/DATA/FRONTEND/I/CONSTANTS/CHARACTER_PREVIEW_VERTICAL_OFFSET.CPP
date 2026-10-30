#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned char g_characterPreviewVerticalOffset[3] = {
    0x42, 0x20, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const RestLinkerAlignmentFill4 g_characterPreviewVerticalOffsetUsRev1LinkerAlignmentFill429 = {
    { 66, 32, 0, 0 },
};
#endif
