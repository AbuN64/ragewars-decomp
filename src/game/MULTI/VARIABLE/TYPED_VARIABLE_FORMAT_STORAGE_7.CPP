#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU_X)
const unsigned char g_MultiVariableRetainedBytes1[3] = {
    0x25, 0x73, 0x00,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_US)
const unsigned int g_MultiVariableRetainedBytes1[1] = {
    0x25730000,
};
#endif
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8043F120_E2FC0_us_rev1.c */
const unsigned char g_MultiVariableRetainedBytes2[3] = {
    0x25, 0x73, 0x00,
};
#endif
