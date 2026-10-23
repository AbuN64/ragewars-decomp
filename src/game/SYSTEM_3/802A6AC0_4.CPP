#include "COMMON/OBJRECAT18V6.H"
#include "SYSTEM_3/802A6AC0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"

/* Steps a four-item toggle menu: counts frames, and once func_802A7098_de allows input opens the menu on button 0x20 or, on release, closes it after running the selected item's select callback (toggling it when that reports 1, or directly when it has none); each frame it settles every item's bounce animation toward zero, toggles the selected item off when an enabled item's update callback fails, advances the blink counter twice, and then either finishes opening, finishes closing, or moves the selection through func_802A70D4_de on buttons 0x100 and 0x200. Toggling an item starts its bounce at +5 with the current frame and its restore values, or at -5 when switching off. */
extern s32 func_802A7098_de(void *menu);

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

void System_UpdateToggleMenu(ToggleMenu *menu, Input_func_802A65E0_de *input) {
    s16 bounce;
    s32 i;
    menu->frame++;
    if (func_802A7098_de(menu) == 0) {
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
