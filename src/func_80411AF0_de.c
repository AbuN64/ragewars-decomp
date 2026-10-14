#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80411B68.h"
#include "types.h"
/* Releases UI resource slot i once its retain count reaches zero, closing its open entry and clearing the slot id. */




extern struct EntryRecAt8V1 *D_80153C10;
extern struct ResourceRecAt6 *D_8014D988;
extern void func_80419624_de(s32);

void func_80411AF0_de(s32 i) {
    struct ResourceRecAt6 *resource;

    resource = (struct ResourceRecAt6 *)(i * 8 + (s32)D_8014D988);
    if (resource->id != -1) {
        if (resource->retained > 0) {
            resource->retained--;
        } else {
            if (D_80153C10[i].flags & 1) {
                func_80419624_de(D_80153C10[i].unused);
                D_80153C10[i].flags &= ~1;
            }
            D_8014D988[i].id = 0;
        }
    }
}
