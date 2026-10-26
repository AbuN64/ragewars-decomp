#include "COMMON/RESIDENTSTATE.H"
#include "RENDER/802944E8_10.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "TEXTURE/80294C64_5.H"
#include "RESMGR/802A0888.H"

#if defined(VERSION_US_REV1)

extern s32 D_8014AEC0;
extern s32 D_8014AECC;
extern s32 D_8014AED0;
extern s32 D_8014AED4;


void TextLoad_ResetArtsendTextureState(void) {
    s32 *base = &D_8014AEB8;

    D_8014AEB0.alternateTitle = 0;
    D_8014AEB1 = 0;
    D_8014AEBC = 0;
    D_8014AEC0 = 0;
    *base = 1;
    D_8014AEB4 = 0;
    D_8014AEC4 = 0;
    D_8014AECC = 0;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    D_8014CFDC = 0;
    D_8014CFE0 = 0;
    D_8014CFE4 = 0;
    D_8014D068 = 0;

    XPlus_FillMemory((s32) ((char *) base + 0x24), 0, 0x2000);
    XPlus_FillMemory((s32) ((char *) base + 0x2024), 0xFF, 0x100);

    *base = *D_8011FED8;
}
#endif
