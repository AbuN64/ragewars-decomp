#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
RestLinkerAlignmentFill4 g_graphicsRuntimeLinkWordUsRev1 = {
    { 32, 12, 16, 0 },
};
#endif
