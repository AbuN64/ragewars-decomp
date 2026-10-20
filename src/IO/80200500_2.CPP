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
extern u32 func_802023DC_de(void);

void func_80200610_de(void) {
    u32 asid, mask, hi, lo0, lo1, size, first, last, count;
    TranslationEntry *entry;
    MemoryRange *range;
    MemoryBoundary *boundary;
    u32 *masks;
    asid = func_802023DC_de();
    entry = D_800F3470;
    range = &D_800F2D00[16];
    range->first = -1;
    do {
        range->flags = 0;
        mask = entry->pageMask;
        hi = entry->entryHi;
        lo0 = entry->entryLo0;
        lo1 = entry->entryLo1;
        entry++;
        if ((lo0 | lo1) & 2) {
            mask &= 0x1FFE000;
            masks = D_800C8148_de;
            size = 0x1000;
            while (*masks != mask) {
                if (*masks++ & 0x80000000) {
                    size = 0;
                    break;
                }
                size <<= 2;
            }
            if (size != 0) {
                if ((lo0 & lo1 & 3) != 3) {
                    if ((lo0 & 3) == 2 && (hi & 0xFF) != (asid & 0xFF)) lo0 &= ~2U;
                    if ((lo1 & 3) == 2 && (hi & 0xFF) != (asid & 0xFF)) lo1 &= ~2U;
                }
                first = hi & 0xFFFFE000;
                if (lo0 & lo1 & 2) size <<= 1;
                else if (lo1 & 2) first += size;
                range->first = first;
                range->last = first + size - 1;
                range->flags = 3;
            }
        }
        range++;
        if (range < &D_800F2D00[48]) range->first = -1;
    } while (range < &D_800F2D00[48]);
    boundary = D_800CB3A0;
    first = 0x80000000;
    if ((s32)boundary->last >= 0) {
        do { boundary++; } while (boundary->last < 0x80000000);
    }
    count = 0;
    range = D_800F2D00;
    do {
        range->first = first;
        last = boundary->last;
        count++;
        range->last = last;
        first = last + 1;
        range->flags = boundary->flags;
        boundary++;
        range++;
    } while (first != 0);
    for (; count < 16; count++, range++) {
        range->first = -1;
        range->flags = 0;
    }
}
#else
INCLUDE_ASM("span_1000", func_80200610_de);
#endif
