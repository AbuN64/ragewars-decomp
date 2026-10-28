#include "COMMON/OWNERRECAT8V2.H"
#include "SCHED/SKY_POSTSCREENMESSAGE.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/libgultra/OSUNMAPTLBALL.H"
#include "sdk/os.h"
#include "RESMGR/X_PLUS.H"
#include "ENGINE/VIRTUAL/VHANDLER.H"
#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AUDIO/GETTHREADID.H"
#include "SCHED/RESOURCE_PAGE_WORKER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/CACHE_RELEASERESOURCE.H"
#include "ENGINE/VIRTUAL/VHANDLER_3.H"
#include "ENGINE/VIRTUAL/VHANDLER_5.H"

/* VHANDLER.CPP */
/* Initializes the game state: clears the whole state block and fills its slot and lookup tables
   with 0xFF, resets the 24 player entries and queue slots, sets up the three lists and the stream
   descriptor for the ROM data at D_16E000, loads the expansion-pak data when more memory is present,
   and builds the eight channels, the message pool and the sprite queue. */

extern char D_801011B8[];

extern void func_8025637C_de(void *dst, void *rom, void *size, u32 extra);
extern u32 Defs_GetMemorySize(void);
extern void func_802AD370_de(s32 arg0, s32 arg1, s32 arg2, u32 addr, s32 arg4, s32 arg5);
extern void osCreateThread(void *queue, s32 count, void *arg2, s32 arg3, void *data, s32 arg5);
extern void osSetEventMesg(s32 count, void *list, s16 *arg2);
extern void osStartThread(void *queue);

static inline void fill(void *dst, u8 value, s32 n) {
    u8 *p = dst;

    while (n--) {
        *p++ = value;
    }
}

void Vhandler_InitializePagerEuroExtended(void) {
    u32 extra;
    u32 i;

    extra = Defs_GetMemorySize() + 0x80000000;
    if (extra <= 0x80400000) {
        extra = 0;
    }
    fill(&D_800FF230, 0, sizeof(PagerState));
    fill(D_800FF230.lookup, 0xFF, sizeof(D_800FF230.lookup));
    fill(D_800FF230.slots, 0xFF, sizeof(D_800FF230.slots));
    osUnmapTLBAll();
    for (i = 0; i < 24; i++) {
        D_800FF230.entries[i].id = 0xFFFF;
        D_800FF230.entries[i].team = 0xFF;
        D_800FF230.entries[i].slot = 0xFF;
    }
    D_800FF230.fBF4 = 0;
    D_800FF230.head = 0;
    for (i = 0; i < 24; i++) {
        D_800FF230.slots[i].a = 0;
        D_800FF230.slots[i].b = 0;
        Virtual_AppendPageChainNode((Field_void_4 *)&D_800FF230.head, &D_800FF230.slots[i]);
        D_800FF230.slots[i].index = i;
    }
    osCreateMesgQueue(&D_800FF230.completion, D_800FF230.list0Data, 0x21);
    osCreateMesgQueue(&D_800FF230.jobs, D_800FF230.list1Data, 8);
    osCreateMesgQueue(&D_800FF230.pending, D_800FF230.list2Data, 8);
    D_800FF230.regions.start = 0x400;
    D_800FF230.regions.pages = 0x100;
    D_800FF230.regions.map = D_800FF230.lookup;
    D_800FF230.regions.next = 0;
    D_800FF230.regions.source = (u8 (*)[4096])((u32) D_176000 | 0xB0000000);
    D_800FF230.fD72 = 0;
    if (Defs_GetMemorySize() > 0x4FFFFF) {
        func_8025637C_de(D_801011B8, D_176000, D_52BF0, extra);
    }
    if (extra != 0) {
        func_802AD370_de(0, 0x1FE000, 0x400000, extra + 0x80000000, -1, 7);
        D_800FF230.fD70 = 1;
        D_800FF230.fD72 = 1;
    }
    for (i = 0; i < 8; i++) {
        osSendMesg(&D_800FF230.jobs, &D_800FF230.channels[i], 1);
    }
    D_800FF230.f20 = 0;
    osSetEventMesg(0xC, &D_800FF230.completion, &D_800FF230.f20);
    XPlus_FillMemory(D_800FF230.pool, 0x63, 0x200);
    osCreateThread(D_800FF230.queue, 0x63, D_0023C934, 0, D_800FF230.queueData, 0x93);
    osStartThread(D_800FF230.queue);
}

/* VHANDLER_2.CPP */
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

u64 Audio_ReadSystemTime(void);
void *Virtual_FindRegionForPage(u32);
void osWritebackDCacheAll(void);
void func_802BD170_de(s32);

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

