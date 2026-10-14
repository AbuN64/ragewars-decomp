#include "shared/gameplay_transition.h"
#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022D944.h"
#include "types.h"



extern s32 func_8024E7DC_de(void *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_80271AA8_de(Vec3 *arg0);









void func_8022D970_de(void *arg0, void *arg1) {
    char *o = (char *)arg0;
    char *a1 = (char *)arg1;
    s32 temp_v0;
    Vec3 sp10;
    Vec3 sp20;

    temp_v0 = func_8024E7DC_de(arg1);
    ((Shared_ActorView *)o)->effectModel = (void *)temp_v0;
    if (temp_v0 != 0) {
        ((Shared_ActorView *)o)->modelState = 0;
        ((Shared_ActorView *)o)->effectPosition.x = ((LevelActor *)a1)->position0.x;
        ((Shared_ActorView *)o)->effectPosition.y = ((LevelActor *)a1)->position0.y;
        ((Shared_ActorView *)o)->effectPosition.z = ((LevelActor *)a1)->position0.z;
        sp10.x = ((ModelBlend *)temp_v0)->effectOffset.x;
        sp10.y = ((ModelBlend *)temp_v0)->effectOffset.y;
        sp10.z = ((ModelBlend *)temp_v0)->effectOffset.z;
        func_80271F68_de(&sp20, &sp10, &((Shared_ActorView *)o)->effectPosition);
        sp20.y = 0.0f;
        ((Shared_ActorView *)o)->modelDistance = func_80271AA8_de(&sp20);
    }
}
