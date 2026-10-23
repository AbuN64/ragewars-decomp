#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct { u32 first, last, flags; } MemoryRange;
typedef struct { u32 pageMask, entryHi, entryLo0, entryLo1; } TranslationEntry;
typedef struct { u32 last, flags; } MemoryBoundary;
extern MemoryRange D_800F2D00[48];
extern TranslationEntry D_800F3470[32];
extern u32 D_800C8148_de[];
extern MemoryBoundary D_800CB3A0[];
extern u32 Libgultra_TrwReadTlbEntry(void);

/* 78/124 words; remaining: register assignment of the TLB loop temporaries (entry pointer and the four entry words land in other t/a registers than the ROM) */
void Libsn_EnumerateMemoryRanges(void) {
    u32 addressSpaceId, pageMask, entryHi, entryLo0, entryLo1, pageSize, first, last, rangeCount, supportedMask, i;
    u32 *entry;
    MemoryRange *range;
    u32 *boundary;
    u32 *supportedMasks;
    addressSpaceId = Libgultra_TrwReadTlbEntry() & 0xFF;
    entry = (u32 *)D_800F3470;
    for (i = 16; i < 48; i++) {
        D_800F2D00[i].first = -1;
        D_800F2D00[i].flags = 0;
        pageMask = *entry++;
        entryHi = *entry++;
        entryLo0 = *entry++;
        entryLo1 = *entry++;
        if ((entryLo0 | entryLo1) & 2) {
            pageMask &= 0x1FFE000;
            supportedMasks = D_800C8148_de;
            pageSize = 0x1000;
            while (1) {
                supportedMask = *supportedMasks;
                if (supportedMask == pageMask) break;
                supportedMasks++;
                if (supportedMask & 0x80000000) {
                    pageSize = 0;
                    break;
                }
                pageSize <<= 2;
            }
            if (pageSize != 0) {
                if ((entryLo0 & entryLo1 & 3) != 3) {
                    if ((entryLo0 & 3) == 2 && (entryHi & 0xFF) != addressSpaceId) entryLo0 &= ~2U;
                    if ((entryLo1 & 3) == 2 && (entryHi & 0xFF) != addressSpaceId) entryLo1 &= ~2U;
                }
                first = entryHi & 0xFFFFE000;
                if (entryLo0 & entryLo1 & 2) pageSize <<= 1;
                else if (entryLo1 & 2) first += pageSize;
                D_800F2D00[i].first = first;
                D_800F2D00[i].last = first + pageSize - 1;
                D_800F2D00[i].flags = 3;
            }
        }
    }
    boundary = (u32 *)D_800CB3A0;
    first = 0x80000000;
    if ((s32)*boundary >= 0) {
        do { boundary += 2; } while (*boundary < first);
    }
    rangeCount = 0;
    do {
        D_800F2D00[rangeCount].first = first;
        last = *boundary++;
        D_800F2D00[rangeCount].last = last;
        first = last + 1;
        D_800F2D00[rangeCount].flags = *boundary++;
        rangeCount++;
    } while (first != 0);
    for (; rangeCount < 16; rangeCount++) {
        D_800F2D00[rangeCount].first = -1;
        D_800F2D00[rangeCount].flags = 0;
    }
}
#else
INCLUDE_ASM("span_1000", Libsn_EnumerateMemoryRanges);
#endif
