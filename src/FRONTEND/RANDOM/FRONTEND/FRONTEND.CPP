#include "include_asm.h"


/* 8042F12C.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char g_FrontendTrailingBytesBlock5[4] = { 0x00, 0x05, 0x10, 0xC0 };
#endif
#if defined(VERSION_DE)
unsigned char g_FrontendTrailingBytesBlock4[4] = { 0x00, 0x00, 0x30, 0x21 };
#endif
#if defined(VERSION_EU)
unsigned char g_FrontendTrailingBytesBlock6[4] = { 0x24, 0xA5, 0xC5, 0x74 };
#endif
