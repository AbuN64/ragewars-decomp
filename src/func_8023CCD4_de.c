#include "span_1000/code_8023B9A0.h"
#include "types.h"
/* Releases the resource node whose id matches the handle's upper bits: unlinks it from the D_80103F88
 * list, frees each slot it holds through func_8023C084_de and marks the slot unused, then posts the node
 * back to the handle's message queue. */







extern Node_func_8023CCD4_de D_80103F88;
extern Slot_func_8023CCD4_de D_800FFB50[];
extern void func_8023C084_de(Slot_func_8023CCD4_de *);
extern s32 func_802BB420_de(s32, Node_func_8023CCD4_de *, s32);

void func_8023CCD4_de(OwnerRecAt8V2 *arg0) {
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
