#include "TYPES.H"

#include "include_asm.h"



/* 8043D1DC_14.CPP */
#if defined(VERSION_DE)
#if defined(VERSION_DE)
struct {
    u8 alignmentFill[12];
} g_ObjectdataTrailingBytes __attribute__((aligned(1))) = {
    { 0x30, 0xB0, 0xFF, 0xFF, 0xAF, 0xBF, 0x02, 0x94, 0xAF, 0xB5, 0x02, 0x84 }
};
#endif
#endif

/* 804453C4_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_EU_X)
struct {
    u8 alignmentFill[12];
} g_ObjectdataWords1 __attribute__((aligned(4))) = {
    { 0xAF, 0xB3, 0x00, 0x64, 0x00, 0xC0, 0x98, 0x21, 0xAF, 0xBF, 0x00, 0x68 }
};
#endif
#if defined(VERSION_US_REV1)
struct {
    u8 alignmentFill[12];
} g_ObjectdataWords1 __attribute__((aligned(4))) = {
    { 0xAF, 0xB3, 0x00, 0x64, 0x00, 0xC0, 0x98, 0x21, 0xAF, 0xBF, 0x00, 0x68 }
};
#endif
#endif
#if defined(VERSION_US)
/* Data separated from executable functions by the legacy split layout. */
#if defined(VERSION_US)
struct {
    u8 alignmentFill[12];
} g_ObjectdataWords1 __attribute__((aligned(1))) = {
    { 0x04, 0x00, 0x00, 0x00, 0x08, 0x2E, 0x31, 0x36, 0x32, 0x66, 0x61, 0x6B }
};
#endif
#endif
