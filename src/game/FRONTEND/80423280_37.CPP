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
extern struct EntryRecAt8V3 D_800E4694[];
void Defs_SetBitValue(u8 *arg0, s32 arg1, s32 arg2);
void Frontend_SelectSuggestedTrial(void);
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
    screen = Cache_AllocateMemory(0xA80);
    D_800E4690 = screen;
    screen->root = arg0;
    D_800E4690->nodes = SmpOverlay_CreateOverlayNode(arg0, 4);
    SmpOverlay_ShowSlotById(arg0, 0, 0x13E);
    SmpOverlay_ShowSlotById(arg0, 1, 0x13E);
    SmpOverlay_ShowSlotById(arg0, 2, 0x13E);
    SmpOverlay_ShowSlotById(arg0, 3, 0x13E);
    for (i = 0; i < 0x24; i++) {
        Defs_SetBitValue(D_800E4690->owned, i, 0);
        Defs_SetBitValue(D_800E4690->pending, i, 0);
    }
    D_800E4690->state = 1;
    D_800E4690->slideFrames = 4;
    wLeft = Frontend_FindWidgetByResourceId(arg0, 0x145);
    D_800E4690->leftPanel = wLeft;
    wLeft->x -= wLeft->width;
    D_800E4690->leftStep = D_800E4690->leftPanel->width / 4;
    d = D_800E4690->leftPanel->width - D_800E4690->leftStep * 4;
    D_800E4690->leftPanel->x += d;
    wRight = Frontend_FindWidgetByResourceId(arg0, 0x144);
    D_800E4690->rightPanel = wRight;
    wRight->x += wRight->width;
    D_800E4690->rightStep = D_800E4690->rightPanel->width / 4;
    d = D_800E4690->rightPanel->width - D_800E4690->rightStep * 4;
    D_800E4690->rightPanel->x -= d;
    D_800E4690->resource = SmpFlicker_CreateFlickerWidget(0x141, 0x6E);
    wHead = Frontend_FindWidgetByResourceId(arg0, 0x13F);
    D_800E4690->focusItem = wHead;
    Frontend_SetWidgetFlag08(wHead, 0);
    D_800E4690->owner = (void *)Frontend_FindWidgetByResourceId(arg0, 0x154);
    D_800E4690->item155 = Frontend_FindWidgetByResourceId(arg0, 0x155);
    D_800E4690->player = 0;
    for (i = 0; i < 4; i++) {
        if (((struct Status *)g_playerSettings)[i].active == 1) {
            D_800E4690->player = i;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        if (((struct Status *)g_playerSettings)[i].pendingClear == 1) {
            ((struct Status *)g_playerSettings)[i].active = 0;
            ((struct Status *)g_playerSettings)[i].pendingClear = 0;
        }
    }
    Frontend_LoadTrialCompletionFlags();
    Frontend_SelectSuggestedTrial();
    D_800E4690->window = Frontend_FindWidgetByResourceId(arg0, (u16)D_800E4694[D_800E4690->selection].id);
    Frontend_RefreshTrialSelectionLabel();
    D_80154020.ready = 0;
    D_80154020.value = -1;
    func_8043C210_de((s32 *)D_800E4690, 0x67, 0, 0, 0);
    wItem = Frontend_FindWidgetByResourceId(arg0, 0x151);
    D_800E4690->item = wItem;
    wItem->alpha = 0xFF;
    D_800E4690->modeFlag = 0;
    mode = D_801462D0.mode;
    if (mode < 5) {
        if (mode >= 3) {
            D_800E4690->modeFlag = 1;
            Frontend_RefreshTrialCharacterPreview(D_800E4690);
        }
    }
    D_800E4690->blinking = 0;
    D_800E4690->frames = 0;
    D_800E4690->blinkDelay = -1;
    switch (D_801462D0.mode) {
    case 1:
    case 3:
    case 4:
        D_800E4690->bannerShadow = Frontend_FindWidgetByResourceId(arg0, 0x13D);
        Menu_InitializeOptionsScene();
        D_800E4690->banner = Frontend_FindWidgetByResourceId(arg0, 0x147);
        Frontend_FindWidgetByResourceId(arg0, 0x148)->alpha = 0x6E;
        break;
    case 2:
        break;
    }
    switch (D_801462D0.mode) {
    case 1:
        Frontend_FillProfileWeaponRows();
        break;
    case 3:
        Frontend_FillSelectedPlayerWeaponRows();
        break;
    case 2:
        Frontend_FillTwoPlayerWeaponRows();
        break;
    }
    if (D_801462D0.mode != 2) {
        func_80427B08_de();
    }
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}
#endif

/* Places the models of the first two active players on the screen D_800E4690: calls
   Tsmos_SetModeOneFlag(1) and Tsmos_DeactivateControllerState, clears the word at 0xA58, and for each player whose 150-byte
   status record in D_80146398 has byte 0x78 equal to one maps its kind byte at 0x80 to a 0x70-byte
   row of D_800E3A58 through func_8041F140_de and shows object 0x38F plus the kind through
   Frontend_InitModelPreview in the next 0x4A8-byte view from 0x20 of the screen, using layout 0 of the row
   (uniform scale, position, float and word) for the first model and layout 2 for the second.
   Returns zero. */










extern void Tsmos_DeactivateControllerState();

s32 Frontend_ShowResultsPlayerModels(void) {
    s32 shown;
    s32 layout;
    s32 view;
    s32 row;
    s32 i;
    CVector3 scale;
    struct Status *status;
    s32 offset;

    Tsmos_SetModeOneFlag(1);
    Tsmos_DeactivateControllerState();
    shown = 0;
    layout = 0;
    i = 0;
    offset = 0;
    view = 0x20;
    D_800E4690->wordA58 = 0;
next:
    status = (struct Status *)((char *)g_playerSettings + offset);
    if (status->active == 1) {
        shown++;
        row = Frontend_FindKeyIndex(status->kind);
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
