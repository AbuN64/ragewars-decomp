#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "TYPES.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/MENU_UI_PROVIDERS.H"

extern u8 D_80152789;
extern void func_8043F52C_de(LayeredText *, TextLayerMetrics *);
extern void func_804402DC_de(LayeredText *, MenuOptionBox *, MenuOptionBox *, int);
extern void func_8043FE3C_de(LayeredText *, MenuOptionBox *, MenuOptionBox *, int, void *, int);

#if !(defined(VERSION_DE) || defined(VERSION_US_REV1))
void func_804404A8_de(LayeredText *source, MenuOptionBox *position, MenuOptionBox *bounds, int flags) {
    LayeredText current;
    TextLayerMetrics first, second, third;
    int center;
    LayeredText *draw;
    center = (bounds->left + bounds->field18) / 2;
    current = *source;
    current.mode = 0;
    func_8043F52C_de(&current, &first);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &second);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &third);
    current = *source;
    current.text = 0;
    position->top += first.height;
    if (source->flags & 1) {
        position->left = center - (second.width + third.width) / 2;
    }
    position->left += third.width / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    current.text = 0;
    position->left += (source->spacing * second.width) / 256 - third.width / 2;
    position->top += second.height / 2 - third.height / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    if (source->flags & 1) {
        position->left = center - first.width / 2;
    }
    draw = &current;
    func_8043FE3C_de(draw, position, bounds, flags, RW_LOCALIZED_TEXT(*draw->text, draw->text, draw->text, D_80152789), 0);
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Measures three text layers, positions their labels, and renders the composite text. */
void func_804404A8_de(LayeredText *source, MenuOptionBox *position, MenuOptionBox *bounds, int flags) {
    LayeredText current;
    TextLayerMetrics first, second, third;
    int center;
    LayeredText *draw;
    center = (bounds->left + bounds->field18) / 2;
    current = *source;
    current.mode = 0;
    func_8043F52C_de(&current, &first);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &second);
    current = *source;
    current.mode = 1;
    current.text = 0;
    func_8043F52C_de(&current, &third);
    current = *source;
    current.text = 0;
    position->top += first.height;
    if (source->flags & 1) {
        position->left = center - (second.width + third.width) / 2;
    }
    position->left += third.width / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    current.text = 0;
    position->left += (source->spacing * second.width) / 256 - third.width / 2;
    position->top += second.height / 2 - third.height / 2;
    func_804402DC_de(&current, position, bounds, flags);
    current = *source;
    if (source->flags & 1) {
        position->left = center - first.width / 2;
    }
    draw = &current;
    func_8043FE3C_de(draw, position, bounds, flags, RW_LOCALIZED_TEXT(*draw->text, draw->text, draw->text, D_80152789), 0);
}
#endif

INCLUDE_ASM("ovl_80400000", func_80440838_de);

