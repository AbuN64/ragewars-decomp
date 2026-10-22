#include "include_asm.h"
#include "MENU/PAK/pak_menu_entries.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"

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

INCLUDE_ASM("ovl_80400000", func_80441214_de);


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
void func_80441BE0_de(u8 *self, void *unused, s32 relative) {
    u8 *view = *(u8 **)(self + 0x40);
    EntryBounds bounds;
    s32 xMin = 0x400;
    s32 xMax = -0x400;
    s32 yMin = 0x400;
    s32 yMax = -0x400;
    s32 i;
    s32 width;
    s32 height;
    f32 centerX;
    f32 margin;
    f32 gap;
    f32 top;
    f32 fade;
    s32 alpha;
    bounds.pad[3] = 0;
    bounds.pad[4] = 0;
    bounds.left = 0;
    bounds.right = 0;
    bounds.top = 0;
    bounds.bottom = 0;
    for (i = 0; i < *(s32 *)(self + 0x10); i++) {
        func_8043F52C_de((TextBoundsText *)(*(u8 **)(self + 0xC) + i * 0x28), (TextBoundsMetrics *)&bounds);
        if (bounds.left < xMin) {
            xMin = bounds.left;
        }
        if (bounds.right > xMax) {
            xMax = bounds.right;
        }
        if (bounds.top < yMin) {
            yMin = bounds.top;
        }
        if (bounds.bottom > yMax) {
            yMax = bounds.bottom;
        }
    }
    width = xMax - xMin;
    height = yMax - yMin;
    if (width < 0 || height < 0) {
        return;
    }
    centerX = *(f32 *)(view + 0x2A4) + *(f32 *)(view + 0x29C) * D_800E2504 + *(s16 *)(self + 2);
    xMin = (s32)(centerX - D_800E28D0 / 2);
    xMax = (s32)(centerX + D_800E28D0 / 2);
    margin = D_800E28D4 * D_800DE4D8;
    gap = D_800E28D4 < 0xDF ? D_800DE4DC : D_800DE4E0_de;
    margin = margin - gap;
    if (relative != 0) {
        top = *(f32 *)(view + 0x2A8) + (f32)D_800E28D4 + *(s16 *)(self + 4) - margin;
    } else {
        top = *(f32 *)(view + 0x2A8) + *(s16 *)(self + 4);
    }
    yMin = (s32)top;
    yMax = (s32)(yMin + margin);
    func_802AA9F4_de();
    fade = *(f32 *)(self + 0x30) * D_800DE4E4;
    if (fade >= *(f32 *)D_800DE4E8) {
        alpha = (s32)(fade - *(f32 *)D_800DE4E8) | 0x80000000;
    } else {
        alpha = (s32)fade;
    }
    func_802A7DE4_de(xMin, yMin, xMax, yMax, 1, 0, 0, 0, 0, alpha & 0xFF);
}
#else
INCLUDE_ASM("ovl_80400000", func_80441BE0_de);
#endif
