#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_viDataZeroWords[];
unsigned int D_src_c0f3ff2a[4] = {
    (unsigned int)g_viDataZeroWords, (unsigned int)g_viDataZeroWords + 0x30, 0x00000000, 0x00000000,
};
#endif
#if defined(VERSION_EU)
extern char g_viDataZeroWords[];
unsigned int D_src_c0f3ff2a[4] = {
    (unsigned int)g_viDataZeroWords, (unsigned int)g_viDataZeroWords + 0x30, 0x20207072, 0x696D6167,
};
#endif
#if defined(VERSION_EU_X)
extern char g_viDataZeroWords[];
unsigned int D_src_c0f3ff2a[4] = {
    (unsigned int)g_viDataZeroWords, (unsigned int)g_viDataZeroWords + 0x30, 0x3A9837F1, 0x3AB504F3,
};
#endif
#if defined(VERSION_US)
extern char g_viDataZeroWords[];
unsigned int D_src_c0f3ff2a[4] = {
    (unsigned int)g_viDataZeroWords, (unsigned int)g_viDataZeroWords + 0x30, 0x585F4649, 0x5245424F,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
unsigned int g_osvigetcurrentframebufferDataAddressWords[2] = {
    0x800D83E0, 0x800D8410,
};
#endif
