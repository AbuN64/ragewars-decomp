#include "include_asm.h"
#include "COMMON/MENU_SCREEN_SETUP.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"

/* Opens the screen g_setupScreen: allocates its 0x470-byte state for the window, sets up the list,
   the left and right arrows (shifted by their width and snapped to 4 pixels), the labels and
   items of the window with their alpha and visibility, resets the selection and the counters at
   D_80154024, clears the pending flag at 0x91 of the eight D_80146398 records, places the four
   character models (ids 0xEA6 to 0xEA9, x 0, -6, -13, -19) and a fifth model 0xEA6, then issues
   request 0xE78 through SoundElement_PlayFlatSound and calls Menu_InitializeOptionsScene; returns zero. */
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "SCENARIOSETUPSCREEN/SCENARIOSETUPSCREEN.H"

#if defined(VERSION_DE)
#define ID_2FE 0x2FA
#define ID_2FF 0x2FC
#define ID_300 0x2FB
#define ID_301 0x2FD
#define ID_303 0x2FF
#define ID_306 0x302
#define ID_308 0x304
#define ID_309 0x305
#define ID_30A 0x307
#define ID_30B 0x308
#define ID_30C 0x306
#define ID_30D 0x309
#define ID_30E 0x30A
#define ID_30F 0x30B
#define ID_310 0x30C
#define ID_35D 0x359
#elif defined(VERSION_EU_X)
#define ID_2FE 0x303
#define ID_2FF 0x304
#define ID_300 0x238
#define ID_301 0x305
#define ID_303 0x307
#define ID_306 0x30A
#define ID_308 0x30C
#define ID_309 0x30D
#define ID_30A 0x30F
#define ID_30B 0x310
#define ID_30C 0x30E
#define ID_30D 0x311
#define ID_30E 0x313
#define ID_30F 0x312
#define ID_310 0x314
#define ID_35D 0x361
#else
#define ID_2FE 0x2FE
#define ID_2FF 0x2FF
#define ID_300 0x300
#define ID_301 0x301
#define ID_303 0x303
#define ID_306 0x306
#define ID_308 0x308
#define ID_309 0x309
#define ID_30A 0x30A
#define ID_30B 0x30B
#define ID_30C 0x30C
#define ID_30D 0x30D
#define ID_30E 0x30E
#define ID_30F 0x30F
#define ID_310 0x310
#define ID_35D 0x35D
#endif

