#include "include_asm.h"
#include "sdk/OBJECTSTATE2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802B3AFC.H"

extern s32 func_802AE500_de(s32, s32);

s32 __readVarLen(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = (u8) func_802AE500_de(arg0, arg1);
    if (var_s0 & 0x80) {
        var_s0 &= 0x7F;
        do {
            temp_v0 = (u8) func_802AE500_de(arg0, arg1);
            var_s0 = (var_s0 << 7) + (temp_v0 & 0x7F);
        } while (temp_v0 & 0x80);
    }
    return var_s0;
}

/** Read the object word at offset 0x2C. */
int func_802AEAA0_de(void *object) {
    ObjRecAt2CV2 *record = object;
    return record->unk2C;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802AE9DC);
#endif
