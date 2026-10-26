#include "MENU/GFX/80414430_24.H"
#include "COMMON/UNUSED.H"
#include "MATH/802A2870.H"
#include "RESMGR/resmgr_stream_callbacks.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SLOTRECATCV1.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_36.H"
#include "FRONTEND/CODE_80411598.H"
#include "RESMGR/resmgr_stream_io.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"
extern struct ResourceRecAt6 *D_8014D988;
extern EntryRecAt18V1 *D_80153C10;
extern FileState D_801539B0;
extern void XStdio_CloseStream(s32 file);
extern void *Cache_AllocateMemory(s32 size);
extern void func_80413720_de(s32 id, s32 format, s16 width, s16 height, s32 stride, s32 rows, s32 a6, s32 size, void *pixels, s32 a9, s32 paletteBytes, void *palette, s32 colors);

/* Tears down the UI resource set: releases eligible entries, closes active
   subsystems, frees each nested chunk allocation and the shared tables, then
   clears the complete state record. */






extern s16 D_80153C0C, D_80153C20;

extern struct ChunkRecAt48C *D_80153C28;


extern void Frontend_ReleaseRetainedImageSlot(s32 i);

extern void Frontend_ReleaseActiveChunkImages(void);

extern void Frontend_ReleaseUnprotectedBuffers(s32), Frontend_UpdateImageReleaseTimers(s32), func_80411D18_de(void);


/* Expires cached UI resources against the current tick from func_802A1934_de unless the cache is
   locked: releases through Frontend_ReleaseRetainedImageSlot the first flagged entry whose unretained resource has an
   id below the tick and stops; otherwise, for each live chunk, clears every flagged slot whose time
   has passed (freeing its data through Gfx_ReleaseImage) and stops as soon as a chunk still holds live
   slots after one expires, freeing through Frontend_ReleaseChunkImages and clearing each chunk left empty. */















extern s32 func_802A1934_de(void);


/* Returns a texture's resource id, first loading its pixel and 16-bit palette data, detecting a transparent palette entry and creating the texture resource when it is not yet loaded, and in both cases updates the texture's usage record for the requested mode (1 stamps the next expiry time, 2 pins it, 3 counts a reference); the opened file handle is stored through the header symbol as in the paletted texture loader, and the resource id is held in two locals (the second passed to func_80419640_de), which reproduces the cartridge's three stack slots. */
















extern void func_804133E4_de(s32 id);

extern void func_80419640_de(s32 texture, s32 id);

static inline void touch(s32 index, s32 mode) {
    switch (mode) {
        case 1:
            if (D_8014D988[index].id != -1) {
                D_8014D988[index].id = func_802A1934_de() + 10;
            }
            break;
        case 2:
            D_8014D988[index].id = -1;
            break;
        case 3:
            D_8014D988[index].retained++;
            break;
    }
}

/* Loads texture and palette data, detects transparency and creates the requested texture resource, storing the opened file handle through the header symbol (a codegen choice that keeps the handle address separate from the header base). */









extern void func_80413480_de(s32 output, s32 id);

