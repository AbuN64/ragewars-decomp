#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_802624A0.h"
#include "span_1000/code_80255BEC.h"
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
