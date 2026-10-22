#include "include_asm.h"
#include "FRONTEND/8040B45C_32.H"
#include "RENDER_2/8025DE50_5.H"

INCLUDE_RODATA("data_800C", rodata_func_8043A890_de_800E1FFC);

#include "TYPES.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "FRONTEND/8041BEA8_6.H"
extern struct FourPlayerResultsScreen *D_800E59E0;
extern Shared_PlayerSettingsRecord D_80146398[];
extern struct RowRecAt54 D_800E3A58[];
extern struct StateFlags D_800E59E6[][19];
extern f32 D_800DDF90_de;
extern void *func_8025305C_de(s32);
extern void *func_8041B610_de(void *, s32);
extern void func_8041B6E8_de(void *, s32, s32);
extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(MenuWidget *, s32);
extern s32 func_8041F140_de(s32);
extern void *func_80419E54_de(s32, s32);
extern void func_8043B96C_de(void);
extern void func_8043B0CC_de(s32);
extern void func_802A2394_de(void);

/* Construct the four-player results/loadout menu and animate its panels into view. */
s32 Frontend_CreateFourPlayerResults(void *window) {
#if defined(VERSION_DE)
    enum { slotResource = 0xC6, leftResource = 0xCC, rightResource = 0xF4,
           titleResource = 0xC9, messageResource = 0xC7 };
#elif defined(VERSION_EU_X)
    enum { slotResource = 0xCC, leftResource = 0xD2, rightResource = 0xFA,
           titleResource = 0xCF, messageResource = 0xCD };
#else
    enum { slotResource = 0xC8, leftResource = 0xCE, rightResource = 0xF6,
           titleResource = 0xCB, messageResource = 0xC9 };
#endif
    s32 player;
    s32 delta;
    struct FourPlayerResultsScreen *screen;
    MenuWidget *widget;
    MenuWidget *bar;
    s32 row;
    CVector3 scale;
    Shared_PlayerSettingsRecord *config;

    D_800E59E0 = func_8025305C_de(sizeof(struct FourPlayerResultsScreen));
    D_800E59E0->window = window;
    D_800E59E0->menu = func_8041B610_de(window, 4);
    func_8041B6E8_de(window, 0, slotResource);
    func_8041B6E8_de(window, 1, slotResource);
    func_8041B6E8_de(window, 2, slotResource);
    func_8041B6E8_de(window, 3, slotResource);
    scale.x = D_800DDF90_de;
    scale.y = D_800DDF90_de;
    scale.z = D_800DDF90_de;
    for (player = 0; player < 4; player++) {
        Shared_PlayerSettingsRecord *config;
        D_800E59E0->panels[player].state = 0;
        D_800E59E0->panels[player].selection = 5;
        bar = func_8040EC30_de(D_800E59E0->window, D_800E59E6[player][1].value);
        D_800E59E0->panels[player].item = bar;
        bar->alpha = 0x64;
        func_8040E8D8_de(bar, 0);
        widget = func_8040EC30_de(D_800E59E0->window, D_800E59E6[player][0].value);
        widget->alpha = 0x6E;
        config = &D_80146398[player];
        if (config->enabled == 1) {
            row = func_8041F140_de(config->character);
            scale.x = D_800E3A58[row].scale[player];
            scale.y = D_800E3A58[row].scale[player];
            scale.z = D_800E3A58[row].scale[player];
            func_8041CAD8_de(&D_800E59E0->panels[player], 9, config->character + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[player], D_800E3A58[row].distance[player], D_800E3A58[row].light[player]);
        }
    }
    D_800E59E0->state = 1;
    D_800E59E0->timer = 4;
    D_800E59E0->leftArrow = func_8040EC30_de(window, leftResource);
    D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x - (u16)D_800E59E0->leftArrow->width;
    D_800E59E0->leftStep = D_800E59E0->leftArrow->width / 4;
    delta = D_800E59E0->leftArrow->width - D_800E59E0->leftStep * 4;
    D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x + delta;
    D_800E59E0->rightArrow = func_8040EC30_de(window, rightResource);
    D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x + (u16)D_800E59E0->rightArrow->width;
    D_800E59E0->rightStep = D_800E59E0->rightArrow->width / 4;
    delta = D_800E59E0->rightArrow->width - D_800E59E0->rightStep * 4;
    D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x - delta;
    func_8040EC30_de(window, titleResource)->alpha = 0x6E;
    D_800E59E0->resource = func_80419E54_de(messageResource, 0xFF);
    widget = func_8040EC30_de(window, messageResource);
    D_800E59E0->message = widget;
    func_8040E8D8_de(widget, 0);
    screen = D_800E59E0;
    for (player = 0; player < 4; player++) {
        config = &D_80146398[player];
        if (config->enabled == 1) {
            switch (config->character) {
            case 14:
            case 17:
            case 18:
                screen->panels[player].mode = 0;
                break;
            default:
                screen->panels[player].mode = 2;
                break;
            }
        }
    }
    func_8043B96C_de();
    for (player = 0; player < 4; player++) {
        config = &D_80146398[player];
        if (config->enabled == 1) {
            func_8043B0CC_de(player);
        }
    }
    D_800E59E0->next = -1;
    func_802A2394_de();
    return 0;
}


INCLUDE_ASM("ovl_80400000", func_8043A330_de);

INCLUDE_ASM("ovl_80400000", func_8043A5F8_de);

INCLUDE_ASM("ovl_80400000", func_8043A890_de);
