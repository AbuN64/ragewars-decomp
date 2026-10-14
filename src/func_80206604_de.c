#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern s32 func_80245B0C_de(void);
extern s32 D_00206724;
extern s32 D_0020694C;
extern s32 D_800C85F0_de;

extern func_80206604_G1 D_801462E5;






void func_80206604_de(void *arg0, void *arg1) {
    s32 flags;
    s32 flags2;

    ((ActorMotionState *)arg1)->table = &D_800C85F0_de;
    ((ActorMotionState *)arg1)->update = &D_00206724;
    flags = ((LevelActor *)arg0)->flags;
    flags |= 0x01000000;
    flags |= 0x02000000;
    flags2 = flags | 0x20000;
    ((LevelActor *)arg0)->flags = flags2;
    if (D_801462E5.unk0 == 0) {
        ((LevelActor *)arg0)->flags = flags2 | 0x10000000;
    }
    if ((((LevelActor *)arg0)->type == 0x453) && (func_80245B0C_de() == 0x6F)) {
        ((ActorMotionState *)arg1)->secondaryUpdate = &D_0020694C;
    }
}
