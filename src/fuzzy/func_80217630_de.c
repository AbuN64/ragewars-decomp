#include "types.h"
#include "gfx.h"
#include "gbi.h"
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
    s32 green;
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
