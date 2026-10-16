#include "span_1000/code_802106E0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"










void func_80212470_eu(CloseAttackActor *arg0) {
    CloseAttackActor *level1 = arg0->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2, r3;

    inner->state = 0;
    func_80209988_de(inner);

    r1 = func_802744D4_de();
    inner->timer = r1 % 4 + 0xC;

    r2 = func_802744D4_de();
    inner->pattern = r2 % 2;

    r3 = func_802744D4_de();
    inner->fireTimer = -1;
    inner->frames = 0;
    inner->visible = 0;
    inner->distance = r3 % 250000 + 360000;
}



void func_80212544_eu(CloseAttackActor *arg0) {
    CloseAttackActor *level1 = arg0->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2, r3;

    inner->state = 0;

    r1 = func_802744D4_de();
    inner->timer = r1 % 4 + 2;

    r2 = func_802744D4_de();
    inner->pattern = r2 % 2;

    r3 = func_802744D4_de();
    inner->distance = r3 % 32400 + 0x2710;

    func_80209988_de(inner);

    inner->frames = 0;
    inner->visible = 0;
    inner->fireTimer = -1;
}

int func_80212610_eu(CloseAttackActor *arg0) {
    CloseAttackActor *level1 = arg0->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2;

    inner->state = 0;
    func_80209988_de(inner);

    r1 = func_802744D4_de();
    inner->timer = r1 % 4 + 0xC;

    r2 = func_802744D4_de();
    inner->pattern = r2 % 2;
}