void Frontend_CloseResourceArchive(void) {
    s32 i;
    s32 invalid;
    s32 i_chunks;
    s32 offset_chunks;
    s32 offset;
    struct ResourceRecAt6 *resource;
    struct ChunkRecAt48C *chunk;
    void **block;
    void **tables;
    void **first;
    void **second;
    FileState *state;
    i = 0;
    if (D_80153C0C > 0) {
        invalid = -1;
        offset = 0;
        do {
            if (((EntryRecAt18V1 *)(offset + (s32)D_80153C10))->unk4 & 1) {
                resource = D_8014D988 + i;
                if (resource->id != invalid && resource->retained == 0) {
                    Frontend_ReleaseRetainedImageSlot(i);
                }
            }
            offset += 0x1C;
        } while (++i < D_80153C0C);
    }
    Frontend_ReleaseActiveChunkImages();
    state = &D_801539B0;
    if (state->unk0) XStdio_CloseStream(state->unk0);
    Frontend_ReleaseUnprotectedBuffers(1);
    Frontend_UpdateImageReleaseTimers(1);
    if (state->entries) Cache_FreeMemory(state->entries);
    i_chunks = 0;
    func_80411D18_de();
    offset_chunks = 0;
    if (state->chunkCount > 0) {
        do {
            block = ((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->optional;
            if (block) {
                Cache_FreeMemory(*block);
                Cache_FreeMemory(((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->optional);
            }
            i_chunks++;
            Cache_FreeMemory(*((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->primary);
            block = ((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->primary;
            offset_chunks += 0x49C;
            Cache_FreeMemory(block);
        } while (i_chunks < D_80153C20);
    }
    tables = D_8014D98C;
    if (tables[0]) Cache_FreeMemory(tables[0]);
    first = tables + 3;
    if (tables[3]) Cache_FreeMemory(tables[3]);
    second = tables + 2;
    if (tables[2]) Cache_FreeMemory(tables[2]);
    if (tables[13]) Cache_FreeMemory(tables[13]);
    if (tables[-1]) Cache_FreeMemory(tables[-1]);
    if (tables[10]) Cache_FreeMemory(tables[10]);
    if (tables[11]) Cache_FreeMemory(tables[11]);
    if (tables[-2]) Cache_FreeMemory(tables[-2]);
    if (tables[12]) Cache_FreeMemory(tables[12]);
    if (tables[7]) Cache_FreeMemory(tables[7]);
    if (first[5]) Cache_FreeMemory(first[5]);
    if (second[3]) Cache_FreeMemory(second[3]);
    XPlus_FillBytes((char *)tables - 0x26C, 0, 0x2A8);
}

void Frontend_EvictExpiredImages(void) {
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
                Frontend_ReleaseRetainedImageSlot(i);
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
                        Gfx_ReleaseImage((struct OwnedImage *)slot->data);
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
                Frontend_ReleaseChunkImages(i);
                D_801539B0.chunks[i].active = 0;
            }
        }
    }
}

s32 Frontend_GetImageTexture(s32 index, s32 mode) {
    s32 id;
    s32 texture;
    u16 *palette;
    void *pixels;
    s32 paletteBytes;
    s32 stride;
    s32 transparent;
    s32 size;
    s32 i;
    s32 format;
    EntryRecAt18V1 *entry;

    if (D_80153C10[index].unk4 & 1) {
        touch(index, mode);
        return D_80153C10[index].unk0;
    }
    palette = 0;
    paletteBytes = 0;
    id = D_80153C10[index].unk0;
    stride = 0;
    func_802A18CC_de();
    ((FileState *)((char *)&D_8014D724 - 4))->unk0 = XStdio_OpenStream(&D_8014D724, &D_800DD0B0);
    entry = &D_8014D724.unk25C[index];
    transparent = 0;
    if (entry->unk8 == 8) {
        stride = (entry->unkA + 7) & -8;
    } else if (entry->unk8 == 4) {
        stride = (entry->unkA + 15) & -16;
    } else if (entry->unk8 == 16) {
        stride = (entry->unkA + 3) & -4;
    }
    func_804133E4_de(id);
    texture = id;
    size = stride * entry->unkC * entry->unk8 / 8;
    pixels = Cache_AllocateMemory(size);
    XStdio_SeekStream(D_801539B0.unk0, D_801539B0.unk248 + entry->unk14, 0);
    XStdio_ReadStream(pixels, size, 1, D_801539B0.unk0);
    if (entry->unkE > 0) {
        paletteBytes = entry->unkE * 2;
        palette = Cache_AllocateMemory(paletteBytes);
        XStdio_SeekStream(D_801539B0.unk0, D_801539B0.unk248 + entry->unk18, 0);
        XStdio_ReadStream(palette, paletteBytes, 1, D_801539B0.unk0);
        for (i = 0; i < entry->unkE; i++) {
            if (!(palette[i] & 1)) {
                transparent = 1;
                D_80153C14[index] = palette[i];
                break;
            }
        }
        if (i == entry->unkE) {
            transparent = 0;
            D_80153C14[index] = 0xFF000000;
        }
    }
    format = -1;
    if (entry->unkE > 0) {
        if (entry->unk8 == 8) {
            format = 32;
            if (transparent) {
                format = 30;
            }
        } else {
            format = 22;
            if (transparent) {
                format = 20;
            }
        }
    } else if (entry->unk8 == 16) {
        format = 5;
    } else if (entry->unk8 == 24) {
        format = 8;
    } else if (entry->unk8 == 32) {
        format = 12;
    }
    func_80413720_de(id, format, entry->unkA, entry->unkC, stride, entry->unkC, 1, size, pixels, 1, paletteBytes,
                  palette, entry->unkE);
    func_80419640_de(texture, id);
    D_80153C10[index].unk4 |= 1;
    XStdio_CloseStream(D_801539B0.unk0);
    D_801539B0.unk0 = 0;
    func_802A18CC_de();
    touch(index, mode);
    return D_80153C10[index].unk0;
}

void func_80410B14_de(s32 index, s32 output) {
    s32 *palette;
    s32 *pixels;
    s32 paletteBytes;
    s32 stride;
    s32 transparent;
    s32 size;
    s32 i;
    s32 format;
    EntryRecAt18V1 *entry;

    if (D_80153C10[index].unk4 & 1) {
        func_80413480_de(output, D_80153C10[index].unk0);
        return;
    }
    palette = 0;
    paletteBytes = 0;
    stride = 0;
    ((FileState *)((char *)&D_8014D724 - 4))->unk0 = XStdio_OpenStream(&D_8014D724, &D_800DD0B0);
    entry = &D_8014D724.unk25C[index];
    transparent = 0;
    if (entry->unk8 == 8) {
        stride = (entry->unkA + 7) & -8;
    } else if (entry->unk8 == 4) {
        stride = (entry->unkA + 15) & -16;
    } else if (entry->unk8 == 16) {
        stride = (entry->unkA + 3) & -4;
    }
    size = stride * entry->unkC * entry->unk8 / 8;
    pixels = Cache_AllocateMemory(size);
    XStdio_SeekStream(D_801539B0.unk0, D_801539B0.unk248 + entry->unk14, 0);
    XStdio_ReadStream(pixels, size, 1, D_801539B0.unk0);
    if (entry->unkE > 0) {
        paletteBytes = entry->unkE * 2;
        palette = Cache_AllocateMemory(paletteBytes);
        XStdio_SeekStream(D_801539B0.unk0, D_801539B0.unk248 + entry->unk18, 0);
        XStdio_ReadStream(palette, paletteBytes, 1, D_801539B0.unk0);
        for (i = 0; i < entry->unkE; i++) {
            if (!(palette[i] & 0xFF000000)) {
                transparent = 1;
                D_80153C14[index] = palette[i];
                break;
            }
        }
        if (i == entry->unkE) {
            transparent = 0;
            D_80153C14[index] = 0xFF000000;
        }
    }
    format = -1;
    if (entry->unkE > 0) {
        if (entry->unk8 == 8) {
            format = 32;
            if (transparent) {
                format = 30;
            }
        } else {
            format = 22;
            if (transparent) {
                format = 20;
            }
        }
    } else if (entry->unk8 == 16) {
        format = 28;
    } else if (entry->unk8 == 24) {
        format = 8;
    } else if (entry->unk8 == 32) {
        format = 12;
    }
    func_80413720_de(output, format, entry->unkA, entry->unkC, stride, entry->unkC, 1, size, pixels, 1, paletteBytes,
                  palette, entry->unkE);
    XStdio_CloseStream(D_801539B0.unk0);
    D_801539B0.unk0 = 0;
}
