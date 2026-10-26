#include "include_asm.h"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

extern s32 D_800CD894_de;

extern s32 PpDecom_UnpackResource(void *, s32);
extern u16 *SetN64_GetSizedPackSection(void *, s32, u32 *);
extern s32 func_8028FDF8_de(void *, s32);
extern s32 **Cache_AllocResourceBlock(s32, void *, s32);
extern void Cache_ReplaceResourceBlock(s32, void *, s32 **);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);

typedef struct {
    s32 **handle;
    s32 unk4;
    u32 flags;
} Resource;

/* Recolours the RGBA5551 frames of a resource by the global or per-resource colour mode, then rebuilds it as a three-part block holding the header, one selected entry of list 1 and one of list 2. */
void func_80294C8C_de(s32 arg0, Resource *handle) {
    u32 size;
    s32 rem1;
    s32 rem2;
    s32 *obj;
    s32 *list2;
    s32 *list1;
    s32 count;
    s32 mode;
    s32 i;
    s32 j;
    s32 n;
    s32 kind;
    s32 len0;
    s32 len1;
    s32 len2;
    s32 off1;
    s32 off2;
    s32 total;
    s32 **res;
    s32 *hdr;
    s32 *entry;

    if (PpDecom_UnpackResource(handle, arg0 >= 0) == 0) {
        return;
    }
    obj = *handle->handle;
    if (*obj == 0) {
        return;
    }
    list2 = SetN64_GetPackSection(obj, 2);
    count = *list2;
    if (count != 0) {
        rem2 = arg0 % count;
    } else {
        rem2 = 0;
    }
    list1 = SetN64_GetPackSection(obj, 1);
    rem1 = arg0 % *list1;
    if (D_800CD894_de != 0) {
        mode = 4;
    } else {
        mode = handle->flags >> 30;
    }
    if (mode != 0) {
        kind = *(u8 *)SetN64_GetPackSection(obj, 0);
        if (kind < 2) if (kind >= 0) {
            for (i = 0; i < count; i++) {
                u16 *data = SetN64_GetSizedPackSection(list2, i, &size);
                n = size >> 1;
                for (j = 0; j < n; j++) {
                    u32 r = (data[j] >> 8) & 0xF8;
                    u32 g = (data[j] >> 3) & 0xF8;
                    u32 b = (data[j] << 2) & 0xF8;
                    u32 a = data[j] & 1;
                    switch (mode) {
                    case 1:
                        data[j] = (g << 8) | (r << 3) | (b >> 2) | a;
                        break;
                    case 2:
                        data[j] = (r << 8) | (r << 3) | (b >> 2) | a;
                        break;
                    case 3:
                        data[j] = (g << 8) | (g << 3) | (b >> 2) | a;
                        break;
                    case 4:
                        data[j] = (r + b + g) / 12 | a;
                        break;
                    }
                }
            }
        }
    }
    if (arg0 < 0) {
        return;
    }
    len0 = func_8028FDF8_de(obj, 0);
    len1 = func_8028FDF8_de(list1, rem1) + 0x10;
    if (count != 0) {
        len2 = func_8028FDF8_de(list2, rem2) + 0x10;
    } else {
        len2 = 8;
    }
    total = ((len0 + 7) & ~7) + 0x18;
    off1 = total;
    total += (len1 + 7) & ~7;
    off2 = total;
    total += (len2 + 7) & ~7;
    res = Cache_AllocResourceBlock(0, handle, total);
    if (res != 0) {
        hdr = *res;
        hdr[0] = 3;
        hdr[1] = 0x18;
        hdr[2] = off1;
        hdr[3] = off2;
        func_802BD3A0_de(SetN64_GetPackSection(hdr, 0), SetN64_GetPackSection(obj, 0), func_8028FDF8_de(obj, 0));
        entry = SetN64_GetPackSection(hdr, 1);
        entry[0] = 1;
        entry[1] = 0x10;
        func_802BD3A0_de(SetN64_GetPackSection(entry, 0), SetN64_GetPackSection(list1, rem1), func_8028FDF8_de(list1, rem1));
        entry = SetN64_GetPackSection(hdr, 2);
        if (count != 0) {
            entry[0] = 1;
            entry[1] = 0x10;
            func_802BD3A0_de(SetN64_GetPackSection(entry, 0), SetN64_GetPackSection(list2, rem2), func_8028FDF8_de(list2, rem2));
        } else {
            entry[0] = 0;
        }
    }
    Cache_ReplaceResourceBlock(0, handle, res);
}

