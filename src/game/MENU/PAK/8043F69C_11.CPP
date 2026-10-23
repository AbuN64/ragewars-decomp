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
typedef struct Copy188 { s32 words[98]; } Copy188;
extern u32 *D_80110634;
extern s32 D_800D297C, D_800E28D0, D_800E28D4, D_800E1E20, D_800CD730, D_800CD8D0, D_8014DE50;
extern f32 D_800DE480_de, D_800DE484, D_800DE488, D_800DE498_de[], D_800DE4A0, literals_func_8028D244_de;
extern s32 D_800CE430[];
extern u8 D_00443128[], D_00443104[];
extern void func_802A001C_de(void *, s32, s32);
extern u8 *func_8028CFA0_de(void *, s32, s32);
extern void func_80272898_de(void *, PakVec *, PakVec *);
extern void func_802466A0_de(u8 *, s32, s32, s32, u8 *, s32, s32, f32, PakVec, s32, PakVec, PakVec, s32);
extern void func_8024B2D0_de(u8 *);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_8028B274_de(void *, u8 *, s32, s32);
extern void func_8024B8C4_de(u8 *);
extern void func_80246E44_de(u8 *);
extern void func_8026D980_de(u8 *, u8 *);
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
extern void *func_80442A58_de(void *);
extern void func_80442B34_de(void *);
extern void func_80442B40_de(void *);
typedef struct MenuBuildState MenuBuildState;
typedef struct MenuBuildEntry MenuBuildEntry;
typedef struct MenuBuildItem {
    s16 type;
    u16 reserved02;
    u32 flags;
    s16 x, y;
    u8 red, green, blue, alpha;
    s32 resource;
    u8 reserved14[8];
    void (*initialize)(MenuBuildEntry *, MenuBuildState *, struct func_8025E5B0_S1 *);
    u8 reserved20[4];
} MenuBuildItem;
typedef struct MenuBuildDefinition {
    MenuBuildItem *items;
    s16 count;
    u16 reserved06;
    void (*initialize)(MenuBuildState *, struct func_8025E5B0_S1 *);
    u8 reserved0C[12];
    s16 x, y, kind;
    u16 reserved1E;
    s32 value;
} MenuBuildDefinition;
struct MenuBuildEntry {
    s32 index;
    s16 type;
    u16 reserved06;
    u32 flags;
    s16 x, y;
    u8 red, green, blue, alpha;
    s32 resource;
    MenuBuildItem *definition;
    s32 selection;
    u8 *extra;
    MenuBuildState *menu;
};
typedef struct MenuBuildStyle {
    u16 first, second, third, reserved06;
    u16 offsetX, offsetY;
    u8 red, green, blue, alpha;
} MenuBuildStyle;
struct MenuBuildState {
    s16 x, y, kind;
    u16 reserved06;
    void **allocation;
    MenuBuildEntry *entries;
    s32 count;
    MenuBuildDefinition *definition;
    s32 value18, value1C;
    u8 *input;
    s32 value24;
    u16 state, ownerSlot;
    s32 value2C, value30, value34, value38, value3C;
    void *context;
    struct func_8025E5B0_S1 *owner;
    MenuBuildStyle styles[2][8];
    u8 reserved148[0x90];
};
static inline s32 menuItemExtraSize(MenuBuildItem *definition) {
    s32 size = 0;
    if (definition->type == 3) size = 0x480;
    return size;
}
static inline void initializeMenuEntry(MenuBuildEntry *entry, MenuBuildItem *definition, s32 index, MenuBuildState *menu, u8 **extra) {
    entry->index = index;
    entry->type = definition->type;
    entry->flags = definition->flags | 0x1800000;
    entry->x = definition->x;
    entry->y = definition->y;
    entry->red = definition->red;
    entry->green = definition->green;
    entry->blue = definition->blue;
    entry->alpha = definition->alpha;
    entry->definition = definition;
    entry->selection = -1;
    entry->menu = menu;
    entry->resource = definition->resource;
    if (menuItemExtraSize(definition) != 0) {
        entry->extra = *extra;
        if (definition->type == 3) MP_FIELD(*extra, s32, 0x478) = 1;
        *extra += menuItemExtraSize(definition);
    }
}
/* 49/195 aligned edits; remaining: style-loop address allocation and scheduling. */
void Pak_InitializeMenu(u8 *memory, void **allocation, MenuBuildDefinition *definition, s32 value18, s32 value1C, u8 *input, s32 value24, struct func_8025E5B0_S1 *owner) {
    u8 *extra;
    MenuBuildState *menu = (MenuBuildState *)memory;
    MenuBuildEntry *entry;
    s32 i, bank;
    u8 *rec;
    menu->x = definition->x;
    menu->y = definition->y;
    menu->kind = definition->kind;
    menu->allocation = allocation;
    menu->entries = (MenuBuildEntry *)(menu + 1);
    menu->count = definition->count;
    extra = (u8 *)(menu + 1);
    extra += definition->count * sizeof(MenuBuildEntry);
    for (i = 0; i < definition->count; i++) {
        initializeMenuEntry(&menu->entries[i], &definition->items[i], i, menu, &extra);
    }
    menu->definition = definition;
    menu->value18 = value18;
    menu->input = input;
    menu->value1C = value1C;
    menu->state = 0;
    menu->value24 = value24;
    menu->ownerSlot = owner->unk14;
    menu->value2C = 0;
    menu->value30 = 0;
    menu->value34 = 0;
    menu->value38 = 1;
    menu->value3C = 0;
    menu->context = func_80442A58_de(owner);
    menu->owner = owner;
    for (bank = 0; bank < 2; bank++) {
        for (i = 0; i < 8; i++) {
            rec = (u8 *)menu + bank * 0x80 + i * 0x10;
            MP_FIELD(rec, u16, 0x48) = MP_FIELD(D_800E1F22, u16, i * 0x18);
            MP_FIELD(rec, u16, 0x4A) = MP_FIELD(D_800E1F26, u16, i * 0x18);
            MP_FIELD(rec, u16, 0x4C) = MP_FIELD(D_800E1F2A, u16, i * 0x18);
            MP_FIELD(rec, u8, 0x54) = D_800E1F2F[i * 0x18];
            MP_FIELD(rec, u8, 0x55) = D_800E1F33[i * 0x18];
            MP_FIELD(rec, u8, 0x57) = 0xFF;
            MP_FIELD(rec, u16, 0x50) = 0;
            MP_FIELD(rec, u16, 0x52) = 0;
            MP_FIELD(rec, u8, 0x56) = D_800E1F37[i * 0x18];
        }
    }
    MP_FIELD(input, s32, 0xB0) = 0;
    MP_FIELD(input, s32, 0xB4) = 0;
    MP_FIELD(input, s32, 0xBC) = 0;
    func_80442B34_de(menu);
    func_80442B40_de(menu);
    if (definition->initialize != 0) definition->initialize(menu, owner);
    i = menu->count;
    entry = menu->entries;
    while (--i != -1) {
        if (entry->definition->flags & 0x4000000) {
            if (entry->definition->initialize != 0) entry->definition->initialize(entry, menu, owner);
        }
        entry++;
    }
}

#else
INCLUDE_ASM("ovl_80400000", Pak_InitializeMenu);
#endif
