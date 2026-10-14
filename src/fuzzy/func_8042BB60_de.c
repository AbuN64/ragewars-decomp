#include "shared/func_80425674_de_layout.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/world.h"
#include "shared/results_setup_text.h"
#include "span_16E000/code_8042BD40.h"
extern func_8042CE54_S1 *D_800E53C0;
extern u8 D_801462D5;
extern s32 D_8015402C, D_8014DD98, D_80146894;
extern s8 D_80102B0D[], D_800FEB0E[];
extern void func_8043C210_de(s32 *, s32, s32, s32, s32);
extern void func_8043C278_de(s32 *);
extern void func_80424B90_de(void);
extern void func_8042C6CC_de(void);
extern void func_80424C50_de(void *, s32);
extern void func_80425D14_de(s32);
extern void func_8042C018_de(void);
extern void func_8042CE74_de(void);

extern void func_8040E950_de(void *, s32);
extern s32 func_8040EBD0_de(void *);
extern s32 func_8042AF28_de(void);
extern s32 func_8042AFB8_de(void);
extern void func_8028D380_de(void *, s32, void *, s32);
extern u8 *func_802A0494_de(u8 *);
extern void func_802A025C_de(char *, char *);

s32 func_8042BB60_de(void *root) {
    char buffer[64];
    MenuWidget *item;
    func_8041F2A0_Item *widget;
    func_8042CE54_S1 *screen;
    Shared_Game *game;
    Shared_PlayerSettingsRecord *config;
    s32 i, offset, expected;

    D_800E53C0 = (void *)func_8025305C_de(0x330);
    D_800E53C0->unkE0 = root;
    func_8040E8D8_de(root, 0);
    func_8043C210_de(D_800E53C0->transition, 0x67, 0, 0, 0);
    i = 0;
    func_8043C278_de(D_800E53C0->transition);
    D_800E53C0->active = 1;
    func_8040EC30_de(root, 0x234 + RESULTS_MENU_SHIFT)->alpha = 110;
    func_8040EC30_de(root, 0x239 + RESULTS_MENU_SHIFT)->alpha = 20;
    func_8040EC30_de(root, 0x236 + RESULTS_MENU_SHIFT)->alpha = 20;
    func_80424B90_de();
    screen = D_800E53C0;
    for (; i < 8; i++) {
        screen->icons[i][0] = -1;
        screen->icons[i][1] = -1;
    }
    D_800E53C0->selection = -1;
    func_8042C6CC_de();
    game = &D_801462C8;
    switch (game->controllerMode) {
    case 0:
        func_80424C50_de(D_800E53C0->data, D_8015402C);
        func_8042D118_de();
        D_800E53C0->mode = 0;
        break;
    case 2:
        if (game->humanWon == 1) {
            i = 0;
            expected=(u8)game->humanWon;
            D_800E53C0->mode = 0;
            config = game->playerSettings;
            func_8042D1C8_de();
            do {
                if (config->enabled == expected && config->locked == 0) func_80425D14_de(i);
                i++;
                config++;
            } while (i < 4);
        } else D_800E53C0->mode = 1;
        break;
    }
    switch (D_801462C8.controllerMode) {
    case 0:
        goto loadPreview;
    case 2:
        screen = D_800E53C0;
        if (screen->mode == 1) {
            screen->first = 0;
            screen->count = 0;
            func_8042CC74_de();
            item = func_8040EC30_de(root, 0x266 + RESULTS_MENU_SHIFT);
            func_8040E8D8_de(item, 1);
            item->alpha = 115;
            item->text = resultsUnavailable();
            func_8040E8D8_de(func_8040EC30_de(root, RESULTS_RIGHT_ITEM), 0);
        } else {
            if (screen->selection == -1) goto loadPreview;
            screen->first = 0;
            screen->count = 0;
            func_8042CC74_de();
            func_8040E8D8_de(func_8040EC30_de(root, RESULTS_RIGHT_ITEM), 0);
            func_8042CE74_de();
        }
        break;
    }
    goto previewDone;
loadPreview:
    func_8042C018_de();
previewDone:
    func_8041B110_de(0x237 + RESULTS_MENU_SHIFT);
    func_8041B110_de(0x238 + RESULTS_MENU_SHIFT);
    func_8041B110_de(0x23C + RESULTS_MENU_SHIFT);
    func_8040E950_de(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT), 1);
    i = 0;
    offset = 0;
    do {
        i++;
        if (D_80102B0D[offset] >= 0 && D_800FEB0E[offset] == 0) {
            func_8040E950_de(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT), 0);
            break;
        }
        offset += 400;
    } while (i < 4);
    if (func_8040EBD0_de(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT)) == 0 && func_8042AF28_de() == 1 && func_8042AFB8_de() == 0) {
        func_8040E950_de(func_8040EC30_de(root, 0x238 + RESULTS_MENU_SHIFT), 1);
    }
    item = func_8040EC30_de(D_800E53C0->unkE0, RESULTS_HEADING1);
    if (D_8014DD98 == 0) item->text = resultsFirstHeading();
    else item->text = resultsSecondHeading();
    item = func_8040EC30_de(D_800E53C0->unkE0, RESULTS_HEADING2);
    switch (D_8014DD98) {
    case 3: item->text = resultsFirstHeading(); break;
    case 0: item->text = resultsFourthHeading(); break;
    case 1:
    default: item->text = resultsThirdHeading(); break;
    }
    item = func_8040EC30_de(root, 0x235 + RESULTS_MENU_SHIFT);
    func_8028D380_de(&D_8011FE88, D_8015402C, buffer, 63);
    func_802A025C_de(D_800E53C0->name, (char *)func_802A0494_de((u8 *)buffer));
    item->text = D_800E53C0->name;
    D_800E53C0->buttonAddress = (s32)func_8040EC30_de(root, 0x23D + RESULTS_MENU_SHIFT);
    {s32 *dirty=&D_800E53C0->dirty; *dirty=1;}
    D_80146894 = 1;
    D_800E53C0->phase = 0;
    func_802A2394_de();
    return 0;
}
