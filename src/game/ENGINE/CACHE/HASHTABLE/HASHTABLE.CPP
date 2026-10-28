#include "COMMON/EXTERNS.H"
#include "COMMON/LONE/D_801051A0.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "TYPES.H"
#include "AUDIO/80255280.H"

/* Creates the address hash table: rounds the requested capacity up to a power of two, allocates twice that many 16-byte slots from pool D_801051A0 (keeping the half size, slot count and both index masks in globals), and clears every slot, numbering each with its index. */



extern s32 D_80101190;
extern EntryRecAtCV1 *func_80255920_de(void *, s32);

void func_802552E0_de(s32 capacity)
{
    s32 bits = 0;
    s32 top = 0;
    s32 i;
    s32 half;
    u32 n;

    for (i = 0; i < 32; i++) {
        s32 bit = 1 << i;
        if (capacity & bit) {
            bits++;
            top = i;
        }
    }
    if (bits != 1) {
        top++;
    }
    half = 1 << top;
    D_800CB6F4 = half * 2;
    D_800CB6F0 = half;
    D_80101190 = D_800CB6F4 - 2;
    D_80101198 = D_800CB6F4 - 1;
    D_80101194 = func_80255920_de(&D_801051A0, half << 5);
    for (n = 0; n < D_800CB6F4; n++) {
        D_80101194[n].value = 0;
        D_80101194[n].key = 0;
        D_80101194[n].next = 0;
        D_80101194[n].index = n;
    }
}

/* Inserts or replaces a keyed value in the address hash table, probing odd overflow slots when its home chain is occupied. The new slot address is written as the scaled index plus the table address because the cartridge adds the index first; array indexing reorders the add and its registers (15 words). */





typedef struct Shared_HashLink Shared_HashLink;

struct Shared_HashLink {
    u32 unknown0[3];
    Shared_HashLink *next;
};


void func_802553B4_de(u32 key, struct ResourceLoadRequest *value) {
 EntryRecAtCV1 *entry = D_80101194 + (((key<<5)^(key>>1)^(key>>9)^(key>>17)) & D_80101190);
 EntryRecAtCV1 *tail;
 EntryRecAtCV1 *slot;
 s32 index;
 if (entry->value == 0) {entry->key=key;entry->value=value;return;}
 tail=entry;
 for (;;) {
  if (entry->key==key) {entry->value=value;return;}
  entry=tail->next;
  if (!entry) break;
  tail=entry;
 }
 index=tail->index|1;
 while (D_80101194[index].value != 0) {index+=2; index &= D_80101198;}
 slot=(EntryRecAtCV1 *)((index << 4) + (u32)D_80101194);
 slot->key=key;slot->value=value;tail->next=slot;
}

void func_80255488_de(s32 resourceKey) {
    s32 key;
    EntryRecAtCV1 *preservedEntry;
    EntryRecAtCV1 *successorEntry;
    EntryRecAtCV1 *previousEntry;
    EntryRecAtCV1 *entryToClear;

    key = resourceKey;
    entryToClear = D_80101194 + (((key << 5) ^ ((u32)key >> 1) ^
                            ((u32)key >> 9) ^ ((u32)key >> 0x11)) &
                           D_80101190);
    previousEntry = 0;
    if (entryToClear->key != key) {
loop:
        previousEntry = entryToClear;
        entryToClear = entryToClear->next;
        if (entryToClear != 0) {
            if (entryToClear->key == key) {
                goto found;
            }
            goto loop;
        }
    } else {
found:
        if (entryToClear != 0) {
            successorEntry = entryToClear->next;
            if (successorEntry != 0) {
                entryToClear->value = successorEntry->value;
                entryToClear->key = successorEntry->key;
                entryToClear->next = successorEntry->next;
                preservedEntry = entryToClear;
                entryToClear = successorEntry;
                successorEntry = preservedEntry;
            }
            if (previousEntry != 0) {
                previousEntry->next = successorEntry;
            }
            entryToClear->value = 0;
            entryToClear->key = 0;
            entryToClear->next = 0;
        }
    }
}

/* Rounds a value up to a power of two by locating its highest set bit and bumping it unless exactly one bit is set. Adapted from Bitarray_GetRequiredBitCount, with a signed loop counter, an exactly-one-bit test, and 1 << bit returned instead of the bit index. */

s32 func_80255540_de(s32 mask) {
    s32 bitCount;
    s32 highestBit;
    s32 bit;

    bitCount = 0;
    highestBit = 0;
    bit = 0;
    do {
        if (mask & (u32)(1 << bit)) {
            bitCount += 1;
            highestBit = bit;
        }
        bit += 1;
    } while (bit < 0x20);
    if (bitCount != 1) {
        highestBit += 1;
    }
    return 1 << highestBit;
}

void func_8025558C_de(void) {
    s32 maximumChainLength;
    s32 scanCount;
    u32 i;
    u32 j;
    u32 limit;
    Shared_HashLink *chainEntry;
    Shared_HashLink *buckets;

    maximumChainLength = 0;
    i = maximumChainLength;
    limit = D_800CB6F0;
    if (limit != 0) {
        scanCount = limit;
        do {
            i += 1;
        } while (i < (u32)scanCount);
    }
    j = 0;
    if (D_800CB6F0 != 0) {
        buckets = (Shared_HashLink *)D_80101194;
        do {
            chainEntry = &buckets[j];
            scanCount = 0;
            if (chainEntry != 0) {
                do {
                    chainEntry = chainEntry->next;
                    scanCount += 1;
                } while (chainEntry != 0);
            }
            if (scanCount < maximumChainLength) {
                scanCount = maximumChainLength;
            }
            j += 1;
            maximumChainLength = scanCount;
        } while (j < D_800CB6F0);
    }
    if (D_800CB6F8 != 0) {
        D_800CB6F8 = 0;
    }
}
