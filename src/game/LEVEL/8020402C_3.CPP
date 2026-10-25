#include "include_asm.h"
#include "COMMON/OBJRECAT30.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_VOIDCALLBACK.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/REC.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "LEVEL/8020402C_3.H"
#include "WEAPONS/80213ED4.H"

extern f32 D_800C6B74;
extern void func_80285DB0_de(Shared_World *, void *, s32);
extern void func_80267198_de(void *, void *, s32, CVector3, ResourceManagerState);
typedef struct BreakableContactRule {
    u32 flags;
    f32 limit;
    s8 damageFactor;
} BreakableContactRule;

typedef struct BreakableContactState {
    u8 pad0[0x40];
    f32 elapsed;
    u8 pad44[0x20];
    f32 limit;
    u8 pad68[0x62];
    s8 team;
    s8 active;
} BreakableContactState;

/* Apply the descriptor hit rule, then update the contact response timer. */
void Level_UpdateBreakableHit(BreakableHitContext *ctx, BreakableContactState *hit) {
    BreakableContactRule *rule = (BreakableContactRule *)(ctx->unk_18 + 0x14);
    ResourceManagerState eventState;
    f32 damageScale;
    s32 triggerResponse;
    s8 team;
    if (rule->damageFactor != -1) {
        damageScale = rule->damageFactor * (1.0f / 127.0f);
        if (ctx->unk_E6 == 1) {
            triggerResponse = 1;
        } else {
            team = hit->team;
            if (ctx->unk_108 != team || ctx->unk_10A != team) {
                triggerResponse = 0;
            } else if (hit->active != 0 && !(ctx->unk_100 & 0x400)) {
                triggerResponse = 1;
            } else {
                if (ctx->unk_10C < 3 && (ctx->unk_100 & 0x400)) {
                    triggerResponse = ctx->unk_12C * damageScale <= ctx->unk_134;
                } else {
                    triggerResponse = ctx->unk_10C * damageScale <= ctx->unk_104;
                }
            }
        }
        if (triggerResponse) {
            eventState.active = 0;
            func_80267198_de(ctx, ctx, 6, ctx->unk_8, eventState);
            func_80285DB0_de(&D_8011FE88, ctx, 1);
        }
    }
    if ((rule->flags & 1) && hit->active != 0) {
        f32 timeLimit = rule->limit;
        if (timeLimit == 0.0f || hit->limit < timeLimit) {
            if (hit->limit == 0.0f) {
                hit->elapsed = 0.0f;
            }
            hit->limit = timeLimit;
        }
    }
    if (hit->limit != 0.0f && hit->limit <= hit->elapsed) {
        Weapons_RequestActorState(ctx, (ObjectStateCC *)hit, 1);
    }
}

/* Destroys a breakable object after a hit: when its descriptor has a damage factor at 0x1D, scaled
   by D_800C6B74, and the object is forced at 0xE6, or the hit's team byte at 0xCA matches both ids at
   0x108 and 0x10A and either the hit at 0xCB bypasses an object without flag 0x400 or the scaled count
   reaches its limit (the count at 0x12C against 0x134 while flagged 0x400 below three hits at 0x10C,
   otherwise the hits against 0x104), it raises event 7 at its position through func_80267198_de and
   releases it through func_80285DB0_de. Written from its own assembly with the destroy decision as an
   if/else chain on a byte-sized damage factor. */







extern void func_80267198_de(void *, void *, s32, CVector3, ResourceManagerState);

extern void func_80285DB0_de(Shared_World *, void *, s32);

extern s32 func_80285F58_de(void *, void *);


extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

extern void func_80285DB0_de(Shared_World *arg0, void *arg1, s32 arg2);

extern void func_80267198_de(void *arg0, void *arg1, s32 arg2,
                          CVector3 arg3, ResourceManagerState arg4);

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

