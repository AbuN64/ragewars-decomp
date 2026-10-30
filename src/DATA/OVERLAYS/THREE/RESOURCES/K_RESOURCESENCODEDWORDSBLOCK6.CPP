#include "TYPES.H"


#if defined(VERSION_EU)
unsigned int g_ResourcesEncodedWordsBlock70[4] = {
    0x53204D45, 0x4E434841, 0x7FFFFFFF, 0x00000000,
};

#if defined(VERSION_EU)
struct {
    u32 addressAndPermissionPairs[20];
    s32 lastMappedSlot;
    u32 alignmentFill;
} k_ResourcesEncodedWordsBlock6 __attribute__((aligned(4))) = {
    { 0x807fffff, 0x3, 0x9fffffff, 0x0, 0xa07fffff, 0x3, 0xa3ffffff, 0x0, 0xa4001fff, 0xb, 0xa5ffffff, 0x0, 0xa63fffff, 0x7, 0xafffffff, 0x0, 0xb1fdffff, 0x7, 0xffffffff, 0x0 },
    -2054,
    0x202d2043
};
typedef char k_ResourcesEncodedWordsBlock6SizeCheck[(sizeof(k_ResourcesEncodedWordsBlock6) == 88) ? 1 : -1];
#endif
#endif
