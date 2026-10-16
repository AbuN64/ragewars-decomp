#include "span_1000/code_80200610.h"
#include "common/types_06e4f7ef1f9e.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_802022E0.h"
#include "span_1000/code_80206258.h"
#include "TYPES.H"

extern s32 func_802034A4_de(void *arg0);

extern s32 func_80214178_de(void *, void *, s32);

extern s32 func_802170A0_de(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_80285DB0_de(Shared_World *, void *, s32);

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

s32 func_80262C88_de();

extern s32 func_80285F58_de(void *, void *);

void func_80203AD8_de(void *arg0, void *arg1) {
    if (func_802034A4_de(arg0) != 0) {
        func_80214178_de(arg0, arg1, 0x3F);
    }
}

void func_80203B1C_de(void *arg0, void *arg1) {
    if (func_802034A4_de(arg0) == 0) {
        func_80214178_de(arg0, arg1, 0x3E);
    }
}

void func_80203B60_de(void *arg0, void *arg1) {
    LevelActor *o0 = arg0;
    ActorMotionState *o1 = arg1;
    ActorMotionDefinition *tmp;
    s32 masked;
    Shared_World *pFlag;

    tmp = &((ActorMotionResource *)o0->definition)->motion;
    func_802170A0_de(arg0, arg1, 4, tmp->eventMask, tmp->secondaryEventMask);
    pFlag = &D_8011FE88;
    o1->event = 0;
    func_80285DB0_de(pFlag, arg0, 1);
    func_80278D78_de(arg0, 1, arg0);
    masked = o0->flags & 0xFFFEFFFF;
    o0->flags = masked;
    if (pFlag->mode != 4) {
        o0->flags = masked | 0x08000000;
    }
}

void func_80203C08_de(LevelActor *arg0, ActorMotionState *arg1) {
    if ((arg1->actionPending != 0) && (arg0->flags & 0x80000)) {
        func_80262C88_de();
    }
}

void func_80203C40_de(Shared_Actor *arg0) {
    if (func_80285F58_de(&D_8011FE88, arg0) == 0) {
        arg0->weaponFlags |= 0x2100;
    }
}
