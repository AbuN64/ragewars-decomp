#include "COMMON/REC.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_VOIDCALLBACK.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "RENDER/80206258.H"
#include "WEAPONS/80213ED4.H"

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

extern void func_80285DB0_de(Shared_World *a, void *b, int c);

/* Spawns effect kind at an actor's position through func_8028FFD0_de in D_80131600's list: kind 0xBD7
   is skipped while both of D_801468A0's flags at 0x78 and 0x80 are set, and kind 0x1388 is offset by
   the variant byte at D_800E4680 when option D_801462D5 is 1 (skipped for variant 0); a spawned node
   has its word at 0x1A0 cleared, takes one charge from the owner and starts effect 0x11D at its own
   position through func_80216288_de. */







extern char D_80131600;


extern u8 D_801462D5;

extern u8 *D_800E4680;

extern SpawnDispatchActor *func_8028FFD0_de(char *, void *, s32, CVector3, Triple, s32, f32);

extern char D_80131150;

extern s32 func_80262CE0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, Triple arg5, f32 arg6, CVector3 arg7,
                         Triple arg8, void *arg9);

extern char D_8011D8D0;

#include "particle/8027A0F4_8.H"

extern char D_80145040;

struct Context;
extern void *func_8022A8F0_de(struct Context *arg0);

extern void func_8024B6A0_de(void *a, s32 c, s32 flag);

extern void func_802472F0_de(void *arg0);

extern s32 func_80245B0C_de(void);

extern s32 D_00206724;

extern s32 D_0020694C;

extern s32 D_800C85F0_de;

extern func_80206604_G1 D_801462E5;


extern s32 func_80285F58_de(void *, void *);

void func_80206258_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 1);
}

void func_80206288_de(void *arg0) {
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_802062B0_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, arg0->owner, arg0->actor, 0);
}

void func_802062E0_de(LevelActor *actor, ActorMotionState *owner, Params params, s32 kind) {
    SpawnDispatchActor *node;
    CGameStatus *settings;

    if (kind == 0xBD7) {
        settings = &D_801462C8.counters;
        if (settings->m_bCTFOn != 0 && settings->m_CTFPlayerWithFlag != 0) {
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

void func_802063EC_de(LevelActor *arg0, ActorMotionState *arg1, Triple arg2, Triple arg3,
                   s32 arg4, s32 arg5, s32 arg6) {
    if (func_80262CE0_de(&D_80131150, arg5, 0, arg6,
                      arg4, arg2,
                      arg0->yaw,
                      arg0->position1, arg3,
                      &arg1->unk124) != 0) {
        arg1->unk128 -= 1;
    }
}

void func_802064A0_de(void *arg0, ActorMotionState *arg1, Triple arg2,
                   s32 unused5, s32 arg6) {
    s32 result;

    result = func_802800C0_de((struct EffectSystem *)&D_8011D8D0, (struct EffectActor *)arg0, (struct EffectActor *)arg0,
                           (s32 *)&arg1->unk124, 0, arg6,
                           ((LevelActor *)arg0)->position1,
                           ((LevelActor *)arg0)->rotation,
                           *(CVector3 *)&arg2, 0, -1, 0);
    arg1->unk128 -= result;
}

s32 func_8020655C_de(s32 arg0) {
    SpawnDispatchActor *node;

    if (arg0 == 0x84F) {
        node = D_80137064.head;
        while (node != 0) {
            if (*node->definition == 4) {
                return 0;
            }
            node = node->next;
        }
        return func_8022A8F0_de(&D_80145040) == 0;
    }
    return 1;
}

void func_802065C0_de(void *a, ActorMotionState *b, s32 c) {
    b->action = -1;
    b->actionPending = 0;
    b->unk124 = c;
    func_8024B6A0_de(a, c, 1);
    func_802472F0_de(a);
}

void func_80206604_de(LevelActor *arg0, ActorMotionState *arg1) {
    s32 flags;
    s32 flags2;

    arg1->table = &D_800C85F0_de;
    arg1->update = &D_00206724;
    flags = arg0->flags;
    flags |= 0x01000000;
    flags |= 0x02000000;
    flags2 = flags | 0x20000;
    arg0->flags = flags2;
    if (D_801462E5.unk0 == 0) {
        arg0->flags = flags2 | 0x10000000;
    }
    if ((arg0->type == 0x453) && (func_80245B0C_de() == 0x6F)) {
        arg1->secondaryUpdate = &D_0020694C;
    }
}

void func_802066A4_de(LevelActor *arg0, Dest *arg1) {
    arg1->field124 = ((ActorHealthDefinition *)arg0->definition)->health;
    func_80214178_de(arg0, arg1, 0);
    arg1->charge = D_800C1AE0_de;
    arg1->field12C = D_800C1AE0_de;
    if (func_80285F58_de(&D_8011FE88, arg0) == 1) {
        arg0->flags &= ~0x2000;
        arg0->flags &= ~0x100;
    }
}

void func_80206724_de(void *arg0, Shared_CallbackOwner *arg1) {
    Shared_CallbackHook *obj = arg1->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            fn();
        }
    }
}

int func_80206758_de(void *arg0, Dest *arg1) {
    return arg1->field124;
}

void func_80206764_de(void) {
}
