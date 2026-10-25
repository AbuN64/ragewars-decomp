#include "include_asm.h"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/LAYOUT.H"
#include "COMMON/FORMAT.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_42.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"

s32 func_80412CDC_de(Format *format) {
    s32 i;
    for (i = 0; i < 36; i++) {
        if (D_800E2B20[i].flags == format->flags &&
            D_800E2B20[i].type == format->type &&
            D_800E2B20[i].mask[0] == format->mask[0] &&
            D_800E2B20[i].mask[1] == format->mask[1] &&
            D_800E2B20[i].mask[2] == format->mask[2] &&
            D_800E2B20[i].mask[3] == format->mask[3]) {
            return i;
        }
    }
    return 0;
}

/* Converts a packed pixel value from format `from` to format `to` of the format table D_800E2B20:
   decodes the value to 0xAARRGGBB with the source format's channel masks and signed shifts, splits
   it into channels and re-encodes them with the destination format's shifts and masks. */





static inline u32 decode(u32 value, Format *format) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    if (format->shift[0] < 0) {
        r = (value & format->mask[0]) << -format->shift[0];
    } else {
        r = (value & format->mask[0]) >> format->shift[0];
    }
    if (format->shift[1] < 0) {
        g = (value & format->mask[1]) << -format->shift[1];
    } else {
        g = (value & format->mask[1]) >> format->shift[1];
    }
    if (format->shift[2] < 0) {
        b = (value & format->mask[2]) << -format->shift[2];
    } else {
        b = (value & format->mask[2]) >> format->shift[2];
    }
    if (format->shift[3] < 0) {
        a = (value & format->mask[3]) << -format->shift[3];
    } else {
        a = (value & format->mask[3]) >> format->shift[3];
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}

static inline u32 encode(u32 color, Format *format) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (format->shift[0] < 0) {
        r = (r >> -format->shift[0]) & format->mask[0];
    } else {
        r = (r << format->shift[0]) & format->mask[0];
    }
    if (format->shift[1] < 0) {
        g = (g >> -format->shift[1]) & format->mask[1];
    } else {
        g = (g << format->shift[1]) & format->mask[1];
    }
    if (format->shift[2] < 0) {
        b = (b >> -format->shift[2]) & format->mask[2];
    } else {
        b = (b << format->shift[2]) & format->mask[2];
    }
    if (format->shift[3] < 0) {
        a = (a >> -format->shift[3]) & format->mask[3];
    } else {
        a = (a << format->shift[3]) & format->mask[3];
    }
    return r | g | b | a;
}

extern void *D_80153C70,*D_80153C64;

/* Releases a resource object's buffers through Scene_FreeMemory (the one at 0x18 when flag 1 is set, the
   one at 0x14 when flag 2 is set and its size at 0x10 is positive) and clears its 32 bytes. */



/* Copies image src into dst: releases dst's owned pixel data (flag 1) and palette (flag 2, when it
   has entries), clears it and copies src's header, drops a palette pointer without entries, marks
   the copies owned, then allocates and copies the pixel data (size from func_804136A8_de) and, when
   src has a palette, the palette (size from func_8041369C_de). Returns 1 when an allocation fails,
   leaving dst cleared, otherwise 0. */




extern s32 func_804136A8_de(OwnedImage *image);

extern s32 func_8041369C_de(OwnedImage *image);

extern void *Scene_AllocateMemory(s32 size);


/* The argument is a pointer into 0x8068xxxx whose first byte the debugger read as 0x14, and the
   stride is 52. D_800E2B40, which func_804136D8_de indexes with the same stride and the same
   argument, sits 24 bytes further on, so both are fields of one 52-byte record. */
extern s32 D_800DEAD8[][13];

/* Returns the word in the 52-byte record D_800E2B2C selected by the first byte of a record. */
extern s32 D_800E2B2C[];

u32 func_80412D94_de(u32 value, s32 from, s32 to) {
    return encode(decode(value, &D_800E2B20[from]), &D_800E2B20[to]);
}

