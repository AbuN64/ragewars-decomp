#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/80423280_38.H"
#include "FRONTEND/80423280_39.H"
#include "FRONTEND/80423280_42.H"
#include "FRONTEND/CODE_80426EC4.H"
#include "FRONTEND/8041BEA8_6.H"
#include "FRONTEND/RESULTSOPTIONSSCREEN.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/S1_5.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"
extern MenuWidget *func_8040EC30_de(void *, s32);
extern struct EntryRecAt8V3 D_800E4694[];
void func_80265688_de(u8 *arg0, s32 arg1, s32 arg2);
void func_80427F10_de(void);
void func_8043C210_de(s32 *record, s32 first, s32 second, s32 third, s32 fourth);




/* The option block at D_801462D0: its byte 5 is the screen mode, also read as D_801462D5 elsewhere. */
struct GameOptions {
    s32 word0;
    u8 byte4;
    u8 mode;
};
extern struct GameOptions D_801462D0;
/* Builds the results options screen into D_800E4690: slides its two side panels in over four frames,
   finds the first active player, clears the pending flags of the eight status records, and runs the
   per-mode setup selected by the option byte. Returns zero. */
s32 Frontend_CreateResultsOptionsScreen(MenuWidget *arg0) {
    ResultsOptionsScreen *screen;
    s32 i;
    s32 d;
    s32 mode;
    MenuWidget *wLeft;
    MenuWidget *wRight;
    MenuWidget *wHead;
    MenuWidget *wItem;
    screen = func_8025305C_de(0xA80);
    D_800E4690 = screen;
    screen->root = arg0;
    D_800E4690->nodes = func_8041B610_de(arg0, 4);
    func_8041B6E8_de(arg0, 0, 0x13E);
    func_8041B6E8_de(arg0, 1, 0x13E);
    func_8041B6E8_de(arg0, 2, 0x13E);
    func_8041B6E8_de(arg0, 3, 0x13E);
    for (i = 0; i < 0x24; i++) {
        func_80265688_de(D_800E4690->owned, i, 0);
        func_80265688_de(D_800E4690->pending, i, 0);
    }
    D_800E4690->state = 1;
    D_800E4690->slideFrames = 4;
    wLeft = func_8040EC30_de(arg0, 0x145);
    D_800E4690->leftPanel = wLeft;
    wLeft->x -= wLeft->width;
    D_800E4690->leftStep = D_800E4690->leftPanel->width / 4;
    d = D_800E4690->leftPanel->width - D_800E4690->leftStep * 4;
    D_800E4690->leftPanel->x += d;
    wRight = func_8040EC30_de(arg0, 0x144);
    D_800E4690->rightPanel = wRight;
    wRight->x += wRight->width;
    D_800E4690->rightStep = D_800E4690->rightPanel->width / 4;
    d = D_800E4690->rightPanel->width - D_800E4690->rightStep * 4;
    D_800E4690->rightPanel->x -= d;
    D_800E4690->resource = func_80419E54_de(0x141, 0x6E);
    wHead = func_8040EC30_de(arg0, 0x13F);
    D_800E4690->focusItem = wHead;
    func_8040E8D8_de(wHead, 0);
    D_800E4690->owner = (void *)func_8040EC30_de(arg0, 0x154);
    D_800E4690->item155 = func_8040EC30_de(arg0, 0x155);
    D_800E4690->player = 0;
    for (i = 0; i < 4; i++) {
        if (((struct Status *)D_80146398)[i].active == 1) {
            D_800E4690->player = i;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        if (((struct Status *)D_80146398)[i].pendingClear == 1) {
            ((struct Status *)D_80146398)[i].active = 0;
            ((struct Status *)D_80146398)[i].pendingClear = 0;
        }
    }
    func_80427008_de();
    func_80427F10_de();
    D_800E4690->window = func_8040EC30_de(arg0, D_800E0646_de[D_800E4690->selection * 14]);
    func_804280BC_de();
    D_80154020.ready = 0;
    D_80154020.value = -1;
    func_8043C210_de((s32 *)D_800E4690, 0x67, 0, 0, 0);
    wItem = func_8040EC30_de(arg0, 0x151);
    D_800E4690->item = wItem;
    wItem->alpha = 0xFF;
    D_800E4690->modeFlag = 0;
    mode = D_801462D0.mode;
    if (mode < 5) {
        if (mode >= 3) {
            D_800E4690->modeFlag = 1;
            func_804279B8_de(D_800E4690);
        }
    }
    D_800E4690->blinking = 0;
    D_800E4690->frames = 0;
    D_800E4690->blinkDelay = -1;
    switch (D_801462D0.mode) {
    case 1:
    case 3:
    case 4:
        D_800E4690->bannerShadow = func_8040EC30_de(arg0, 0x13D);
        func_80422170_de();
        D_800E4690->banner = func_8040EC30_de(arg0, 0x147);
        func_8040EC30_de(arg0, 0x148)->alpha = 0x6E;
        break;
    case 2:
        break;
    }
    switch (D_801462D0.mode) {
    case 1:
        func_80428300_de();
        break;
    case 3:
        func_8042840C_de();
        break;
    case 2:
        func_80428214_de();
        break;
    }
    if (D_801462D0.mode != 2) {
        func_80427B08_de();
    }
    func_8025DF34_de(0xE78);
    return 0;
}
#endif

/* Places the models of the first two active players on the screen D_800E4690: calls
   func_802A23C4_de(1) and func_802A2394_de, clears the word at 0xA58, and for each player whose 150-byte
   status record in D_80146398 has byte 0x78 equal to one maps its kind byte at 0x80 to a 0x70-byte
   row of D_800E3A58 through func_8041F140_de and shows object 0x38F plus the kind through
   Frontend_InitModelPreview in the next 0x4A8-byte view from 0x20 of the screen, using layout 0 of the row
   (uniform scale, position, float and word) for the first model and layout 2 for the second.
   Returns zero. */










extern void func_802A2394_de();

s32 Frontend_ShowResultsPlayerModels(void) {
    s32 shown;
    s32 layout;
    s32 view;
    s32 row;
    s32 i;
    CVector3 scale;
    struct Status *status;
    s32 offset;

    func_802A23C4_de(1);
    func_802A2394_de();
    shown = 0;
    layout = 0;
    i = 0;
    offset = 0;
    view = 0x20;
    D_800E4690->wordA58 = 0;
next:
    status = (struct Status *)((char *)D_80146398 + offset);
    if (status->active == 1) {
        shown++;
        row = func_8041F140_de(status->kind);
        scale.x = D_800E3A58[row].scale[layout];
        scale.y = D_800E3A58[row].scale[layout];
        scale.z = D_800E3A58[row].scale[layout];
        Frontend_InitModelPreview((char *)D_800E4690 + view, 9, status->kind + 0x38F, 0x4B, 0x5DC0, scale,
                      D_800E3A58[row].position[layout], D_800E3A58[row].distance[layout],
                      D_800E3A58[row].light[layout]);
        view += 0x4A8;
        layout = 2;
        if (shown >= layout) {
            goto done;
        }
    }
    i++;
    offset += 150;
    if (i < 4) {
        goto next;
    }
done:
    return 0;
}
