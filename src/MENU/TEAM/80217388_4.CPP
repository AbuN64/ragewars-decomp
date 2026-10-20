#include "include_asm.h"
#include "MENU/TEAMMENU.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MATH_HELPERS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
extern void func_80272898_de(void *arg0, void *arg1, void *arg2);

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "particle/80271B18_3.H"
typedef struct WeaponMenuIconsVec3f { f32 x, y, z; } WeaponMenuIconsVec3f;

struct WeaponMenuIconsItem;
typedef struct WeaponMenuIconsItem WeaponMenuIconsItem;
typedef struct WeaponMenuIconsMenu WeaponMenuIconsMenu;
typedef struct WeaponMenuIconsPlayer WeaponMenuIconsPlayer;
typedef struct WeaponMenuIconsView WeaponMenuIconsView;

struct WeaponMenuIconsMenu;

struct WeaponMenuIconsPlayer;

struct WeaponMenuIconsView;









struct WeaponMenuIconsItem {
    s32 slot;
    s32 weapon;
    WeaponMenuIconsVec3f position;
    s32 icon;
    f32 width;
    f32 height;
};
struct WeaponMenuIconsMenu {
    s32 active;
    s32 pad4;
    f32 open;
    char padC[0x14 - 0xC];
    f32 phase;
    char pad18[0x37C - 0x18];
    s32 cursor;
};
struct WeaponMenuIconsPlayer {
    char pad[0x5DC];
    WeaponMenuIconsView *view;
};
struct WeaponMenuIconsView {
    char pad[0x29C];
    f32 viewport[4];
};

/* Draws a player's weapon menu icons: for each listed item it places the icon inside the player's
   viewport from 0x5DC, sets the environment colour to a pulsing grey for the item under the cursor at
   0x37C or to 200 or 100 by whether func_8022EB0C_de says the player owns the weapon, fades it by the
   item's alpha, the menu's opening and the options fade D_801462DE, and draws the sprite through
   func_802AAC28_de scaled to the viewport and the item's size. */









extern u8 D_801462DE;
extern f32 D_800C2200_de;
extern f32 D_800C2208_de;
extern f32 D_800C2210_de;
extern f32 D_800C2218_de;
extern Gfx *D_80110634;
extern s32 func_8022EB0C_de(WeaponMenuIconsPlayer *, s32);
extern void func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);

void func_80217630_de(WeaponMenuIconsMenu *menu, WeaponMenuIconsItem *items, s32 count, WeaponMenuIconsPlayer *player) {
    s32 width;
    s32 height;
    f32 base;
    f32 fade;
    s32 level;
    f32 scaleX;
    f32 scaleY;
    f32 x;
    f32 y;
    f32 alpha;
    s32 red;
    s16 green;
    s32 blue;
    WeaponMenuIconsView *view;
    f32 *viewport;
    WeaponMenuIconsItem *item;

    level = D_801462DE + 0x40;
    fade = menu->open * (level < 0x100 ? level : 255.0f);
    item = items;
    while (--count != -1) {
        view = player->view;
        scaleX = view->viewport[0] * (1.0f / 320.0f);
        scaleY = view->viewport[1] * (1.0f / 240.0f);
        viewport = view->viewport;
        x = viewport[2] + viewport[0] * 0.5f + item->position.x * 0.5f * viewport[0];
        y = viewport[3] + viewport[1] * 0.5f + item->position.y * 0.5f * viewport[1];
        alpha = item->width;
        if (item->icon != 0) {
            func_802AA950_de(item->icon, 0, &width, &height);
            if (menu->cursor == item->slot) {
                blue = red = func_802B6560_de(menu->phase) * 63.0f + 192.0f;
                alpha = 1.0f;
                green = red;
            } else {
                red = func_8022EB0C_de(player, item->weapon);
                red = red == 0 ? 100 : 200;
                green = red;
                blue = red;
            }
            gDPSetEnvColor(D_80110634++, red, green, blue, (u32)(alpha * fade));
            func_802AAC28_de(item->icon, 0, x - width * item->height * scaleX * 0.5f,
                          y - height * item->height * scaleY * 0.5f,
                          scaleX * item->height, scaleY * item->height, 1);
        }
        item++;
    }
}
#else
INCLUDE_ASM("span_1000", func_80217630_de);
#endif

