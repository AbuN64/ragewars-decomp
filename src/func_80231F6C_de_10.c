#include "span_1000/code_80231F5C.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "types.h"
#include "span_1000/code_80204E78.h"
#include "span_1000/code_8022E938.h"

extern s32 func_80214178_de(void *, void *, s32);

s32 func_8044A07C_de(s32);


extern void func_8022AF74_de(void *arg0, s32 arg1);



void func_80232B64_de(void *arg0, void *arg1) {
    extern s32 func_802301F4_de(void);
    void *temp_v0;

    temp_v0 = ((LevelActor *)arg0)->controller;
    ((Shared_ActorView *)temp_v0)->controllerMode = 1;
    ((Shared_ActorView *)temp_v0)->controllerOwner = 0;
    ((Player *)temp_v0)->controllerTimer = 0;
    ((WeaponFireState *)arg1)->spinStep = 0;
    ((WeaponFireState *)arg1)->spin = 0;
    if ((((WeaponFireState *)arg1)->triggerMode != 0) && (func_802301F4_de() == 0)) {
        func_80214178_de(arg0, arg1, 2);
    }
}

s32 func_80232BD0_de(void *arg0, void *arg1, void *arg2) {
    s32 temp_v0;
    void *temp_v1;

    {
        f32 field = ((Shared_ActorView *)arg2)->stun;
        if (D_800C301C_de < field) {
            return 1;
        }
    }
    if ((((LevelActor *)arg0)->flags & 0x300000) && (((Shared_ActorView *)arg2)->remote != 0)) {
        temp_v1 = ((Shared_ActorView *)arg2)->owner;
        temp_v0 = ((LevelActor *)temp_v1)->actionReady;
        ((LevelActor *)temp_v1)->actionReady = 0;
        return temp_v0 == 0;
    }
    if (((Shared_ActorView *)arg2)->actionFlags & 0x2000) {
        if (((Shared_ActorView *)arg2)->actionState != 0) {
            return 1;
        }
        return func_80222AA4_de(arg2, ((Shared_ActorView *)arg2)->selectedAction) == 0;
    }
    return 1;
}

void func_80232C68_de(void *arg0) {
    func_8044A07C_de((((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link));
}

void func_80232C88_de(void *arg0, void *arg1) {
    void *temp_a0;
    s16 idx;

    temp_a0 = ((Shared_ActorView *)arg0)->self;
    idx = ((Shared_ActorView *)temp_a0)->selectedAction;
    ((WeaponFireState *)arg1)->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3020_de;
    if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) && (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}

void func_80232CEC_de(void *arg0, void *arg1) {
    extern s32 func_802301F4_de(void *, void *);
    Player *state;

    state = ((Shared_Actor *)arg0)->entity;
    if (((WeaponFireState *)arg1)->triggerMode != 0) {
        if (func_802301F4_de(arg0, arg1) != 0) {
            ((WeaponFireState *)arg1)->triggerMode = 0;
            ((WeaponFireState *)arg1)->queuedAction = -1;
        } else {
            switch (state->selectedAction) {
            case 8:
                func_8025DE54_de(0xA3E, state->pos,
                              (s32)&state->pos, -1);
            case 0:
            case 14:
                func_8022B00C_de(state);
                func_80214178_de(arg0, arg1, 2);
                break;
            default:
                func_80214178_de(arg0, arg1, 2);
                break;
            }
        }
        state->controllerMode = 1;
        state->controllerTimer = 0;
    } else if ((state->selectedAction == 12) &&
               ((state->inputFlags & 0x4000) != 0)) {
        func_8022B190_de((s32)state);
    }
}
