#include "shared/level_actor.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8022C894.h"
#include "types.h"

extern void func_8044A07C_de(s32 arg0);




void func_8022D214_de(void *arg0) {
    LevelActor *actor = arg0;
    Shared_ActorView *player = arg0;
    actor->flags &= 0xFF7FFFFF;
    player->stun = 0;
    player->field11FC = 0.0f;
    actor->flags |= 0x01000000;
    func_8044A07C_de((s32) arg0);
}
