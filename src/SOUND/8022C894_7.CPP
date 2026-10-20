#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "TYPES.H"
#include "RENDER_2/802192C0_3.H"

extern s32 func_8024E7DC_de(void *);
extern s32 func_8024E62C_de(void *arg0);
extern f32 D_800C7F08;











void func_8022E6A4_de(Shared_ActorView *arg0, LevelActor *arg1) {
    void *temp_v0;

    temp_v0 = func_8024E7DC_de(arg1);
    if ((temp_v0 != 0) && (((Shared_Surface *)temp_v0)->flags & 0x4000)) {
        arg1->position1.y = 0;
    } else if (arg1->position0.y < (D_801370C4 - D_800C7F08)) {
        func_8021B1E4_de(arg0, arg0->spawn, 0, 0);
    }
    if (func_8024E62C_de(arg1) != 0) {
        arg0->contactPosition = arg1->position0;
    }
}
