#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "FRONTEND/RESULTS_REFRESHTRIALCATALOGUEWIDGETS.H"
#include "FRONTEND/RESULTS_UPDATERESULTSHEADING.H"
#include "FRONTEND/RESULTS_FILLPROFILEWEAPONROWS.H"
#include "FRONTEND/RESULTS_LOADTRIALCOMPLETIONFLAGS.H"
#include "FRONTEND/FRONTEND_DRAWMODELPREVIEW.H"
#include "FRONTEND/RESULTSOPTIONSSCREEN.H"

/* The resource ids of this screen are numbered per version: de two lower than us, eu-x four higher
   (the same 11 ids at 19 sites, checked word by word against each ROM). */
static inline s32 resultsRes(s32 id) {
#if defined(VERSION_DE)
    return id - 2;
#elif defined(VERSION_EU_X)
    return id + 4;
#else
    return id;
#endif
}

#if defined(VERSION_US) || defined(VERSION_US_REV1) || defined(VERSION_EU) || defined(VERSION_DE) || defined(VERSION_EU_X)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ANIMATION.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/MENU_INITIALIZEOPTIONSSCENE.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
extern struct ResultsOptionEntry g_trialCatalogueStages[];
void Defs_SetBitValue(u8 *bits, s32 bitIndex, s32 found);
void Results_SelectSuggestedTrial(void);
void Frontend_InitMenuImage(s32 *record, s32 first, s32 second, s32 third, s32 fourth);




/* The option block at D_801462D0: its byte 5 is the screen mode, also read as D_801462D5 elsewhere. */
struct GameOptions {
    s32 word0;
    u8 byte4;
    u8 mode;
};
extern struct GameOptions D_801462D0;
/* Builds the results options screen into g_trialCatalogueScreen: slides its two side panels in over four frames,
   finds the first active player, clears the pending flags of the eight status records, and runs the
   per-mode setup selected by the option byte. Returns zero. */
