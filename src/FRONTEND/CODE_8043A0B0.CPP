#include "include_asm.h"
#include "FRONTEND/8040B45C_32.H"
#include "RENDER_2/8025DE50_5.H"

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
extern struct StateFlags D_800E5A06[][19];
extern s32 func_80419F38_de(void *);
extern void func_80419F24_de(void *);
extern void func_80419F58_de(void *, int);
extern void func_80298368_de(s32);
extern void func_802A2360_de(void);
extern void func_8029973C_de(void);

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

/* Advance the four-player results screen one frame: slide the arrows, count the timer down, step the state. */
s32 Frontend_UpdateFourPlayerResults(void) {
    s32 i;
    s32 player;
    s32 left;
    s32 timer;
    struct FourPlayerResultsScreen *screen;
    switch (D_800E59E0->state) {
    case 1:
        D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x + (u16)D_800E59E0->leftStep;
        D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x - (u16)D_800E59E0->rightStep;
        D_800E59E0->timer--;
        if (D_800E59E0->timer <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E59E0->message, 1);
            func_80419F58_de(D_800E59E0->resource, 4);
            D_800E59E0->state = 4;
            D_800E59E0->timer = 4;
        }
        break;
    case 2:
        D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x - (u16)D_800E59E0->leftStep;
        D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x + (u16)D_800E59E0->rightStep;
        D_800E59E0->timer--;
        if (D_800E59E0->timer <= 0) {
            D_800E59E0->state = 3;
            func_8029973C_de();
            func_80298368_de(D_800E59E0->next);
            return 0;
        }
        break;
    case 3:
        func_802A2360_de();
        return 0;
    case 4:
        screen = D_800E59E0;
        timer = screen->timer;
        left = timer - 1;
        if (left >= 0) {
            left = timer - (timer < left ^ 1);
        } else {
            left = 0;
        }
        screen->timer = left;
        if (D_800E59E0->timer <= 0) {
            if (func_80419F38_de(D_800E59E0->resource)) {
                func_80419F24_de(D_800E59E0->resource);
                D_800E59E0->state = 3;
            }
        }
        return 0;
    case 5:
        func_8025DF34_de(0xE78);
        D_800E59E0->state = 2;
        D_800E59E0->timer = 4;
        func_8040E8D8_de(D_800E59E0->message, 0);
        for (player = 0; player < 4; player++) {
            for (i = 0; i < 5; i++) {
                func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E5A06[player][i].value), 0);
            }
            func_8040E8D8_de(D_800E59E0->panels[player].item, 0);
        }
        break;
    case 6:
    case 7:
        break;
    }
    return 0;
}

#include "gbi.h"
extern Gfx *D_80110634;
extern s32 D_800E28D0;
extern void func_8041C7F4_de(struct ResultsPlayerPanel *);
extern s32 func_80439CC8_de(char *);
#if defined(VERSION_DE)
extern void func_804397F0_auto(char *);
#else
extern void func_804399D0(char *);
#endif
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern struct Shape_typemap_6 D_800E41C0[];
extern s32 D_800E28D4;
extern struct FourPlayerResultsScreen *D_800E59E0;
/* Draw callback of the four-player results screen: on draw event 1 in state 3 it resets the fill colour D_800D15E0
   and the colour table D_800D15E4, scissors the display list to each active panel rectangle in D_800E41C0 and draws
   the panel, then clips to the full screen and draws the badge of every panel whose state is 1. Returns zero. */
s32 Frontend_DrawFourPlayerResults(void *window, void *item, s32 event) {
    s32 i;
    if (event == 1 && D_800E59E0->state == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 || D_800E59E0->panels[i].state == 2) {
                gDPSetScissorFrac(D_80110634++, 0, (s32)((f32)((D_800E41C0[i].field_0)) * 4.0f), (s32)((f32)((D_800E41C0[i].field_4)) * 4.0f), (s32)((f32)((D_800E41C0[i].field_8)) * 4.0f), (s32)((f32)((D_800E41C0[i].field_C)) * 4.0f));
                func_8041C7F4_de(&D_800E59E0->panels[i]);
            }
        }
        gDPSetScissorFrac(D_80110634++, 0, 0, 0, (s32)((f32)(D_800E28D0 - 1) * 4.0f), (s32)((f32)(D_800E28D4 - 1) * 4.0f));
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 && func_80439CC8_de(D_800E59E0->badges[i]) != 0) {
                D_800D15E0 = 1;
                D_800D15E4[3] = 150.0f;
#if defined(VERSION_DE)
                func_804397F0_auto(D_800E59E0->badges[i]);
#else
                func_804399D0(D_800E59E0->badges[i]);
#endif
                D_800D15E0 = 0;
                D_800D15E4[3] = 255.0f;
            }
        }
    }
    return 0;
}
