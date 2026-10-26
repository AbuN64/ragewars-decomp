#include "COMMON/RESIDENTSTATE.H"
#include "RENDER/802944E8_10.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/TEXTURE_REQUEST.H"

#if defined(VERSION_US_REV1)
extern ResidentSlot D_8014AEC8;
extern ResidentEntry D_8014AECC;

void func_802956AC_us_rev1(s32 resource, s32 **palette) {
    s32 var_v1;
    s32 var_v1_2;

    if ((D_800D2AE0 != 0) && (*palette != 0)) {
        if (D_8014AEC8.unk0 != 0) {
            return;
        }
        var_v1 = 0;
        if (D_8014AEB0.alternateTitle != 0) {
            var_v1 = (u32)D_800D2AE0 > 0U;
        }
        if (var_v1 != 0) {
            var_v1_2 = (D_8014AEC8.unk21A0 % 10) < 3;
        } else {
            var_v1_2 = 1;
        }
        if (resource == D_8014AECC.unk0) {
            if (var_v1_2 != 0) {
                *palette = &D_8014AECC.unk2010;
                return;
            }
            *palette = D_8014AEB0.paletteOverride;
        }
    }
}

void func_8029576C_us_rev1(void) {
    s32 temp_v1;

    if (D_auto_800D2AE8++ >= 3) {
        temp_v1 = D_8014AEB8.unk4 + 1;
        D_auto_800D2AE8 = 0;
        D_8014AEB8.unkC = 1;
        D_8014AEB8.unk4 = temp_v1;
        D_8014AEB8.unk4 = temp_v1 % D_8014AEB8.unk0;
    }
}
#endif
