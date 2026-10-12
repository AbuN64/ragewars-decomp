#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "span_1000/code_80291054.h"
#include "types.h"

/** Thin wrapper around func_80264404_de. */
void func_80293268_de(void) {
    func_80264404_de();
}


extern s32 func_8044D220_de(s8 *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
extern RenderCounters D_801468A0;






void func_80293284_de(void *arg0, s32 arg1) {
    s32 sp18[6];
    s32 var_s0;

    var_s0 = arg1;
    if (func_8044D220_de((s8 *)&D_8011FE88, -1, var_s0, sp18, 1) == 0) {
        var_s0 = 0;
    }
    D_801468A0.unk0 = 0;
    D_801468A0.unk4 = 0;
    D_801468A0.unk8 = 0;
    D_801468A0.unkC = 0;
    D_801468A0.first = 0;
    ((func_80293268_S2 *)(arg0))->unk26DC1 = 2;
    ((func_80293268_S2 *)(arg0))->unk26DD8 = var_s0;
    ((func_80293268_S2 *)(arg0))->unk26DDC = 1;
    ((func_80293268_S2 *)(arg0))->unk26DBC = 0xD;
}

void func_8044A370_de(void *a);
void func_804499B0_de(void *a, void *b, void *c);




void func_80293334_de(void *arg0, void *arg1, void *arg2) {
    func_8044A370_de((char *)arg0 + 0x255C8);
    func_804499B0_de(&((func_80293318_S1 *)(arg0))->unk25580, arg1, arg2);
}