/* VHANDLER_3.CPP */
extern Region D_80103F88;


void **Cache_AllocateResource(s32 arg0, s32 arg1, s32 arg2, void *arg3);

void Vhandler_UpdatePagerStatistics(void) {
    u32 var_a2;
    u32 var_a3;
    s32 var_a1;
    u32 *var_a0;
    u32 temp_v1;
    Region *var_v1;
    s32 var_a0_2;
    u16 temp_v0;
    s32 *out;
    s32 *ordered;

    var_a2 = 0;
    var_a3 = 0x80000000;
    var_a1 = 0;
    var_a0 = &D_800FFB5C;
    do {
        temp_v1 = *var_a0;
        if (var_a2 < temp_v1) {
            var_a2 = temp_v1;
        }
        if (temp_v1 < var_a3) {
            var_a3 = temp_v1;
        }
        *var_a0 = temp_v1 + 1;
        var_a1 += 1;
        var_a0 += 4;
    } while (var_a1 < 0x18);

    var_v1 = &D_80103F88;
    var_a0_2 = 0;
    if (&D_80103F88 != 0) {
        do {
            temp_v0 = var_v1->pages;
            var_v1 = var_v1->next;
            var_a0_2 += temp_v0 << 0xC;
        } while (var_v1 != 0);
    }

    out = D_800FF24C;
    ordered = out;
    *ordered = var_a0_2;
    ordered[-3] = var_a2;
    ordered[-2] = var_a3;
    __builtin_memcpy(&out[-1], &((func_80205628_S3 *)D_800FFE20)->unkC, sizeof(s32));
}

void Vhandler_MapBootstrapAddressRange(void) {
    func_802AD370_de(0x1F, 0x1FE000, 0x200000, 0, 0x100000, 7);
}

void *Vhandler_AllocateVirtualRegion(s32 arg0, s32 arg1_unused, s32 arg2)
{
  char sp10[0x18];
  int new_var2;
  Block10 blk;
  s32 sp38;
  u32 temp_s1;
  void *sp3C;
  u32 rounded;
  void **temp_v0;
  Draw *temp_v1;
  int new_var;
  temp_s1 = ((u32) (arg0 + 0xFFF)) >> 0xC;
  new_var = (temp_s1 + 1) & (~1);
  if (1)
  {
    osCreateMesgQueue(sp10, (s32) (&sp38), 1);
    blk.f28 = 3;
    blk.f2C = arg0;
    blk.f34 = (void **) sp10;
    new_var2 = temp_s1 * 4;
    rounded = new_var + 0x18;
    temp_v0 = Cache_AllocateResource(0, new_var2 + rounded, 3, &s_virtualRegionText);
    temp_v1 = *temp_v0;
    blk.f30 = temp_v1;
    temp_v1->model = temp_v0;
  }
  ((Draw *)blk.f30)->allocationMode = arg2;
  osSendMesg(&D_800FF230.completion, &blk.f28, 1);
  osRecvMesg(sp10, &sp3C, 1);
  return sp3C;
}

void Vhandler_FreeVirtualRegion(s32 arg0) {
    char sp10[0x18];
    BlockVirtualFreeVirtualRegion block;
    s32 sp38;
    void *sp3C;

    osCreateMesgQueue(sp10, (s32)&sp38, 1);
    block.type = 2;
    block.value = arg0;
    block.data = sp10;
    osSendMesg(&D_800FF230.completion, &block, 1);
    osRecvMesg(sp10, &sp3C, 1);
    Cache_ReleaseResource(0, ((Draw *)(sp3C))->model);
}

void Vhandler_GetPagerCounters(struct PagerCounters *arg0) {
    *arg0 = D_800FF230.counters;
}

/* Resource manager thread setup and loop: fills a 0x200-byte stack with a marker, creates and starts the
 * thread object at D_80103720 (entry D_0023CA24, stack top D_800FFB50), then forever receives request
 * messages and dispatches on the request type to Vhandler_HandleResourcePageRequest, Virtual_FinishPageJob, Virtual_ReleaseVirtualRegion or
 * Virtual_AssignVirtualRegion. */
extern char D_0023CA24[];