void func_80412F54_de(ImageDescriptor *destination, ImageDescriptor *source) {
    Format dst,src;
    D_80153CDC=0;
    D_80153CD8=0;
    D_80153CD4=0;
    D_80153CD0=0;
    D_80153C88=0;
    D_80153C7C=0;
    D_80153C70=0;
    D_80153C64=0;
    D_80153C84=0;
    D_80153C78=0;
    D_80153C6C=0;
    D_80153C60=0;
    D_80153D58=0;
    D_80153D54=0;
    if(destination) {
        D_80153D58=(void *)destination;
        dst=D_800E2B20[destination->format];
        D_8014DA90=dst;
        if(dst.flags) D_80153C70=destination->pixels;
        else D_80153C70=destination->palette;
        if(dst.flags) D_80153C88=destination->palette;
        else D_80153C88=0;
        if(dst.bits==16) D_80153CD4=D_0041406C;
        else if(dst.bits==24) D_80153CD4=D_004140BC;
        else if(dst.bits==32) D_80153CD4=D_00414094;
        if(dst.type==4) D_80153CDC=D_00414244;
        else if(dst.type==8) D_80153CDC=D_00414220;
        D_8014DA10=dst.mask[0];
        D_8014DA14=dst.mask[1];
        D_8014DA18=dst.mask[2];
        D_8014DA1C=dst.mask[3];
        D_8014DA30=dst.shift[0];
        D_8014DA34=dst.shift[1];
        D_8014DA38=dst.shift[2];
        D_8014DA3C=dst.shift[3];
    }
    if(source) {
        D_80153D54=(void *)source;
        src=D_800E2B20[source->format];
        D_8014DA50=src;
        if(src.flags) D_80153C64=source->pixels;
        else D_80153C64=source->palette;
        if(src.flags) D_80153C7C=source->palette;
        else D_80153C7C=0;
        if(src.bits==16) D_80153CD0=D_00413FCC;
        else if(src.bits==24) D_80153CD0=D_00414024;
        else if(src.bits==32) D_80153CD0=D_00413FF8;
        if(src.type==4) D_80153CD8=D_00414168;
        else if(src.type==8) D_80153CD8=D_00414138;
        else if(src.type==16) D_80153CD8=D_004141C0;
        else if(src.type==24) D_80153CD8=D_004141E0;
        else if(src.type==32) D_80153CD8=D_00414200;
        D_8014DA00=src.mask[0];
        D_8014DA04=src.mask[1];
        D_8014DA08=src.mask[2];
        D_8014DA0C=src.mask[3];
        D_8014DA20=src.shift[0];
        D_8014DA24=src.shift[1];
        D_8014DA28=src.shift[2];
        D_8014DA2C=src.shift[3];
    }
}

void func_804133E4_de(int value) {
    Resmgr_FillBytes(value, 0, 0x20);
}

void func_80413404_de(OwnedImage *res) {
    if (res->flags & 1) {
        Scene_FreeMemory(res->pixels);
    }
    if ((res->flags & 2) && res->paletteCount > 0) {
        Scene_FreeMemory(res->palette);
    }
    Resmgr_FillBytes(res, 0, 32);
}

/** Report false. */
int func_80413478_de(void) {
    return 0;
}

s32 func_80413480_de(OwnedImage *dst, OwnedImage *src) {
    s32 size;

    if (dst->flags & 1) {
        Scene_FreeMemory(dst->pixels);
    }
    if ((dst->flags & 2) && dst->paletteCount > 0) {
        Scene_FreeMemory(dst->palette);
    }
    Resmgr_FillBytes(dst, 0, 0x20);
    *dst = *src;
    if (dst->paletteCount == 0) {
        dst->palette = 0;
    }
    dst->flags = 1;
    if (dst->palette != 0) {
        dst->flags = 3;
    }
    size = func_804136A8_de(src);
    if ((dst->pixels = Scene_AllocateMemory(size)) == 0) {
        return 1;
    }
    Resmgr_CopyBytes(dst->pixels, src->pixels, size);
    if (src->paletteCount != 0) {
        size = func_8041369C_de(src);
        if ((dst->palette = Scene_AllocateMemory(size)) == 0) {
            Scene_FreeMemory(dst->pixels);
            Resmgr_FillBytes(dst, 0, 0x20);
            return 1;
        }
        Resmgr_CopyBytes(dst->palette, src->palette, size);
    }
    return 0;
}

/* Returns the first byte of a record; func_80413608_de, which follows it, reads the same byte. */
u8 func_804135FC_de(u8 *record) {
    return record[0];
}

s32 func_80413608_de(u8 *record) {
    return D_800DEAD8[*record][0];
}

s32 func_80413634_de(u8 *record) {
    return D_800E2B2C[record[0] * 13];
}

/* Returns the halfword at offset 0x2 of a record. It is one of a run of accessors from
   func_80413660_de to func_80413690_de that return the halfwords at offsets 2 to 0xA in turn. */
s16 func_80413660_de(s16 *record) {
    return record[0x2 / 2];
}

/* Returns the halfword at offset 0x4 of a record. It is one of a run of accessors from
   func_80413660_de to func_80413690_de that return the halfwords at offsets 2 to 0xA in turn. */
s16 func_8041366C_de(s16 *record) {
    return record[0x4 / 2];
}

/* Returns the halfword at offset 0x6 of a record. It is one of a run of accessors from
   func_80413660_de to func_80413690_de that return the halfwords at offsets 2 to 0xA in turn. */
s16 func_80413678_de(s16 *record) {
    return record[0x6 / 2];
}

/* Returns the halfword at offset 0x8 of a record. It is one of a run of accessors from
   func_80413660_de to func_80413690_de that return the halfwords at offsets 2 to 0xA in turn. */
s16 func_80413684_de(s16 *record) {
    return record[0x8 / 2];
}

/* Returns the halfword at offset 0xA of a record. It is one of a run of accessors from
   func_80413660_de to func_80413690_de that return the halfwords at offsets 2 to 0xA in turn. */
s16 func_80413690_de(s16 *record) {
    return record[0xA / 2];
}
