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
#include "COMMON/OBJECTRECAT28.H"
#include "gbi.h"
typedef struct PakModelDefinition {
    s32 kind, model, variant;
    CVector3 offset, scale;
    u8 reserved24[8];
    f32 rotationSpeed;
} PakModelDefinition;
typedef struct PakModelEntry {
    u8 reserved0[8];
    u32 flags;
    u8 reservedC[8];
    PakModelDefinition *definition;
    u8 reserved18[8];
    StateRecAt47C *state;
} PakModelEntry;
typedef struct PakModelContext {
    s16 selection;
    u8 reserved2[0x2E];
    f32 fade, alpha;
    u8 reserved38[8];
    MenuModelScreen *screen;
} PakModelContext;
extern Gfx *D_80110634;
extern s32 D_800D297C, D_800E28D0, D_800E28D4, D_800E1E20, D_800CD730, D_800CD8D0, D_8014DE50;
extern f32 D_800DE480_de, D_800DE484, D_800DE488, D_800DE498_de[], D_800DE4A0, literals_func_8028D244_de;
extern s32 D_800CE430[];
extern u8 D_00443128[], D_00443104[];
extern void func_802A001C_de(void *, s32, s32);
extern u8 *func_8028CFA0_de(void *, s32, s32);
extern void func_80272898_de(void *, CVector3 *, CVector3 *);
extern void func_802466A0_de(u8 *, s32, s32, s32, u8 *, s32, s32, f32, CVector3, s32, CVector3, CVector3, s32);
extern void func_8024B2D0_de(u8 *);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_8028B274_de(void *, u8 *, s32, s32);
extern void func_8024B8C4_de(u8 *);
extern void func_80246E44_de(u8 *);
extern void func_8026D980_de(u8 *, u8 *);
extern void func_80249E28_de();
extern void func_8026D9D0_de();
static inline PreviewWidget *pakLoadModel(PakModelEntry *entry, s32 id, s32 variant) {
    StateRecAt47C *owner = entry->state;
    PreviewWidget *source = (PreviewWidget *)func_8028CFA0_de(&D_8011FE88, id, variant);
    if (source == 0) {
        owner->active = 0;
        return 0;
    }
    owner->selection = id;
    owner->active = 1;
    owner->model = *source;
    owner->model.x = 0.0f;
    owner->model.y = 0.0f;
    owner->model.dx = 0.0f;
    owner->model.dy = 0.0f;
    owner->model.dz = 0.0f;
    owner->model.depth = D_800DE480_de;
    owner->size = owner->model.size;
    return &owner->model;
}
/* 18/346 aligned edits; remaining: opacity float registers and final screen-load scheduling. */
void Pak_DrawMenuModel(PakModelEntry *entry, s32 *selected, void *unused, PakModelContext *context) {
    CVector3 zero;
    CVector3 offset;
    CVector3 placed;
    CVector3 scaled;
    StateRecAt47C *widget, *selectedWidget;
    PakModelDefinition *def;
    LevelActor *draw;
    PreviewWidget *link;
    f32 ratioX;
    f32 ratioY;
    f32 wobble, opacity;
    func_802A001C_de(&zero, 0, 0xC);
    selectedWidget = entry->state;
    if (selectedWidget == 0) return;
    widget = selectedWidget;
    def = entry->definition;
    draw = &widget->actor;
    if (widget->active == 0) return;
    gSPMatrix(D_80110634++, &context->screen->matrices[D_800D297C], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    {
        MenuModelScreen *screen = context->screen;
        ratioX = screen->width / (f32)D_800E28D0;
        ratioY = screen->height;
        scaled.x = def->scale.x * ratioX;
        scaled.z = def->scale.z * ratioX;
        ratioY /= (f32)D_800E28D4;
        scaled.y = def->scale.y * ratioY;
    }
    widget->size = widget->model.size;
    link = 0;
    if (!(entry->flags & 0x2000000)) {
        link = pakLoadModel(entry, def->model, def->variant);
    }
    offset = def->offset;
    offset.y = offset.y - widget->size * scaled.y * D_800DE484;
    func_80272898_de(&context->screen->camera, &offset, &placed);
    if (link != 0 && !(entry->flags & 0x2000000)) {
        func_802466A0_de(draw, -1, def->kind, D_800CD8D0, link, -1, 0,
                         context->screen->heading + D_800DE488, placed, 0,
                         def->scale, zero, 0);
        func_8024B2D0_de(draw);
        entry->flags |= 0x2000000;
    }
    wobble = func_802B7130_de((f32)(u32)((u32)D_800CD730 * 10U) * D_800DE498_de[0]);
    wobble += 1.0f;
    opacity = context->fade;
    opacity *= context->alpha;
    wobble = wobble * D_800DE4A0 + D_800DE4A0;
    D_8014DE50 = (s32)(opacity * wobble);
    if (context->selection == selected[0]) {
        draw->update = D_00443128;
    } else {
        draw->update = D_00443104;
    }
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    if (widget->selection == 0xB) {
        func_8028B274_de(&D_8011FE88, draw, D_800CE430[draw->definition->character], 1);
    }
    if (D_800E1E20 != 4) {
        D_800E1E20 = 4;
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
        gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
        gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    }
    draw->scale = scaled;
    draw->position0 = placed;
    draw->referencePosition = placed;
    func_8024B8C4_de(draw);
    draw->position0 = placed;
    draw->referencePosition = placed;
    func_80246E44_de(draw);
    draw->yaw = draw->yaw + def->rotationSpeed * literals_func_8028D244_de;
    draw->position0 = placed;
    draw->referencePosition = placed;
    func_8026D980_de(draw, context->screen);
    func_80249E28_de(draw);
    func_8026D9D0_de();
}
#else
INCLUDE_ASM("ovl_80400000", Pak_DrawMenuModel);
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
    u8 *styleRecord;
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
            styleRecord = (u8 *)menu + bank * 0x80 + i * 0x10;
            MP_FIELD(styleRecord, u16, 0x48) = MP_FIELD(D_800E1F22, u16, i * 0x18);
            MP_FIELD(styleRecord, u16, 0x4A) = MP_FIELD(D_800E1F26, u16, i * 0x18);
            MP_FIELD(styleRecord, u16, 0x4C) = MP_FIELD(D_800E1F2A, u16, i * 0x18);
            MP_FIELD(styleRecord, u8, 0x54) = D_800E1F2F[i * 0x18];
            MP_FIELD(styleRecord, u8, 0x55) = D_800E1F33[i * 0x18];
            MP_FIELD(styleRecord, u8, 0x57) = 0xFF;
            MP_FIELD(styleRecord, u16, 0x50) = 0;
            MP_FIELD(styleRecord, u16, 0x52) = 0;
            MP_FIELD(styleRecord, u8, 0x56) = D_800E1F37[i * 0x18];
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
