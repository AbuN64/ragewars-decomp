#include "shared/gameplay_transition.h"
#include "shared/gameplay_round_rules.h"
#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022C894.h"
#include "span_1000/code_80233920.h"
#include "types.h"



extern const f32 D_800C2D94_de;
extern const f32 D_800C2D98_de;
extern const f32 D_800C2D9C_de;



extern void func_80218464_de();
extern s32 func_8025DE54_de(s16 arg0, Vec3 arg1, s32 arg4, s32 arg5);






void func_8022CF38_de(void *arg0, void *arg1) {
    f32 value;
    f32 minimum;
    ((Shared_ActorView *)arg0)->forwardSpeed *= D_800C2D94_de;
    ((Shared_ActorView *)arg0)->lateralSpeed *= D_800C2D94_de;

    value = ((LevelActor *)arg1)->position1.y * D_800C2D98_de;
    minimum = D_800C2D9C_de;
    ((LevelActor *)arg1)->position1.y = value;
    if (value < minimum) {
        ((LevelActor *)arg1)->position1.y = minimum;
    }

    ((Shared_ActorView *)arg0)->collisionState = 0;
    func_8023913C_de(((Shared_ActorView *)arg0)->message);
    func_80218464_de(((Shared_func_80227014_S2 *)arg0)->unk938);

    if (((LevelActor *)arg1)->motionState & 0x8000) {
        func_8025DE54_de(0x2DA, ((LevelActor *)arg1)->position0, 0, -1);
    } else {
        func_8025DE54_de(0x2DC, ((LevelActor *)arg1)->position0, 0, -1);
    }
}
