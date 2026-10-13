#include "shared/gameplay_transition.h"
#include "shared/gameplay_movement.h"
#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022D944.h"
#include "types.h"



extern s32 func_8024E7DC_de(void *);
extern s32 func_8024E62C_de(void *arg0);
extern void func_8021B1E4_de(void *, s32, s32, s32);
extern f32 D_800C7F08;











void func_8022E6A4_de(void *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = func_8024E7DC_de(arg1);
    if ((temp_v0 != 0) && (((Shared_Surface *)temp_v0)->flags & 0x4000)) {
        ((Actor_func_8024A7A0_de *)arg1)->position1.y = 0;
    } else if (((Actor_func_8024A7A0_de *)arg1)->position0.y < (D_801370C4 - D_800C7F08)) {
        func_8021B1E4_de(arg0, ((Shared_ActorView *)arg0)->spawn, 0, 0);
    }
    if (func_8024E62C_de(arg1) != 0) {
        ((Shared_ActorView *)arg0)->contactPosition = ((Actor_func_8024A7A0_de *)arg1)->position0;
    }
}
