#include "COMMON/STATEPAIR.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "RESMGR/802A2230_7.H"

/** Set D_800D2C90 to one. */


s32 GetMenuScreenOwner();


void Tsmos_RequestFrontendShutdown(void) {
    extern int D_800D2C90;
    D_800D2C90 = 1;
}

void Tsmos_ScaleCurrentScreen(void) {
    if (D_800E28D8 == 1) {
        Tsmos_ScaleWidgetTree(Frontend_GetScreenData(GetMenuScreenOwner()), 0);
    }
}
