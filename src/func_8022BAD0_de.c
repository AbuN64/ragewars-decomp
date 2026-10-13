#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "span_1000/code_8021CD70.h"
#include "shared/world.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"

extern void *func_8028CFA0_de(void *arg0, s32 arg1, s32 arg2);
extern s32 D_801468F4;









void func_8022BAD0_de(void *arg0) {
    s32 var_a2;
    void *result;

    var_a2 = ((Shared_ActorView *)arg0)->state;
    if (D_801468F4 != 0 && ((Shared_ActorView *)arg0)->controls->transientFlag == 1) {
        var_a2 = 0x13;
    }
    result = func_8028CFA0_de(&D_8011FE88, 0xB, var_a2);
    if (result != 0) {
        ((Shared_ActorView *)arg0)->model = result;
    } else {
        result = func_8028CFA0_de(&D_8011FE88, 0xB, -1);
        if (result != 0) {
            ((Shared_ActorView *)arg0)->model = result;
        } else {
            result = func_8028CFA0_de(&D_8011FE88, -1, -1);
            ((Shared_ActorView *)arg0)->model = result;
        }
    }
    ((Actor_func_8024A7A0_de *)arg0)->scale.x = ((ObjectState108 *)result)->unk_FC;
    ((Actor_func_8024A7A0_de *)arg0)->scale.y = ((ObjectState108 *)result)->unk_100;
    ((Actor_func_8024A7A0_de *)arg0)->scale.z = ((ObjectState108 *)result)->unk_104;
}
