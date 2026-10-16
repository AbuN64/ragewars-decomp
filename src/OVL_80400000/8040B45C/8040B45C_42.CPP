#include "span_16E000/code_8040B45C.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"
#include "TYPES.H"

/* Tears down the UI resource set: releases eligible entries, closes active
   subsystems, frees each nested chunk allocation and the shared tables, then
   clears the complete state record. */






extern s16 D_80153C0C, D_80153C20;

extern struct ChunkRecAt48C *D_80153C28;

extern void *D_8014D98C[];

extern void func_80411AF0_de(s32 i);

extern void func_8040F580_de(void);

extern void func_804118E4_de(s32), func_80410E1C_de(s32), func_80411D18_de(void);

extern void func_802547E4_de(void *), func_802A0748_de(void *, s32, s32);

/* Expires cached UI resources against the current tick from func_802A1934_de unless the cache is
   locked: releases through func_80411AF0_de the first flagged entry whose unretained resource has an
   id below the tick and stops; otherwise, for each live chunk, clears every flagged slot whose time
   has passed (freeing its data through func_80419624_de) and stops as soon as a chunk still holds live
   slots after one expires, freeing through func_80411518_de and clearing each chunk left empty. */















extern s32 func_802A1934_de(void);

extern void func_80419624_de(char *data);

/* Returns a texture's resource id, first loading its pixel and 16-bit palette data, detecting a transparent palette entry and creating the texture resource when it is not yet loaded, and in both cases updates the texture's usage record for the requested mode (1 stamps the next expiry time, 2 pins it, 3 counts a reference); the opened file handle is stored through the header symbol as in the paletted texture loader, and the resource id is held in two locals (the second passed to func_80419640_de), which reproduces the cartridge's three stack slots. */











extern FileHeader D_8014D724;

extern s32 *D_80153C14;

extern char D_800DD0B0;

extern s32 func_802A0E8C_de(void *header, void *name);

extern void func_802A0F60_de(s32 file, s32 offset, s32 whence);

extern void func_802A18CC_de();

extern void func_804133E4_de(s32 id);

extern void func_80419640_de(s32 texture, s32 id);

static inline void touch(s32 index, s32 mode) {
    extern Usage *D_8014D988;
    switch (mode) {
        case 1:
            if (D_8014D988[index].expiry != -1) {
                D_8014D988[index].expiry = func_802A1934_de() + 10;
            }
            break;
        case 2:
            D_8014D988[index].expiry = -1;
            break;
        case 3:
            D_8014D988[index].count++;
            break;
    }
}

/* Loads texture and palette data, detects transparency and creates the requested texture resource, storing the opened file handle through the header symbol (a codegen choice that keeps the handle address separate from the header base). */









extern void func_80413480_de(s32 output, s32 id);

void func_804101BC_de(void) {
    extern void func_802A0EB0_de(void *);
    extern struct EntryRecAt8V1 *D_80153C10;
    extern struct State_func_804101BC_de D_801539B0;
    extern struct ResourceRecAt6 *D_8014D988;
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
    struct State_func_804101BC_de *state;
    i = 0;
    if (D_80153C0C > 0) {
        invalid = -1;
        offset = 0;
        do {
            if (((struct EntryRecAt8V1 *)(offset + (s32)D_80153C10))->flags & 1) {
                resource = D_8014D988 + i;
                if (resource->id != invalid && resource->retained == 0) {
                    func_80411AF0_de(i);
                }
            }
            offset += 0x1C;
        } while (++i < D_80153C0C);
    }
    func_8040F580_de();
    state = &D_801539B0;
    if (state->active) func_802A0EB0_de(state->active);
    func_804118E4_de(1);
    func_80410E1C_de(1);
    if (state->resource) func_802547E4_de(state->resource);
    i_chunks = 0;
    func_80411D18_de();
    offset_chunks = 0;
    if (state->count > 0) {
        do {
            block = ((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->optional;
            if (block) {
                func_802547E4_de(*block);
                func_802547E4_de(((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->optional);
            }
            i_chunks++;
            func_802547E4_de(*((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->primary);
            block = ((struct ChunkRecAt48C *)(offset_chunks + (s32)D_80153C28))->primary;
            offset_chunks += 0x49C;
            func_802547E4_de(block);
        } while (i_chunks < D_80153C20);
    }
    tables = D_8014D98C;
    if (tables[0]) func_802547E4_de(tables[0]);
    first = tables + 3;
    if (tables[3]) func_802547E4_de(tables[3]);
    second = tables + 2;
    if (tables[2]) func_802547E4_de(tables[2]);
    if (tables[13]) func_802547E4_de(tables[13]);
    if (tables[-1]) func_802547E4_de(tables[-1]);
    if (tables[10]) func_802547E4_de(tables[10]);
    if (tables[11]) func_802547E4_de(tables[11]);
    if (tables[-2]) func_802547E4_de(tables[-2]);
    if (tables[12]) func_802547E4_de(tables[12]);
    if (tables[7]) func_802547E4_de(tables[7]);
    if (first[5]) func_802547E4_de(first[5]);
    if (second[3]) func_802547E4_de(second[3]);
    func_802A0748_de((char *)tables - 0x26C, 0, 0x2A8);
}

void func_80410448_de(void) {
    extern struct State_func_80410448_de D_801539B0;
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

s32 func_80410674_de(s32 index, s32 mode) {
    extern void func_80413720_de(s32 id, s32 format, s16 width, s16 height, s32 stride, s32 rows, s32 a6, s32 size, void *pixels, s32 a9, s32 paletteBytes, u16 *palette, s32 colors);
    extern void func_802A0ED4_de(void *buffer, s32 size, s32 count, s32 file);
    extern void func_802A0EB0_de(s32 file);
    extern void *func_8025305C_de(s32 size);
    extern EntryRecAt18V1 *D_80153C10;
    extern FileState D_801539B0;
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
    ((FileState *)((char *)&D_8014D724 - 4))->unk0 = func_802A0E8C_de(&D_8014D724, &D_800DD0B0);
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
    pixels = func_8025305C_de(size);
    func_802A0F60_de(D_801539B0.unk0, D_801539B0.unk248 + entry->unk14, 0);
    func_802A0ED4_de(pixels, size, 1, D_801539B0.unk0);
    if (entry->unkE > 0) {
        paletteBytes = entry->unkE * 2;
        palette = func_8025305C_de(paletteBytes);
        func_802A0F60_de(D_801539B0.unk0, D_801539B0.unk248 + entry->unk18, 0);
        func_802A0ED4_de(palette, paletteBytes, 1, D_801539B0.unk0);
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
    func_802A0EB0_de(D_801539B0.unk0);
    D_801539B0.unk0 = 0;
    func_802A18CC_de();
    touch(index, mode);
    return D_80153C10[index].unk0;
}

void func_80410B14_de(s32 index, s32 output) {
    extern void func_80413720_de(s32 output, s32 format, s16 width, s16 height, s32 stride, s32 rows, s32 a6, s32 size, s32 *pixels, s32 a9, s32 paletteBytes, s32 *palette, s32 colors);
    extern void func_802A0ED4_de(s32 *buffer, s32 size, s32 count, s32 file);
    extern void func_802A0EB0_de(s32 file);
    extern s32 *func_8025305C_de(s32 size);
    extern EntryRecAt18V1 *D_80153C10;
    extern FileState D_801539B0;
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
    ((FileState *)((char *)&D_8014D724 - 4))->unk0 = func_802A0E8C_de(&D_8014D724, &D_800DD0B0);
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
    pixels = func_8025305C_de(size);
    func_802A0F60_de(D_801539B0.unk0, D_801539B0.unk248 + entry->unk14, 0);
    func_802A0ED4_de(pixels, size, 1, D_801539B0.unk0);
    if (entry->unkE > 0) {
        paletteBytes = entry->unkE * 2;
        palette = func_8025305C_de(paletteBytes);
        func_802A0F60_de(D_801539B0.unk0, D_801539B0.unk248 + entry->unk18, 0);
        func_802A0ED4_de(palette, paletteBytes, 1, D_801539B0.unk0);
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
    func_802A0EB0_de(D_801539B0.unk0);
    D_801539B0.unk0 = 0;
}