void Vhandler_RunPagerDispatcher(void) {
    OSMesg request;

    XPlus_FillMemory(D_800FF230.pool2, 0x62, sizeof(D_800FF230.pool2));
    osCreateThread(D_800FF230.queueData, 0x62, D_0023CA24, 0, D_800FF230.pool2 + sizeof(D_800FF230.pool2), 0x94);
    osStartThread(D_800FF230.queueData);
    for (;;) {
        osRecvMesg(&D_800FF230.completion, &request, 1);
        switch (((Request *)request)->type) {
        case 0:
            Vhandler_HandleResourcePageRequest();
            break;
        case 1:
            Virtual_FinishPageJob(request);
            break;
        case 3:
            Virtual_AssignVirtualRegion(request);
            break;
        case 2:
            Virtual_ReleaseVirtualRegion(request);
            break;
        }
    }
}

extern void func_802BCF70_de(void *addr, s32 size);
extern void func_802BD010_de(void *addr, s32 size);

/* Resource page reader thread: takes page jobs from the pending queue, reads the page from the cartridge
 * into its slot of the page array, writes the data cache back and invalidates the instruction cache, then
 * returns the job to the manager. */
void Vhandler_RunPageLoadWorker(void *unused) {
    OSMesgQueue queue;
    OSMesg queueMessage;
    OSMesg message;

    osCreateMesgQueue(&queue, &queueMessage, 1);
    for (;;) {
        osRecvMesg(&D_800FF230.pending, &message, 1);
        if (*((ResourcePageJob *)message)->slot == 0xFF) {
            func_8025637C_de(D_801011B8, ((ResourcePageJob *)message)->source, (void *)((((ResourcePageJob *)message)->size + 1) & ~1),
                             (u32)&D_8014E000 + (((ResourcePageJob *)message)->mapping->index << 12));
            func_802BCF70_de(&D_8014E000 + (((ResourcePageJob *)message)->mapping->index << 12), 0x1000);
            func_802BD010_de(&D_8014E000 + (((ResourcePageJob *)message)->mapping->index << 12), 0x1000);
        }
        ((Request *)message)->type = 1;
        osSendMesg(&D_800FF230.completion, message, 1);
    }
}

typedef struct PageChain {
    ResourcePageMapping *head;
    ResourcePageMapping *tail;
} PageChain;

/* Unlinks a mapping from a doubly linked chain. */
void Vhandler_RemovePageChainNode(PageChain *list, ResourcePageMapping *node) {
    if (node->prev != 0) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
        node->next->prev = 0;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
        node->prev->next = 0;
    }
}

/* VHANDLER_5.CPP */
/* VHANDLER_4.CPP */

void Virtual_AppendPageChainNode(Field_void_4 *arg0, void *pageNode) {
    void *previousTail;

    *(void **)pageNode = 0;
    ((Field_void_4 *)(pageNode))->value = arg0->value;
    previousTail = arg0->value;
    if (previousTail != 0) {
        *(void **)previousTail = pageNode;
    }
    arg0->value = pageNode;
    if (*(void **)arg0 == 0) {
        *(void **)arg0 = pageNode;
    }
}

void Virtual_PrependPageChainNode(Field_void_4 *arg0, Field_void_4 *arg1) {
    void *temp_v0;

    arg1->value = 0;
    *(void **)arg1 = *(void **)arg0;
    temp_v0 = *(void **)arg0;
    if (temp_v0 != 0) {
        ((Field_void_4 *)(temp_v0))->value = arg1;
    }
    *(void **)arg0 = arg1;
    if (arg0->value == 0) {
        arg0->value = arg1;
    }
}

void *Virtual_FindRegionForPage(u32 arg0) {
    NodeVirtualFindRegionForPage *region;
    u16 firstPage;

    region = (NodeVirtualFindRegionForPage *)&D_80103F88;
    if (&D_80103F88 != 0) {
    loop_1:
        firstPage = region->f4;
        if ((arg0 < firstPage) || (arg0 >= (u32)(firstPage + region->f6))) {
            region = region->next;
            if (region != 0) {
                goto loop_1;
            }
        }
    }
    return region;
}

/* VHANDLER_5.CPP */

/* Releases the resource node whose id matches the handle's upper bits: unlinks it from the D_80103F88
 * list, frees each slot it holds through Vhandler_UnmapResourcePage and marks the slot unused, then posts the node
 * back to the handle's message queue. */

/* Registers a memory region: rounds its size to whole pages, places it after the last region of the chain at D_80103F88 on an even page at or above 0x800, marks every page of its map as free, and maps it through func_802BB420_de. */