s32 CScenarioSetup_OpenScenarioSetupScreen(void *window) {
    SetupModelVector scale;
    SetupModelVector position;
    SetupModelVector rotation;
    SetupModelVector offset;
    MenuWidget *item1, *item2, *item3, *item4, *item5, *item6, *item7, *item8;
    MenuWidget *opacityItem;
    f32 z;
    ListScreenRecord *record;
    s32 i;
    s32 x;
    s32 id;

    g_setupScreen = Cache_AllocateMemory(sizeof(SetupScreen));
    g_setupScreen->window = window;
    g_setupScreen->list = SmpOverlay_CreateOverlayNode(window, 4);
    SmpOverlay_ShowSlotById(window, 0, ID_2FF);
    SmpOverlay_ShowSlotById(window, 1, ID_2FF);
    SmpOverlay_ShowSlotById(window, 2, ID_2FF);
    SmpOverlay_ShowSlotById(window, 3, ID_2FF);
    g_setupScreen->unk3DC = 1;
    g_setupScreen->unk45C = 0;
    g_setupScreen->unk3E0 = 4;

    item1 = Node_FindWidgetByResourceId(window, ID_306);
    g_setupScreen->left = item1;
    item1->x -= item1->width;
    g_setupScreen->leftCount = g_setupScreen->left->width / 4;
    x = g_setupScreen->left->width - g_setupScreen->leftCount * 4;
    g_setupScreen->left->x += x;

    item2 = Node_FindWidgetByResourceId(window, ID_30F);
    g_setupScreen->right = item2;
    item2->x += item2->width;
    g_setupScreen->rightCount = g_setupScreen->right->width / 4;
    x = g_setupScreen->right->width - g_setupScreen->rightCount * 4;
    g_setupScreen->right->x -= x;

    opacityItem = Node_FindWidgetByResourceId(window, ID_30A);
    opacityItem->alpha = 0x6E;
    item3 = Node_FindWidgetByResourceId(window, ID_35D);
    g_setupScreen->widget35D = item3;
    item3->alpha = 0x41;
    Widget_SetWidgetFlag08(g_setupScreen->widget35D, 0);
    g_setupScreen->text3E4 = SmpFlicker_CreateFlickerWidget(ID_303, 0x6E);
    item4 = Node_FindWidgetByResourceId(window, ID_301);
    g_setupScreen->widget301 = item4;
    Widget_SetWidgetFlag08(item4, 0);
    g_setupScreen->label = Node_FindWidgetByResourceId(window, ID_30E);
    g_setupScreen->widget310 = Node_FindWidgetByResourceId(window, ID_310);
    ScenarioSetup_HideSetupCatalogue();
    g_setupScreen->selection = 0;
    g_setupScreen->category = 0;
    ScenarioSetup_RefreshSelectedArenaLabel();
    ScenarioSetup_LoadSetupArenaLabel();
    g_selectionMessageReply.ready = 0;
    g_selectionMessageReply.value = -1;
    g_setupScreen->widget308 = Node_FindWidgetByResourceId(window, ID_308);
    opacityItem = Node_FindWidgetByResourceId(window, ID_309);
    opacityItem->alpha = 0x6E;
    g_setupScreen->unk46C = 0;
    item5 = Node_FindWidgetByResourceId(window, ID_30B);
    g_setupScreen->widget30B = item5;
    item5->alpha = 0x8C;
    Widget_SetWidgetFlag08(g_setupScreen->widget30B, 1);
    item6 = Node_FindWidgetByResourceId(window, ID_30D);
    g_setupScreen->widget30D = item6;
    item6->alpha = 0x8C;
    Widget_SetWidgetFlag08(g_setupScreen->widget30D, 0);
    item7 = Node_FindWidgetByResourceId(window, ID_30C);
    g_setupScreen->widget30C = item7;
    item7->alpha = 0xFF;
    g_setupScreen->widget2FE = Node_FindWidgetByResourceId(window, ID_2FE);
    item8 = Node_FindWidgetByResourceId(window, ID_300);
    g_setupScreen->widget300 = item8;
    Widget_SetWidgetFlag08(item8, 1);
    Tsmos_DeactivateControllerState();
    g_setupScreen->unk460 = 0;
    g_setupScreen->unk464 = 0;
    g_setupScreen->unk468 = -1;

    for (i = 0; i < 8; i++) {
        record = &g_playerSettings[i];
        if (record->m_IsBot == 1) {
            record->active = 0;
            record->m_IsBot = 0;
        }
    }
    Tsmos_SetModeOneFlag(1);

    x = 0;
    id = 0;
    scale.value.x = g_setupFirstPreviewScale;
    scale.value.y = g_setupFirstPreviewScale;
    scale.value.z = g_setupFirstPreviewScale;
    rotation.value.x = 0.0f;
    rotation.value.y = 0.0f;
    rotation.value.z = 0.0f;
    offset.value.x = 0.0f;
    offset.value.y = g_setupFirstPreviewYOffset;
    offset.value.z = 0.0f;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            x = 0;
            id = 0xEA6;
            break;
        case 1:
            x = -6;
            id = 0xEA7;
            break;
        case 2:
            x = -13;
            id = 0xEA8;
            break;
        case 3:
            x = -19;
            id = 0xEA9;
            break;
        }
        position.value.x = x;
        position.value.y = g_setupFirstPreviewY;
        z = g_setupPreviewDepth;
        position.value.z = z;
        Frontend_InitModelPreviewTransform(&g_setupScreen->models[i].initial, id, scale.words, position.words);
        Frontend_SetPreviewRotation(&g_setupScreen->models[i].rotation, rotation.words);
        Frontend_SetPreviewRotationSpeed(&g_setupScreen->models[i].offset, offset.words);
    }
    scale.value.x = g_setupSecondPreviewScale;
    scale.value.y = g_setupSecondPreviewScale;
    scale.value.z = g_setupSecondPreviewScale;
    position.value.z = z;
    position.value.x = g_setupSecondPreviewX;
    position.value.y = g_setupSecondPreviewY;
    Frontend_InitModelPreviewTransform(&g_setupScreen->models[4].initial, 0xEA6, scale.words, position.words);
    Frontend_SetPreviewRotation(&g_setupScreen->models[4].rotation, rotation.words);
    Frontend_SetPreviewRotationSpeed(&g_setupScreen->models[4].offset, offset.words);
    SoundElement_PlayFlatSound(0xE78);
    Menu_InitializeOptionsScene();
    return 0;
}

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
const unsigned int k_SetupEncodedWords[7] = {
    0x3C9374BC, 0x40A00000, 0x41500000, 0xC2480000, 0x3D23D70A, 0x41880000, 0xC1200000,
};
#endif
