#include "COMMON/EXTERNS_15.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJ.H"
#include "COMMON/REC.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4.H"

extern s32 Turret_TrackTarget(void *arg0);


extern s32 func_802170A0_de(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_80285DB0_de(Shared_World *, void *, s32);

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

s32 func_80262C88_de(void *);

extern s32 func_80285F58_de(void *, void *);

void Turret_Code_IDLE(void *arg0, void *arg1) {
    if (Turret_TrackTarget(arg0) != 0) {
        func_80214178_de(arg0, arg1, 0x3F);
    }
}

void Turret_Code_FIRE(void *arg0, void *arg1) {
    if (Turret_TrackTarget(arg0) == 0) {
        func_80214178_de(arg0, arg1, 0x3E);
    }
}

void Turret_Setup_DEATH(void *arg0, void *arg1) {
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

void Turret_Code_DEATH(LevelActor *arg0, ActorMotionState *arg1) {
    if ((arg1->actionPending != 0) && (arg0->flags & 0x80000)) {
        func_80262C88_de(arg0);
    }
}

void Turret_LinkEffect_MakeVisible(Shared_Actor *arg0) {
    if (func_80285F58_de(&D_8011FE88, arg0) == 0) {
        arg0->weaponFlags |= 0x2100;
    }
}
