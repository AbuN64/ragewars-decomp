#include "span_1000/code_80206258.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "shared/func_80206724_de_closed.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80204E78.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_80279208.h"
#include "types.h"

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

extern void func_80285DB0_de(void *a, void *b, int c);

/* Spawns effect kind at an actor's position through func_8028FFD0_de in D_80131600's list: kind 0xBD7
   is skipped while both of D_801468A0's flags at 0x78 and 0x80 are set, and kind 0x1388 is offset by
   the variant byte at D_800E4680 when option D_801462D5 is 1 (skipped for variant 0); a spawned node
   has its word at 0x1A0 cleared, takes one charge from the owner and starts effect 0x11D at its own
   position through func_80216288_de. */







extern char D_80131600;

extern Settings D_801468A0;

extern u8 D_801462D5;

extern u8 *D_800E4680;

extern SpawnDispatchActor *func_8028FFD0_de(char *, void *, s32, Vec3, Triple, s32, f32);

extern char D_80131150;

extern s32 func_80262CE0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, Triple arg5, f32 arg6, Vec3 arg7,
                         Triple arg8, void *arg9);

extern char D_8011D8D0;

extern s32 func_802800C0_de(void *, void *, void *, void *, s32, s32,
                         Vec3, Vector4f, Triple, s32, s32, s32);

extern char D_80145040;

extern void *func_8022A8F0_de(void *arg0);

extern void func_8024B6A0_de(void *a, s32 c, s32 flag);

extern void func_802472F0_de(void *arg0);

extern s32 func_80245B0C_de(void);

extern s32 D_00206724;

extern s32 D_0020694C;

extern s32 D_800C85F0_de;

extern func_80206604_G1 D_801462E5;

extern s32 func_80214178_de(void *, void *, s32);

extern s32 func_80285F58_de(void *, void *);

void func_80206258_de(void *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)((Trigger *)arg0)->unk8, (u32)((Trigger *)arg0)->unk4 >> 16, 1);
}

void func_80206288_de(void *arg0) {
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_802062B0_de(void *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)((Trigger *)arg0)->unk8, (u32)((Trigger *)arg0)->unk4 >> 16, 0);
}

void func_802062E0_de(LevelActor *actor, ActorMotionState *owner, Params params, s32 kind) {
    SpawnDispatchActor *node;
    Settings *settings;

    if (kind == 0xBD7) {
        settings = &D_801468A0;
        if (settings->flag78 != 0 && settings->flag80 != 0) {
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

void func_802063EC_de(void *arg0, void *arg1, Triple arg2, Triple arg3,
                   s32 arg4, s32 arg5, s32 arg6) {
    if (func_80262CE0_de(&D_80131150, arg5, 0, arg6,
                      arg4, arg2,
                      ((LevelActor *)arg0)->yaw,
                      ((LevelActor *)arg0)->position1, arg3,
                      &((ActorMotionState *)arg1)->unk124) != 0) {
        ((ActorMotionState *)arg1)->unk128 -= 1;
    }
}

void func_802064A0_de(void *arg0, void *arg1, Triple arg2,
                   s32 unused5, s32 arg6) {
    s32 result;

    result = func_802800C0_de(&D_8011D8D0, arg0, arg0,
                           &((ActorMotionState *)arg1)->unk124, 0, arg6,
                           ((LevelActor *)arg0)->position1,
                           ((LevelActor *)arg0)->rotation,
                           arg2, 0, -1, 0);
    ((ActorMotionState *)arg1)->unk128 -= result;
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

void func_802065C0_de(void *a, void *b, s32 c) {
    ((ActorMotionState *)b)->action = -1;
    ((ActorMotionState *)b)->actionPending = 0;
    ((ActorMotionState *)b)->unk124 = c;
    func_8024B6A0_de(a, c, 1);
    func_802472F0_de(a);
}

void func_80206604_de(void *arg0, void *arg1) {
    s32 flags;
    s32 flags2;

    ((ActorMotionState *)arg1)->table = &D_800C85F0_de;
    ((ActorMotionState *)arg1)->update = &D_00206724;
    flags = ((LevelActor *)arg0)->flags;
    flags |= 0x01000000;
    flags |= 0x02000000;
    flags2 = flags | 0x20000;
    ((LevelActor *)arg0)->flags = flags2;
    if (D_801462E5.unk0 == 0) {
        ((LevelActor *)arg0)->flags = flags2 | 0x10000000;
    }
    if ((((LevelActor *)arg0)->type == 0x453) && (func_80245B0C_de() == 0x6F)) {
        ((ActorMotionState *)arg1)->secondaryUpdate = &D_0020694C;
    }
}

void func_802066A4_de(void *arg0, void *arg1) {
    ((Dest *)arg1)->field124 = ((ActorHealthDefinition *)((LevelActor *)arg0)->definition)->health;
    func_80214178_de(arg0, arg1, 0);
    ((Dest *)arg1)->charge = D_800C1AE0_de;
    ((Dest *)arg1)->field12C = D_800C1AE0_de;
    if (func_80285F58_de(&D_8011FE88, arg0) == 1) {
        ((LevelActor *)arg0)->flags &= ~0x2000;
        ((LevelActor *)arg0)->flags &= ~0x100;
    }
}

void func_80206724_de(void *arg0, void *arg1) {
    Shared_CallbackHook *obj = ((Shared_CallbackOwner *)arg1)->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            fn();
        }
    }
}

int func_80206758_de(void *arg0, void *arg1) {
    return ((Dest *)arg1)->field124;
}

void func_80206764_de(void) {
}
