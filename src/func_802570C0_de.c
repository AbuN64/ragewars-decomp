#include "span_1000/code_80256220.h"
#include "types.h"
/* Returns the physical address of a cached copy of a data block: finds the cache entry keyed by the
 * block's address and refreshes the copy (and flushes it from the data cache) when the size changed;
 * otherwise reuses a free entry or allocates and links a new 0x90-byte one, copies the block into it and
 * marks it in use. */



extern CacheEntry *D_80107DFC;
extern void *D_80107EA0;

extern void *func_802BD3A0_de(void *destination, const void *source, int count);
extern void func_802BD280_de(void *, s32);
extern s32 func_802B0340_de(s32, s32, void *, s32, s32);
extern u32 func_802BBBC0_de(void *);

u32 func_802570C0_de(void *block, s32 size) {
    CacheEntry *entry;
    CacheEntry *unused;

    unused = 0;
    for (entry = D_80107DFC; entry != 0; entry = entry->next) {
        if (entry->key == block) {
            entry->state = 3;
            if (entry->size != size) {
                entry->size = size;
                func_802BD3A0_de(entry->data, block, size);
                func_802BD280_de(entry->data, size);
            }
            return func_802BBBC0_de(entry->data);
        }
        if (entry->state == 0) {
            unused = entry;
        }
    }
    if (unused == 0) {
        unused = (CacheEntry *)func_802B0340_de(0, 0, D_80107EA0, 1, 0x90);
        unused->next = D_80107DFC;
        D_80107DFC = unused;
        D_800CB714++;
    }
    unused->key = block;
    unused->state = 3;
    unused->size = size;
    func_802BD3A0_de(unused->data, block, size);
    return func_802BBBC0_de(unused->data);
}
