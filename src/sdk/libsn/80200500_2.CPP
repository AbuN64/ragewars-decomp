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
void func_80200610_de(void) {
    u32 asid, mask, hi, lo0, lo1, size, first, last, count, m, i;
    u32 *entry;
    MemoryRange *range;
    u32 *boundary;
    u32 *masks;
    asid = Libgultra_TrwReadTlbEntry() & 0xFF;
    entry = (u32 *)D_800F3470;
    for (i = 16; i < 48; i++) {
        D_800F2D00[i].first = -1;
        D_800F2D00[i].flags = 0;
        mask = *entry++;
        hi = *entry++;
        lo0 = *entry++;
        lo1 = *entry++;
        if ((lo0 | lo1) & 2) {
            mask &= 0x1FFE000;
            masks = D_800C8148_de;
            size = 0x1000;
            while (1) {
                m = *masks;
                if (m == mask) break;
                masks++;
                if (m & 0x80000000) {
                    size = 0;
                    break;
                }
                size <<= 2;
            }
            if (size != 0) {
                if ((lo0 & lo1 & 3) != 3) {
                    if ((lo0 & 3) == 2 && (hi & 0xFF) != asid) lo0 &= ~2U;
                    if ((lo1 & 3) == 2 && (hi & 0xFF) != asid) lo1 &= ~2U;
                }
                first = hi & 0xFFFFE000;
                if (lo0 & lo1 & 2) size <<= 1;
                else if (lo1 & 2) first += size;
                D_800F2D00[i].first = first;
                D_800F2D00[i].last = first + size - 1;
                D_800F2D00[i].flags = 3;
            }
        }
    }
    boundary = (u32 *)D_800CB3A0;
    first = 0x80000000;
    if ((s32)*boundary >= 0) {
        do { boundary += 2; } while (*boundary < first);
    }
    count = 0;
    do {
        D_800F2D00[count].first = first;
        last = *boundary++;
        D_800F2D00[count].last = last;
        first = last + 1;
        D_800F2D00[count].flags = *boundary++;
        count++;
    } while (first != 0);
    for (; count < 16; count++) {
        D_800F2D00[count].first = -1;
        D_800F2D00[count].flags = 0;
    }
}
#else
INCLUDE_ASM("span_1000", func_80200610_de);
#endif
