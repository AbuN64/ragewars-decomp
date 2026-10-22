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

#ifdef NON_MATCHING
extern BreakableHitContext D_80150000;
extern f32 D_800C6B74;
extern void func_80285DB0_de(Shared_World *, void *, s32);
extern void func_80267198_de(void *, void *, s32, CVector3, ResourceManagerState);
void func_80204868_de(void *unused, ObjectStateCC *arg1) {
    BreakableHitContext *ctx = &D_80150000;
    u8 *state = ctx->unk_18 + 0x14;
    f32 *hitFloat = (f32 *)((u8 *)arg1 + 0x40);
    f32 *hitLimit = (f32 *)((u8 *)arg1 + 0x64);
    ResourceManagerState local;
    f32 scale;
    f32 value;
    f32 limit;
    s32 destroy;
    s8 team;
    if (((s8 *)state)[8] != -1) {
        scale = ((s8 *)state)[8] * D_800C6B74;
        if (ctx->unk_E6 == 1) {
            destroy = 1;
        } else {
            team = arg1->unk_CA;
            if (ctx->unk_108 != team || ctx->unk_10A != team) {
                destroy = 0;
            } else if (arg1->unk_CB != 0 && !(ctx->unk_100 & 0x400)) {
                destroy = 1;
            } else {
                if (ctx->unk_10C < 3 && (ctx->unk_100 & 0x400)) {
                    value = ctx->unk_12C * scale;
                    limit = ctx->unk_134;
                } else {
                    value = ctx->unk_10C * scale;
                    limit = ctx->unk_104;
                }
                destroy = value <= limit;
            }
        }
        if (destroy) {
            local.active = 0;
            func_80267198_de(ctx, ctx, 6, ctx->unk_8, local);
            func_80285DB0_de(&D_8011FE88, ctx, 1);
        }
    }
    if ((*(u32 *)state & 1) && arg1->unk_CB != 0) {
        f32 flag = *(f32 *)(state + 4);
        if (flag == 0.0f || *hitLimit < flag) {
            if (*hitLimit == 0.0f) {
                *hitFloat = 0.0f;
            }
            *hitLimit = flag;
        }
    }
    if (*hitLimit != 0.0f && *hitLimit <= *hitFloat) {
        func_80214178_de(ctx, arg1, 1);
    }
}
#else
INCLUDE_ASM("span_1000", func_80204868_de);
#endif

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

void func_80204A68_de(void *arg0, ObjectStateCC *arg1) {
    ResourceManagerState local;
    s8 factor;
    f32 scale;
    s32 destroy;
    s8 team;

    factor = ((struct ObjectState1E *) ((BreakableHitContext *) arg0)->unk_18)->unk_1D;
    if (factor == -1) {
        return;
    }
    scale = factor * D_800C6B74;
    if (((BreakableHitContext *)(arg0))->unk_E6 == 1) {
        destroy = 1;
    } else {
        team = arg1->unk_CA;
        if (((BreakableHitContext *)(arg0))->unk_108 != team || ((BreakableHitContext *)(arg0))->unk_10A != team) {
            destroy = 0;
        } else if (arg1->unk_CB != 0 && !(((BreakableHitContext *)(arg0))->unk_100 & 0x400)) {
            destroy = 1;
        } else if (((BreakableHitContext *)(arg0))->unk_10C < 3 && (((BreakableHitContext *)(arg0))->unk_100 & 0x400)) {
            destroy = ((BreakableHitContext *)(arg0))->unk_12C * scale <= ((BreakableHitContext *)(arg0))->unk_134;
        } else {
            destroy = ((BreakableHitContext *)(arg0))->unk_10C * scale <= ((BreakableHitContext *)(arg0))->unk_104;
        }
    }
    if (destroy) {
        local.active = 0;
        func_80267198_de(arg0, arg0, 7, ((BreakableHitContext *)(arg0))->unk_8, local);
        func_80285DB0_de(&D_8011FE88, arg0, 0);
    }
}

void func_80204BB4_de(void *arg0, Dest *arg1) {
    arg1->table = &D_800C8380_de;
    arg1->enter = &D_00204C34;
}

void func_80204BD0_de(void *arg0, void *arg1) {
    s32 different = func_80285F58_de(&D_8011FE88, arg0) != 1;

    if (different == 0) {
        func_80214178_de(arg0, arg1, 0);
    } else {
        func_80214178_de(arg0, arg1, 1);
    }
}

void func_80204C34_de(void *arg0, Shared_CallbackOwner *arg1) {
    Shared_CallbackHook *obj = arg1->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            fn();
        }
    }
}

extern void func_802A5D38_de(SceneRecAt95A8 *, s32);
void func_80204C68_de(void *arg0, ActorMotionState *arg1) {
    ResourceManagerState local;
    Shared_World *flag;

    local.active = 0;
    flag = &D_8011FE88;
    func_80285DB0_de(flag, arg0, 1);
    func_80278D78_de(arg0, 0x4000, arg0);
    arg1->speed = 0;
    func_802A5D38_de(&D_801379C0, (s32)arg0);
    if (flag->mode != 4) {
        func_80267198_de(arg0, arg0, 6,
                      ((LevelActor *)arg0)->position0, local);
        ((LevelActor *)arg0)->flags |= 0x08000000;
    }
}

void func_80204D2C_de(BreakableHitContext *arg0) {
    ResourceManagerState local;
    Shared_World *flag;

    local.active = 0;
    flag = &D_8011FE88;
    func_80285DB0_de(flag, arg0, 0);
    func_80278D78_de(arg0, 0x8000, arg0);
    func_802A5D38_de(&D_801379C0, (s32)arg0);
    if (flag->mode != 4) {
        func_80267198_de(arg0, arg0, 7,
                      arg0->unk_8, local);
        arg0->unk_100 |= 0x08000000;
    }
}

void func_80204DE0_de(void *a, void *b) {
    func_80214178_de(a, b, 0x0); }

void func_80204DFC_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 1);
}

void func_80204E2C_de(void *a, void *b) {
    func_80214178_de(a, b, 0x1); }

void func_80204E48_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 0);
}
