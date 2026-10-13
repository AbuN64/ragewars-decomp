#include "shared/level_actor.h"
#include "shared/gameplay_transition.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"




extern void func_80271FC8_de(void *arg0, f32 t, void *a, void *b);
extern f32 func_8024D284_de(void *arg0);






s32 func_80267444_de(void *arg0, Vec3 *arg1) {
    Vec3 first;
    Vec3 second;
    Actor_func_8024A7A0_de *object = arg0;
    Shared_ActorView *actor;
    s16 state;
    s32 result;

    result = 0;
    if ((object->kind == 1) &&
        ((object->flags & 0x300000) != 0)) {
        actor = object->controller;
        if (arg0 == &actor->weapon) {
            state = actor->selectedAction;
            if ((state == 0) || (state == 0x11) || (state == 0x10)) {
                first = *arg1;
                second = ((Actor_func_8024A7A0_de *)actor)->position0;
                func_80271FC8_de(arg1, 0.75f, &first, &second);
                arg1->y += func_8024D284_de(actor) * D_800C4430_de;
                result = 1;
            }
        }
    }
    return result;
}