/* Lays out a player's weapon menu when it is active: for each of the eight slots at 0x1C holding a
   weapon it eases the slot's scale toward its target (1.3 times larger under the cursor at 0x37C),
   turns an offset raised by the menu's opening by the slot's angle to place it, and lists it with its
   weapon's icon from D_800D052C (no icon for weapons outside 0 to 21), then passes the list to
   func_80217630_de. */














extern ObjRecAt6V1 *D_800D052C[];

extern f32 func_80274808_de(f32, f32, f32);

extern void func_802727D8_de(Matrix *);

extern void func_80273C68_de(Matrix *, f32);


extern void func_80217630_de(Menu *, Item *, s32, s32);

void func_80217928_de(Menu *menu, s32 arg1, s32 arg2) {
    Matrix matrix;
    CVector3 position;
    Item items[36];
    CVector3 offset;
    s32 count;
    s32 i;
    SlotRecAt14 *slot;
    Item *item;
    f32 target;
    f32 size;
    s32 weapon;

    if (menu->active != 0) {
        offset.x = 0.0f;
        item = items;
        count = 0;
        offset.y = -0.6f - (0.4f - menu->open * 0.4f);
        offset.z = 0.0f;
        for (i = 0; i < 8; i++) {
            slot = &menu->slots[i];
            if (menu->slots[i].weapon != -1) {
                if (i == menu->cursor) {
                    target = *(&D_800C9138_de + 1) * 1.3f;
                } else {
                    target = *(&D_800C9138_de + 1);
                }
                size = 1.0f;
                slot->scale = func_80274808_de(slot->scale, target, *(&D_800C9138_de + 1) * 0.1f);
                func_802727D8_de(&matrix);
                func_80273C68_de(&matrix, slot->angle);
                func_80272898_de(&matrix, &offset, &position);
                weapon = menu->slots[i].weapon;
                if (weapon < 0) {
                    goto no_icon;
                }
                if (weapon >= 0x16) {
                no_icon:
                    item->icon = item->width = 0;
                    item->slot = i;
                    item->weapon = menu->slots[i].weapon;
                    item->position = position;
                } else {
                    item->slot = i;
                    item->weapon = menu->slots[i].weapon;
                    item->position = position;
                    item->icon = D_800D052C[weapon]->unk6;
                    item->width = size;
                    item->height = size;
                }
                item++;
                count++;
            } else {
                item->icon = item->width = 0;
            }
        }
        func_80217630_de(menu, items, count, arg2);
    }
}

/* Returns which of eight menu directions a player's stick points in: -1 inside a dead zone of radius
   60, a diagonal (1, 3, 5 or 7) when both axes are non-zero and their magnitudes differ by less than 46,
   otherwise 2 or 6 when the horizontal axis dominates and 0 or 4 when the vertical one does, reading
   the stick bytes at 0xC6 and 0xC7 of the controller at 0x698. */
s32 func_80217B3C_de(PlayerRecAt698 *player) {
    ControllerRecAtC7 *controller;
    s8 x;
    s8 y;
    controller = player->controller;
    x = controller->x;
    y = controller->y;
    if (x * x + y * y < 3600) {
        return -1;
    }
    if (RW_ABS(RW_ABS(x) - RW_ABS(y)) < 46 && x != 0 && y != 0) {
        if (x * y > 0) {
            if (x > 0) {
                return 1;
            }
            if (controller->x != 0) {
                return 5;
            }
            return 5;
        }
        return y > 0 ? 7 : 3;
    }
    if (RW_ABS(x) > RW_ABS(y)) {
        return x <= 0 ? 6 : 2;
    }
    if (y > 0) {
        return 0;
    }
    return 4;
}
