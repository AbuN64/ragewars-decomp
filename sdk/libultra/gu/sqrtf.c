#include "include_asm.h"
#include "TYPES.H"

f32 Gu_Sqrtf(f32 value) {
    return __builtin_sqrtf(value);
}

#if defined(VERSION_EU)
unsigned char g_SqrtfTrailingBytesBlock1[4] = { 0x8C, 0xA2, 0x00, 0x00 };
#endif
