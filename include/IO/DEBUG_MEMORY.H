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
/* MemoryRange.flags: the debugger may read (1) / write (2) the range. */
#define MEMORY_READ 1
#define MEMORY_WRITE 2
/* R4300 TLB fields (libultra R4300.h names). */
#ifndef TLBLO_V
#define TLBLO_G 0x1
#define TLBLO_V 0x2
#define TLBHI_PIDMASK 0xFF
#define TLBHI_VPN2MASK 0xFFFFE000
#define TLBPGMASK_16M 0x1FFE000
#endif
/* One TLB entry as Libgultra_TrwReadTlbEntry stores it (CP0 PageMask, EntryHi, EntryLo0, EntryLo1). */
typedef struct TlbEntry { u32 pageMask, entryHi, entryLo0, entryLo1; } TlbEntry;
/* Snapshot of all 32 TLB entries; Libgultra_TrwReadTlbEntry fills it and returns CP0 EntryHi. */
extern TlbEntry D_800F3470[32];
extern u32 Libgultra_TrwReadTlbEntry(void);
/* PageMask of each supported page size (4 KB, 16 KB, ... 16 MB), ended by 0x80000000. */
extern u32 D_800C8148_de[8];
#endif
