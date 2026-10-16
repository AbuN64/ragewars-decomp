#ifndef RW_DEBUG_MEMORY_H
#define RW_DEBUG_MEMORY_H
#include "TYPES.H"
/* Inclusive address ranges and transfer permissions, populated by the
 * debug memory-map enumerator. */
typedef struct MemoryRange { u32 first, last, flags; } MemoryRange;
extern MemoryRange D_800F2D00[48];
#endif
