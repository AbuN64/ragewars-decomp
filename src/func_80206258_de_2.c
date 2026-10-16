#include "span_1000/code_80206258.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_80279208.h"
#include "types.h"

extern void func_802065C0_de(void *a, ActorMotionState *b, unsigned short c);

extern void func_8028B670_de(void *a, unsigned short b, unsigned short c, int d);

extern int func_80245798_de(void);

/** For each of the object's child slots, attach the child to the record and spawn its effect. */
extern int D_800D297C;

extern void *func_8024BFD4_de(void *, int);

extern void func_8024AA18_de(char *obj, s32 unused, char *info);

extern void func_8026DA4C_de(void *, int, int, void *, int, int);

void func_8020676C_de(void *arg0, void *arg1, Trigger *arg2) {
    extern void func_80285DB0_de(Shared_World *a, void *b, int c);
    extern void func_802472F0_de(void *arg0);
    func_802065C0_de(arg0, arg1, (u16)arg2->unk4);
    ((LevelActor *)arg0)->flags = ((LevelActor *)arg0)->flags | 0x2100;
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_802067BC_de(Shared_Actor *arg0) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    s32 v = arg0->weaponFlags;
    v &= ~0x2000;
    v &= ~0x100;
    arg0->weaponFlags = v;
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}

void func_802067FC_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)arg0->unk8, (u32)arg0->unk4 >> 16, 1);
}

void func_8020682C_de(Shared_Actor *arg0, s32 *arg1) {
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    extern void func_802472F0_de(Shared_Actor *arg0);
    arg0->weaponFlags |= 0x2100;
    if (func_80245798_de() != 0) {
        *arg1 |= 0x200;
    }
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_80206898_de(Trigger *arg0) {
    func_8028B670_de(&D_8011FE88, (u16)arg0->unk8, (u32)arg0->unk4 >> 16, 0);
}

void func_802068C8_de(struct Shared_Actor *arg0, s32 arg1, s32 arg2) {
    extern void func_80402FB4_de(s32, s32);
    extern void func_80285DB0_de(Shared_World *, void *, s32);
    func_80402FB4_de(arg0, arg2);
    arg0->weaponFlags |= 0x2100;
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

void func_80206910_de(s32 arg0) {
    s32 func_80402FB4_de(s32, s32);
    func_80402FB4_de(0, arg0);
}

/** Copy the source byte at offset 7 into two fields under object offset 0x18. */
void func_80206930_de(LevelActor *arg0, int arg1, Trigger *arg2) {
    void *inner = arg0->definition;
    ((ActorDefinitionHeader *)inner)->first = (s8)arg2->unk4;
    inner = arg0->definition;
    ((ActorDefinitionHeader *)inner)->second = (s8)arg2->unk4;
}

void func_8020694C_de(char *arg0, void *arg1, Rec *arg2) {
    int i;
    int n;
    void *child;

    n = (s8)((LevelActor *)arg0)->stateE7;
    for (i = 0; i < n; i++) {
        child = func_8024BFD4_de(arg0, i);
        if (child != 0) {
            arg2->a = child;
            arg2->b = child;
            func_8024AA18_de(arg0, arg1, arg2);
            func_8026DA4C_de(child, ((LevelActor *)arg0)->fieldB4, 1, &((LevelActor *)arg0)->lighting[D_800D297C], 0, ((LevelActor *)arg0)->field3);
        }
    }
}
