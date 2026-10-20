#include "MENU/TEAMMENU.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "COMMON/SESSIONHANDLERROW.H"

extern u8 D_801462DE;


extern s32 D_800E28D0;

extern s32 D_800E28D4;


 /* "Select Team" */


extern void func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);

extern void func_802A84F8_de(void);

extern void func_802A8F28_de(char *, s32, s32, s32, s32, s32, f32, f32);

void func_802185D0_de(struct TeamMenu *menu, ItemRecAt18V1 *items, s32 count, WeaponMenuPlayer *player) {
    s32 width;
    s32 height;
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
    WeaponMenuView *view;
    WeaponMenuView *titleView;
    f32 *viewport;
    ItemRecAt18V1 *item;

    titleView = player->view;
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
                red = func_802B6560_de(menu->spin) * 63.0f + 192.0f;
                alpha = 1.0f;
                green = red;
                blue = red;
            } else {
                red = 150;
                green = red;
                blue = red;
                alpha *= 0.75f;
            }
            gDPSetEnvColor(D_80110634++, red, green, blue, alpha * fade);
            func_802AAC28_de(item->icon, 0, x - width * item->height * scaleX * 0.5f,
                          y - height * item->height * scaleY * 0.5f,
                          scaleX * item->height, scaleY * item->height, 1);
        }
        item++;
    }
    scaleY = titleView->viewport[1] / D_800E28D4;
    scaleX = titleView->viewport[0] / D_800E28D0;
    func_802A84F8_de();
    func_802AAB68_de(0.6f, 0.6f);
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    x = viewport[2] + viewport[0] * 0.5f;
    y = viewport[3] + viewport[1] * 0.5f;
    func_802A8F28_de(D_800C2260_de, x, y, 0xC8, 1, 1, scaleX, scaleY);
}

/* Returns the cardinal team-menu slot, or -1 inside the deadzone/diagonals. */
s32 func_80218988_de(void *object) {
    StickPlayer *player = object;
    StickInput *input = player->input;
    s8 x = input->x;
    s8 y = input->y;
    if (x*x + y*y < 3600) return -1;
    if (((f32)(((f32)x < 0.0f ? -x : x) - ((f32)y < 0.0f ? -y : y)) < 0.0f ? -(((f32)x < 0.0f ? -x : x) - ((f32)y < 0.0f ? -y : y)) : (((f32)x < 0.0f ? -x : x) - ((f32)y < 0.0f ? -y : y))) < 46 && x && y) goto diagonal;

    if (((f32)x < 0.0f ? -x : x) > ((f32)y < 0.0f ? -y : y)) { s32 r = 1; if (x <= 0) r = 3; return r; }
    return (y <= 0) << 1;

diagonal:
    return -1;
}
