#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

extern s32 Visdata_ContainsPoint(s32 planes, Triple *point);

s32 Gsky_ContainsVisiblePoint(s32 cameraAddress, Triple testPoint) {
    return Visdata_ContainsPoint(cameraAddress + 0x2F0, &testPoint);
}
