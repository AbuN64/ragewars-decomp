#include "COMMON/RECRECAT4.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SCREEN.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/CTX.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/S1_5.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "FRONTEND/80423280_38.H"
#include "FRONTEND/80423280_42.H"
#include "FRONTEND/CODE_80426EC4.H"
#include "RENDER_2/8025DE50_5.H"

extern struct ScreenFrontendAnimateResultsOptionsScreen *D_800E4690;

extern s32 D_80154020[];

extern void func_80298368_de(s32);


extern void SmpFlicker_StartFlicker(void *, s32);

extern void Tsmos_ActivateControllerState(void);

extern s32 func_80419F38_de(void *);

extern void func_80419F24_de(void *);

s32 Frontend_AnimateResultsOptionsScreen(void *unused0, void *unused1, s32 delta) {
    s32 clock;

    if (D_80154020[1] == 1) {
        D_80154020[1] = 0;
        if (D_80154020[0] != -1) {
            D_800E4690->banner->alpha = 0x5A;
            MarkMenuEventHandled();
            func_80298368_de(D_80154020[0]);
            return 0;
        }
        D_800E4690->banner->alpha = 0xFF;
        D_800E4690->state = 9;
    }
    switch (D_800E4690->state) {
    case 1:
        D_800E4690->left->x += (u16)D_800E4690->leftSpeed;
        D_800E4690->right->x -= (u16)D_800E4690->rightSpeed;
        if (--D_800E4690->timer > 0) {
            break;
        }
        SoundElement_PlayFlatSound(0xE79);
        Frontend_SetWidgetFlag08(D_800E4690->button, 1);
        SmpFlicker_StartFlicker(D_800E4690->prompt, 4);
        D_800E4690->state = 4;
        D_800E4690->timer = 4;
        break;
    case 2:
        D_800E4690->left->x -= (u16)D_800E4690->leftSpeed;
        D_800E4690->right->x += (u16)D_800E4690->rightSpeed;
        if (--D_800E4690->timer > 0) {
            break;
        }
        D_800E4690->state = 3;
        MarkMenuEventHandled();
        if (D_801462C8.controllerMode == 4) {
            func_80298368_de(3);
        } else {
            func_80298368_de(7);
        }
        return 0;
    case 3:
        if (D_800E4690->requested == 0) {
            Tsmos_ActivateControllerState();
            D_800E4690->requested = 1;
        }
        break;
    case 4:
        D_800E4690->timer = RW_CLAMP(D_800E4690->timer - 1, 0, D_800E4690->timer);
        if (D_800E4690->timer <= 0 && func_80419F38_de(D_800E4690->prompt) != 0) {
            func_80419F24_de(D_800E4690->prompt);
            D_800E4690->state = 3;
        }
        break;
    case 5:
        SoundElement_PlayFlatSound(0xE78);
        Frontend_SetWidgetFlag08(D_800E4690->button, 0);
        switch (D_801462C8.controllerMode) {
        case 1:
        case 3:
        case 4:
            Frontend_ShowTrialPreviewBanner();
        }
        Frontend_HideTrialCatalogueWidgets();
        D_800E4690->state = 2;
        D_800E4690->timer = 4;
        break;
    case 8:
        D_800E4690->state = 3;
        Frontend_HideTrialCatalogueWidgets();
        func_8042E988_de(0xB);
        return 0;
    case 9:
        D_800E4690->state = 3;
        Frontend_LoadTrialCompletionFlags();
        break;
    }
    if (D_800E4690->state == 3) {
        clock = D_800E4690->clock + delta;
        D_800E4690->clock = clock;
        if (D_80154020[0] == -1) {
            D_800E4690->pulse->alpha = (u32)(Math_Cosf(clock * 0.005f) * 100.0f + 150.0f);
        }
    }
    return 0;
}
