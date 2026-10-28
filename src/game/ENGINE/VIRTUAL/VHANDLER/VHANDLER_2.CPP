#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "SCHED/8023A284.H"
#include "TYPES.H"
#include "ENGINE/VIRTUAL/VHANDLER_2.H"
#include "sdk/os.h"
#include "AUDIO_4/802BFE60.H"



/* Array views share measured storage: FF F2A - FF B5B = 0x3CF;
 * the two four-byte-stride index streams occupy adjacent bytes. */


extern ResourcePageMapping *D_800FFE20;

static __inline__ ResourcePageMapping *readLink(ResourcePageMapping **value) { return *value; }

static __inline__ void writeLink(ResourcePageMapping **where, ResourcePageMapping *value) { *where = value; }

/* Releases one page of a resource's TLB slot: clears the odd (flag 1) or even page of the slot's entry in
 * D_80103F28 and, when the other page is still in use, remaps the slot with only that page through
 * func_802AD370_de; otherwise it unmaps the slot through osUnmapTLB and frees its virtual page. The
 * resource then has no slot. */







int Vhandler_RecycleTlbSlot(void) {
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

void Vhandler_MapResourcePage(s16 flags, ResourcePageMapping *item, s32 unused, u8 *out) {
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
        slot = Vhandler_RecycleTlbSlot();
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

void Vhandler_UnmapResourcePage(ResourcePageMapping *mapping) {
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

#include "SCHED/RESOURCE_PAGE_WORKER.H"
extern s32 D_800CB3F8_de;
extern f32 D_800C3610_de;
extern f32 D_800C3614_de;
extern f32 D_800C3618_de;
extern f32 D_800C361C_de;
u64 Audio_ReadSystemTime(void);
void *Virtual_FindRegionForPage(u16);
void osWritebackDCacheAll(void);
void func_802BD170_de(s32);
void osStartThread(void *);

static __inline__ void detachPage(ResourcePageMapping *mapping) {
    if (readLink(&mapping->prev)) readLink(&mapping->prev)->next = readLink(&mapping->next);
    else {
        D_800FFE20 = readLink(&mapping->next);
        readLink(&mapping->next)->prev = 0;
    }
    if (readLink(&mapping->next)) readLink(&mapping->next)->prev = readLink(&mapping->prev);
    else {
        D_800FFE24 = readLink(&mapping->prev);
        readLink(&mapping->prev)->next = 0;
    }
}
/* The pager uses the same two-pointer list operations as its worker. */
/* The LRU list as the pager helpers see it: head D_800FFE20, tail D_800FFE24, reached through a list pointer. */
typedef struct PageList { ResourcePageMapping *head, *tail; } PageList;
static __inline__ ResourcePageMapping *oldestPage(PageList *list) {
    return list->head;
}
static __inline__ void appendPage(Field_void_4 *list, void *node) {
    void *tail;
    *(void **)node = 0;
    ((Field_void_4 *)node)->value = list->value;
    tail = list->value;
    if (tail) *(void **)tail = node;
    list->value = node;
    if (!*(void **)list) *(void **)list = node;
}
static __inline__ Region *findPageRegion(u32 page) {
    Region *region;
    for (region = &D_800FF230.regions; region != 0; region = region->next) {
        if (page >= region->start && page < region->start + region->pages) break;
    }
    return region;
}
void Vhandler_HandleResourcePageRequest(void) {
    ResourcePageThread *thread;
    Region *region;
    ResourcePageMapping *mapping;
    ResourcePageJob *job;
    u8 *slot;
    u32 page, kind;
    u64 start, elapsed;
    f32 duration;
    f32 scale;
    f32 limit;
    thread = Audio_GetInterruptMask();
    kind = thread->message & 0x7C;
    if (kind == 4 || kind == 8) {
        D_800FF230.counters.requests++;
        page = thread->address >> 12;
        region = findPageRegion(page);
        if (region) {
            D_800FF230.counters.lastAddress = thread->address;
            slot = &region->map[page - region->start];
            if (*slot != 0xFF) {
                mapping = &D_800FF230.slots[*slot].chain;
                if (mapping->slot == 0xFF) {
                    detachPage(mapping);
                    Vhandler_MapResourcePage(page, mapping, thread->slot, slot);
                    appendPage((Field_void_4 *)&D_800FFE20, mapping);
                }
                thread->state = 2;
                osStartThread(thread);
                return;
            }
            osRecvMesg(&D_800FF230.jobs, (void **)&job, 1);
            D_800FF230.counters.misses++;
            job->source = region->source[page - region->start];
            job->size = 4096;
            mapping = oldestPage((PageList *)&D_800FFE20);
            detachPage(mapping);
            Vhandler_UnmapResourcePage(mapping);
            if (mapping->id != 0xFFFF) {
                Region *previousRegion = Virtual_FindRegionForPage(mapping->id);
                previousRegion->map[mapping->id - previousRegion->start] = 0xFF;
                mapping->id = 0xFFFF;
            }
            mapping->fieldC = 0;
            job->mapping = mapping;
            job->page = page;
            job->slot = slot;
            job->thread = thread;
            osSendMesg(&D_800FF230.pending, job, 1);
            return;
        }
        start = Audio_ReadSystemTime();
        scale = D_800C3610_de;
        limit = D_800C3614_de;
        do {
            elapsed = ((Audio_ReadSystemTime() - start) << 6) / 3000;
            duration = elapsed;
        } while (duration * scale < limit);
    } else {
        start = Audio_ReadSystemTime();
        scale = D_800C3618_de;
        limit = D_800C361C_de;
        do {
            elapsed = ((Audio_ReadSystemTime() - start) << 6) / 3000;
            duration = elapsed;
        } while (duration * scale < limit);
    }
    osWritebackDCacheAll();
    func_802BD170_de(1);
    ((void (*)(void))0x80000400)();
    D_800CB3F8_de = -1;
    thread->state = 2;
    osStartThread(thread);
}
