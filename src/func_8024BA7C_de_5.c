#include "span_1000/code_8024BA6C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/level_actor.h"
#include "span_1000/code_802609CC.h"
#include "span_1000/code_8027302C.h"
#include "types.h"

/* Spawns the standing effects of an animation for an object: every event whose effect id is 6 or 7 is placed by transforming its local point through the object's matrix at 0x74 and spawned through func_80265E10_de with its parameters. */







extern EventRecAt14 *func_80262598_de(void *);

extern s32 func_802625C4_de(void *);

extern void func_80265E10_de(char *, char *, u16, s32, Vec3, struct IntPair);

extern char D_800C3830_de;

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern void *func_8028FDB4_de(void *arg0, s32 arg1);

extern void func_80253754_de(s32 arg0, s32 arg1);

void *func_8024C104_de(Triple *arg0, void *arg1, s32 *arg2) {
    extern void func_80272898_de(void *, void *, void *);
    extern void func_8025E5B0_de(s32 *arg0, s32 arg1, s32 arg2, f32 *arg3);
    char *o1 = (char *) arg1;
    char mtx[0x40];
    f32 spVec[3];
    f32 inVec[3];
    f32 outVec[3];

    func_8025E5B0_de(arg2, 0, *arg2, spVec);
    inVec[0] = spVec[0];
    inVec[1] = spVec[2];
    inVec[2] = spVec[1];
    func_802736D4_de(mtx, ((LevelActor *)o1)->yaw);
    func_80272898_de(mtx, inVec, outVec);
    outVec[0] *= ((LevelActor *)o1)->scale.x;
    outVec[1] *= ((LevelActor *)o1)->scale.y;
    outVec[2] *= ((LevelActor *)o1)->scale.z;
    *arg0 = *(Triple *) outVec;
    return arg0;
}

void func_8024C1C4_de(char *obj, void *anim)
{
    extern void func_80272898_de(void *matrix, Vec3 *in, Vec3 *out);
    EventRecAt14 *e;
    s32 count;
    s32 i;
    Vec3 pos;

    e = func_80262598_de(anim);
    count = func_802625C4_de(anim);
    for (i = 0; i < count; i++) {
        switch (e[i].effect) {
        case 6:
        case 7:
            func_80272898_de(obj + 0x74, &e[i].local, &pos);
            func_80265E10_de(obj, obj, e[i].effect, -1, pos, e[i].params);
        }
    }
}

s32 func_8024C294_de(LevelActor *arg0, s32 arg1) {
    void *temp_v0;
    Table *temp_v1;
    s32 temp_s0;

    if (arg0->flags & 0x40000) {
        temp_v0 = func_8025193C_de(0, arg0->resource, arg0->resource, arg0->resourceFlags, 4, 0, 0, &D_800C3830_de, 1);
        if (temp_v0 != 0) {
            temp_v1 = func_8028FDB4_de(*(void **) temp_v0, 1);
            temp_s0 = temp_v1->deltas[arg1];
            func_80253754_de(0, (s32) temp_v0);
            return temp_s0;
        }
    }
    return -1;
}

int func_8024C344_de(void) {
    return 0;
}

void func_8024C34C_de(LevelActor *arg0, s32 *arg1) {
    extern void func_80272898_de(void *arg0, void *arg1, void *arg2);
    extern void func_8025E5B0_de(s32 *, s32, f32, f32 *);
    Scratch scratch;
    f32 zero;

    zero = 0.0f;
    func_8025E5B0_de(arg1, 0, zero, scratch.first);
    func_8025E5B0_de(arg1, 0, ((AnimChannel *)arg1)->time, scratch.second);
    scratch.in[0] = scratch.second[0] - scratch.first[0];
    scratch.in[1] = zero;
    scratch.in[2] = scratch.second[1] - scratch.first[1];
    func_802736D4_de(scratch.matrix, arg0->yaw);
    func_80272898_de(scratch.matrix, scratch.in, scratch.out);
    scratch.position.x = arg0->position0.x +
                          (scratch.out[0] * arg0->scale.x);
    scratch.position.y = arg0->position0.y;
    scratch.position.z = arg0->position0.z +
                          (scratch.out[2] * arg0->scale.z);
    func_8024E79C_de(arg0, scratch.position, &arg0->position0,
                  &arg0->model, 0, 0);
}
