#include "include_asm.h"

/* 802944E8_6.CPP */
#if defined(VERSION_US)
/** Perform no operation. */
void Visdata_EmptyInitializeHookUs(void) {
}
#endif

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VisdataEmptyRegionalHooksTrailingBytesAlignmentPad[8] = { 0x03, 0xE0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };
#endif

