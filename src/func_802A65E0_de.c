#include "span_1000/code_802A6AC0.h"
#include "types.h"
#include "math_helpers.h"
#include "gfx.h"
#include "gbi.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80291054.h"
/* Steps a four-item toggle menu: counts frames, and once func_802A7098_de allows input opens the menu on button 0x20 or, on release, closes it after running the selected item's select callback (toggling it when that reports 1, or directly when it has none); each frame it settles every item's bounce animation toward zero, toggles the selected item off when an enabled item's update callback fails, advances the blink counter twice, and then either finishes opening, finishes closing, or moves the selection through func_802A70D4_de on buttons 0x100 and 0x200. Toggling an item starts its bounce at +5 with the current frame and its restore values, or at -5 when switching off. */
extern s32 func_802A7098_de(void);
extern void func_802A70D4_de(ToggleMenu *menu, s32 direction);
static inline void toggle(ToggleMenu *menu, MenuItem *item) {
    if ((item->on = !item->on) != 0) {
        item->bounce = 5;
        item->startFrame = menu->frame;
        item->value = item->restoreValue;
        item->extra = item->restoreExtra;
    } else {
        item->bounce = -5;
    }
}
void func_802A65E0_de(ToggleMenu *menu, Input_func_802A65E0_de *input) {
    s16 bounce;
    s32 i;
    /* FAKEMATCH: preserve the original frame-update instruction scheduling at the function entry. */
do {
    } while (0);
    menu->frame++;
    if (func_802A7098_de() == 0) {
        return;
    }
    if (menu->state < 2) {
        if ((input->held & 0x20) && menu->state != 1) {
            menu->state = 1;
        }
    } else if (!(input->held & 0x20) && menu->state != 3) {
        menu->state = 3;
        if (menu->items[menu->selected].active != 0) {
            if (menu->items[menu->selected].select != 0) {
                if (menu->items[menu->selected].select(input, &menu->items[menu->selected]) == 1) {
                    toggle(menu, &menu->items[menu->selected]);
                }
            } else {
                toggle(menu, &menu->items[menu->selected]);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        bounce = RW_ABS(menu->items[i].bounce);
        if (bounce != 0) {
            if (bounce == menu->items[i].bounce) {
                menu->items[i].bounce--;
            } else {
                menu->items[i].bounce++;
            }
        }
        if (menu->items[i].active != 0 && menu->items[i].on != 0 && menu->items[i].update != 0 &&
            menu->items[i].update(input, &menu->items[i]) == 0) {
            toggle(menu, &menu->items[menu->selected]);
        }
    }
    if (++menu->blink >= 5) {
        menu->blink = -5;
    }
    if (++menu->blink >= 5) {
        menu->blink = -5;
    }
    if (menu->state == 1) {
        if (++menu->timer >= 5) {
            menu->state = 2;
        }
    } else if (menu->state == 3) {
        if (--menu->timer == 0) {
            menu->state = 0;
        }
    } else if (input->pressed & 0x100) {
        func_802A70D4_de(menu, 0);
    } else if (input->pressed & 0x200) {
        func_802A70D4_de(menu, 1);
    }
}

extern s32 func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);

/* Draw active toggle-menu items in activation order, then draw the open menu
* with a pulsing highlight on its selected item. */
void func_802A6900_de(ToggleMenu *panel, Input_func_802A65E0_de *player) {
    MenuItem *sorted[4];
    s32 width;
    s32 height;
    MenuItem *slot;
    MenuItem *first;
    MenuItem *second;
    f32 *view;
    s32 i;
    s32 swapped;
    s32 n;
    s16 magnitude;
    s32 pulse;
    s16 r, g, b;
    f32 spacing;
    f32 opacity;
    f32 sx, sy;
    f32 x, y;
    f32 unit;
    f32 colorScale;
    f32 fadeStep;
    f32 grid;
    f32 origin;
    s32 row;
    f32 factor;

    spacing = 0.0f;
    for (i = 0; i < 4; i++) {
        sorted[i] = &panel->items[i];
    }
    do {
        swapped = 0;
        for (i = 0; i < 3; i++) {
            first = sorted[i];
            second = sorted[i + 1];
            if ((u32)first->startFrame > (u32)second->startFrame) {
                swapped = 1;
                sorted[i] = second;
                sorted[i+1] = first;
            }
        }
    } while (swapped);
    r = g = b = 255;
    i = 0;
    n = i;
    colorScale = 255.0f;
    fadeStep = 0.1f;
    grid = 0.25f;
    origin = 0.75f;
    unit = 0.5f;

    view = player->view->viewport;
    sx = view[0] * 0.0015625f;
    sy = view[1] * 0.0020833334f;
    for (i = 0; i < 4; i++) {
        slot = sorted[i];
        magnitude = slot->bounce;
        if ((f32)magnitude < 0.0f) {
            magnitude = -magnitude;
        }
        if (slot->active && (slot->on || magnitude != 0)) {
            func_802AA950_de(slot->image, slot->imageFrame, &width, &height);
            if (width != 0) {
                opacity = (magnitude != slot->bounce ? (f32)magnitude : (f32)(5-magnitude)) * fadeStep;
                row = n;
                if (n < 0) {
                    row = n + 3;
                }
                row >>= 2;
                x = view[2] + view[0]*unit + ((origin - (f32)(n-row*4)*grid)+spacing)*unit*view[0];
                y = view[3] + view[1]*unit + (origin - (f32)(row))*unit*view[1];
                gDPSetEnvColor(D_80110634++, r, g, b, opacity*colorScale);
                func_802AAC28_de(slot->image, slot->imageFrame,
                (s16)(s32)(x-(f32)width*sx*unit),
                (s16)(s32)(y-(f32)height*sy*unit), sx, sy, 1);
                if (magnitude != slot->bounce && opacity < grid) {
                    spacing += grid - opacity;
                }
                n++;
            }
        }
    }
    if (panel->state) {
        i = 0;
        n = i;
        unit = 0.5f;

        sx = view[0]*0.003125f;
        colorScale = (f32)(panel->timer*51);
        sy = view[1]*0.004166667f;
        for (i = 0; i < 4; i++) {
            slot = &panel->items[i];
            if (slot->active) {
                func_802AA950_de(slot->image, slot->imageFrame, &width, &height);
                if (width != 0) {
                    row = n;
                    if (n < 0) {
                        row = n + 3;
                    }
                    row >>= 2;
                    x = view[2]+view[0]*unit+((2.0f*(f32)(n-row*4)*0.25f)+-0.75f)*unit*view[0];
                    y = view[3]+view[1]*unit+((2.0f*(f32)(row))+-0.5f)*unit*view[1];
                    if (i == panel->selected) {
                        pulse = panel->blink;
                        factor = (f32)((((f32)pulse < 0.0f ? -pulse : pulse) * 191) / 5 + 64);
                        opacity = factor * 0.00390625f;
                        r = 255;
                        g = 255;
                        b = 255;
                    } else {
                        r = 128;
                        g = 128;
                        b = 128;
                        opacity = unit;
                    }
                    gDPSetEnvColor(D_80110634++, r, g, b, opacity*colorScale);
                    n++;
                    func_802AAC28_de(slot->image, slot->imageFrame,
                    (s16)(s32)(x-(f32)width*sx*unit),
                    (s16)(s32)(y-(f32)height*sy*unit), sx, sy, 1);
                }
            }
        }
    }
}
