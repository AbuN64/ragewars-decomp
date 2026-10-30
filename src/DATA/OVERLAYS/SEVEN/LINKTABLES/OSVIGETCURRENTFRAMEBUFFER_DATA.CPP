#include "TYPES.H"

#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_viDataZeroWords[];
#if defined(VERSION_DE)
void * D_src_c0f3ff2a[4] = {
    (void *)g_viDataZeroWords, (void *)g_viDataZeroWords + 0x30, 0, 0
};
#endif
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
#if defined(VERSION_US_REV1)
struct {
    void * __osViCurr;
    void * __osViNext;
} g_osvigetcurrentframebufferDataAddressWords __attribute__((aligned(4))) = {
    (void *)&g_viDataZeroWords,
    (void *)((char *)&g_viDataZeroWords + 48)
};
typedef char g_osvigetcurrentframebufferDataAddressWordsSizeCheck[(sizeof(g_osvigetcurrentframebufferDataAddressWords) == 8) ? 1 : -1];
#endif
#endif
