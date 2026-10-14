#include "common/unused.h"
#include "shared/gameplay_reactions.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

extern s32 func_80214178_de(void *, void *, s32);






void func_80203E78_de(void *arg0, void *arg1, void *arg2) {
    s32 var_v1;

    var_v1 = ((Dest *)arg1)->health - ((Shared_DamageEvent *)arg2)->damage;
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    ((Dest *)arg1)->health = var_v1;
    if (var_v1 == 0) {
        func_80214178_de(arg0, arg1, 0x40);
    }
}
