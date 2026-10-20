#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "TYPES.H"
#include "SCHED/8023A284_15.H"
#include "sdk/os.h"

#if defined(VERSION_EU_X)
INCLUDE_ASM("span_1000", func_8023B9C0_eu);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_8023B9B0_de);
#endif

/* Array views share measured storage: FF F2A - FF B5B = 0x3CF;
 * the two four-byte-stride index streams occupy adjacent bytes. */

extern PagerState D_800FF230;

extern ResourcePageMapping *D_800FFE20;

static __inline__ ResourcePageMapping *readLink(ResourcePageMapping **value) { return *value; }

static __inline__ void writeLink(ResourcePageMapping **where, ResourcePageMapping *value) { *where = value; }

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

void func_8023BD34_de(s16 flags, ResourcePageMapping *item, s32 unused, u8 *out) {
    extern void func_802AD370_de(s32, s32, s32, u32, s32, s32);
    u8 *pair;
    s32 mapped;
    s32 slot;
    ResourcePageMapping *entry;
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

void func_8023C084_de(ResourcePageMapping *mapping) {
    extern void func_802AD370_de(s32, s32, s32, u32, s32, s32);
    s32 slot;

    if (mapping->slot == 0xFF) {
        return;
    }
    if (mapping->id & 1) {
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

#ifdef NON_MATCHING
#include "SCHED/RESOURCE_PAGE_WORKER.H"
extern s32 D_800CB3F8_de;
extern f32 D_800C3610_de, D_800C3614_de, D_800C3618_de, D_800C361C_de;
void *func_802BAD70_de(void);
u64 func_802BADC0_de(void);
void *func_8023CBC0_de(u16);
void osWritebackDCacheAll(void);
void func_802BD170_de(s32);
void func_802BB750_de(void *);
/* Firmware restart entry at80000400, called by the native fatal-fault path. */
void rw_boot_entry(void);

static __inline__ void detachPage(ResourcePageMapping *mapping) {
    if (mapping->prev) mapping->prev->next = mapping->next;
    else {
        D_800FF230.head = mapping->next;
        mapping->next->prev = 0;
    }
    if (mapping->next) mapping->next->prev = mapping->prev;
    else {
        D_800FF230.tail = mapping->prev;
        mapping->prev->next = 0;
    }
}
void func_8023C1F0_de(void) {
    ResourcePageThread *thread;
    Region *region;
    ResourcePageMapping *mapping;
    ResourcePageJob *job;
    void *message;
    u8 *slot;
    u32 page, kind;
    u64 start, elapsed;
    f32 duration;
    thread = func_802BAD70_de();
    kind = thread->message & 0x7C;
    if (kind == 4 || kind == 8) {
        D_800FF230.counters.requests++;
        page = thread->address >> 12;
        region = &D_800FF230.regions;
        while (region) {
            if (page >= region->start && page < region->start + region->pages) break;
            region = region->next;
        }
        if (region) {
            D_800FF230.counters.lastAddress = thread->address;
            slot = &region->map[page - region->start];
            if (*slot != 0xFF) {
                mapping = &D_800FF230.slots[*slot].chain;
                if (mapping->slot == 0xFF) {
                    detachPage(mapping);
                    func_8023BD34_de(page, mapping, thread->slot, slot);
                    mapping->next = 0;
                    mapping->prev = D_800FF230.tail;
                    if (D_800FF230.tail) D_800FF230.tail->next = mapping;
                    D_800FF230.tail = mapping;
                    if (!D_800FF230.head) D_800FF230.head = mapping;
                }
                thread->state = 2;
                func_802BB750_de(thread);
                return;
            }
            func_802BB2A0_de(&D_800FF230.jobs, &message, 1);
            job = message;
            D_800FF230.counters.misses++;
            job->size = 4096;
            job->source = region->source[page - region->start];
            mapping = D_800FF230.head;
            detachPage(mapping);
            func_8023C084_de(mapping);
            if (mapping->id != 0xFFFF) {
                region = func_8023CBC0_de(mapping->id);
                region->map[mapping->id - region->start] = 0xFF;
                mapping->id = 0xFFFF;
            }
            mapping->fieldC = 0;
            job->mapping = mapping;
            job->page = page;
            job->slot = slot;
            job->thread = thread;
            func_802BB420_de(&D_800FF230.pending, job, 1);
            return;
        }
        start = func_802BADC0_de();
        do {
            elapsed = ((func_802BADC0_de() - start) << 6) / 3000;
            duration = elapsed;
        } while (duration * D_800C3610_de < D_800C3614_de);
    } else {
        start = func_802BADC0_de();
        do {
            elapsed = ((func_802BADC0_de() - start) << 6) / 3000;
            duration = elapsed;
        } while (duration * D_800C3618_de < D_800C361C_de);
    }
    osWritebackDCacheAll();
    func_802BD170_de(1);
    rw_boot_entry();
    D_800CB3F8_de = -1;
    thread->state = 2;
    func_802BB750_de(thread);
}
#else
INCLUDE_ASM("span_1000", func_8023C1F0_de);
#endif
