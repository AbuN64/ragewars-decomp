#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "ENGINE/VIRTUAL/VHANDLER_5.H"
#include "SCHED/8023A284.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "ENGINE/VIRTUAL/VHANDLER_2.H"

extern ResourcePageMapping *D_800FFE20;
extern Region D_80103F88;


extern Node_func_8023CC08_de *func_8023CBC0_de(u32 arg0);

/* Releases the resource node whose id matches the handle's upper bits: unlinks it from the D_80103F88
 * list, frees each slot it holds through func_8023C084_de and marks the slot unused, then posts the node
 * back to the handle's message queue. */










/* Registers a memory region: rounds its size to whole pages, places it after the last region of the chain at D_80103F88 on an even page at or above 0x800, marks every page of its map as free, and maps it through func_802BB420_de. */







ResourcePageMapping *func_8023CC08_de(void) {
    ResourcePageMapping *entry;
    Node_func_8023CC08_de *node;

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

    func_8023C084_de(entry);
    if (entry->id != 0xFFFF) {
        node = func_8023CBC0_de(entry->id);
        node->data[entry->id - node->start] = 0xFF;
        entry->id = 0xFFFF;
    }
    entry->fieldC = 0;
    return entry;
}

void func_8023CCD4_de(OwnerRecAt8V2 *arg0) {
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
            func_8023C084_de(&D_800FFB50[*slot]);
            D_800FFB50[*slot].id = 0xFFFF;
        }
        slot++;
    }
    osSendMesg(arg0->queue, node, 1);
}

void func_8023CDD4_de(RegionDesc *desc)
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

#include "SCHED/RESOURCE_PAGE_WORKER.H"

extern char D_800FFCD0[];
extern void func_802BCF70_de(u32, s32);
extern void func_802BD010_de(u32, s32);
extern void func_802BB750_de(void *);

static __inline__ void writeLink(ResourcePageMapping **where, ResourcePageMapping *value) { *where = value; }

void Sched_FinishPageJob(ResourcePageJob *req) {
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
        func_8023BD34_de(req->page, req->mapping, req->thread->slot, req->slot);
        func_802BCF70_de(req->page << 12, 0x1000);
        func_802BD010_de(req->page << 12, 0x1000);
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
    func_802BB750_de(req->thread);
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
