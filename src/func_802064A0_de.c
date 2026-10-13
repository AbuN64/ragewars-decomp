#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "types.h"





extern char D_8011D8D0;
extern s32 func_802800C0_de(void *, void *, void *, void *, s32, s32,
                         Vec3, Vector4f, Triple, s32, s32, s32);






void func_802064A0_de(void *arg0, void *arg1, Triple arg2,
                   s32 unused5, s32 arg6) {
    s32 result;

    result = func_802800C0_de(&D_8011D8D0, arg0, arg0,
                           &((ActorMotionState *)arg1)->unk124, 0, arg6,
                           ((Actor_func_8024A7A0_de *)arg0)->position1,
                           ((Actor_func_8024A7A0_de *)arg0)->rotation,
                           arg2, 0, -1, 0);
    ((ActorMotionState *)arg1)->unk128 -= result;
}
