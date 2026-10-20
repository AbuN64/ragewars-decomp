#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

extern s32 func_802969E8_de(s32 arg0, Triple *arg1);

s32 func_802393AC_de(s32 arg0, Triple arg1) {
    return func_802969E8_de(arg0 + 0x2F0, &arg1);
}
