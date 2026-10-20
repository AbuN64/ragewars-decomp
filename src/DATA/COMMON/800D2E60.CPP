#include "include_asm.h"

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", D_src_12ed218b);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int D_blob_91e6b63025ab2677f5de[24] = {
    0xE3001001, 0x00000000, 0xD7000002, 0x80008000, 0xD9F9FBFF, 0x00000000, 0xD9FFFFFF, 0x00210004,
    0xFCFF97FF, 0xFFFFFE38, 0xE200001C, 0xC8104B50, 0xDB040004, 0x00000001, 0xDB04000C, 0x00000001,
    0xDB040014, 0x0000FFFF, 0xDB04001C, 0x0000FFFF, 0x01004008, 0x801469A0, 0xDF000000, 0x00000000,
};
#endif
