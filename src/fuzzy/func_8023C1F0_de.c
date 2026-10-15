#include "shared/resource_page_worker.h"
extern ResourcePagerSystem D_800FF230;
extern s32 D_800CB3F8_de;
extern f32 D_800C3610_de, D_800C3614_de, D_800C3618_de, D_800C361C_de;
void *func_802BAD70_de(void);
u64 func_802BADC0_de(void);
void func_8023BD34_de(s16, void *, u8, u8 *);
void func_8023C084_de(void *);
void *func_8023CBC0_de(u16);
s32 func_802BB2A0_de(void *, void **, s32);
s32 func_802BB420_de(void *, void *, s32);
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
    ResourcePageRegion *region;
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
        D_800FF230.requests++;
        page = thread->address >> 12;
        region = &D_800FF230.regions;
        while (region) {
            if (page >= region->first && page < region->first + region->count) break;
            region = region->next;
        }
        if (region) {
            D_800FF230.lastAddress = thread->address;
            slot = &region->slots[page - region->first];
            if (*slot != 0xFF) {
                mapping = &D_800FF230.mappings[*slot];
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
            D_800FF230.misses++;
            job->size = 4096;
            job->source = region->pages[page - region->first];
            mapping = D_800FF230.head;
            detachPage(mapping);
            func_8023C084_de(mapping);
            if (mapping->page != 0xFFFF) {
                region = func_8023CBC0_de(mapping->page);
                region->slots[mapping->page - region->first] = 0xFF;
                mapping->page = 0xFFFF;
            }
            mapping->resident = 0;
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
