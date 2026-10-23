#include "include_asm.h"
#include "COMMON/LOCALDECODERANGE.H"
#include "TYPES.H"
#include "SYSTEM/802609CC_5.H"

/** Return the low five bits of the supplied value. */
unsigned int func_8026160C_de(unsigned int value) {
    return value & 0x1F;
}

u32 func_80261614_de(s32 arg0) {
    u32 var_a1;
    u32 var_a2;
    u32 var_v1;

    var_a1 = 0;
    var_a2 = 0;
    var_v1 = 0;
    do {
        if (arg0 & (u32)(1 << var_v1)) {
            var_a1 += 1;
            var_a2 = var_v1;
        }
        var_v1 += 1;
    } while (var_v1 < 0x20U);
    if (var_a1 >= 2U) {
        return var_a2 + 1;
    }
    return var_a2;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80261608[2] = {
    0x04000000, 0x01000400,
};
#endif
