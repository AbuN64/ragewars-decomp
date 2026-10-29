#include "include_asm.h"


#if defined(VERSION_US_REV1)
unsigned char g_PakTrailingBytesBlock4[8] = { 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x21 };
#endif
#if defined(VERSION_US)
/* Eight bytes ahead of the first function of the Pak menu code: 0x0F and the tag SM_A. */
unsigned char g_PakTrailingBytesBlock4[8] = { 0x00, 0x00, 0x00, 0x0F, 0x53, 0x4D, 0x5F, 0x41 };
#endif
