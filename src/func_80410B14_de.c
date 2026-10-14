#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Loads texture and palette data, detects transparency and creates the requested texture resource, storing the opened file handle through the header symbol (a codegen choice that keeps the handle address separate from the header base). */







extern FileState D_801539B0;
extern FileHeader D_8014D724;
extern EntryRecAt18V1 *D_80153C10;
extern s32 *D_80153C14;
extern char D_800DD0B0;
extern s32 *func_8025305C_de(s32 size);
extern s32 func_802A0E8C_de(void *header, void *name);
extern void func_802A0EB0_de(s32 file);
extern void func_802A0ED4_de(s32 *buffer, s32 size, s32 count, s32 file);
extern void func_802A0F60_de(s32 file, s32 offset, s32 whence);
extern void func_80413480_de(s32 output, s32 id);
extern void func_80413720_de(s32 output, s32 format, s16 width, s16 height, s32 stride, s32 rows, s32 a6, s32 size,
                          s32 *pixels, s32 a9, s32 paletteBytes, s32 *palette, s32 colors);

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
