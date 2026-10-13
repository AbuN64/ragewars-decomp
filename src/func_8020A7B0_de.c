#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"


extern f32 func_80216F44_de(Player *arg0, Vec3 point);
extern f32 func_8020AA0C_de(void *arg0);









void func_8020A7B0_de(void *arg0, void *arg1) {
    AiController *brain = arg0;
    s32 timer;
    Player *record;
    f32 distance;

    if (arg0 == 0) {
        return;
    }
    func_8020A884_de(arg0, arg1);
    timer = brain->unk2E4;
    if (timer > 0) {
        brain->unk2E4 = timer - 1;
        return;
    }
    if (timer == 0) {
        brain->unk23C = 1;
        brain->unk2E8 -= 1;
    }
    if (brain->unk2E8 != 0) {
        return;
    }
    brain->unk2E4 = -1;
    record = brain->target->player;
    distance = func_80216F44_de(brain->player, record->pos);
    if (func_8020AA0C_de(arg0) < distance) {
        brain->unk23C = 1;
        return;
    }
    brain->unk23C = 0;
    func_8020A95C_de(arg0, arg1);
}
