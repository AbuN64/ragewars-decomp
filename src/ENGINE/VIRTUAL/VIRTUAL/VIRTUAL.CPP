#include "include_asm.h"

/* 8023A284_22.CPP */
/* 8023A284_22.CPP */
#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VirtualTrailingBytesAlignmentPad[8] = { 0xC4, 0x20, 0x36, 0x10, 0x46, 0x00, 0x08, 0xC2 };
#endif

/* 8023CFB0_3.CPP */
#if defined(VERSION_DE)
/** Perform no operation. */
void Virtual_RegionLifecycleNoOp(void) {
}
#endif

/* 8023A284_24.CPP */
/* 8023A284_24.CPP */
#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VirtualTrailingBytesBlock1AlignmentPad[8] = { 0x00, 0x03, 0x17, 0xC2, 0x00, 0x62, 0x18, 0x21 };
#endif

/* 8023A284_25.CPP */
#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VirtualTrailingBytesBlock2AlignmentPad[8] = { 0xAF, 0xA0, 0x00, 0x30, 0xAF, 0xA0, 0x00, 0x34 };
#endif

/* 8023EEF0_2.CPP */
#if defined(VERSION_US_REV1)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VirtualTrailingBytesBlock3AlignmentPad[12] = { 0x2C, 0x42, 0x00, 0x02, 0x10, 0x40, 0x00, 0x59, 0x00, 0x60, 0x90, 0x21 };
#endif

/* 80255C40_8.CPP */
#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned char g_VirtualTrailingBytesBlock4AlignmentPad[12] = { 0x00, 0x09, 0x00, 0x18, 0x00, 0x00, 0x00, 0x07, 0x2E, 0x32, 0x34, 0x66 };
#endif
