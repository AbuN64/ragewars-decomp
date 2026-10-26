#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define Menu_AnimateTabOptionsMenu Menu_UpdateLocalizedOptionsTransitions
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_5.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER_2/8025DE50_5.H"
s32 Menu_AnimateTabOptionsMenu(void) {
    s32 cameraState;
    s32 transitionPhase;
    s32 openingTicksLeft;
    s32 closingTicksLeft;
    s32 decrementedTicks;
    s32 pages;
    s32 clampedTicks;
    MenuWidget *openingLeftTab;
    MenuWidget *openingRightTab;
    MenuWidget *closingLeftTab;
    MenuWidget *closingRightTab;
    Shared_OptionsScreen *timer;
    Shared_OptionsScreen *finish;
    s32 *ready;

    if (D_800E28E0 <= 0) {
        if ((Frontend_GetMenuImageState(D_800E4518) != 1) && ((((Shared_OptionsScreen *)(D_800E4518))->state) == 0)) {
            (((Shared_OptionsScreen *)(D_800E4518))->state) = 1;
            Tsmos_ActivateControllerState();
            return 0;
        }
        cameraState = D_800E2830->state3C;
        if ((cameraState == 1) && (Cinema_IsSequenceInWindow() == cameraState)) {
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->prompt), 0);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->footer), 0);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->rumbleIcon), 0);
            D_800E2830->state3C = 0;
        }
        ready = &D_80154020.ready;
        if (*ready == 1) {
            *ready = 0;
            if (D_80154020.value != -1) {
                Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 0);
                Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->header), 0);
                MarkMenuEventHandled();
                SmXlate_SwitchScreen(D_80154020.value);
                return 0;
            }
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 1);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->header), 1);
            Smos_SetFocusedElement(0x37D);
            goto block_11;
        }
block_11:
        transitionPhase = (((Shared_OptionsScreen *)(D_800E4518))->page);
        switch (transitionPhase) {
        case 1:
            openingLeftTab = (((Shared_OptionsScreen *)(D_800E4518))->leftTab);
            openingLeftTab->x = (u16) (openingLeftTab->x + (u16)(((Shared_OptionsScreen *)(D_800E4518))->leftStep));
            openingRightTab = (((Shared_OptionsScreen *)(D_800E4518))->rightTab);
            openingRightTab->x = (u16) (openingRightTab->x - (u16)(((Shared_OptionsScreen *)(D_800E4518))->rightStep));
            openingTicksLeft = (((Shared_OptionsScreen *)(D_800E4518))->pages) - 1;
            (((Shared_OptionsScreen *)(D_800E4518))->pages) = openingTicksLeft;
            if (openingTicksLeft <= 0) {
                Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->marker), 1);
                Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 1);
                SmpFlicker_StartFlicker((((Shared_OptionsScreen *)(D_800E4518))->title), 4);
                finish = (Shared_OptionsScreen *)D_800E4518;
                finish->page = 4;
                finish->pages = 4;
            }
        case 3:
        default:
            break;
        case 2:
            closingLeftTab = (((Shared_OptionsScreen *)(D_800E4518))->leftTab);
            closingLeftTab->x = (u16) (closingLeftTab->x - (u16)(((Shared_OptionsScreen *)(D_800E4518))->leftStep));
            closingRightTab = (((Shared_OptionsScreen *)(D_800E4518))->rightTab);
            closingRightTab->x = (u16) (closingRightTab->x + (u16)(((Shared_OptionsScreen *)(D_800E4518))->rightStep));
            closingTicksLeft = (((Shared_OptionsScreen *)(D_800E4518))->pages) - 1;
            (((Shared_OptionsScreen *)(D_800E4518))->pages) = closingTicksLeft;
            if (closingTicksLeft <= 0) {
                D_80145040.pause = 0;
                (((Shared_OptionsScreen *)(D_800E4518))->page) = 3;
                Items_ResetActorPools(&D_80145040.object, 0);
                Ovlgame_InitializePlayerPool(&D_80145040, 0, 0);
                Scene_LoadLevelResources(&g_world, 0, 0);
                if (func_8025477C_de() == 0) {
                    func_8025476C_de(1U);
                }
                D_80145040.stage = 8;
                MarkMenuEventHandled();
                SmXlate_SwitchScreen((((Shared_OptionsScreen *)(D_800E4518))->selection));
                return 0;
            }
            break;
        case 4:
            timer = (Shared_OptionsScreen *)D_800E4518;
            pages = timer->pages;
            decrementedTicks = pages - 1;
            if (decrementedTicks >= 0) {
                clampedTicks = pages - (pages >= decrementedTicks);
            } else {
                clampedTicks = 0;
            }
            timer->pages = clampedTicks;
            if (((((Shared_OptionsScreen *)(D_800E4518))->pages) <= 0) && (SmpFlicker_IsFlickerIdle((((Shared_OptionsScreen *)(D_800E4518))->title)) != 0)) {
                SmpFlicker_RestoreFlickerValue((((Shared_OptionsScreen *)(D_800E4518))->title));
                (((Shared_OptionsScreen *)(D_800E4518))->page) = 3;
            }
            break;
        case 5:
            SoundElement_PlayFlatSound(0xE78);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->marker), 0);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->pakIcon), 0);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->footer), 1);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->rumbleIcon), 1);
            Frontend_SetWidgetFlag08((((Shared_OptionsScreen *)(D_800E4518))->prompt), 1);
            finish = (Shared_OptionsScreen *)D_800E4518;
            finish->page = 2;
            finish->pages = 4;
            break;
        }
        if ((((Shared_OptionsScreen *)(D_800E4518))->page) != 3) {
            return 0;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_UpdateLocalizedOptionsTransitions);
#endif
#endif
