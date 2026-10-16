#include "span_16E000/code_8040F1E0.h"
#include "TYPES.H"
/* Releases every loaded slot of the active, referenced entries of the pool at D_80153C20: each
   loaded slot (flag 1) has its data released through func_80419624_de, its flags and owner cleared and
   the entry's reference count decremented, and an entry left without references is unloaded
   through func_80411518_de and marked inactive. Pool layout and indexed slot access follow func_80411518_de. */









extern Pool_func_8040F580_de D_80153C20;

extern void func_80419624_de(char *data);


void func_8040F580_de(void) {
    s32 e;
    s32 n;
    s32 i;
    SlotRecAtCV2 *slot;

    for (e = 0; e < D_80153C20.count; e++) {
        if (D_80153C20.entries[e].refCount != 0 && D_80153C20.entries[e].active != 0) {
            for (n = 0; n < D_80153C20.entries[e].def->unkE; n++) {
                slot = D_80153C20.entries[e].pages[n];
                for (i = 0; i < 0x60; i++) {
                    if (slot[i].flags & 1) {
                        func_80419624_de(slot[i].data);
                        slot[i].flags = 0;
                        slot[i].owner = 0;
                        D_80153C20.entries[e].refCount--;
                    }
                }
            }
            if (D_80153C20.entries[e].refCount == 0) {
                func_80411518_de(e);
                D_80153C20.entries[e].active = 0;
            }
        }
    }
}
