#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
#include "span_1000/code_802A25C4.h"

extern void func_80255ED8_de(void *, s32);







void func_802A5D38_de(void *arg0, s32 arg1) {
    s32 count;
    s32 offset;
    void **slot;
    Particle *node;
    Particle *next;

    if (((Scene_func_802A5180_de *)arg0)->free.count != 0x64) {
        count = 0;
        offset = 0x94E0;
        do {
            slot = &((Scene_func_802A5180_de *)arg0)->lists[count].head;
            node = *slot;
            if (node != 0) {
                do {
                    next = node->next;
                    if (node->owner == arg1) {
                        func_80255ED8_de(slot, (s32) node);
                        func_80255D14_de(&((Scene_func_802A5180_de *)arg0)->free, node);
                    }
                    node = next;
                } while (node != 0);
            }
            count += 1;
            offset += 0x14;
        } while (count < 0xA);
    }
}
