#include "include_asm.h"
#include "MENU/PAK/pak_menu_entries.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "MENU/pak_menu_entries.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "MENU/8043F69C.H"

/* Moves a menu cursor through its entry table in one direction (16 to 19, reading the step byte at that offset of the current entry), wrapping at either end, recording the reverse step on the new entry when its flag allows, until it reaches an entry flagged 0x1800000 whose descriptor word at 0x1C is set. */






void func_804410AC_de(struct MenuRecAt10 *menu, u8 dir) {
    struct EntryRecAt18V2 *entry;
    s32 old;

    entry = &menu->entries[menu->cursor];
    do {
        old = menu->cursor;
        menu->cursor += ((s8 *)entry)[dir];
        if (menu->cursor < 0) {
            menu->cursor = menu->count - 1;
        } else if (menu->cursor >= menu->count) {
            menu->cursor = 0;
        }
        entry = &menu->entries[menu->cursor];
        old -= menu->cursor;
        switch (dir) {
        case 16:
            if (entry->flags & 0x80000) {
                entry->back[1] = old;
            }
            break;
        case 17:
            if (entry->flags & 0x40000) {
                entry->back[0] = old;
            }
            break;
        case 18:
            if (entry->flags & 0x200000) {
                entry->back[3] = old;
            }
            break;
        case 19:
            if (entry->flags & 0x100000) {
                entry->back[2] = old;
            }
            break;
        }
    } while ((entry->flags & 0x1800000) != 0x1800000 || entry->target->locked == 0);
}

