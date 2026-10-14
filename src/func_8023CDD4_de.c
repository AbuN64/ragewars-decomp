#include "span_1000/code_8023B9A0.h"
#include "types.h"

/* Registers a memory region: rounds its size to whole pages, places it after the last region of the chain at D_80103F88 on an even page at or above 0x800, marks every page of its map as free, and maps it through func_802BB420_de. */





extern Region D_80103F88;
extern void func_802BB420_de(void *mapping, s32 address, s32 mode);

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
