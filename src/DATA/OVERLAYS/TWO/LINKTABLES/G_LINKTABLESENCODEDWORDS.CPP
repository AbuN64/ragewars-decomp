#include "TYPES.H"


#if defined(VERSION_US)
unsigned int k_LinktablesEncodedWordsBlock1[4] = {
    0x52000058, 0x06000010, 0x7FFFFFFF, 0x00000000,
};

#if defined(VERSION_US)
struct {
    u32 addressAndPermissionPairs[20];
    s32 lastMappedSlot;
    u32 alignmentFill;
} g_LinktablesEncodedWords __attribute__((aligned(4))) = {
    { 0x807fffff, 0x3, 0x9fffffff, 0x0, 0xa07fffff, 0x3, 0xa3ffffff, 0x0, 0xa4001fff, 0xb, 0xa5ffffff, 0x0, 0xa63fffff, 0x7, 0xafffffff, 0x0, 0xb1fdffff, 0x7, 0xffffffff, 0x0 },
    -2054,
    0x4e455f32
};
typedef char g_LinktablesEncodedWordsSizeCheck[(sizeof(g_LinktablesEncodedWords) == 88) ? 1 : -1];
#endif
#endif
