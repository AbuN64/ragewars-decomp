#include "IO/DEBUG_MEMORY.H"


#if defined(VERSION_US)
#if defined(VERSION_US)
MemoryBoundary k_LinktablesEncodedWordsBlock1[2] = {
    { 0x52000058, 0x6000010 }, { 0x7fffffff, 0x0 }
};
#endif

#if defined(VERSION_US)
struct {
    MemoryBoundary boundaries[10];
    s32 lastMappedSlot;
    u32 alignmentFill;
} g_LinktablesEncodedWords __attribute__((aligned(4))) = {
    { { 0x807fffff, 0x3 }, { 0x9fffffff, 0x0 }, { 0xa07fffff, 0x3 }, { 0xa3ffffff, 0x0 }, { 0xa4001fff, 0xb }, { 0xa5ffffff, 0x0 }, { 0xa63fffff, 0x7 }, { 0xafffffff, 0x0 }, { 0xb1fdffff, 0x7 }, { 0xffffffff, 0x0 } },
    -2054,
    0x4e455f32
};
#endif
#endif
