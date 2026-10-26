#include "MENU/GFX/80414430_24.H"
#include "COMMON/UNUSED.H"
#include "MATH/802A2870.H"
#include "RESMGR/resmgr_stream_callbacks.H"
#include "include_asm.h"
#include "COMMON/SLOTRECATCV1.H"
#include "TYPES.H"
#include "FRONTEND/CODE_80411598.H"
#include "FRONTEND/ARCHIVEDATA.H"
#include "RESMGR/resmgr_stream_io.H"
#include "SCENE/802508E0_13.H"

/* Unloads entry index of the pool at D_80153C20: releases the data of every loaded slot (flag 1) in
   each of the entry's slot ns (the n count comes from the entry's definition) through
   Gfx_ReleaseImage and clears the flag, frees the entry's buffer through Cache_FreeMemory and clears the
   buffer table when one is held, and marks the entry inactive. */









extern PoolFrontendReleaseChunkImages D_80153C20;


void Frontend_ReleaseChunkImages(s32 index) {
    s32 n;
    s32 i;
    SlotRecAtCV1 *slot;

    for (n = 0; n < D_80153C20.entries[index].def->unkE; n++) {
        slot = D_80153C20.entries[index].ns[n];
        for (i = 0; i < 0x60; i++) {
            if (slot[i].flags & 1) {
                Gfx_ReleaseImage((struct OwnedImage *)slot[i].data);
                slot[i].flags &= ~1;
            }
        }
    }
    if (D_80153C20.entries[index].buffers[0] != 0) {
        Cache_FreeMemory(D_80153C20.entries[index].buffers[0]);
        D_80153C20.entries[index].buffers[0] = 0;
        for (n = 0; n < 0x60; n++) {
            D_80153C20.entries[index].buffers[n] = 0;
        }
    }
    D_80153C20.entries[index].active = 0;
}

extern void *Cache_AllocateMemory(s32);

extern void Frontend_RelocateWidgetTree(void *, void *, s32);
extern void XStdio_CloseStream(s32);

/* Loads entry index of the menu archive into memory and counts the use: in cache mode 1 an entry
   already loaded is restored from its saved copy and rebased; otherwise an entry not yet loaded is
   read from the archive file into a new buffer (and copied into a second buffer when copies are
   kept) and rebased. */
void Frontend_AcquireArchiveEntry(s32 index) {
    void *data;
    D_801539B0.RefCount[index]++;
    if (D_801539B0.NeverFreeResources == 1) {
        if (D_801539B0.Screen[index].data == 0) goto load;
        XPlus_CopyBytes(D_801539B0.Screen[index].data, D_801539B0.ScreenOriginal[index].data, D_801539B0.Screen[index].size);
        data = D_801539B0.Screen[index].data;
        Frontend_RelocateWidgetTree(data, data, D_801539B0.Screen[index].offset - D_801539B0.Screen[0].offset);
    }
    if (D_801539B0.Screen[index].data != 0) return;
load:
    func_802A18CC_de();
    D_801539B0.Screen[index].data = Cache_AllocateMemory(D_801539B0.Screen[index].size);
    D_801539B0.In = XStdio_OpenStream(D_801539B0.Name, &D_800DD0B0);
    XStdio_SeekStream(D_801539B0.In, D_801539B0.Header.ScreenData + D_801539B0.Screen[index].offset, 0);
    XStdio_ReadStream(D_801539B0.Screen[index].data, D_801539B0.Screen[index].size, 1, D_801539B0.In);
    if (D_800E2AC4 != 0) {
        D_801539B0.ScreenOriginal[index].data = Cache_AllocateMemory(D_801539B0.Screen[index].size);
        XPlus_CopyBytes(D_801539B0.ScreenOriginal[index].data, D_801539B0.Screen[index].data, D_801539B0.Screen[index].size);
    }
    XStdio_CloseStream(D_801539B0.In);
    D_801539B0.In = 0;
    data = D_801539B0.Screen[index].data;
    Frontend_RelocateWidgetTree(data, data, D_801539B0.Screen[index].offset - D_801539B0.Screen[0].offset);
    func_802A18CC_de();
}
