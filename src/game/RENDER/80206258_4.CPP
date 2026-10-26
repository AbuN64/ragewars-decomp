#include "COMMON/REC.H"
#include "RENDER/80206258.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "RENDER/80206258_4.H"

extern void BuildRollMatrix(void *arg0, f32 arg1);

extern void PitchMatrix(void *arg0, f32 arg1);

extern void YawMatrix(void *arg0, f32 arg1);

extern void CopyMatrix(float *arg0, float *arg1);

extern void ScaleMatrixLocal(void *arg0, f32 sx, f32 sy, f32 sz);

extern s32 Particle_LimitVectorLength(f32 *arg0, f32 arg1);

extern void TranslateMatrix(f32 *, f32, f32, f32);

extern void SwapMatrixUpForward(void *);

s32 Render_TestActorStateBit(void *, void *);

void Render_UpdateTriggeredMotion(Player *mover, ActorMotionState *rider);

void func_80206DD4_de(Actor_func_80206DD4_de *, RiderCode80206258 *);

void Render_BuildPlayerMatrix(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    f32 orientationMatrix[16];
    f32 *matrix;

    BuildRollMatrix(orientationMatrix, motionState->pitch);
    PitchMatrix(orientationMatrix, motionState->yaw);
    YawMatrix(orientationMatrix, player->heading);
    matrix = player->matrix;
    CopyMatrix(matrix, orientationMatrix);
    ScaleMatrixLocal(matrix, player->scale.x, player->scale.y, player->scale.z);
    Particle_LimitVectorLength(&player->pos.x, 20000.0f);
    TranslateMatrix(matrix, player->pos.x, player->pos.y, player->pos.z);
    SwapMatrixUpForward(matrix);
}

void func_802079B0_de(Player *mover, ActorMotionState *rider) {
    ActorMotionResource *resource = mover->definition;
    ActorMotionDefinition *body = &resource->motion;

    if (Render_TestActorStateBit(&g_world, mover) == 0) {
        mover->weaponFlags &= ~0x10000;
        mover->weaponFlags &= ~0x100;
        return;
    }
    mover->weaponFlags |= 0x10000;
    if (rider->hooks != 0 && rider->hooks->onStep != 0) {
        rider->hooks->onStep(mover, rider);
    }
    rider->progress += body->progressScale * D_800D2988;
    Render_UpdateTriggeredMotion(mover, rider);
    if (rider->mode != 4) {
        func_80206DD4_de((void *)mover, (void *)rider);
    }
}

void func_80207A90_de(void *actor, s32 *stateFlags) {
    if (!((((struct func_8020D1FC_S1 *) ((s8 *) ((struct ObjRecAt18V5 *) ((s8 *) actor))->unk18))->unk38) & 0x40)) {
        *stateFlags &= 0xFFFEFFFF;
    }
}