#ifdef NON_MATCHING
/* 84/248 aligned edits; remaining: register roles of the entry loop (menu/entry/index) */
extern f32 literals_func_8028D244_de;
extern f32 D_800E24D4, D_800DE4A8, D_800DE4AC, D_800DE4B0_de;
typedef struct PakMenu PakMenu;
typedef struct PakEntry PakEntry;
typedef s32 (*PakEntryCallback)();
typedef struct PakEntryClass {
    u8 pad0[0x18];
    PakEntryCallback update; /* 0x18 */
    PakEntryCallback confirm; /* 0x1C */
} PakEntryClass;
struct PakEntry {
    u8 pad0[4];
    s16 type; /* 4 */
    u8 pad6[2];
    s32 flags; /* 8 */
    u8 padC[0xC];
    PakEntryClass *cls; /* 0x18 */
    s32 value; /* 0x1C */
    u8 pad20[8];
};
typedef struct PakMenuClass {
    u8 pad0[0x14];
    PakEntryCallback hold; /* 0x14 */
} PakMenuClass;
typedef struct PakInput {
    u8 pad0[0xB0];
    s32 buttons; /* 0xB0 */
} PakInput;
struct PakMenu {
    s16 selected; /* 0 */
    u8 pad2[10];
    PakEntry *entries; /* 0xC */
    s32 count; /* 0x10 */
    PakMenuClass *cls; /* 0x14 */
    u8 pad18[8];
    PakInput *input; /* 0x20 */
    u8 pad24[4];
    s16 state; /* 0x28 */
    u8 pad2A[2];
    f32 fade; /* 0x2C */
    f32 openA; /* 0x30 */
    f32 openB; /* 0x34 */
};
s32 func_80441214_de(PakMenu *menu, void *ctx) {
    s32 hold = 0;
    PakEntry *entry;
    PakEntry *current;
    s32 i;
    s32 flags;
    s32 allowRepeat;
    s32 pad;
    s32 state;
    PakEntryCallback callback;
    callback = menu->cls->hold;
    if (callback != 0) {
        hold = callback();
    }
    entry = menu->entries;
    for (i = menu->count - 1; i != -1; i--) {
        callback = entry->cls->update;
        if (callback != 0) {
            callback(entry, menu, ctx);
        }
        entry++;
    }
    current = menu->entries + menu->selected;
    menu->fade += literals_func_8028D244_de;
    flags = current->flags & 0x400000;
    func_80442B5C_de(menu);
    switch (menu->state) {
    case 0:
        menu->openA += literals_func_8028D244_de;
        if (menu->openA >= D_800E24D4) {
            menu->openA = D_800E24D4;
            menu->state = 1;
        }
        break;
    case 1:
        menu->openB += literals_func_8028D244_de * D_800DE4A8;
        if (menu->openB >= D_800DE4AC) {
            menu->openB = D_800DE4AC;
            menu->state = 2;
        }
        break;
    case 3:
        menu->openB -= literals_func_8028D244_de * D_800DE4B0_de;
        if (menu->openB <= 0.0f) {
            menu->openB = 0.0f;
            menu->state = 4;
        }
        break;
    case 4:
        menu->openA -= literals_func_8028D244_de;
        if (menu->openA <= 0.0f) {
            menu->openA = 0.0f;
            return 1;
        }
        break;
    }
    state = menu->state;
    if (state >= 3 || state < 0) {
        return 0;
    }
    if (hold != 0) {
        menu->state = 4;
    }
    if (current->flags & 8) {
        return 0;
    }
    allowRepeat = 1;
    if (current->type == 2) {
        pad = menu->input->buttons;
        if (pad & 0x20202) {
            allowRepeat = 0;
            current->value -= 2;
            if (current->value < 0) {
                current->value = 0;
            }
        } else if (pad & 0x40101) {
            current->value += 2;
            allowRepeat = 0;
            if (current->value >= 0x100) {
                current->value = 0xFF;
            }
        }
    }
    if (flags == 0) {
        if (func_80264388_de(menu->input) != 0) {
            func_804410AC_de(menu, 0x10);
        }
        if (func_802643A0_de(menu->input) != 0) {
            func_804410AC_de(menu, 0x11);
        }
    } else if (menu->input->buttons & 0x60303) {
        allowRepeat = 0;
    }
    if (allowRepeat != 0) {
        if (func_802643B8_de(menu->input) != 0) {
            func_804410AC_de(menu, 0x12);
        }
        if (func_802643D0_de(menu->input) != 0) {
            func_804410AC_de(menu, 0x13);
        }
    }
    if (menu->state != 2) {
        return 0;
    }
    if (func_8026437C_de(menu->input) != 0 ||
        ((func_80264388_de(menu->input) != 0 || func_802643A0_de(menu->input) != 0) && flags != 0)) {
        callback = current->cls->confirm;
        if (callback != 0 && callback(current, menu, ctx) == 0) {
            return 0;
        }
        menu->state = 3;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80441214_de);
#endif


extern void *func_80442A58_de(s8 *);
extern void func_8043F52C_de(TextBoundsText *, TextBoundsMetrics *);
extern void func_802AA9F4_de(void);
extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u32 D_800CD730;
extern s32 D_800E1E20;
extern const f32 g_menuCenterFraction;

/* Lay out visible menu entries and draw their callbacks with a pulsing selection highlight. */
void Pak_DrawMenuEntries(struct MenuStyle *menu, s8 *member) {
    TextBoundsMetrics bounds, metrics, placed;
    TextBoundsData *data;
    TextBoundsText *entry;
    s32 i;
    f32 centerX, centerY, top, bottom, alpha;

    data = func_80442A58_de(member);
    bounds.left = 1024;
    bounds.right = -1024;
    bounds.top = 1024;
    bounds.bottom = -1024;
    metrics.width = 0;
    metrics.height = 0;
    metrics.left = 0;
    metrics.right = 0;
    metrics.top = 0;
    metrics.bottom = 0;
    for (i = 0; i < menu->count; i++) {
        entry = &menu->entries[i];
        if (entry->flags & 0x800000) {
            if (entry->flags & 0x20000000) {
                metrics.left = 1024;
                metrics.right = -1024;
                metrics.top = 1024;
                metrics.bottom = -1024;
                metrics.width = 0;
                metrics.height = 0;
            } else {
                func_8043F52C_de(entry, &metrics);
            }
            bounds.left = bounds.left < metrics.left ? bounds.left : metrics.left;
            bounds.right = bounds.right > metrics.right ? bounds.right : metrics.right;
            bounds.top = bounds.top < metrics.top ? bounds.top : metrics.top;
            bounds.bottom = bounds.bottom > metrics.bottom ? bounds.bottom : metrics.bottom;
        }
    }
    bounds.width = bounds.right - bounds.left;
    bounds.height = bounds.bottom - bounds.top;
    if (bounds.width < 0 || bounds.height < 0) {
        return;
    }
    /* fakematch: the split source keeps the leading half-scale constant separate
       so the following double literal retains its ROM alignment. */
    centerX = data->x + data->unk_29C * g_menuCenterFraction + menu->x;
    centerY = data->y + data->unk_2A0 * g_menuCenterFraction + menu->y;
    bounds.left = centerX - bounds.width / 2;
    bounds.right = centerX + bounds.width / 2;
    bounds.top = centerY - bounds.height / 2;
    bounds.bottom = centerY + bounds.height / 2;
    metrics.width = 0;
    metrics.height = 0;
    metrics.left = 0;
    metrics.right = 0;
    metrics.top = 0;
    metrics.bottom = 0;
    D_800E1E20 = -1;
    for (i = 0; i < menu->count; i++) {
        entry = &menu->entries[i];
        if (entry->flags & 0x800000) {
            metrics.field0 = i;
            if (entry->flags & 0x20000000) {
                func_8043F52C_de(entry, &metrics);
                metrics.width = 0;
                metrics.height = 0;
                metrics.left = data->x;
                metrics.right = 0;
                metrics.top = data->y;
                metrics.bottom = 0;
            } else {
                func_8043F52C_de(entry, &metrics);
            }
            placed = metrics;
            if (!(entry->flags & 0x20000000)) {
                placed.left += bounds.left;
                placed.right += bounds.left;
                placed.top += bounds.top;
                placed.bottom += bounds.top;
            }
            if (entry->flags & 1) {
                placed.left = centerX - metrics.width / 2;
                placed.right = placed.left + metrics.width;
            }
            if (entry->flags & 2) {
                placed.left = bounds.left;
                placed.right = placed.left + metrics.width;
            }
            if (entry->flags & 4) {
                placed.right = bounds.right;
                placed.left = placed.right - metrics.width;
            }
            if (entry->flags & 0x800000) {
                if (menu->state == i && entry->mode != 3 && !(entry->flags & 8)) {
                    top = placed.top;
                    bottom = placed.bottom;
                    /* Preserve the highlight extent calculation and its float rounding. */
                    bottom = top + (bottom - top);
                    func_802AA9F4_de();
                    alpha = menu->alpha * menu->fade *
                        ((func_802B7130_de((f32)(D_800CD730 * 10) * 0.017453294f) + 1.0f) * 50.0f + 50.0f);
                    if (entry->flags & 0x10) {
                        func_802A7DE4_de(placed.left - 4, top, placed.right + 4, bottom, 0, 0, 255, 0, 10, (u8)alpha);
                    } else {
                        func_802A7DE4_de(placed.left - 4, top, placed.right + 4, bottom, 0, 0, 255, 0, 10, (u8)alpha);
                    }
                    D_800E1E20 = -1;
                }
                entry->field18->draw(entry, &placed, &bounds, menu);
            }
        }
    }
}


#ifdef NON_MATCHING
#include "COMMON/MENU_UI_PROVIDERS.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
typedef struct EntryBounds { s32 pad[5]; s32 left; s32 right; s32 top; s32 bottom; } EntryBounds;
extern f32 D_800E2504;
extern void func_802AA9F4_de();
/* 69/180 words (111 aligned edits); remaining: the ROM frame is 16 bytes larger (extra stack words) and keeps a dead load of unused->8 & 0x3FE0 */
void func_80441BE0_de(u8 *self, void *unused, s32 relative) {
    u8 *view = *(u8 **)(self + 0x40);
    EntryBounds bounds;
    struct { s32 xMin, xMax, yMin, yMax; } box;
    struct { s32 w, h; } size;
    s32 i;
    f32 centerX;
    f32 margin;
    f32 gap;
    f32 top;
    f32 fade;
    s32 alpha;
    box.xMin = 0x400;
    box.xMax = -0x400;
    box.yMin = 0x400;
    box.yMax = -0x400;
    bounds.pad[1] = 0;
    bounds.pad[2] = 0;
    bounds.left = 0;
    bounds.right = 0;
    bounds.top = 0;
    bounds.bottom = 0;
    for (i = 0; i < *(s32 *)(self + 0x10); i++) {
        func_8043F52C_de((TextBoundsText *)(*(u8 **)(self + 0xC) + i * 0x28), (TextBoundsMetrics *)&bounds);
        if (bounds.left < box.xMin) {
            box.xMin = bounds.left;
        }
        if (bounds.right > box.xMax) {
            box.xMax = bounds.right;
        }
        if (bounds.top < box.yMin) {
            box.yMin = bounds.top;
        }
        if (bounds.bottom > box.yMax) {
            box.yMax = bounds.bottom;
        }
    }
    size.w = box.xMax - box.xMin;
    size.h = box.yMax - box.yMin;
    if (size.w < 0 || size.h < 0) {
        return;
    }
    centerX = *(f32 *)(view + 0x2A4) + *(f32 *)(view + 0x29C) * D_800E2504 + *(s16 *)(self + 2);
    box.xMin = (s32)(centerX - D_800E28D0 / 2);
    box.xMax = (s32)(centerX + D_800E28D0 / 2);
    margin = D_800E28D4 * D_800DE4D8;
    gap = D_800E28D4 < 0xDF ? D_800DE4DC : D_800DE4E0_de;
    margin = margin - gap;
    if (relative != 0) {
        top = *(f32 *)(view + 0x2A8) + (f32)D_800E28D4 + *(s16 *)(self + 4) - margin;
    } else {
        top = *(f32 *)(view + 0x2A8) + *(s16 *)(self + 4);
    }
    box.yMin = (s32)top;
    box.yMax = (s32)(box.yMin + margin);
    func_802AA9F4_de();
    fade = *(f32 *)(self + 0x30) * D_800DE4E4;
    if (fade >= *(f32 *)D_800DE4E8) {
        alpha = (s32)(fade - *(f32 *)D_800DE4E8) | 0x80000000;
    } else {
        alpha = (s32)fade;
    }
    func_802A7DE4_de(box.xMin, box.yMin, box.xMax, box.yMax, 1, 0, 0, 0, 0, alpha & 0xFF);
}
#else
INCLUDE_ASM("ovl_80400000", func_80441BE0_de);
#endif
