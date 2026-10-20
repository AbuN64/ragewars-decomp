#include "COMMON/EXTERNS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "TYPES.H"
#include "AUDIO_2/80255280_2.H"

/* Inserts or replaces a keyed value in the address hash table, probing odd overflow slots when its home chain is occupied. The new slot address is written as the scaled index plus the table address because the cartridge adds the index first; array indexing reorders the add and its registers (15 words). */

extern s32 D_80101190;

extern s32 D_80101190;

typedef struct Shared_HeapBlock Shared_HeapBlock;

struct Shared_HeapBlock {
    u32 start;
    u32 unknown4[2];
    u32 flags;
    u32 unknown10[5];
    Shared_HeapBlock *next;
};

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

void func_80255488_de(s32 arg0) {
    s32 key;
    EntryRecAtCV1 *temp_v0;
    EntryRecAtCV1 *var_a0;
    EntryRecAtCV1 *var_a2;
    EntryRecAtCV1 *var_v1;

    key = arg0;
    var_v1 = D_80101194 + (((key << 5) ^ ((u32)key >> 1) ^
                            ((u32)key >> 9) ^ ((u32)key >> 0x11)) &
                           D_80101190);
    var_a2 = 0;
    if (var_v1->key != key) {
loop:
        var_a2 = var_v1;
        var_v1 = var_v1->next;
        if (var_v1 != 0) {
            if (var_v1->key == key) {
                goto found;
            }
            goto loop;
        }
    } else {
found:
        if (var_v1 != 0) {
            var_a0 = var_v1->next;
            if (var_a0 != 0) {
                var_v1->value = var_a0->value;
                var_v1->key = var_a0->key;
                var_v1->next = var_a0->next;
                temp_v0 = var_v1;
                var_v1 = var_a0;
                var_a0 = temp_v0;
            }
            if (var_a2 != 0) {
                var_a2->next = var_a0;
            }
            var_v1->value = 0;
            var_v1->key = 0;
            var_v1->next = 0;
        }
    }
}

/* Rounds a value up to a power of two by locating its highest set bit and bumping it unless exactly one bit is set. Adapted from func_80261614_de, with a signed loop counter, an exactly-one-bit test, and 1 << bit returned instead of the bit index. */

s32 func_80255540_de(s32 arg0) {
    s32 var_a1;
    s32 var_a2;
    s32 var_v1;

    var_a1 = 0;
    var_a2 = 0;
    var_v1 = 0;
    do {
        if (arg0 & (u32)(1 << var_v1)) {
            var_a1 += 1;
            var_a2 = var_v1;
        }
        var_v1 += 1;
    } while (var_v1 < 0x20);
    if (var_a1 != 1) {
        var_a2 += 1;
    }
    return 1 << var_a2;
}

void func_8025558C_de(void) {
    s32 var_a1;
    s32 var_v1;
    u32 var_a0;
    u32 var_a0_2;
    u32 limit;
    Shared_HashLink *var_v0;
    Shared_HashLink *buckets;

    var_a1 = 0;
    var_a0 = var_a1;
    limit = D_800CB6F0;
    if (limit != 0) {
        var_v1 = limit;
        do {
            var_a0 += 1;
        } while (var_a0 < (u32)var_v1);
    }
    var_a0_2 = 0;
    if (D_800CB6F0 != 0) {
        buckets = (Shared_HashLink *)D_80101194;
        do {
            var_v0 = &buckets[var_a0_2];
            var_v1 = 0;
            if (var_v0 != 0) {
                do {
                    var_v0 = var_v0->next;
                    var_v1 += 1;
                } while (var_v0 != 0);
            }
            if (var_v1 < var_a1) {
                var_v1 = var_a1;
            }
            var_a0_2 += 1;
            var_a1 = var_v1;
        } while (var_a0_2 < D_800CB6F0);
    }
    if (D_800CB6F8 != 0) {
        D_800CB6F8 = 0;
    }
}
