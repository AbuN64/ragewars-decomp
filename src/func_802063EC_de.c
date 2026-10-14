#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "types.h"



extern char D_80131150;

extern s32 func_80262CE0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, Triple arg5, f32 arg6, Vec3 arg7,
                         Triple arg8, void *arg9);






void func_802063EC_de(void *arg0, void *arg1, Triple arg2, Triple arg3,
                   s32 arg4, s32 arg5, s32 arg6) {
    if (func_80262CE0_de(&D_80131150, arg5, 0, arg6,
                      arg4, arg2,
                      ((LevelActor *)arg0)->yaw,
                      ((LevelActor *)arg0)->position1, arg3,
                      &((ActorMotionState *)arg1)->unk124) != 0) {
        ((ActorMotionState *)arg1)->unk128 -= 1;
    }
}
