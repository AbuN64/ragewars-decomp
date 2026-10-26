#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHARED_MENUREPLY.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define Frontend_CreateResultsOptionsScreen Frontend_OpenLocalizedResultsOptions
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
#define D_800E4690 fz_D_800E4690
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
extern struct Screen_func_80426788_de *D_800E4690;
extern struct Status g_playerSettings[];
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
void Defs_SetBitValue(u8 *arg0, s32 arg1, s32 arg2);
void Frontend_SelectSuggestedTrial(void);
void Frontend_InitMenuImage(s32 *record, s32 first, s32 second, s32 third, s32 fourth);




s32 Frontend_CreateResultsOptionsScreen(MenuWidget *owner) {
    MenuWidget *leftTab;
    MenuWidget *rightTab;
    MenuWidget *leftTabWidget;
    MenuWidget *rightTabWidget;
    MenuWidget *markerWidget;
    MenuWidget *opaqueLabelWidget;
    ResultsOptionsScreen *screen;
    u8 *playerScan;
    u8 *playerResetScan;
    s16 roundedLeftWidth;
    s16 roundedRightWidth;
    s32 clearedBit;
    s32 leftSlideStep;
    s32 rightSlideStep;
    s32 ownedBit;
    s32 i;
    s32 j;
    s32 k;
    u8 currentControllerMode;

    screen = Cache_AllocateMemory(0xA80);
    (*(ResultsOptionsScreen **)&D_800E4690) = screen;
    screen->root = owner;
    i = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((void * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2420))) = SmpOverlay_CreateOverlayNode(owner, 4);
    SmpOverlay_ShowSlotById(owner, 0, 0x13E);
    SmpOverlay_ShowSlotById(owner, 1, 0x13E);
    SmpOverlay_ShowSlotById(owner, 2, 0x13E);
    SmpOverlay_ShowSlotById(owner, 3, 0x13E);
    ownedBit = 0;
    do {
        Defs_SetBitValue((*(ResultsOptionsScreen **)&D_800E4690)->owned, ownedBit, 0);
        clearedBit = i;
        i += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        Defs_SetBitValue(&(*((u8 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2681))), clearedBit, 0);
        ownedBit = i;
    } while (i < 0x24);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2440))) = 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2444))) = 4;
    leftTabWidget = Frontend_FindWidgetByResourceId(owner, 0x145);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2424))) = leftTabWidget;
    leftTabWidget->x = (u16) leftTabWidget->x - (u16) leftTabWidget->width;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    roundedLeftWidth = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2424)))->width;
    if (roundedLeftWidth < 0) {
        roundedLeftWidth += 3;
    }
    leftSlideStep = roundedLeftWidth >> 2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2428))) = leftSlideStep;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    leftTab = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2424)));
    leftTab->x = (u16) leftTab->x + (leftTab->width - (leftSlideStep * 4));
    rightTabWidget = Frontend_FindWidgetByResourceId(owner, 0x144);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432))) = rightTabWidget;
    rightTabWidget->x = (u16) rightTabWidget->x + (u16) rightTabWidget->width;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    roundedRightWidth = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432)))->width;
    if (roundedRightWidth < 0) {
        roundedRightWidth += 3;
    }
    j = 0;
    rightSlideStep = roundedRightWidth >> 2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2436))) = rightSlideStep;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    rightTab = (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2432)));
    rightTab->x = (u16) rightTab->x - (rightTab->width - (rightSlideStep * 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((void * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2448))) = SmpFlicker_CreateFlickerWidget(0x141, 0x6E);
    markerWidget = Frontend_FindWidgetByResourceId(owner, 0x13F);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2452))) = markerWidget;
    Frontend_SetWidgetFlag08(markerWidget, 0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2456))) = Frontend_FindWidgetByResourceId(owner, 0x154);
    playerScan = g_playerSettings;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2460))) = Frontend_FindWidgetByResourceId(owner, 0x155);
    (*(ResultsOptionsScreen **)&D_800E4690)->player = 0;
loop_7:
    if (playerScan[0x78] != 1) {
        j += 1;
        playerScan += 0x96;
        if (j < 4) {
            goto loop_7;
        }
    } else {
        (*(ResultsOptionsScreen **)&D_800E4690)->player = j;
    }
    k = 0;
    playerResetScan = g_playerSettings;
    do {
        k += 1;
        if (playerResetScan[0x91] == 1) {
            playerResetScan[0x78] = 0;
            playerResetScan[0x91] = 0;
        }
        playerResetScan += 0x96;
    } while (k < 8);
    Frontend_LoadTrialCompletionFlags();
    Frontend_SelectSuggestedTrial();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2632))) = Frontend_FindWidgetByResourceId(owner, (s32) *(D_800E0646_de + ((*(ResultsOptionsScreen **)&D_800E4690)->selection * 0x1C)));
    Frontend_RefreshTrialSelectionLabel();
    D_80154020.ready = 0;
    D_80154020.value = -1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    Frontend_InitMenuImage(&(*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 0))), 0x67, 0, 0, 0);
    opaqueLabelWidget = Frontend_FindWidgetByResourceId(owner, 0x151);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2640))) = opaqueLabelWidget;
    opaqueLabelWidget->alpha = 0xFF;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2636))) = 0;
    if (((s32) D_801462C8.controllerMode < 5) && ((s32) D_801462C8.controllerMode >= 3)) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2636))) = 1;
        Frontend_RefreshTrialCharacterPreview((*(ResultsOptionsScreen **)&D_800E4690));
    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2664))) = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2668))) = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    (*((s32 *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2672))) = -1;
    currentControllerMode = D_801462C8.controllerMode;
    switch (currentControllerMode) {                            /* switch 1; irregular */
    default:                                        /* switch 1 */
    case 1:                                         /* switch 1 */
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2656))) = Frontend_FindWidgetByResourceId(owner, 0x13D);
        Menu_InitializeOptionsScene();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        (*((MenuWidget * *) ((u8 *) (*(ResultsOptionsScreen **)&D_800E4690) + 2660))) = Frontend_FindWidgetByResourceId(owner, 0x147);
        Frontend_FindWidgetByResourceId(owner, 0x148)->alpha = 0x6E;
        /* fallthrough */
    case 2:                                         /* switch 1 */
        break;
    }
    switch (currentControllerMode) {                            /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        Frontend_FillProfileWeaponRows();
        break;
    case 3:                                         /* switch 2 */
        Frontend_FillSelectedPlayerWeaponRows();
        break;
    case 2:                                         /* switch 2 */
        Frontend_FillTwoPlayerWeaponRows();
        break;
    }
    if (D_801462C8.controllerMode != 2) {
        Frontend_UpdateResultsHeading();
    }
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}
#undef D_800E4690
#else
INCLUDE_ASM("ovl_80400000", Frontend_OpenLocalizedResultsOptions);
#endif
#endif
