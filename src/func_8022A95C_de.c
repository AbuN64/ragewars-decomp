#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022A274.h"
#include "types.h"







extern f32 D_800D2988;
extern void func_8024BE3C_de(void *arg0);
extern void func_80246E44_de(char *);






void func_8022A95C_de(void *arg0) {
    LevelActor *base;
    s32 old_value;
    s32 new_value;
    f32 saved_value;

    base = &((Shared_ActorView *)arg0)->weapon;
    old_value = ((Shared_ActorView *)arg0)->effectId;
    saved_value = D_800D2988;
    base->renderFlags = 0x10;
    base->flags &= 0xFFFDFFFF;
    func_8024BE3C_de(base);
    if (((Shared_ActorView *)arg0)->stun <= 0.0f) {
        func_80246E44_de(base);
    }
    new_value = ((Shared_ActorView *)arg0)->effectId;
    D_800D2988 = saved_value;
    if (old_value != new_value) {
        ((LevelActor *)arg0)->animationPending = 0;
    }
    ((Shared_ActorView *)arg0)->weapon.position0 = ((LevelActor *)arg0)->position0;
    ((Shared_ActorView *)arg0)->weapon.yaw = ((LevelActor *)arg0)->yaw;
    ((Shared_ActorView *)arg0)->weapon.model = ((LevelActor *)arg0)->model;
    ((Shared_ActorView *)arg0)->weapon.rotation = ((LevelActor *)arg0)->rotation;
}
