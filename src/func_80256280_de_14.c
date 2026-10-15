#include "span_1000/code_80256220.h"
#include "span_1000/code_802BB15C.h"
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

/* Returns the physical address of a ROM offset through the 0x300-byte ROM window cache: a cached window
 * covering the offset and length is stamped with the current frame; otherwise a free window node is
 * linked in address order (or at the head), aligned to an even start, stamped, counted, filled from ROM
 * through func_80256454_de and its buffer address returned with the odd byte added back. */






extern Window *D_80107DF8;

extern char D_801011B8;

extern void func_80256454_de(void *, u32, s32, s32, void *, s32, s32);

void func_80256FC0_de(void) {
    extern void func_802B2480_de(void *arg0, void **arg1);
    extern void func_802B2450_de(Node_func_80256FC0_de *arg0);
    extern Node_func_80256FC0_de *D_80107DF4[];
    extern char D_80107DD8[];
    extern u32 D_800CB704_de;
    extern u32 D_800CB700_de;
    u32 i;
    s32 value;
    Node_func_80256FC0_de *node;
    Node_func_80256FC0_de *next;

    value = 0;
    for (i = 0; i < D_800CB704_de; i++) {
        func_802BB2A0_de(D_80107DD8, &value, 1);
    }

    node = D_80107DF4[0];
    if (node != 0) {
        do {
            next = node->prev;
            if (node->age + 1 < D_800CB700_de) {
                if (D_80107DF4[0] == node) {
                    D_80107DF4[0] = next;
                }
                func_802B2450_de(node);
                if (D_80107DF4[1] != 0) {
                    func_802B2480_de(node, (void **)D_80107DF4[1]);
                } else {
                    D_80107DF4[1] = node;
                    node->prev = 0;
                    node->next = 0;
                }
            }
            node = next;
        } while (node != 0);
    }

    D_800CB704_de = 0;
    D_800CB700_de++;
}

u32 func_802570C0_de(void *block, s32 size) {
    extern u32 func_802BBBC0_de(void *);
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

u32 func_802571F0_de(s32 offset, s32 length) {
    extern u32 func_802BBBC0_de(s32);
    extern void func_802B2480_de(Window *, Window *);
    extern void func_802B2450_de(Window *);
    extern Window *D_80107DF4;
    extern char D_80107DD8;
    extern s32 D_800CB704_de;
    extern s32 D_800CB700_de;
    Window *window;
    Window *after;
    Window **pool;
    u32 address;
    s32 end;
    s32 top;
    s32 odd;
    s32 word;

    after = 0;
    address = offset + D_801076A0;
    end = address + length;
    for (window = D_80107DF4; window != 0; window = window->next) {
        top = window->base + 0x300;
        word = window->base;
        if (address < word) {
            break;
        }
        after = window;
        if (top >= end) {
            window->frame = D_800CB700_de;
            return func_802BBBC0_de(window->buffer + address - window->base);
        }
    }
    pool = &D_80107DF8;
    window = *pool;
    *pool = window->next;
    func_802B2450_de(window);
    if (after != 0) {
        func_802B2480_de(window, after);
    } else if (pool[-1] != 0) {
        after = pool[-1];
        pool[-1] = window;
        window->next = after;
        window->prev = 0;
        after->prev = window;
    } else {
        pool[-1] = window;
        window->next = 0;
        window->prev = 0;
    }
    odd = address & 1;
    address -= odd;
    window->base = address;
    window->frame = D_800CB700_de;
    word = window->buffer;
    D_800CB704_de++;
    func_80256454_de(&D_801011B8, address, 0x300, word, &D_80107DD8, 0, 1);
    return func_802BBBC0_de(word) + odd;
}
