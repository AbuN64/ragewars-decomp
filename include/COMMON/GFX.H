#ifndef COMMON_GFX_H
#define COMMON_GFX_H
#include "TYPES.H"

typedef union Gfx {
    struct { u32 w0; u32 w1; } words;
    u64 force_structure_alignment;
} Gfx;
#endif
