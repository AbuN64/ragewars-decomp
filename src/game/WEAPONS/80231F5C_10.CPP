#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "TYPES.H"
extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);
extern s32 func_802301F4_de(void *, void *);
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "RENDER_2/8022AE90_2.H"
#include "WEAPONS/80231F5C_10.H"
#include "WEAPONS/80213ED4.H"


s32 Items_ReleaseObjectHandles(s32);


extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);



void func_80232B64_de(LevelActor *actor, WeaponFireState *fireState) {
    void *controller;

    controller = actor->controller;
    ((Shared_ActorView *)controller)->controllerMode = 1;
    ((Shared_ActorView *)controller)->controllerOwner = 0;
    ((Player *)controller)->controllerTimer = 0;
    fireState->spinStep = 0;
    fireState->spin = 0;
    if ((fireState->triggerMode != 0) && (func_802301F4_de(actor, fireState) == 0)) {
        Weapons_RequestActorState(actor, fireState, 2);
    }
}

s32 func_80232BD0_de(LevelActor *actor, void *arg1, Shared_ActorView *arg2) {
    s32 temp_v0;
    void *owner;

    {
        f32 field = arg2->stun;
        if (D_800C301C_de < field) {
            return 1;
        }
    }
    if ((actor->flags & 0x300000) && (arg2->remote != 0)) {
        owner = arg2->owner;
        temp_v0 = ((LevelActor *)owner)->actionReady;
        ((LevelActor *)owner)->actionReady = 0;
        return temp_v0 == 0;
    }
    if (arg2->actionFlags & 0x2000) {
        if (arg2->actionState != 0) {
            return 1;
        }
        return Weapons_HasAmmoForMode(arg2, arg2->selectedAction) == 0;
    }
    return 1;
}

void func_80232C68_de(void *arg0) {
    Items_ReleaseObjectHandles((((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link));
}

void func_80232C88_de(Shared_ActorView *arg0, WeaponFireState *fireState) {
    void *temp_a0;
    s16 idx;

    temp_a0 = arg0->self;
    idx = ((Shared_ActorView *)temp_a0)->selectedAction;
    fireState->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3020_de;
    if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) && (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}

void func_80232CEC_de(void *actor, void *attack) {
    Player *state;

    state = ((Shared_Actor *)actor)->entity;
    if (((WeaponFireState *)attack)->triggerMode != 0) {
        if (func_802301F4_de(actor, attack) != 0) {
            ((WeaponFireState *)attack)->triggerMode = 0;
            ((WeaponFireState *)attack)->queuedAction = -1;
        } else {
            switch (state->selectedAction) {
            case 8:
                Render_PlaySoundAtPosition(0xA3E, state->pos,
                              (s32)&state->pos, -1);
            case 0:
            case 14:
                func_8022B00C_de(state);
                Weapons_RequestActorState(actor, attack, 2);
                break;
            default:
                Weapons_RequestActorState(actor, attack, 2);
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
