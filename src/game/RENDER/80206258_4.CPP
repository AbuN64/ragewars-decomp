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

extern void func_80273448_de(f32 *, f32, f32, f32);

extern void func_80273D6C_de(void *);

s32 func_80285F58_de(void *, void *);

void func_80206A20_de(Player *mover, ActorMotionState *rider);

void func_80206DD4_de(Actor_func_80206DD4_de *, RiderCode80206258 *);

void func_80207910_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    f32 sp10[16];
    f32 *temp_s1;

    func_80273760_de(sp10, arg1->pitch);
    func_802738C0_de(sp10, arg1->yaw);
    func_80273A98_de(sp10, arg0->heading);
    temp_s1 = arg0->matrix;
    func_8027302C(temp_s1, sp10);
    func_8027347C_de(temp_s1, arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_8027254C_de(&arg0->pos.x, 20000.0f);
    func_80273448_de(temp_s1, arg0->pos.x, arg0->pos.y, arg0->pos.z);
    func_80273D6C_de(temp_s1);
}

void func_802079B0_de(Player *mover, ActorMotionState *rider) {
    ActorMotionResource *resource = mover->definition;
    ActorMotionDefinition *body = &resource->motion;

    if (func_80285F58_de(&D_8011FE88, mover) == 0) {
        mover->weaponFlags &= ~0x10000;
        mover->weaponFlags &= ~0x100;
        return;
    }
    mover->weaponFlags |= 0x10000;
    if (rider->hooks != 0 && rider->hooks->onStep != 0) {
        rider->hooks->onStep(mover, rider);
    }
    rider->progress += body->progressScale * D_800D2988;
    func_80206A20_de(mover, rider);
    if (rider->mode != 4) {
        func_80206DD4_de((void *)mover, (void *)rider);
    }
}

void func_80207A90_de(void *arg0, s32 *arg1) {
    if (!((((struct func_8020D1FC_S1 *) ((s8 *) ((struct ObjRecAt18V5 *) ((s8 *) arg0))->unk18))->unk38) & 0x40)) {
        *arg1 &= 0xFFFEFFFF;
    }
}
