#include "span_1000/code_8023A284.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_8023B9A0.h"
#include "types.h"


/* Array views share measured storage: FF F2A - FF B5B = 0x3CF;
 * the two four-byte-stride index streams occupy adjacent bytes. */

extern State_func_8023B9C0_eu D_800FF230;

extern Link_func_8023CC08_de *D_800FFE20;

static __inline__ Link_func_8023CC08_de *readLink(Link_func_8023CC08_de **value) { return *value; }

static __inline__ void writeLink(Link_func_8023CC08_de **where, Link_func_8023CC08_de *value) { *where = value; }

/* Releases one page of a resource's TLB slot: clears the odd (flag 1) or even page of the slot's entry in
 * D_80103F28 and, when the other page is still in use, remaps the slot with only that page through
 * func_802AD370_de; otherwise it unmaps the slot through osUnmapTLB and frees its virtual page. The
 * resource then has no slot. */







int func_8023BC74_de(void) {
    u16 previous;
    s16 index;
    previous = D_800FFFA0[0];
    D_800FFFA0[0] = previous + 1;
    if ((s16)(previous + 1) >= 24) {
        D_800FFFA0[0] = D_800FFFA0[1];
    }
    index = (s16)previous;
    if (D_800FFB5B.first.indices[index * 4] != 0xFF) {
        D_800FFB5B.marks[D_800FFB5B.first.indices[index * 4] << 4] = 0xFF;
        D_800FFB5B.first.indices[index * 4] = 0xFF;
    }
    if (D_800FFB5B.second.indices[index * 4] != 0xFF) {
        D_800FFB5B.marks[D_800FFB5B.second.indices[index * 4] << 4] = 0xFF;
        D_800FFB5B.second.indices[index * 4] = 0xFF;
    }
    return index;
}

void func_8023BD34_de(u16 flags, Link_func_8023CC08_de *item, s32 unused, u8 *out) {
    extern void func_802AD370_de(s32, s32, s32, u32, s32, s32);
    u8 *pair;
    s32 mapped;
    s32 slot;
    Link_func_8023CC08_de *entry;
    u32 first;
    s32 second;
    pair = out;
    if (flags & 1) pair = out - 1;
    if (pair[0] != 0xFF && D_800FFB5B.marks[pair[0] * 16] != 0xFF) {
        slot = D_800FFB5B.marks[pair[0] * 16];
        D_80103F28[(s16)slot].slot = item->index;
    } else if (pair[1] != 0xFF && D_800FFB5B.marks[pair[1] * 16] != 0xFF) {
        slot = D_800FFB5B.marks[pair[1] * 16];
        D_80103F28[(s16)slot].team = item->index;
    } else {
        slot = func_8023BC74_de();
        if (flags & 1) {
            D_80103F28[(s16)slot].slot = item->index;
            if (pair[0] != 0xFF) {
                entry = &D_800FF230.slots[pair[0]].chain;
                D_80103F28[(s16)slot].team = entry->index;
                entry->slot = slot;
                if (readLink(&entry->prev) != 0) readLink(&entry->prev)->next = readLink(&entry->next);
                else { D_800FFE20 = readLink(&entry->next); readLink(&entry->next)->prev = 0; }
                if (readLink(&entry->next) != 0) readLink(&entry->next)->prev = readLink(&entry->prev);
                else { D_800FFE24 = readLink(&entry->prev); readLink(&entry->prev)->next = 0; }
                writeLink(&entry->next, 0);
                writeLink(&entry->prev, D_800FF230.tail);
                if (D_800FF230.tail != 0) D_800FF230.tail->next = entry;
                D_800FFE24 = entry;
                if (D_800FFE20 == 0) D_800FFE20 = entry;
            }
        } else {
            D_80103F28[(s16)slot].team = item->index;
            if (pair[1] != 0xFF) {
                entry = &D_800FF230.slots[pair[1]].chain;
                D_80103F28[(s16)slot].slot = entry->index;
                entry->slot = slot;
                if (readLink(&entry->prev) != 0) readLink(&entry->prev)->next = readLink(&entry->next);
                else { D_800FFE20 = readLink(&entry->next); readLink(&entry->next)->prev = 0; }
                if (readLink(&entry->next) != 0) readLink(&entry->next)->prev = readLink(&entry->prev);
                else { D_800FFE24 = readLink(&entry->prev); readLink(&entry->prev)->next = 0; }
                writeLink(&entry->next, 0);
                writeLink(&entry->prev, D_800FF230.tail);
                if (D_800FF230.tail != 0) D_800FF230.tail->next = entry;
                D_800FFE24 = entry;
                if (D_800FFE20 == 0) D_800FFE20 = entry;
            }
        }
        D_80103F28[(s16)slot].id = flags & 0xFFFE;
    }
    item->id = flags;
    item->slot = slot;
    *out = item->index;
    mapped = (s16)slot;
    unused = D_80103F28[mapped].id << 12;
    if (D_80103F28[mapped].team != 0xFF)
        first = ((u32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[mapped].team << 12);
    else first = -1;
    func_802AD370_de(mapped, 0, unused, first,
        D_80103F28[(s16)slot].slot != 0xFF ? ((u32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[(s16)slot].slot << 12) : -1, 7);
}

void func_8023C084_de(Mapping *mapping) {
    extern void func_802AD370_de(s32, s32, s32, s32, s32, s32);
    s32 slot;

    if (mapping->slot == 0xFF) {
        return;
    }
    if (mapping->flags & 1) {
        D_80103F28[mapping->slot].slot = 0xFF;
        slot = mapping->slot;
        if (D_80103F28[slot].team == 0xFF) {
            goto unmap;
        }
        func_802AD370_de(slot, 0, D_80103F28[slot].id << 12,
                      ((s32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[slot].team << 12), -1, 7);
    } else {
        D_80103F28[mapping->slot].team = 0xFF;
        slot = mapping->slot;
        if (D_80103F28[slot].slot == 0xFF) {
        unmap:
            osUnmapTLB(slot);
            D_80103F28[mapping->slot].id = 0xFFFF;
        } else {
            func_802AD370_de(slot, 0, D_80103F28[slot].id << 12, -1,
                          ((s32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[slot].slot << 12), 7);
        }
    }
    mapping->slot = 0xFF;
}
