#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

extern s32 VisData_ContainsPoint(s32 arg0, Triple *arg1);

s32 func_802393AC_de(s32 cameraAddress, Triple testPoint) {
    return VisData_ContainsPoint(cameraAddress + 0x2F0, &testPoint);
}
