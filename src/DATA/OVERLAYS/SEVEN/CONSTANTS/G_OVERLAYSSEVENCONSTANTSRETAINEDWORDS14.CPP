#include "TYPES.H"


#if defined(VERSION_US_REV1)
unsigned int g_OverlaysSevenConstantsRetainedWords15[4] = {
    0xC4000000, 0xC8000000, 0x7FFFFFFF, 0x00000000,
};

#if defined(VERSION_US_REV1)
struct {
    u32 addressAndPermissionPairs[20];
    s32 lastMappedSlot;
    u32 alignmentFill;
} g_OverlaysSevenConstantsRetainedWords14 __attribute__((aligned(4))) = {
    { 0x807fffff, 0x3, 0x9fffffff, 0x0, 0xa07fffff, 0x3, 0xa3ffffff, 0x0, 0xa4001fff, 0xb, 0xa5ffffff, 0x0, 0xa63fffff, 0x7, 0xafffffff, 0x0, 0xb1fdffff, 0x7, 0xffffffff, 0x0 },
    -2054,
    0x3fc88fbb
};
typedef char g_OverlaysSevenConstantsRetainedWords14SizeCheck[(sizeof(g_OverlaysSevenConstantsRetainedWords14) == 88) ? 1 : -1];
#endif
#endif
