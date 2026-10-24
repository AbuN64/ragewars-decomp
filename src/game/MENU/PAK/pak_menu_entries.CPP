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

/* Update entry callbacks, animate opening/closing, and handle the selected entry. */
extern f32 literals_func_8028D244_de;
extern const f32 g_pakMenuAnimationLimits[4];
extern f32 D_800DE4A8, D_800DE4AC, D_800DE4B0_de;
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
s32 Pak_UpdateMenuEntries(PakMenu *menu, void *context) {
    s32 closeRequested = 0;
    PakEntry *entry;
    s32 i;
    s32 selectionFlags;
    s32 allowRepeat;
    s32 buttons;
    s32 state;
    PakEntryCallback callback;
    callback = menu->cls->hold;
    if (callback != 0) {
        closeRequested = callback();
    }
    i = menu->count;
    entry = menu->entries;
    while (--i != -1) {
        callback = entry->cls->update;
        if (callback != 0) {
            callback(entry, menu, context);
        }
        entry++;
    }
    entry = menu->entries + menu->selected;
    menu->fade += literals_func_8028D244_de;
    selectionFlags = entry->flags & 0x400000;
    func_80442B5C_de(menu);
    switch (menu->state) {
    case 0:
        menu->openA += literals_func_8028D244_de;
        if (menu->openA >= g_pakMenuAnimationLimits[0]) {
            menu->openA = g_pakMenuAnimationLimits[0];
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
    if (state >= 3) {
        return 0;
    }
    if (state < 0) {
        return 0;
    }
    if (closeRequested != 0) {
        menu->state = 4;
    }
    if (entry->flags & 8) {
        return 0;
    }
    allowRepeat = 1;
    if (entry->type == 2) {
        buttons = menu->input->buttons;
        if (buttons & 0x20202) {
            allowRepeat = 0;
            entry->value -= 2;
            if (entry->value < 0) {
                entry->value = 0;
            }
        } else if (buttons & 0x40101) {
            entry->value += 2;
            allowRepeat = 0;
            if (entry->value >= 0x100) {
                entry->value = 0xFF;
            }
        }
    }
    if (selectionFlags == 0) {
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
        (func_80264388_de(menu->input) != 0 && selectionFlags != 0) ||
        (func_802643A0_de(menu->input) != 0 && selectionFlags != 0)) {
        callback = entry->cls->confirm;
        if (callback != 0 && callback(entry, menu, context) == 0) {
            return 0;
        }
        menu->state = 3;
    }
    return 0;
}


extern void *func_80442A58_de(s8 *);
extern void func_8043F52C_de(TextBoundsText *, CItemInfo *);
extern void func_802AA9F4_de(void);
extern void func_802A7DE4_de(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u32 D_800CD730;
extern s32 D_800E1E20;
extern const f32 g_menuCenterFraction;

/* Lay out visible menu entries and draw their callbacks with a pulsing selection highlight. */
void Pak_DrawMenuEntries(struct MenuStyle *menu, s8 *member) {
    CItemInfo bounds, metrics, placed;
    TextBoundsData *data;
    TextBoundsText *entry;
    s32 i;
    f32 centerX, centerY, top, bottom, alpha;

    data = func_80442A58_de(member);
    bounds.left = 1024;
    bounds.right = -1024;
    bounds.m_Top = 1024;
    bounds.m_Bottom = -1024;
    metrics.width = 0;
    metrics.height = 0;
    metrics.left = 0;
    metrics.right = 0;
    metrics.m_Top = 0;
    metrics.m_Bottom = 0;
    for (i = 0; i < menu->count; i++) {
        entry = &menu->entries[i];
        if (entry->flags & 0x800000) {
            if (entry->flags & 0x20000000) {
                metrics.left = 1024;
                metrics.right = -1024;
                metrics.m_Top = 1024;
                metrics.m_Bottom = -1024;
                metrics.width = 0;
                metrics.height = 0;
            } else {
                func_8043F52C_de(entry, &metrics);
            }
            bounds.left = bounds.left < metrics.left ? bounds.left : metrics.left;
            bounds.right = bounds.right > metrics.right ? bounds.right : metrics.right;
            bounds.m_Top = bounds.m_Top < metrics.m_Top ? bounds.m_Top : metrics.m_Top;
            bounds.m_Bottom = bounds.m_Bottom > metrics.m_Bottom ? bounds.m_Bottom : metrics.m_Bottom;
        }
    }
    bounds.width = bounds.right - bounds.left;
    bounds.height = bounds.m_Bottom - bounds.m_Top;
    if (bounds.width < 0 || bounds.height < 0) {
        return;
    }
    /* fakematch: the split source keeps the leading half-scale constant separate
       so the following double literal retains its ROM alignment. */
    centerX = data->x + data->unk_29C * g_menuCenterFraction + menu->x;
    centerY = data->y + data->unk_2A0 * g_menuCenterFraction + menu->y;
    bounds.left = centerX - bounds.width / 2;
    bounds.right = centerX + bounds.width / 2;
    bounds.m_Top = centerY - bounds.height / 2;
    bounds.m_Bottom = centerY + bounds.height / 2;
    metrics.width = 0;
    metrics.height = 0;
    metrics.left = 0;
    metrics.right = 0;
    metrics.m_Top = 0;
    metrics.m_Bottom = 0;
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
                metrics.m_Top = data->y;
                metrics.m_Bottom = 0;
            } else {
                func_8043F52C_de(entry, &metrics);
            }
            placed = metrics;
            if (!(entry->flags & 0x20000000)) {
                placed.left += bounds.left;
                placed.right += bounds.left;
                placed.m_Top += bounds.m_Top;
                placed.m_Bottom += bounds.m_Top;
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
                    top = placed.m_Top;
                    bottom = placed.m_Bottom;
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
extern f32 D_800E2504;
extern void func_802AA9F4_de();
extern TextBoundsFont D_800E1E24_de[];
static __inline__ TextBoundsFont *textBoundsFont(TextBoundsText *text) {
    s32 style = 0;
    switch ((u32)text->flags & 0x3FE0) {
    case 0x20: style = 0; break;
    case 0x40: style = 1; break;
    case 0x80: style = 2; break;
    case 0x100: style = 3; break;
    case 0x200: style = 4; break;
    case 0x400: style = 5; break;
    case 0x800: style = 6; break;
    case 0x1000: style = 7; break;
    case 0x2000: style = 8; break;
    default: style = 0; break;
    }
    return &D_800E1E24_de[style];
}
/* 20/180 aligned edits; remaining: parameter copy order, the gap/margin join and the relative-top float loads;
 * the (u32) alpha conversion uses its own 2^31 literal, while D_800DE4E8 (that literal in the ROM) is also read
 * at +4 as a string by other functions, so the pool cannot be placed yet. */
void Pak_DrawMenuPanel(u8 *self, void *unused, s32 relative) {
    TextBoundsFont *font = textBoundsFont((TextBoundsText *)unused);
    u8 *view = *(u8 **)(self + 0x40);
    CItemInfo box;
    CItemInfo bounds;
    s32 i;
    f32 centerX;
    f32 margin;
    f32 gap;
    f32 top;
    box.left = 0x400;
    box.right = -0x400;
    box.m_Top = 0x400;
    box.m_Bottom = -0x400;
    bounds.width = 0;
    bounds.height = 0;
    bounds.left = 0;
    bounds.right = 0;
    bounds.m_Top = 0;
    bounds.m_Bottom = 0;
    for (i = 0; i < *(s32 *)(self + 0x10); i++) {
        func_8043F52C_de((TextBoundsText *)(*(u8 **)(self + 0xC) + i * 0x28), &bounds);
        box.left = box.left < bounds.left ? box.left : bounds.left;
        box.right = box.right > bounds.right ? box.right : bounds.right;
        box.m_Top = box.m_Top < bounds.m_Top ? box.m_Top : bounds.m_Top;
        box.m_Bottom = box.m_Bottom > bounds.m_Bottom ? box.m_Bottom : bounds.m_Bottom;
    }
    box.width = box.right - box.left;
    box.height = box.m_Bottom - box.m_Top;
    if (box.width < 0 || box.height < 0) {
        return;
    }
    centerX = *(f32 *)(view + 0x2A4) + *(f32 *)(view + 0x29C) * D_800E2504 + *(s16 *)(self + 2);
    box.width = D_800E28D0;
    box.left = (s32)(centerX - box.width / 2);
    box.right = (s32)(centerX + box.width / 2);
    margin = D_800E28D4 * D_800DE4D8;
    gap = D_800E28D4 < 0xDF ? D_800DE4DC : D_800DE4E0_de;
    margin = margin - gap;
    if (relative != 0) {
        top = *(f32 *)(view + 0x2A8) + (f32)D_800E28D4 + *(s16 *)(self + 4) - margin;
    } else {
        top = *(f32 *)(view + 0x2A8) + *(s16 *)(self + 4);
    }
    box.m_Top = (s32)top;
    box.m_Bottom = (s32)(box.m_Top + margin);
    box.height = box.m_Bottom - box.m_Top;
    func_802AA9F4_de();
    func_802A7DE4_de(box.left, box.m_Top, box.right, box.m_Bottom, 1, 0, 0, 0, 0, (u8)(u32)(*(f32 *)(self + 0x30) * D_800DE4E4));
}
#else
INCLUDE_ASM("ovl_80400000", Pak_DrawMenuPanel);
#endif
