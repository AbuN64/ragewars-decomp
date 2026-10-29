#include "include_asm.h"



/* 8043D1DC_14.CPP */
#if defined(VERSION_DE)
unsigned char g_ObjectdataTrailingBytes[12] = { 0x30, 0xB0, 0xFF, 0xFF, 0xAF, 0xBF, 0x02, 0x94, 0xAF, 0xB5, 0x02, 0x84 };
#endif

/* 804453C4_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_ObjectdataWords1[3] = { 0xAFB30064U, 0x00C09821U, 0xAFBF0068U };
#endif
#if defined(VERSION_US)
/* Data separated from executable functions by the legacy split layout. */
unsigned char g_ObjectdataWords1[12] = { 0x04, 0x00, 0x00, 0x00, 0x08, 0x2E, 0x31, 0x36, 0x32, 0x66, 0x61, 0x6B };
#endif
