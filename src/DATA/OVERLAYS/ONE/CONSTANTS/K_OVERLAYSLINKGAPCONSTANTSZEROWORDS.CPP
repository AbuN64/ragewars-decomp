#include "TYPES.H"

#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
#if defined(VERSION_DE)
struct {
    u8 alignmentFill[12];
} k_OverlaysLinkGapConstantsZeroWords __attribute__((aligned(4))) = {
    { 0x8F, 0xB7, 0x00, 0x34, 0x8F, 0xB6, 0x00, 0x30, 0x8F, 0xB5, 0x00, 0x2C }
};
#endif
#endif
#if defined(VERSION_US)
unsigned int k_OverlaysLinkGapConstantsZeroWords[1] = {
    0x00000000,
};
#endif
#endif
