#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"

/** Set D_800D2C90 to one. */


extern void Controller_ClearControllerFlags(s32 *arg0);

/** Return the global word at D_800D2C98. */




void Tsmos_ActivateControllerState(void) {
    s32 *p;

    p = &D_800CDA24;
    if (*p != 1) {
        *p = 1;
        Controller_ClearControllerFlags(p);
    }
}

void Tsmos_DeactivateControllerState(void) {
    D_800CDA24 = 0;
}

int Tsmos_IsControllerStateActive(void) {
    return D_800CDA24;
}

int Tsmos_IsFrontendActive(void) {
    return D_800D2C98;
}

void Tsmos_SetModeOneFlag(s32 arg0) {
    if (arg0 == 1) {
        D_800CDA2C = arg0;
        return;
    }
    D_800CDA2C = 0;
}

int Tsmos_GetModeOneFlag(void) {
    return D_800CDA2C;
}
