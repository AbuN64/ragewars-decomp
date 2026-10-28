#include "TYPES.H"
#include "IO/DEBUG_MEMORY.H"

/* Rebuild the debugger memory map: entries 16-47 describe the valid pages of the 32 TLB entries
 * (snapshot taken by Libgultra_TrwReadTlbEntry), entries 0-15 copy the static region table from
 * KSEG0 (0x80000000) up to the end marker (last == 0xFFFFFFFF); unused entries get first = -1. */
void Libsn_EnumerateMemoryRanges(void) {
    u32 addressSpaceId, pageMask, entryHi, entryLo0, entryLo1, pageSize, first, rangeCount, supportedMask, i;
    u32 *entry;
    u32 *boundary;
    u32 *supportedMasks;
    addressSpaceId = Libgultra_TrwReadTlbEntry() & 0xFF;
    entry = &D_800F3470[0].pageMask;
    for (i = 16; i < 48; i++) {
        D_800F2D00[i].first = -1;
        D_800F2D00[i].flags = 0;
        pageMask = *entry++;
        entryHi = *entry++;
        entryLo0 = *entry++;
        entryLo1 = *entry++;
        if ((entryLo0 | entryLo1) & TLBLO_V) {
            pageMask &= TLBPGMASK_16M;
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
                if ((entryLo0 & entryLo1 & (TLBLO_V | TLBLO_G)) != (TLBLO_V | TLBLO_G)) {
                    if ((entryLo0 & (TLBLO_V | TLBLO_G)) == TLBLO_V && (entryHi & TLBHI_PIDMASK) != addressSpaceId) entryLo0 &= ~TLBLO_V;
                    if ((entryLo1 & (TLBLO_V | TLBLO_G)) == TLBLO_V && (entryHi & TLBHI_PIDMASK) != addressSpaceId) entryLo1 &= ~TLBLO_V;
                }
                first = entryHi & TLBHI_VPN2MASK;
                if (entryLo0 & entryLo1 & TLBLO_V) pageSize <<= 1;
                else if (entryLo1 & TLBLO_V) first += pageSize;
                D_800F2D00[i].first = first;
                D_800F2D00[i].last = first + pageSize - 1;
                D_800F2D00[i].flags = MEMORY_READ | MEMORY_WRITE;
            }
        }
    }
    boundary = &D_800CB3A0[0].last;
    first = 0x80000000;
    while (*boundary < first) boundary += 2;
    rangeCount = 0;
    do {
        D_800F2D00[rangeCount].first = first;
        D_800F2D00[rangeCount].last = *boundary++;
        D_800F2D00[rangeCount].flags = *boundary++;
        first = D_800F2D00[rangeCount].last + 1;
        rangeCount++;
    } while (first != 0);
    for (; rangeCount < 16; rangeCount++) {
        D_800F2D00[rangeCount].first = -1;
        D_800F2D00[rangeCount].flags = 0;
    }
}
