#ifndef RAGEWARS_PACKED_FLOAT_H
#define RAGEWARS_PACKED_FLOAT_H

#include "types.h"

/* Decodes a float stored as its high 16 bits. */
extern f32 func_802AD520_eu(s32);
extern f32 func_802B2350(s32);
#if defined(VERSION_EU)
#define RW_BITS_TO_FLOAT func_802AD520_eu
#else
#define RW_BITS_TO_FLOAT func_802B2350
#endif

#endif
