#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned char g_pakFormatInt1Dot[5] = {
    0x25, 0x31, 0x64, 0x2E, 0x00,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif
