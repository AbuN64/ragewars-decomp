#include "MENU/GFX/80414430_24.H"
#include "MATH/802A2870.H"
#include "RESMGR/resmgr_stream_callbacks.H"
#include "include_asm.h"
#include "COMMON/SLOTRECATCV1.H"
#include "TYPES.H"
#include "RESMGR/resmgr_stream_io.H"

/* Advances the deferred-release timers: for each of the D_80153C0C slots (all reset first when mode
   is 1) whose owner is not -1, counts the delay down, and once it has run out releases the slot's
   loaded resource data through Gfx_ReleaseImage, clearing its loaded flag, and clears the owner. */







extern PoolRecAtC D_80153C0C;


void func_80410E1C_de(s32 mode) {
    s32 i;

    for (i = 0; i < D_80153C0C.count; i++) {
        if (mode == 1) {
            D_80153C0C.timers[i].delay = 0;
            D_80153C0C.timers[i].owner = 0;
        }
        if (D_80153C0C.timers[i].owner != -1) {
            if (D_80153C0C.timers[i].delay > 0) {
                D_80153C0C.timers[i].delay--;
            } else {
                if (D_80153C0C.resources[i].flags & 1) {
                    Gfx_ReleaseImage((struct OwnedImage *)D_80153C0C.resources[i].data);
                    D_80153C0C.resources[i].flags &= ~1;
                }
                D_80153C0C.timers[i].owner = 0;
            }
        }
    }
}

typedef struct {
    char pad0[0x20];
} Texture;
typedef struct {
    char pad0[4];
    s32 stamp;
    u16 flags;
    char pad0A[2];
    Texture texture;
} TextureSlot;
typedef struct {
    s32 offset;
    s8 fmt;
    s8 siz;
    s8 wid;
    char pad7[1];
} Tile;
typedef struct {
    char pad0[8];
    s16 depth;
    char pad0A[0x0E];
    s32 base;
    s32 size;
} Image;
typedef struct {
    s32 loaded;
    Tile tiles[0x60];
    u8 *offsets[0x60];
    TextureSlot **slotsByPass;
    s32 **listsByPass;
    Image *image;
    u8 loads;
    char pad491[3];
    s32 stamp;
    s16 held;
    char pad49A[2];
} Bank;
typedef struct {
    char pad0[0x30];
    s32 base;
    char pad34[0x24];
    Bank *banks;
} Tables;
typedef struct {
    s32 handle;
    s32 name;
    char pad8[0x218];
    Tables tables;
} File;
extern File D_801539B0;
extern s32 D_800DD0B0;
extern s32 func_8025305C_de(s32 size);
extern void func_802A0EB0_de(s32 handle);
extern s32 func_802A1934_de(void);
extern void func_804133E4_de(Texture *texture);
extern void func_80413404_de(Texture *texture);
extern void func_80413720_de(Texture *texture, s32 kind, s8 fmt, s8 siz, s32 wid, s32 siz2, s32 zero,
                          s32 bytes, void *offset, s32 zero2, s32 pitch, s32 *list, s32 depth);
extern void func_80419490_de(Texture *texture);
extern void func_80419640_de(Texture *into, Texture *from);
extern void func_804196C8_de(s32 flag);

void *Frontend_GetBankTileTexture(u8 which, s32 group, s32 pass) {
    s32 sizes[0x60];
    Texture scratch;
    Texture *texture;
    Texture *into;
    Image *image;
    s32 kind;
    Tile *tile;
    TextureSlot *slot;
    s32 threshold;
    Bank *bank;
    TextureSlot *slots;
    s32 index;
    s32 code;
    s32 stamp;
    s32 size;
    s32 bytes;
    s32 i;

    slots = D_801539B0.tables.banks[group].slotsByPass[pass];
    index = which;
    {
    if (slots[index].flags & 1) {
        Bank *cachedBank;
        stamp = func_802A1934_de() + 0xA;
        slots[index].stamp = stamp;
        cachedBank = &D_801539B0.tables.banks[group];
        if (cachedBank->held == 0 && cachedBank->stamp != -1) {
            cachedBank->stamp = stamp;
        }
        return &slots[which].texture;
    }
    }
    kind = 0;
    func_802A18CC_de();
    image = D_801539B0.tables.banks[group].image;
    tile = &D_801539B0.tables.banks[group].tiles[index];
    slot = &slots[index];
    code = 0;
    if (tile->fmt == 0 || tile->siz == 0) {
        return 0;
    }
    texture = &slot->texture;
    func_804133E4_de(texture);
    into = texture;
    if (image->depth == 0) {
        code = 0x20;
    } else if (image->depth < 0x11) {
        code = 4;
    } else if (image->depth < 0x101) {
        code = 8;
    }
    if (image->depth > 0) {
        kind = 0x14;
        if (code == 8) {
            kind = 0x1E;
        }
    } else if (code == 0x10) {
        kind = 0x1C;
    } else if (code == 0x18) {
        kind = 8;
    } else if (code == 0x20) {
        kind = 0xC;
    }
    if (D_801539B0.tables.banks[group].loaded == 0) {
        Tables *tables = &D_801539B0.tables;

        bank = &tables->banks[group];
        D_801539B0.handle = Resmgr_OpenStream(&D_801539B0.name, &D_800DD0B0);
        size = bank->image->size;
        i = 0;
        bank->offsets[0] = func_8025305C_de(size);
        Resmgr_SeekStream(D_801539B0.handle, D_801539B0.tables.base + bank->image->base, 0);
        Resmgr_ReadStream(D_801539B0.tables.banks[group].offsets[0], size, 1, D_801539B0.handle);
        do {
            sizes[i] = bank->tiles[i].wid * bank->tiles[i].siz;
            sizes[i] = sizes[i] * code / 8;
            bank->offsets[i] = bank->offsets[0] + (bank->tiles[i].offset - bank->image->base);
            i += 1;
        } while (i < 0x60);
        threshold = 0x1000;
        if (image->depth > 0) {
            threshold = 0x800;
        }
        i = 0;
        do {
            if (threshold < sizes[i]) {
                Tile *big = &D_801539B0.tables.banks[group].tiles[i];

                func_804133E4_de(&scratch);
                func_80413720_de(&scratch, kind, big->fmt, big->siz, big->wid, big->siz, 0, sizes[i],
                              D_801539B0.tables.banks[group].offsets[i], 0, image->depth * 2,
                              D_801539B0.tables.banks[group].listsByPass[pass], image->depth);
                func_80419490_de(&scratch);
                func_80413404_de(&scratch);
            }
            i += 1;
        } while (i < 0x60);
        func_802A0EB0_de(D_801539B0.handle);
        D_801539B0.handle = 0;
        bank->loaded = 1;
    }
    bytes = tile->wid * tile->siz * code >> 3;
    func_80413720_de(texture, kind, tile->fmt, tile->siz, tile->wid, tile->siz, 0,
                  bytes, D_801539B0.tables.banks[group].offsets[which], 0,
                  image->depth * 2, D_801539B0.tables.banks[group].listsByPass[pass], image->depth);
    func_804196C8_de(0);
    func_80419640_de(into, texture);
    func_804196C8_de(1);
    func_802A18CC_de();
    slot->stamp = func_802A1934_de() + 0xA;
    D_801539B0.tables.banks[group].loads += 1;
    slot->flags |= 1;
    return &slot->texture;
}
