#include "include_asm.h"

/* VisdataEmptyRegionalHooksEncodedWordsUnit.CPP */
#if defined(VERSION_DE)
unsigned int g_VisdataEmptyRegionalHooksEncodedWords[3] = {
    0x0029702C, 0x00296F3C, 0x00296F3C,
};
#endif

/* 80290B90.CPP */
#if defined(VERSION_EU)
void Visdata_EmptyHookEu(void) {}
#endif

#if defined(VERSION_EU)
unsigned int func_80290B98_eu_padding_91798[2] = {
    0x02002021, 0x0C0A3FC2,
};
#endif

/* 80290BC0.CPP */
#if defined(VERSION_EU_X)
/** Perform no operation. */
void Visdata_EmptyHookEuX(void) {
}
#endif

/* 802944E8_6.CPP */
#if defined(VERSION_US)
/** Perform no operation. */
void Visdata_EmptyInitializeHookUs(void) {
}
#endif

#if defined(VERSION_US)
unsigned char g_VisdataEmptyRegionalHooksTrailingBytes[8] = { 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };
#endif

/* 802944E8_8.CPP */
#if defined(VERSION_US)
/** Perform no operation. */
void Visdata_EmptyReleaseHookUs(void) {
}
#endif

#if defined(VERSION_US)
unsigned char g_VisdataEmptyRegionalHooksTrailingBytesBlock1[8] = { 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };
#endif