s32 Results_CreateResultsOptionsScreen(MenuWidget *rootWidget) {
    ResultsOptionsScreen *screen;
    s32 i;
    s32 d;
    s32 mode;
    MenuWidget *wLeft;
    MenuWidget *wRight;
    MenuWidget *wHead;
    MenuWidget *wItem;
    screen = Cache_AllocateMemory(0xA80);
    g_trialCatalogueScreen = screen;
    screen->root = rootWidget;
    g_trialCatalogueScreen->nodes = SmpOverlay_CreateOverlayNode(rootWidget, 4);
    SmpOverlay_ShowSlotById(rootWidget, 0, resultsRes(0x13E));
    SmpOverlay_ShowSlotById(rootWidget, 1, resultsRes(0x13E));
    SmpOverlay_ShowSlotById(rootWidget, 2, resultsRes(0x13E));
    SmpOverlay_ShowSlotById(rootWidget, 3, resultsRes(0x13E));
    for (i = 0; i < 0x24; i++) {
        Defs_SetBitValue(g_trialCatalogueScreen->owned, i, 0);
        Defs_SetBitValue(g_trialCatalogueScreen->pending, i, 0);
    }
    g_trialCatalogueScreen->state = 1;
    g_trialCatalogueScreen->slideFrames = 4;
    wLeft = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x145));
    g_trialCatalogueScreen->leftPanel = wLeft;
    wLeft->x -= wLeft->width;
    g_trialCatalogueScreen->leftStep = g_trialCatalogueScreen->leftPanel->width / 4;
    d = g_trialCatalogueScreen->leftPanel->width - g_trialCatalogueScreen->leftStep * 4;
    g_trialCatalogueScreen->leftPanel->x += d;
    wRight = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x144));
    g_trialCatalogueScreen->rightPanel = wRight;
    wRight->x += wRight->width;
    g_trialCatalogueScreen->rightStep = g_trialCatalogueScreen->rightPanel->width / 4;
    d = g_trialCatalogueScreen->rightPanel->width - g_trialCatalogueScreen->rightStep * 4;
    g_trialCatalogueScreen->rightPanel->x -= d;
    g_trialCatalogueScreen->resource = SmpFlicker_CreateFlickerWidget(resultsRes(0x141), 0x6E);
    wHead = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x13F));
    g_trialCatalogueScreen->focusItem = wHead;
    Widget_SetWidgetFlag08(wHead, 0);
    g_trialCatalogueScreen->owner = (void *)Node_FindWidgetByResourceId(rootWidget, resultsRes(0x154));
    g_trialCatalogueScreen->item155 = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x155));
    g_trialCatalogueScreen->player = 0;
    for (i = 0; i < 4; i++) {
        if (((struct Status *)g_playerSettings)[i].active == 1) {
            g_trialCatalogueScreen->player = i;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        if (((struct Status *)g_playerSettings)[i].pendingClear == 1) {
            ((struct Status *)g_playerSettings)[i].active = 0;
            ((struct Status *)g_playerSettings)[i].pendingClear = 0;
        }
    }
    Results_LoadTrialCompletionFlags();
    Results_SelectSuggestedTrial();
    g_trialCatalogueScreen->window = Node_FindWidgetByResourceId(rootWidget, (u16)g_trialCatalogueStages[g_trialCatalogueScreen->selection].id);
    Results_RefreshTrialSelectionLabel();
    g_selectionMessageReply.ready = 0;
    g_selectionMessageReply.value = -1;
    Frontend_InitMenuImage((s32 *)g_trialCatalogueScreen, 0x67, 0, 0, 0);
    wItem = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x151));
    g_trialCatalogueScreen->item = wItem;
    wItem->alpha = 0xFF;
    g_trialCatalogueScreen->modeFlag = 0;
    mode = D_801462D0.mode;
    if (mode < 5) {
        if (mode >= 3) {
            g_trialCatalogueScreen->modeFlag = 1;
            Results_RefreshTrialCharacterPreview(g_trialCatalogueScreen);
        }
    }
    g_trialCatalogueScreen->blinking = 0;
    g_trialCatalogueScreen->frames = 0;
    g_trialCatalogueScreen->blinkDelay = -1;
    switch (D_801462D0.mode) {
    case 1:
    case 3:
    case 4:
        g_trialCatalogueScreen->bannerShadow = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x13D));
        Menu_InitializeOptionsScene();
        g_trialCatalogueScreen->banner = Node_FindWidgetByResourceId(rootWidget, resultsRes(0x147));
        Node_FindWidgetByResourceId(rootWidget, resultsRes(0x148))->alpha = 0x6E;
        break;
    case 2:
        break;
    }
    switch (D_801462D0.mode) {
    case 1:
        Results_FillProfileWeaponRows();
        break;
    case 3:
        Results_FillSelectedPlayerWeaponRows();
        break;
    case 2:
        Results_FillTwoPlayerWeaponRows();
        break;
    }
    if (D_801462D0.mode != 2) {
        Results_UpdateResultsHeading();
    }
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}
#endif

/* Places the models of the first two active players on the screen g_trialCatalogueScreen: calls
   Tsmos_SetModeOneFlag(1) and Tsmos_DeactivateControllerState, clears the word at 0xA58, and for each player whose 150-byte
   status record in D_80146398 has byte 0x78 equal to one maps its kind byte at 0x80 to a 0x70-byte
   row of g_characterPortraitRecords through func_8041F140_de and shows object 0x38F plus the kind through
   Preview_InitModelPreview in the next 0x4A8-byte view from 0x20 of the screen, using layout 0 of the row
   (uniform scale, position, float and word) for the first model and layout 2 for the second.
   Returns zero. */











s32 Results_ShowResultsPlayerModels(void) {
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
    g_trialCatalogueScreen->wordA58 = 0;
next:
    status = (struct Status *)((char *)g_playerSettings + offset);
    if (status->active == 1) {
        shown++;
        row = Key_FindKeyIndex(status->kind);
        scale.x = g_characterPortraitRecords[row].scale[layout];
        scale.y = g_characterPortraitRecords[row].scale[layout];
        scale.z = g_characterPortraitRecords[row].scale[layout];
        Preview_InitModelPreview((char *)g_trialCatalogueScreen + view, 9, status->kind + 0x38F, 0x4B, 0x5DC0, scale,
                      g_characterPortraitRecords[row].position[layout], g_characterPortraitRecords[row].distance[layout],
                      g_characterPortraitRecords[row].light[layout]);
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
