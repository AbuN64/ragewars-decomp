#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"











s32 func_80232BD0_de(void *arg0, void *arg1, void *arg2) {
    s32 temp_v0;
    void *temp_v1;

    {
        f32 field = ((Shared_ActorView *)arg2)->stun;
        if (D_800C301C_de < field) {
            return 1;
        }
    }
    if ((((Actor_func_8024A7A0_de *)arg0)->flags & 0x300000) && (((Shared_ActorView *)arg2)->remote != 0)) {
        temp_v1 = ((Shared_ActorView *)arg2)->owner;
        temp_v0 = ((Actor_func_8024A7A0_de *)temp_v1)->actionReady;
        ((Actor_func_8024A7A0_de *)temp_v1)->actionReady = 0;
        return temp_v0 == 0;
    }
    if (((Shared_ActorView *)arg2)->actionFlags & 0x2000) {
        if (((Shared_ActorView *)arg2)->actionState != 0) {
            return 1;
        }
        return func_80222AA4_de(arg2, ((Shared_ActorView *)arg2)->selectedAction) == 0;
    }
    return 1;
}
