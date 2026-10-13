#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"


extern f32 func_80216F44_de(Player *arg0, Vec3 point);
extern f32 func_8020AA0C_de(void *arg0);









void func_8020A6D8_de(void *arg0, void *arg1) {
    s32 timer;
    s32 minus_one;
    Player *record;
    f32 distance;

    if (arg0 == 0) {
        return;
    }
    func_8020A884_de(arg0, arg1);
    timer = ((AiController *)arg0)->unk2E4;
    if (timer > 0) {
        ((AiController *)arg0)->unk2E4 = timer - 1;
        return;
    }
    minus_one = -1;
    if (timer == minus_one) {
        ((AiController *)arg0)->unk23C = 1;
        ((AiController *)arg0)->unk2E8 += minus_one;
    } else {
        record = ((AiController *)arg0)->target->player;
        distance = func_80216F44_de(((AiController *)arg0)->player, record->pos);
        if (func_8020AA0C_de(arg0) < distance) {
            return;
        }
        ((AiController *)arg0)->unk23C = 1;
        ((AiController *)arg0)->unk2E4 = minus_one;
    }
    if (((AiController *)arg0)->unk2E8 == 0) {
        ((AiController *)arg0)->unk23C = 0;
        func_8020A95C_de(arg0, arg1);
    }
}
