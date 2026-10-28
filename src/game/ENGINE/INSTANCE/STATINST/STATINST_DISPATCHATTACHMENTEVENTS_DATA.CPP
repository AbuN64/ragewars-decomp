#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_staticEventsText[14] =
    "static events\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80250624_C9B60_us_rev1.c */
const char D_blob_c06563bbfef28be84e19[14] = "static events";
#endif
