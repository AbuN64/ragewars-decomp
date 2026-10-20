#ifndef IO_DEBUG_MEMORY_H
#define IO_DEBUG_MEMORY_H
#include "TYPES.H"
extern s8 D_800F3450;
/* Inclusive address ranges and transfer permissions, populated by the
 * debug memory-map enumerator. */
typedef struct MemoryRange { u32 first, last, flags; } MemoryRange;
extern MemoryRange D_800F2D00[48];
/* Last address and permission flags of each debug memory region; func_802013E0_de
 * sets the RAM size limits of entries 1 and 3. */
typedef struct MemoryBoundary { u32 last, flags; } MemoryBoundary;
extern MemoryBoundary D_800CB3A0[];
#endif
