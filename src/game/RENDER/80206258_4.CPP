#include "COMMON/REC.H"
#include "RENDER/80206258.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "RENDER/80206258_4.H"

extern void func_80273760_de(void *arg0, f32 arg1);

extern void func_802738C0_de(void *arg0, f32 arg1);

extern void func_80273A98_de(void *arg0, f32 arg1);

extern void func_8027302C(float *arg0, float *arg1);

extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);

extern s32 func_8027254C_de(f32 *arg0, f32 arg1);

extern void TranslateMatrix(f32 *, f32, f32, f32);

extern void SwapMatrixUpForward(void *);

s32 Render_TestActorStateBit(void *, void *);

void Render_UpdateTriggeredMotion(Player *mover, ActorMotionState *rider);

void func_80206DD4_de(Actor_func_80206DD4_de *, RiderCode80206258 *);

void Render_BuildPlayerMatrix(void *object, void *state) {
    Player *player = object;
    ActorMotionState *motionState = state;
    f32 sp10[16];
    f32 *matrix;

    func_80273760_de(sp10, motionState->pitch);
    func_802738C0_de(sp10, motionState->yaw);
    func_80273A98_de(sp10, player->heading);
    matrix = player->matrix;
    func_8027302C(matrix, sp10);
    func_8027347C_de(matrix, player->scale.x, player->scale.y, player->scale.z);
    func_8027254C_de(&player->pos.x, 20000.0f);
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

void func_80207A90_de(void *arg0, s32 *arg1) {
    if (!((((struct func_8020D1FC_S1 *) ((s8 *) ((struct ObjRecAt18V5 *) ((s8 *) arg0))->unk18))->unk38) & 0x40)) {
        *arg1 &= 0xFFFEFFFF;
    }
}
