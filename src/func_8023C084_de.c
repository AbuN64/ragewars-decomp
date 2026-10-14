#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023B9A0.h"
#include "types.h"
/* Releases one page of a resource's TLB slot: clears the odd (flag 1) or even page of the slot's entry in
 * D_80103F28 and, when the other page is still in use, remaps the slot with only that page through
 * func_802AD370_de; otherwise it unmaps the slot through func_802AD3F0_de and frees its virtual page. The
 * resource then has no slot. */





extern EntryRecAt3 D_80103F28[];
extern char D_8014E000;
extern void func_802AD370_de(s32, s32, s32, s32, s32, s32);


void func_8023C084_de(Mapping *mapping) {
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
            func_802AD3F0_de(slot);
            D_80103F28[mapping->slot].id = 0xFFFF;
        } else {
            func_802AD370_de(slot, 0, D_80103F28[slot].id << 12, -1,
                          ((s32)&D_8014E000 & 0x3FFFFFF) + (D_80103F28[slot].slot << 12), 7);
        }
    }
    mapping->slot = 0xFF;
}
