#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENTSTATE.H"
#include "RENDER/802944E8_10.H"
#include "TYPES.H"
#include "COMMON/TEXTURE_REQUEST.H"

#if defined(VERSION_US_REV1)
extern char D_8014AEC8[];

extern Selection_func_802955EC_us_rev1 D_8014AECC;




void func_802955EC_us_rev1(s32 resource, s32 **texture) {
    s32 enabled;
    s32 choose;

    if ((D_800D2AE0 != 0) && (*texture != 0) && (*(s32 *)&D_8014AEC8[0] == 0)) {
        enabled = 0;
        if (D_8014AEB0.alternateTitle != 0) {
            enabled = (u32)D_800D2AE0 > 0U;
        }
        if (enabled != 0) {
            choose = (*(s32 *)&D_8014AEC8[0x21A0] % 10) < 3;
        } else {
            choose = 1;
        }
        if (resource == D_8014AECC.value) {
            if (choose != 0) {
                *texture = &D_8014AECC.alternative;
                return;
            }
            *texture = D_8014AEB0.textureOverride;
        }
    }
}
#endif
