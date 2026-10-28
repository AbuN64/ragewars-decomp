#include "COMMON/VIEWFLAGS.H"
#include "CAMERA/80233920.H"
#include "TYPES.H"
#include "CAMERA/GSKY_GETMASKEDEFFECTCOLOR.H"

extern s32 D_801462C8;


void Gsky_GetMaskedEffectColor(ThreeChannels *threeChannels, s8 *red, s8 *green, s8 *blue) {
    if (D_801462C8 & 0x4000) {
        *red = 0;
        *green = 0;
        *blue = 0;
        return;
    }
    *red = threeChannels->first & 0xF8;
    *green = threeChannels->second & 0xF8;
    *blue = threeChannels->third & 0xF8;
}
