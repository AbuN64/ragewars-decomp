#include "include_asm.h"

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_EngineLinkGapD64TrailingBytesAlignmentPad[12] = { 0x00, 0x00, 0x00, 0x00, 0x8E, 0x04, 0x00, 0x3C, 0x0C, 0x0A, 0x61, 0x2E };
#endif

