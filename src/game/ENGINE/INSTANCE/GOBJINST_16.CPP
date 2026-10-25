#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/LOCALDECODERANGE.H"
#include "COMMON/MTX.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_16.H"
#include "GAME/CODE_8027302C.H"
#include "SCENE/802508E0_4.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"

/* Spawns the standing effects of an animation for an object: every event whose effect id is 6 or 7 is placed by transforming its local point through the object's matrix at 0x74 and spawned through func_80265E10_de with its parameters. */







extern CROMEventEntry *func_80262598_de(void *);


extern void System_DeliverContactEffect(char *, char *, u16, s32, CVector3, struct IntPair);




extern void Scene_UnlockResource(s32 arg0, s32 arg1);
extern void System_SampleVectorTrack(AnimChannel *, s32, f32, f32 *);

void *func_8024C104_de(Triple *arg0, void *arg1, AnimChannel *anim) {
    char *o1 = (char *) arg1;
    char mtx[0x40];
    f32 spVec[3];
    f32 inVec[3];
    f32 outVec[3];

    System_SampleVectorTrack(anim, 0, anim->time, spVec);
    inVec[0] = spVec[0];
    inVec[1] = spVec[2];
    inVec[2] = spVec[1];
    BuildYawMatrix(mtx, ((LevelActor *)o1)->yaw);
    Particle_TransformPoint(mtx, inVec, outVec);
    outVec[0] *= ((LevelActor *)o1)->scale.x;
    outVec[1] *= ((LevelActor *)o1)->scale.y;
    outVec[2] *= ((LevelActor *)o1)->scale.z;
    *arg0 = *(Triple *) outVec;
    return arg0;
}

void func_8024C1C4_de(char *obj, void *anim)
{
    CROMEventEntry *e;
    s32 count;
    s32 i;
    CVector3 pos;

    e = func_80262598_de(anim);
    count = func_802625C4_de(anim);
    for (i = 0; i < count; i++) {
        switch (e[i].effect) {
        case 6:
        case 7:
            Particle_TransformPoint(obj + 0x74, &e[i].local, &pos);
            System_DeliverContactEffect(obj, obj, e[i].effect, -1, pos, e[i].params);
        }
    }
}

s32 func_8024C294_de(LevelActor *actor, s32 arg1) {
    void *temp_v0;
    Table *temp_v1;
    s32 temp_s0;

    if (actor->flags & 0x40000) {
        temp_v0 = Scene_RequestResource(0, actor->resource, actor->resource, actor->resourceFlags, 4, 0, 0, &D_800C3830_de, 1);
        if (temp_v0 != 0) {
            temp_v1 = Render_GetPackSection(*(void **) temp_v0, 1);
            temp_s0 = temp_v1->deltas[arg1];
            Scene_UnlockResource(0, (s32) temp_v0);
            return temp_s0;
        }
    }
    return -1;
}

int func_8024C344_de(void) {
    return 0;
}

void func_8024C34C_de(LevelActor *actor, AnimChannel *arg1) {
    Scratch scratch;
    f32 zero;

    zero = 0.0f;
    System_SampleVectorTrack(arg1, 0, zero, scratch.first);
    System_SampleVectorTrack(arg1, 0, arg1->time, scratch.second);
    scratch.in[0] = scratch.second[0] - scratch.first[0];
    scratch.in[1] = zero;
    scratch.in[2] = scratch.second[1] - scratch.first[1];
    BuildYawMatrix(scratch.matrix, actor->yaw);
    Particle_TransformPoint(scratch.matrix, scratch.in, scratch.out);
    scratch.position.x = actor->position0.x +
                          (scratch.out[0] * actor->scale.x);
    scratch.position.y = actor->position0.y;
    scratch.position.z = actor->position0.z +
                          (scratch.out[2] * actor->scale.z);
    func_8024E79C_de(actor, scratch.position, &actor->position0,
                  &actor->model, 0, 0);
}