void func_80204A68_de(void *breakableHitContext, ObjectStateCC *arg1) {
    ResourceManagerState local;
    s8 factor;
    f32 scale;
    s32 destroy;
    s8 team;

    factor = ((struct ObjectState1E *) ((BreakableHitContext *) breakableHitContext)->unk_18)->unk_1D;
    if (factor == -1) {
        return;
    }
    scale = factor * D_800C6B74;
    if (((BreakableHitContext *)(breakableHitContext))->unk_E6 == 1) {
        destroy = 1;
    } else {
        team = arg1->unk_CA;
        if (((BreakableHitContext *)(breakableHitContext))->unk_108 != team || ((BreakableHitContext *)(breakableHitContext))->unk_10A != team) {
            destroy = 0;
        } else if (arg1->unk_CB != 0 && !(((BreakableHitContext *)(breakableHitContext))->unk_100 & 0x400)) {
            destroy = 1;
        } else if (((BreakableHitContext *)(breakableHitContext))->unk_10C < 3 && (((BreakableHitContext *)(breakableHitContext))->unk_100 & 0x400)) {
            destroy = ((BreakableHitContext *)(breakableHitContext))->unk_12C * scale <= ((BreakableHitContext *)(breakableHitContext))->unk_134;
        } else {
            destroy = ((BreakableHitContext *)(breakableHitContext))->unk_10C * scale <= ((BreakableHitContext *)(breakableHitContext))->unk_104;
        }
    }
    if (destroy) {
        local.active = 0;
        func_80267198_de(breakableHitContext, breakableHitContext, 7, ((BreakableHitContext *)(breakableHitContext))->unk_8, local);
        func_80285DB0_de(&D_8011FE88, breakableHitContext, 0);
    }
}

void func_80204BB4_de(void *unused0, Dest *arg1) {
    arg1->table = &D_800C8380_de;
    arg1->enter = &D_00204C34;
}

void func_80204BD0_de(void *arg0, void *arg1) {
    s32 different = func_80285F58_de(&D_8011FE88, arg0) != 1;

    if (different == 0) {
        Weapons_RequestActorState(arg0, arg1, 0);
    } else {
        Weapons_RequestActorState(arg0, arg1, 1);
    }
}

void func_80204C34_de(void *arg0, Shared_CallbackOwner *callbackOwner) {
    Shared_CallbackHook *obj = callbackOwner->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            fn();
        }
    }
}

extern void func_802A5D38_de(SceneRecAt95A8 *, s32);
void func_80204C68_de(void *arg0, ActorMotionState *motionState) {
    ResourceManagerState local;
    Shared_World *flag;

    local.active = 0;
    flag = &D_8011FE88;
    func_80285DB0_de(flag, arg0, 1);
    func_80278D78_de(arg0, 0x4000, arg0);
    motionState->speed = 0;
    func_802A5D38_de(&D_801379C0, (s32)arg0);
    if (flag->mode != 4) {
        func_80267198_de(arg0, arg0, 6,
                      ((LevelActor *)arg0)->position0, local);
        ((LevelActor *)arg0)->flags |= 0x08000000;
    }
}

void func_80204D2C_de(BreakableHitContext *breakableHitContext) {
    ResourceManagerState local;
    Shared_World *flag;

    local.active = 0;
    flag = &D_8011FE88;
    func_80285DB0_de(flag, breakableHitContext, 0);
    func_80278D78_de(breakableHitContext, 0x8000, breakableHitContext);
    func_802A5D38_de(&D_801379C0, (s32)breakableHitContext);
    if (flag->mode != 4) {
        func_80267198_de(breakableHitContext, breakableHitContext, 7,
                      breakableHitContext->unk_8, local);
        breakableHitContext->unk_100 |= 0x08000000;
    }
}

void func_80204DE0_de(void *a, void *b) {
    Weapons_RequestActorState(a, b, 0x0); }

void func_80204DFC_de(Trigger *trigger) {
    func_8028B670_de(&D_8011FE88, trigger->owner, trigger->actor, 1);
}

void func_80204E2C_de(void *a, void *b) {
    Weapons_RequestActorState(a, b, 0x1); }

void func_80204E48_de(Trigger *trigger) {
    func_8028B670_de(&D_8011FE88, trigger->owner, trigger->actor, 0);
}
