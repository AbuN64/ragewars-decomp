#include "span_1000/code_8023A284.h"
#include "span_1000/code_8023B9A0.h"
#include "TYPES.H"
#include "common/unused.h"

extern Link_func_8023CC08_de *D_800FFE20;


extern Node_func_8023CC08_de *func_8023CBC0_de(u32 arg0);

/* Releases the resource node whose id matches the handle's upper bits: unlinks it from the D_80103F88
 * list, frees each slot it holds through func_8023C084_de and marks the slot unused, then posts the node
 * back to the handle's message queue. */










/* Registers a memory region: rounds its size to whole pages, places it after the last region of the chain at D_80103F88 on an even page at or above 0x800, marks every page of its map as free, and maps it through func_802BB420_de. */







Link_func_8023CC08_de *func_8023CC08_de(void) {
    extern void func_8023C084_de(void *arg0);
    Link_func_8023CC08_de *entry;
    Node_func_8023CC08_de *node;

    entry = D_800FFE20;
    if (entry->prev != 0) {
        entry->prev->next = *(Link_func_8023CC08_de * volatile *)&entry->next;
    } else {
        D_800FFE20 = entry->next;
        (*(Link_func_8023CC08_de * volatile *)&entry->next)->prev = 0;
    }
    if (entry->next != 0) {
        entry->next->prev = *(Link_func_8023CC08_de * volatile *)&entry->prev;
    } else {
        D_800FFE24 = entry->prev;
        (*(Link_func_8023CC08_de * volatile *)&entry->prev)->next = 0;
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
    extern s32 func_802BB420_de(s32, Node_func_8023CCD4_de *, s32);
    extern void func_8023C084_de(Slot_func_8023CCD4_de *);
    extern Node_func_8023CCD4_de D_80103F88;
    Node_func_8023CCD4_de *node;
    Node_func_8023CCD4_de *prev;
    u8 *slot;
    s32 i;
    u32 key;

    node = &D_80103F88;
    key = arg0->handle >> 12;
    prev = 0;
    while (node != 0) {
        if (node->id == key) {
            break;
        }
        prev = node;
        node = node->next;
    }
    prev->next = node->next;
    slot = node->slots;
    for (i = 0; i < node->count; i++) {
        if (*slot != 0xFF) {
            func_8023C084_de(&D_800FFB50[*slot]);
            D_800FFB50[*slot].id = 0xFFFF;
        }
        slot++;
    }
    func_802BB420_de(arg0->queue, node, 1);
}

void func_8023CDD4_de(RegionDesc *desc)
{
    extern void func_802BB420_de(void *mapping, s32 address, s32 mode);
    extern Region D_80103F88;
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
    r->map = r->data;
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
    func_802BB420_de(desc->mapping, start << 12, 1);
}
