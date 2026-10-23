#include "ANIM/RAY180.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "ANIM/802412C0_5.H"

extern void func_80271F34_de(CVector3 *, CVector3 *, CVector3 *);

/** Set flag 8 in the first object and flag 0x10 in the second. */
void func_802428D0_de(void *first, void *second) {
    ActorRecAtB0 *actor = first;
    Input_func_802426CC_de *input = second;
    actor->flags |= 8;
    input->flags38 |= 0x10;
}

void func_802428EC_de(void *arg0, void *levelActor) {
    Actor_func_80241BAC_de *actor = arg0;
    LevelActor *target = levelActor;
    CVector3 *position = &target->position1;
    actor->flags |= 8;
    func_80271F34_de(position, position, &actor->movement);
}
