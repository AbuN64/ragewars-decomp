#include "span_1000/code_80293A04.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "span_1000/code_80291054.h"
#include "types.h"

/** Thin wrapper around func_80264404_de. */
void func_80293268_de(void *unused) {
    func_80264404_de();
}


extern s32 func_8044D220_de(s8 *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);






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
    ((Session_func_80293A20_de *)arg0)->phase = 2;
    ((Session_func_80293A20_de *)arg0)->selector = var_s0;
    ((Session_func_80293A20_de *)arg0)->selectionActive = 1;
    ((Session_func_80293A20_de *)arg0)->target = 0xD;
}

void func_8044A370_de(void *a);
void func_804499B0_de(void *a, void *b, void *c);




void func_80293334_de(void *arg0, void *arg1, void *arg2) {
    func_8044A370_de(((Session_func_80293A20_de *)arg0)->players);
    func_804499B0_de(((Session_func_80293A20_de *)arg0)->menu, arg1, arg2);
}
