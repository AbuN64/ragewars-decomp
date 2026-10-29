#include "MENU/PLAYERSETTINGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/CMENUPROFILE_OPENTIMEDPLAYERDIALOG.H"
#include "COMMON/SHARED_DEBUGFIELD.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MENU/MISC/CMENUPROFILE_OPENTIMEDPLAYERDIALOG.H"

extern s8 Menu_AdjustValue(Outer8043E458 *menu, s8 value, s32 step, s32 minimum, s32 maximum, s32 wrap);

extern void Menu_AllocateMenu(void *owner, void *params, void *list);

/* Points arg0's unk14 field at g_profileModeZeroLabel or g_profileModeOneLabel when the mode byte at 0x7B of the owner's record is 0 or 1, and returns 0. */











/* Forwards arg0->unk20->unk4 to func_80264770_de and clears D_800E28C0. */



extern s32 D_800E28C0;

extern void Control_EnableControllerPak(s32 kind);

/* Returns whether any of the words at offsets 0x28, 0x1C and 0x20 of g_matchRoundCounters is set. */



/* Restarts a round for the player passed in arg1: clears the world timer flag D_800E28C0 via
   func_804097E8_de, cancels the active countdown sound through SoundElement_StopAudioExceptKey, then reallocates a
   fresh scoreboard entry via Menu_OpenDialog using arg1's fields at 0x1C and 0x20, and always
   reports success. */

extern s32 g_matchEndingTeamWheelClose;

extern s32 D_0044E468;

void Timer_ClearTimerFlag(void);

void *Menu_OpenDialog(void *owner, void *list, s32 b, s32 c, s32 d);

/** Runs a target's animation/state transition through Menu_AdjustValue and stores the new state. */
s32 CMenuProfile_ToggleProfileMode(void *menuItem, Outer8043E458 *menuContext) {
    Target8043E458 *profileOptions;

    profileOptions = menuContext->unk1C->unk5D8;
    profileOptions->unk7B = Menu_AdjustValue(menuContext, profileOptions->unk7B, 1, 0, 1, 1);
    return 0;
}

/** Forwards arg1 through and arg2 as the first parameter, adding the D_452834 record. */
s32 CMenuProfile_OpenPrimaryProfileMenu(void *unused0, void *menuOwner, void *menuContext) {
    Menu_AllocateMenu(menuContext, menuOwner, &D_004518A4);
    return 1;
}

s32 CMenuProfile_BindSelectedDebugField(Shared_DebugWidget *widget, Shared_MenuHandle *handle) {
    widget->field = g_profileSelectionResources[handle->selection->index];
    return 0;
}

/* Forwards arg1 through and arg2 as the first parameter, adding the D_4505C0 record. */
s32 CMenuProfile_OpenSecondaryProfileMenu(void *unused0, void *menuOwner, void *menuContext) {
    Menu_AllocateMenu(menuContext, menuOwner, &D_0044F994_de);
    return 1;
}

s32 CMenuProfile_UpdateProfileModeLabel(MenuLabelPointerView *modeLabel, MenuCMenuProfileUpdateProfileModeLabel *menu) {
    switch (menu->owner->record->mode) {
    case 0:
        modeLabel->label = &g_profileModeZeroLabel;
        break;
    case 1:
        modeLabel->label = &g_profileModeOneLabel;
        break;
    }
    return 0;
}

/** Forwards the pointed-to inner byte field on to func_80264770_de. */
void CMenuProfile_EnableOwnerControllerPak(Outer8043E56C *menuOwner) {
    Control_EnableControllerPak(menuOwner->controller->controllerPort);
}

void CMenuProfile_EnableControllerPakAndClearState(struct Shared_PakMenu *pakMenu) {
    Control_EnableControllerPak(pakMenu->owner->controllerPort);
    D_800E28C0 = 0;
}

s32 CMenuProfile_HasProfileRoundProgress(void) {
    CGameStatus *state = &g_gameSettings.counters;

    return state->round != 0 || state->elapsed != 0 || state->state != 0;
}

s32 CMenuProfile_OpenTimedPlayerDialog(void *unused0, Arg1Struct *menuContext) {
    s32 val1C;

    val1C = menuContext->player;
    Timer_ClearTimerFlag();
    ((s32 (*)(s32))SoundElement_StopAudioExceptKey)(-1);
    Menu_OpenDialog(&g_matchEndingTeamWheelClose, &D_0044E468, val1C, menuContext->controller, 0);
    return 1;
}

/** Return 0. */
s32 CMenuProfile_ProfileModeReturnZero(void) {
    return 0;
}