ResourcePageMapping *Virtual_AcquireRecycledPage(void) {
    ResourcePageMapping *entry;
    NodeVirtualAcquireRecycledPage *node;

    entry = D_800FFE20;
    if (entry->prev != 0) {
        entry->prev->next = *(ResourcePageMapping * volatile *)&entry->next;
    } else {
        D_800FFE20 = entry->next;
        (*(ResourcePageMapping * volatile *)&entry->next)->prev = 0;
    }
    if (entry->next != 0) {
        entry->next->prev = *(ResourcePageMapping * volatile *)&entry->prev;
    } else {
        D_800FFE24 = entry->prev;
        (*(ResourcePageMapping * volatile *)&entry->prev)->next = 0;
    }

    Vhandler_UnmapResourcePage(entry);
    if (entry->id != 0xFFFF) {
        node = Virtual_FindRegionForPage(entry->id);
        node->data[entry->id - node->start] = 0xFF;
        entry->id = 0xFFFF;
    }
    entry->fieldC = 0;
    return entry;
}

void Virtual_ReleaseVirtualRegion(OwnerRecAt8V2 *arg0) {
    Region *node;
    Region *prev;
    u8 *slot;
    s32 i;
    u32 key;

    node = &D_80103F88;
    key = arg0->handle >> 12;
    prev = 0;
    while (node != 0) {
        if (node->start == key) {
            break;
        }
        prev = node;
        node = node->next;
    }
    prev->next = node->next;
    slot = node->map;
    for (i = 0; i < node->pages; i++) {
        if (*slot != 0xFF) {
            Vhandler_UnmapResourcePage(&D_800FFB50[*slot]);
            D_800FFB50[*slot].id = 0xFFFF;
        }
        slot++;
    }
    osSendMesg(arg0->queue, node, 1);
}

void Virtual_AssignVirtualRegion(RegionDesc *desc)
{
    Region *p;
    Region *prev;
    Region *r;
    unsigned int start;
    s32 pages;
    s32 count;
    u8 *map;
    s32 i;
    s32 fill;

    start = 0;
    pages = (desc->size + 0xFFF) / 0x1000;
    p = &D_80103F88;
    prev = 0;
    r = desc->region;
    r->map = (u8 *)(r + 1);
    count = (pages + 1) & ~1;
    for (; p != 0; p = p->next) {
        prev = p;
        start = p->start + p->pages;
    }
    if (start & 1) {
        start++;
    }
    if (start < 0x800) {
        start = 0x800;
    }
    i = count;
    r->start = start;
    r->pages = pages;
    r->next = 0;
    prev->next = r;
    map = r->map;
    fill = 0xFF;
    while (i-- != 0) {
        *map++ = fill;
    }
    osSendMesg(desc->mapping, start << 12, 1);
}

extern char D_800FFCD0[];

void Virtual_FinishPageJob(ResourcePageJob *req) {
    ResourcePageMapping *link;

    if (*req->slot == 0xFF) {
        link = req->mapping;
        writeLink(&link->next, 0);
        writeLink(&link->prev, D_800FF230.tail);
        if (D_800FF230.tail != 0) {
            D_800FF230.tail->next = link;
        }
        D_800FFE24 = link;
        if (D_800FFE20 == 0) {
            D_800FFE20 = link;
        }
        Vhandler_MapResourcePage(req->page, req->mapping, req->thread->slot, req->slot);
        func_802BCF70_de((void *)(req->page << 12), 0x1000);
        func_802BD010_de((void *)(req->page << 12), 0x1000);
    } else {
        link = req->mapping;
        writeLink(&link->prev, 0);
        writeLink(&link->next, D_800FF230.head);
        if (D_800FF230.head != 0) {
            D_800FF230.head->prev = link;
        }
        D_800FFE20 = link;
        if (D_800FFE24 == 0) {
            D_800FFE24 = link;
        }
    }
    req->thread->state = 2;
    osStartThread(req->thread);
    osSendMesg(D_800FFCD0, req, 1);
}

#if defined(VERSION_EU_X)
unsigned int func_8023D008_eu_x_padding_3DC08[2] = {
    0x0C09C7E5, 0x02203021,
};
#endif

#if defined(VERSION_DE)
unsigned int func_8023CFC8_de_padding_3DBC8[2] = {
    0x27BDFFF0, 0x3C01800D,
};
#endif

/* VHANDLER_1.CPP */
#if !(defined(VERSION_US_REV1))
const char g_virtualRegionText[15] =
    "Virtual Region\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8023C78C_C92F0_us_rev1.c */
const unsigned char s_virtualRegionText[15] = {
    0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x20, 0x52, 0x65, 0x67, 0x69, 0x6F, 0x6E, 0x00,
};
#endif

/* VHANDLER_4.CPP */
const unsigned int D_auto_src_rw_pool_8023C1F0_C9300_us_rev1[4] = {
    0x358637BD, 0x40000000, 0x358637BD, 0x40000000,
};