#if !(defined(VERSION_US_REV1))
#ifdef NON_MATCHING
extern s32 D_800CD890, D_80146DF0, D_80146DF4, D_80146DF8, D_80146DFC;
extern u32 *g_displayListCursor;
extern void Cache_MarkResourceInUse(s32);
extern u8 D_800CBD50_de[];
#define DLW(a, b) do { g_displayListCursor[0] = (u32)(a); g_displayListCursor[1] = (u32)(b); g_displayListCursor += 2; } while (0)
/* Texture state setter (the gDP texture-load sequence of a texture-header object): looks up the header, bitmap and palette
   tables of the object's resource, skips the load when the same texture and tile parameters are already set, otherwise
   emits SetTextureImage / SetTile / LoadBlock-or-LoadTLUT for the texture's format (header byte 0: 0 and 1 are 16-bit and 32-bit
   texels, 2 and 3 are the 4/8-bit palette formats, 4 and 5 are intensity/alpha), then the tile sync and the final
   SetTileSize-style command built from the shift/clamp arguments. */
void func_802950B4_de(s32 unused, void **obj, s32 frame, s32 tile, u32 wrap, u32 maskS, u32 maskT, u32 shift, s32 extra) {
    u8 *hdr;
    u8 *bits;
    u32 *palette;
    s32 changed = 0;
    s32 needLoad;
    u8 fmt, size, lines;
    s32 words;
    u32 t3 = 0, t0 = 0;

    Cache_MarkResourceInUse(0);
    hdr = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(obj[0], 0), 1), frame);
    bits = SetN64_GetPackSection(obj[0], 2);
    palette = 0;
    if (*(s32 *)bits != 0) {
        palette = SetN64_GetPackSection(bits, tile);
    }
    needLoad = (D_800CD890 != (s32)obj || D_80146DF0 != frame || D_80146DF8 != (s32)wrap || D_80146DFC != (s32)maskS ||
                D_80146DF4 != tile);
    if (needLoad == 0) {
        goto done;
    }
    D_800CD890 = (s32)obj;
    D_80146DF0 = frame;
    D_80146DF4 = tile;
    D_80146DF8 = wrap;
    D_80146DFC = maskS;
    if ((wrap & 2) == 0) {
        t3 = hdr[2];
    }
    if ((maskS & 2) == 0) {
        t0 = hdr[3];
    }
    fmt = hdr[0];
    size = hdr[2];
    lines = hdr[3];
    switch (fmt) {
    case 0:
    case 1:
    case 2:
    case 3:
        DLW(0xFD500000, bits);
        DLW(0xF5500000 | (maskS & 3) << 18 | (t0 & 0xF) << 14 | (maskT & 0xF) << 10 | (wrap & 3) << 8 | (t3 & 0xF) << 4 | (maskT & 0xF), 0x07000000);
        DLW(0xE6000000, 0);
        DLW(0xF3000000, 0);
        words = (1 << size);
        DLW(0x07000000 | ((words + 7) / 8 + 0x7FF & 0xFFF) << 12 | (((1 << size) << lines) >> 1) & 0xFFF, 0xE3001001);
        DLW(0xE7000000, 0);
        DLW(0xF5480000 | (((1 << size) + 7) >> 3 & 0x1FF) << 9, ((1 << size) - 1) << 14 | ((1 << lines) - 1) << 2);
        DLW(0xF2000000, 0x8000);
        break;
    case 4:
    case 5:
        DLW(0xFD180000, bits);
        DLW(0xF5180000 | (maskS & 3) << 18 | (t0 & 0xF) << 14 | (maskT & 0xF) << 10 | (wrap & 3) << 8 | (t3 & 0xF) << 4 | (maskT & 0xF), 0x07000000);
        DLW(0xF3000000, 0);
        DLW(0xE3001001, 0xC000);
        break;
    default:
        goto done;
    }
    if (palette != 0) {
        DLW(0xFD100000, palette);
        DLW(0xE8000000, 0);
        DLW(0xF5000100, 0x07000000);
        DLW(0xE6000000, 0);
        DLW(0xF0000000, 0x073FC000);
        DLW(0xE7000000, 0);
    }
done:
    switch (hdr[5]) {
    case 0: DLW(0xE3000D01, 0x20000); break;
    case 1: DLW(0xE3000D01, 0); break;
    case 2: DLW(0xE3000D01, 0); break;
    case 3: DLW(0xE3000D01, 0); break;
    default: break;
    }
    DLW(0xDE000000, D_800CBD50_de);
    DLW(0xE7000000, 0);
    DLW(0xD7000002 | ((hdr[0] == 4 ? 5 : hdr[0] == 5 ? 6 : 0) << 11), (u32)(extra) << 16 | (extra & 0xFFFF));
}
#else
INCLUDE_ASM("span_1000", func_802950B4_de);
#endif
#endif