#ifdef NON_MATCHING
#define MP_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
extern u8 D_800E1F22[], D_800E1F26[], D_800E1F2A[], D_800E1F2F[], D_800E1F33[], D_800E1F37[];
typedef void (*MenuEntryInit)(u8 *, u8 *);
typedef void (*MenuEntryHook)(u8 *, u8 *, u8 *);
void func_80440DA0_de(u8 *self, s32 arg1, u8 *def, s32 arg3, s32 arg4, u8 *arg5, s32 arg6, u8 *arg7) {
    u8 *extra;
    u8 *entry;
    u8 *src;
    s32 count;
    s32 i;
    s32 j;
    s32 k;
    s32 size;
    u8 *rec;
    MenuEntryInit init;
    MenuEntryHook hook;
    MP_FIELD(self, u16, 0) = MP_FIELD(def, u16, 0x18);
    MP_FIELD(self, u16, 2) = MP_FIELD(def, u16, 0x1A);
    MP_FIELD(self, s32, 8) = arg1;
    MP_FIELD(self, u8 *, 0xC) = self + 0x1D8;
    MP_FIELD(self, u16, 4) = MP_FIELD(def, u16, 0x1C);
    count = MP_FIELD(def, s16, 4);
    MP_FIELD(self, s32, 0x10) = count;
    extra = self + 0x1D8 + count * 0x28;
    for (i = 0; i < MP_FIELD(def, s16, 4); i++) {
        entry = MP_FIELD(self, u8 *, 0xC) + i * 0x28;
        src = MP_FIELD(def, u8 *, 0) + i * 0x24;
        MP_FIELD(entry, s32, 0) = i;
        MP_FIELD(entry, u16, 4) = MP_FIELD(src, u16, 0);
        MP_FIELD(entry, u32, 8) = MP_FIELD(src, u32, 4) | 0x1800000;
        MP_FIELD(entry, u16, 0xC) = MP_FIELD(src, u16, 8);
        MP_FIELD(entry, u16, 0xE) = MP_FIELD(src, u16, 0xA);
        MP_FIELD(entry, u8, 0x10) = MP_FIELD(src, u8, 0xC);
        MP_FIELD(entry, u8, 0x11) = MP_FIELD(src, u8, 0xD);
        MP_FIELD(entry, u8, 0x12) = MP_FIELD(src, u8, 0xE);
        MP_FIELD(entry, u8, 0x13) = MP_FIELD(src, u8, 0xF);
        MP_FIELD(entry, u8 *, 0x18) = src;
        MP_FIELD(entry, s32, 0x1C) = -1;
        MP_FIELD(entry, u8 *, 0x24) = self;
        MP_FIELD(entry, s32, 0x14) = MP_FIELD(src, s32, 0x10);
        size = MP_FIELD(src, s16, 0) == 3 ? 0x480 : 0;
        if (size != 0) {
            MP_FIELD(entry, u8 *, 0x20) = extra;
            if (MP_FIELD(src, s16, 0) == 3) {
                MP_FIELD(extra, s32, 0x478) = 1;
            }
            extra += size;
        }
    }
    MP_FIELD(self, u8 *, 0x14) = def;
    MP_FIELD(self, s32, 0x18) = arg3;
    MP_FIELD(self, u8 *, 0x20) = arg5;
    MP_FIELD(self, s32, 0x1C) = arg4;
    MP_FIELD(self, u16, 0x28) = 0;
    MP_FIELD(self, s32, 0x24) = arg6;
    MP_FIELD(self, u16, 0x2A) = MP_FIELD(arg7, u16, 0x14);
    MP_FIELD(self, s32, 0x2C) = 0;
    MP_FIELD(self, s32, 0x30) = 0;
    MP_FIELD(self, s32, 0x34) = 0;
    MP_FIELD(self, s32, 0x38) = 1;
    MP_FIELD(self, s32, 0x3C) = 0;
    MP_FIELD(self, s32, 0x40) = func_80442A58_de(arg7);
    MP_FIELD(self, u8 *, 0x44) = arg7;
    for (j = 0; j < 2; j++) {
        for (k = 0; k < 8; k++) {
            rec = self + j * 0x80 + k * 0x10;
            MP_FIELD(rec, u16, 0x48) = MP_FIELD(D_800E1F22, u16, k * 0x18);
            MP_FIELD(rec, u16, 0x4A) = MP_FIELD(D_800E1F26, u16, k * 0x18);
            MP_FIELD(rec, u16, 0x4C) = MP_FIELD(D_800E1F2A, u16, k * 0x18);
            MP_FIELD(rec, u8, 0x54) = D_800E1F2F[k * 0x18];
            MP_FIELD(rec, u8, 0x55) = D_800E1F33[k * 0x18];
            MP_FIELD(rec, u8, 0x57) = 0xFF;
            MP_FIELD(rec, u16, 0x50) = 0;
            MP_FIELD(rec, u16, 0x52) = 0;
            MP_FIELD(rec, u8, 0x56) = D_800E1F37[k * 0x18];
        }
    }
    MP_FIELD(arg5, s32, 0xB0) = 0;
    MP_FIELD(arg5, s32, 0xB4) = 0;
    MP_FIELD(arg5, s32, 0xBC) = 0;
    func_80442B34_de(self);
    func_80442B40_de(self);
    init = MP_FIELD(def, MenuEntryInit, 8);
    if (init != 0) {
        init(self, arg7);
    }
    entry = MP_FIELD(self, u8 *, 0xC);
    for (i = MP_FIELD(self, s32, 0x10) - 1; i != -1; i--, entry += 0x28) {
        if (MP_FIELD(MP_FIELD(entry, u8 *, 0x18), u32, 4) & 0x4000000) {
            hook = MP_FIELD(MP_FIELD(entry, u8 *, 0x18), MenuEntryHook, 0x1C);
            if (hook != 0) {
                hook(entry, self, arg7);
            }
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_80440DA0_de);
#endif
