#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

/* 800CC694_36.CPP */
/* ROM-grounded data: src/s_epirawreadExText.c */
const unsigned char s_epirawreadExText[3] = {
    0x45, 0x58, 0x00,
};

/* 800CC694_37.CPP */
/* ROM-grounded data: src/ragewars_resident_strings_CD7A4_us_rev1.c */
#if defined(VERSION_US)
unsigned int k_EpirawreadEncodedWords[3] = {
    0x66000000, 0x04000000, 0x0000082E,
};
#endif

/* 802BE040_13.CPP */
/* 802BE040_13.CPP */
#if defined(VERSION_EU)
unsigned char g_EpirawreadTrailingBytes[12] = { 0x00, 0x00, 0x00, 0x00, 0x3C, 0x02, 0x05, 0x00, 0x00, 0x04, 0x24, 0x00 };
#endif

/* 802C0390_16.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BB574_eu_x[3] = { 0x016C082AU, 0x10200024U, 0x00000000U };
#endif

/* 802BE040_9.CPP */
#if defined(VERSION_DE)
unsigned char g_EpirawreadTrailingBytesBlock1[12] = { 0x34, 0x42, 0x00, 0x10, 0x8C, 0x42, 0x00, 0x00, 0x30, 0x42, 0x00, 0x03 };
#endif
