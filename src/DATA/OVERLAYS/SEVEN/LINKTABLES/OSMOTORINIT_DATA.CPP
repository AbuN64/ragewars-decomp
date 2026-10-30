#include "TYPES.H"


#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800D80A0_unclaimed_D8F40_unclaimed_D8F74 */
#if defined(VERSION_US_REV1)
struct {
    u8 alignmentFill[12];
} g_osmotorinitDataAddressWords __attribute__((aligned(4))) = {
    { 0x80, 0x15, 0x1B, 0xC8, 0x80, 0x15, 0x2B, 0x80, 0x00, 0x00, 0x00, 0x00 }
};
#endif

#if defined(VERSION_US_REV1)
s32 g_osmotorinitDataZeroWords[4] = {
    0, 0, 0, 0
};
#endif
#endif
