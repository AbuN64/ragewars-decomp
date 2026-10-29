#include "include_asm.h"

/* 80408CB0_5.CPP */
#if defined(VERSION_EU)
unsigned char g_PakTrailingBytes[12] = { 0x8C, 0x62, 0x00, 0xE0, 0x24, 0x42, 0xFE, 0x70, 0x2C, 0x42, 0x00, 0x04 };
#endif

/* DATA_80405DB4.CPP */
#if defined(VERSION_DE)
/* ROM-grounded data for de; supplied-list member has no us-rev1 placement. */
unsigned int g_PakEncodedWordsBlock1[3] = {
    0x43523A42, 0x22213123, 0x40345262,
};
#endif

/* 80405454.CPP */
#if defined(VERSION_EU_X)
unsigned char g_PakTrailingBytesBlock1[12] = { 0x3C, 0x01, 0x80, 0x0F, 0xAC, 0x30, 0xA0, 0xAC, 0x08, 0x10, 0x1C, 0x02 };
#endif

/* 80405454_5.CPP */
#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_80405DB4_us_rev1[3] = { 0x8E3128C8U, 0x02202021U, 0x02002821U };
#endif
