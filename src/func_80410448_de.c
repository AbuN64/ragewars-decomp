#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Expires cached UI resources against the current tick from func_802A1934_de unless the cache is
   locked: releases through func_80411AF0_de the first flagged entry whose unretained resource has an
   id below the tick and stops; otherwise, for each live chunk, clears every flagged slot whose time
   has passed (freeing its data through func_80419624_de) and stops as soon as a chunk still holds live
   slots after one expires, freeing through func_80411518_de and clearing each chunk left empty. */













extern struct State_func_80410448_de D_801539B0;

extern s32 func_802A1934_de(void);
extern void func_80411AF0_de(s32 index);
extern void func_80419624_de(char *data);


void func_80410448_de(void) {
    s32 now;
    s32 i;
    s32 j;
    s32 k;
    struct SlotRecAtCV2 *slot;
    struct SlotRecAtCV2 *slots;
    struct ResourceRecAt6 *resource;

    now = func_802A1934_de();
    if (D_801539B0.locked != 0) {
        return;
    }
    for (i = 0; i < D_801539B0.count; i++) {
        if (D_801539B0.entries[i].flags & 1) {
            resource = &D_801539B0.resources[i];
            if (resource->id != -1 && resource->retained == 0 && resource->id < now) {
                func_80411AF0_de(i);
                return;
            }
        }
    }
    for (i = 0; i < D_801539B0.chunkCount; i++) {
        if (D_801539B0.chunks[i].live != 0 && D_801539B0.chunks[i].active != 0) {
            for (j = 0; j < D_801539B0.chunks[i].header->unkE; j++) {
                slots = D_801539B0.chunks[i].slots[j];
                for (k = 0; k < 0x60; k++) {
                    slot = &slots[k];
                    if ((slot->flags & 1) && slot->owner < now) {
                        func_80419624_de(slot->data);
                        slot->owner = 0;
                        slot->flags &= ~1;
                        D_801539B0.chunks[i].live--;
                        if (D_801539B0.chunks[i].live != 0) {
                            return;
                        }
                    }
                }
            }
            if (D_801539B0.chunks[i].live == 0) {
                func_80411518_de(i);
                D_801539B0.chunks[i].active = 0;
            }
        }
    }
}
