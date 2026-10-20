#include "include_asm.h"
#include "COMMON/SLOTRECATCV1.H"
#include "TYPES.H"
#include "FRONTEND/CODE_80411598.H"
#include "FRONTEND/ARCHIVEDATA.H"
#include "RESMGR/802A0888_8.H"
#include "SCENE/802508E0_13.H"

/* Unloads entry index of the pool at D_80153C20: releases the data of every loaded slot (flag 1) in
   each of the entry's slot ns (the n count comes from the entry's definition) through
   func_80419624_de and clears the flag, frees the entry's buffer through func_802547E4_de and clears the
   buffer table when one is held, and marks the entry inactive. */









extern Pool_func_80411518_de D_80153C20;

extern void func_80419624_de(char *data);

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

extern ArchiveFile D_801539B0;
extern s32 D_800E2AC4;
extern char D_800DD0B0;
extern void *func_8025305C_de(s32);
extern void func_802A0724_de(void *, const void *, s32);
extern void func_8040F6DC_de(void *, void *, s32);
extern f64 func_802A18CC_de(void);
extern s32 func_802A0E8C_de(void *, void *);
extern void func_802A0F60_de(s32, s32, s32);
extern void func_802A0EB0_de(s32);

/* Loads entry index of the menu archive into memory and counts the use: in cache mode 1 an entry
   already loaded is restored from its saved copy and rebased; otherwise an entry not yet loaded is
   read from the archive file into a new buffer (and copied into a second buffer when copies are
   kept) and rebased. */
void Frontend_AcquireArchiveEntry(s32 index) {
    void *data;
    D_801539B0.useCounts[index]++;
    if (D_801539B0.mode == 1) {
        if (D_801539B0.map[index].data == 0) goto load;
        func_802A0724_de(D_801539B0.map[index].data, D_801539B0.copies[index].data, D_801539B0.map[index].size);
        data = D_801539B0.map[index].data;
        func_8040F6DC_de(data, data, D_801539B0.map[index].offset - D_801539B0.map[0].offset);
    }
    if (D_801539B0.map[index].data != 0) return;
load:
    func_802A18CC_de();
    D_801539B0.map[index].data = func_8025305C_de(D_801539B0.map[index].size);
    D_801539B0.handle = func_802A0E8C_de(&D_801539B0.header, &D_800DD0B0);
    func_802A0F60_de(D_801539B0.handle, D_801539B0.header.dataOffset + D_801539B0.map[index].offset, 0);
    func_802A0ED4_de(D_801539B0.map[index].data, D_801539B0.map[index].size, 1, D_801539B0.handle);
    if (D_800E2AC4 != 0) {
        D_801539B0.copies[index].data = func_8025305C_de(D_801539B0.map[index].size);
        func_802A0724_de(D_801539B0.copies[index].data, D_801539B0.map[index].data, D_801539B0.map[index].size);
    }
    func_802A0EB0_de(D_801539B0.handle);
    D_801539B0.handle = 0;
    data = D_801539B0.map[index].data;
    func_8040F6DC_de(data, data, D_801539B0.map[index].offset - D_801539B0.map[0].offset);
    func_802A18CC_de();
}
