#include "COMMON/CALLBACK.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "RESMGR/8029AA48_11.H"

void Smos_SetControllerEventFilter(s32 (*arg0)(void)) {
    D_8014D0B0->callback = arg0;
}
