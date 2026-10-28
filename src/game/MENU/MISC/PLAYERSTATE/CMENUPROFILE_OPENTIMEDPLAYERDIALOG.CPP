#include "MENU/PLAYERSETTINGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/CMENUPROFILE_OPENTIMEDPLAYERDIALOG.H"
#include "COMMON/SHARED_DEBUGFIELD.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MENU/MISC/CMENUPROFILE_OPENTIMEDPLAYERDIALOG.H"

extern s8 Menu_AdjustValue(Outer8043E458 *arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern void Menu_AllocateMenu(void *arg0, void *arg1, void *arg2);

/* Points arg0's unk14 field at D_800D7688 or D_800D768C when the mode byte at 0x7B of the owner's record is 0 or 1, and returns 0. */











/* Forwards arg0->unk20->unk4 to func_80264770_de and clears D_800E28C0. */



extern s32 D_800E28C0;

extern void Control_EnableControllerPak(s32 kind);

/* Returns whether any of the words at offsets 0x28, 0x1C and 0x20 of D_801468A0 is set. */



/* Restarts a round for the player passed in arg1: clears the world timer flag D_800E28C0 via
   func_804097E8_de, cancels the active countdown sound through func_8025E214_de, then reallocates a
   fresh scoreboard entry via Menu_OpenDialog using arg1's fields at 0x1C and 0x20, and always
   reports success. */

extern s32 D_8014561C;

extern s32 D_0044E468;

void Timer_ClearTimerFlag(void);

void *Menu_OpenDialog(void *owner, void *list, s32 b, s32 c, s32 d);

/** Runs a target's animation/state transition through Menu_AdjustValue and stores the new state. */
s32 CMenuProfile_ToggleProfileMode(void *arg0, Outer8043E458 *menuContext) {
    Target8043E458 *profileOptions;

    profileOptions = menuContext->unk1C->unk5D8;
    profileOptions->unk7B = Menu_AdjustValue(menuContext, profileOptions->unk7B, 1, 0, 1, 1);
    return 0;
}

/** Forwards arg1 through and arg2 as the first parameter, adding the D_452834 record. */
s32 func_8043E418_de(void *unused0, void *menuOwner, void *menuContext) {
    Menu_AllocateMenu(menuContext, menuOwner, &D_004518A4);
    return 1;
}

s32 CMenuProfile_BindSelectedDebugField(Shared_DebugWidget *widget, Shared_MenuHandle *handle) {
    widget->field = D_800E1CC0[handle->selection->index];
    return 0;
}

/* Forwards arg1 through and arg2 as the first parameter, adding the D_4505C0 record. */
s32 func_8043E468_de(void *unused0, void *menuOwner, void *menuContext) {
    Menu_AllocateMenu(menuContext, menuOwner, &D_0044F994_de);
    return 1;
}

s32 CMenuProfile_UpdateProfileModeLabel(ObjRecAt14V1 *modeLabel, MenuCMenuProfileUpdateProfileModeLabel *menu) {
    switch (menu->owner->record->mode) {
    case 0:
        modeLabel->unk14 = &D_800D7688;
        break;
    case 1:
        modeLabel->unk14 = &D_800D768C;
        break;
    }
    return 0;
}

/** Forwards the pointed-to inner byte field on to func_80264770_de. */
void CMenuProfile_EnableOwnerControllerPak(Outer8043E56C *menuOwner) {
    Control_EnableControllerPak(menuOwner->unk20->unk4);
}

void CMenuProfile_EnableControllerPakAndClearState(struct Shared_PakMenu *pakMenu) {
    Control_EnableControllerPak(pakMenu->owner->unk4);
    D_800E28C0 = 0;
}

s32 CMenuProfile_HasProfileRoundProgress(void) {
    CGameStatus *state = &D_801462C8.counters;

    return state->round != 0 || state->elapsed != 0 || state->state != 0;
}

s32 CMenuProfile_OpenTimedPlayerDialog(void *unused0, Arg1Struct *menuContext) {
    s32 val1C;

    val1C = menuContext->unk1C;
    Timer_ClearTimerFlag();
    ((s32 (*)(s32))func_8025E214_de)(-1);
    Menu_OpenDialog(&D_8014561C, &D_0044E468, val1C, menuContext->unk20, 0);
    return 1;
}

/** Return 0. */
s32 func_8043E5C8_de(void) {
    return 0;
}
