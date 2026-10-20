#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/S1.H"

void func_8044ADF0_de(ObjRecAt5F14 *arg0) {
    SceneEffect *var_s0;
    s32 var_s1;

    func_80255CA0_de(&arg0->unk5F00, 0x2E8, 0x2EC);
    func_80255CA0_de(&arg0->unk5F14, 0x2E8, 0x2EC);
    var_s1 = 0;
    var_s0 = arg0->effects;
    do {
        func_80255D14_de(&arg0->unk5F00, var_s0);
        var_s1 += 1;
        var_s0 += 1;
    } while (var_s1 < 0x20);
}

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8044AFD4);
#endif
