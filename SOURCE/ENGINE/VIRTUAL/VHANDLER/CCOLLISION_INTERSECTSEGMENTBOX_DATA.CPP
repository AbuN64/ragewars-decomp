#include "IO/DEBUG_MEMORY.H"
#include "TYPES.H"
#include "include_asm.h"
#if defined(VERSION_DE)
#if defined(VERSION_DE)
struct {
    MemoryBoundary boundaries[10];
    s32 lastMappedSlot;
    u32 alignmentFill;
} g_CcollisionIntersectsegmentboxWords2 __attribute__((aligned(4))) = {
    { { 0x807fffff, 0x3 }, { 0x9fffffff, 0x0 }, { 0xa07fffff, 0x3 }, { 0xa3ffffff, 0x0 }, { 0xa4001fff, 0xb }, { 0xa5ffffff, 0x0 }, { 0xa63fffff, 0x7 }, { 0xafffffff, 0x0 }, { 0xb1fdffff, 0x7 }, { 0xffffffff, 0x0 } },
    -2054,
    0x92060009
};
#endif
#endif
