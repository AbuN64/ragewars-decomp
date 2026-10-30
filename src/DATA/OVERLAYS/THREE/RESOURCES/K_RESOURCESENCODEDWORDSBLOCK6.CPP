#include "IO/DEBUG_MEMORY.H"


#if defined(VERSION_EU)
#if defined(VERSION_EU)
MemoryBoundary g_ResourcesEncodedWordsBlock70[2] = {
    { 0x53204d45, 0x4e434841 }, { 0x7fffffff, 0x0 }
};
#endif

#if defined(VERSION_EU)
struct {
    MemoryBoundary boundaries[10];
    s32 lastMappedSlot;
    u32 alignmentFill;
} k_ResourcesEncodedWordsBlock6 __attribute__((aligned(4))) = {
    { { 0x807fffff, 0x3 }, { 0x9fffffff, 0x0 }, { 0xa07fffff, 0x3 }, { 0xa3ffffff, 0x0 }, { 0xa4001fff, 0xb }, { 0xa5ffffff, 0x0 }, { 0xa63fffff, 0x7 }, { 0xafffffff, 0x0 }, { 0xb1fdffff, 0x7 }, { 0xffffffff, 0x0 } },
    -2054,
    0x202d2043
};
#endif
#endif
