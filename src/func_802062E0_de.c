#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "types.h"
#include "shared/level_actor.h"
#include "span_1000/code_80204E78.h"
/* Spawns effect kind at an actor's position through func_8028FFD0_de in D_80131600's list: kind 0xBD7
   is skipped while both of D_801468A0's flags at 0x78 and 0x80 are set, and kind 0x1388 is offset by
   the variant byte at D_800E4680 when option D_801462D5 is 1 (skipped for variant 0); a spawned node
   has its word at 0x1A0 cleared, takes one charge from the owner and starts effect 0x11D at its own
   position through func_80216288_de. */







extern char D_80131600;


extern Settings D_801468A0;
extern u8 D_801462D5;
extern u8 *D_800E4680;
extern SpawnDispatchActor *func_8028FFD0_de(char *, void *, s32, Vec3, Triple, s32, f32);









void func_802062E0_de(Actor_func_8024A7A0_de *actor, ActorMotionState *owner, Params params, s32 kind) {
    SpawnDispatchActor *node;
    Settings *settings;

    if (kind == 0xBD7) {
        settings = &D_801468A0;
        if (settings->flag78 != 0 && settings->flag80 != 0) {
            return;
        }
    }
    if (kind == 0x1388 && D_801462D5 == 1) {
        kind = *D_800E4680 + 0x1388;
        if (kind == 0x1388) {
            return;
        }
    }
    node = func_8028FFD0_de(&D_80131600, &owner->unk124, kind,
                         actor->position1, params.v, params.w, 0.0f);
    if (node != 0) {
        node->state = 0;
        owner->unk128 -= 1;
        func_80216288_de(node, 0x11D, node->position, 0);
    }
}
