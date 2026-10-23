#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "MENU/8043F69C.H"
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

#ifdef NON_MATCHING
#include "COMMON/WORLD.H"
#define PD_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
typedef struct PakVec { f32 x; f32 y; f32 z; } PakVec;
typedef struct Copy188 { u8 bytes[0x188]; } Copy188;
extern u32 *D_80110634;
extern s32 D_800D297C, D_800E28D0, D_800E28D4, D_800E1E20, D_800CD730, D_800CD8D0, D_8014DE50;
extern f32 D_800DE480_de, D_800DE484, D_800DE488, D_800DE498_de[], D_800DE4A0, literals_func_8028D244_de;
extern s32 D_800CE430[];
extern u8 D_00443128[], D_00443104[];
extern void func_802A001C_de();
extern u8 *func_8028CFA0_de();
extern void func_80272898_de();
extern void func_802466A0_de();
extern void func_8024B2D0_de();
extern s32 func_8025477C_de();
extern void func_8025476C_de();
extern void func_8028B274_de();
extern void func_8024B8C4_de();
extern void func_80246E44_de();
extern void func_8026D980_de();
extern void func_80249E28_de();
extern void func_8026D9D0_de();
void func_80440838_de(u8 *self, s32 *selected, void *unused, u8 *ctx) {
    PakVec zero50;
    PakVec scaled;
    PakVec offset;
    PakVec placed;
    u8 *widget;
    u8 *def;
    u8 *draw;
    u8 *link = 0;
    u8 *owner;
    u8 *source;
    u32 *list;
    f32 ratioX;
    f32 ratioY;
    f32 wobble;
    s32 id;
    func_802A001C_de(&zero50, 0, 0xC);
    widget = PD_FIELD(self, u8 *, 0x20);
    if (widget == 0 || PD_FIELD(widget, s32, 0x478) == 0) {
        return;
    }
    def = PD_FIELD(self, u8 *, 0x14);
    draw = widget + 0x190;
    list = D_80110634;
    list[0] = 0xDA380007;
    list[1] = PD_FIELD(ctx, u32, 0x40) + 0x380 + D_800D297C * 64;
    ratioX = PD_FIELD(PD_FIELD(ctx, u8 *, 0x40), f32, 0x29C) / (f32)D_800E28D0;
    scaled.x = PD_FIELD(def, f32, 0x18) * ratioX;
    scaled.z = PD_FIELD(def, f32, 0x20) * ratioX;
    ratioY = PD_FIELD(PD_FIELD(ctx, u8 *, 0x40), f32, 0x2A0) / (f32)D_800E28D4;
    scaled.y = PD_FIELD(def, f32, 0x1C) * ratioY;
    D_80110634 = list + 2;
    PD_FIELD(widget, f32, 0x47C) = PD_FIELD(widget, f32, 0xF8);
    if (!(PD_FIELD(self, u32, 8) & 0x2000000)) {
        id = PD_FIELD(def, s32, 4);
        owner = PD_FIELD(self, u8 *, 0x20);
        source = func_8028CFA0_de(&D_8011FE88, id, PD_FIELD(def, s32, 8));
        if (source != 0) {
            PD_FIELD(owner, s32, 0) = id;
            PD_FIELD(owner, s32, 0x478) = 1;
            *(Copy188 *)(owner + 4) = *(Copy188 *)source;
            PD_FIELD(owner, s32, 4) = 0;
            PD_FIELD(owner, s32, 8) = 0;
            PD_FIELD(owner, s32, 0x18) = 0;
            PD_FIELD(owner, s32, 0x1C) = 0;
            PD_FIELD(owner, s32, 0x20) = 0;
            PD_FIELD(owner, f32, 0xC) = D_800DE480_de;
            PD_FIELD(owner, f32, 0x47C) = PD_FIELD(owner, f32, 0xF8);
            link = owner + 4;
        } else {
            PD_FIELD(owner, s32, 0x478) = 0;
        }
    }
    offset = PD_FIELD(def, PakVec, 0xC);
    offset.y = offset.y - PD_FIELD(widget, f32, 0x47C) * scaled.y * D_800DE484;
    func_80272898_de(PD_FIELD(ctx, u8 *, 0x40) + 0x160, &offset, &placed);
    if (link != 0 && !(PD_FIELD(self, u32, 8) & 0x2000000)) {
        func_802466A0_de(draw, -1, PD_FIELD(def, s32, 0), D_800CD8D0, link, -1, 0,
                         PD_FIELD(PD_FIELD(ctx, u8 *, 0x40), f32, 0x28) + D_800DE488, placed, 0,
                         PD_FIELD(def, PakVec, 0x18), zero50, 0);
        func_8024B2D0_de(draw);
        PD_FIELD(self, u32, 8) |= 0x2000000;
    }
    wobble = func_802B7130_de((f32)(u32)(D_800CD730 * 10) * D_800DE498_de[0]);
    D_8014DE50 = (s32)(PD_FIELD(ctx, f32, 0x30) * PD_FIELD(ctx, f32, 0x34) * ((wobble + D_800DE498_de[1]) * D_800DE4A0 + D_800DE4A0));
    PD_FIELD(draw, u8 *, 0x27C) = PD_FIELD(ctx, s16, 0) == selected[0] ? D_00443128 : D_00443104;
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    if (PD_FIELD(widget, s32, 0) == 0xB) {
        func_8028B274_de(&D_8011FE88, draw, D_800CE430[PD_FIELD(PD_FIELD(draw, u8 *, 0x18), s16, 0xC)], 1);
    }
    if (D_800E1E20 != 4) {
        D_800E1E20 = 4;
        list = D_80110634;
        list[0] = 0xE7000000;
        list[1] = 0;
        list[2] = 0xE3000A01;
        list[3] = 0x100000;
        list[4] = 0xE3000C00;
        list[5] = 0x80000;
        list[6] = 0xE3001201;
        list[7] = 0x2000;
        D_80110634 = list + 8;
    }
    PD_FIELD(draw, PakVec, 0x50) = scaled;
    PD_FIELD(draw, PakVec, 8) = placed;
    PD_FIELD(draw, PakVec, 0x1C4) = placed;
    func_8024B8C4_de(draw);
    PD_FIELD(draw, PakVec, 8) = placed;
    PD_FIELD(draw, PakVec, 0x1C4) = placed;
    func_80246E44_de(draw);
    PD_FIELD(draw, f32, 0x6C) = PD_FIELD(draw, f32, 0x6C) + PD_FIELD(def, f32, 0x2C) * literals_func_8028D244_de;
    PD_FIELD(draw, PakVec, 8) = placed;
    PD_FIELD(draw, PakVec, 0x1C4) = placed;
    func_8026D980_de(draw, PD_FIELD(ctx, u8 *, 0x40));
    func_80249E28_de(draw);
    func_8026D9D0_de();
}
#else
INCLUDE_ASM("ovl_80400000", func_80440838_de);
#endif

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
