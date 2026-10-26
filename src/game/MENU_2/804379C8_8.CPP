#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "abi.h"
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/GFX.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SCREEN.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
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
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/S1_5.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"

/* Calls MarkMenuEventHandled; when func_80299A08_de reports 0x1D3, passes -1 to Frontend_SetMenuChoiceResult if
   func_802999A0_de reports 0x16 for zero and 0xB otherwise, then calls func_802998A8_de. Returns zero. */




/* Calls MarkMenuEventHandled, then passes -1 to Frontend_SetMenuChoiceResult when func_802999A0_de reports 0x16 for zero
   and 0xB otherwise, then calls func_802998A8_de. Returns zero. */


s32 func_804393A8_de(void) {
    MarkMenuEventHandled();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x1CF) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x1D3) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x1DC) {
#endif
        Frontend_SetMenuChoiceResult(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
        func_802998A8_de();
    }
    return 0;
}

s32 func_80439404_de(void) {
    MarkMenuEventHandled();
    Frontend_SetMenuChoiceResult(func_802999A0_de(0) == 0x16 ? -1 : 0xB);
    func_802998A8_de();
    return 0;
}
