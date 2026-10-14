#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Unloads entry index of the pool at D_80153C20: releases the data of every loaded slot (flag 1) in
   each of the entry's slot ns (the n count comes from the entry's definition) through
   func_80419624_de and clears the flag, frees the entry's buffer through func_802547E4_de and clears the
   buffer table when one is held, and marks the entry inactive. */









extern Pool_func_80411518_de D_80153C20;

extern void func_80419624_de(char *data);
extern void func_802547E4_de(void *buffer);

void func_80411518_de(s32 index) {
    s32 n;
    s32 i;
    SlotRecAtCV1 *slot;

    for (n = 0; n < D_80153C20.entries[index].def->unkE; n++) {
        slot = D_80153C20.entries[index].ns[n];
        for (i = 0; i < 0x60; i++) {
            if (slot[i].flags & 1) {
                func_80419624_de(slot[i].data);
                slot[i].flags &= ~1;
            }
        }
    }
    if (D_80153C20.entries[index].buffers[0] != 0) {
        func_802547E4_de(D_80153C20.entries[index].buffers[0]);
        D_80153C20.entries[index].buffers[0] = 0;
        for (n = 0; n < 0x60; n++) {
            D_80153C20.entries[index].buffers[n] = 0;
        }
    }
    D_80153C20.entries[index].active = 0;
}
