#ifndef GAME_ATTACK_SELECTWEIGHTEDATTACKBEHAVIOR_H
#define GAME_ATTACK_SELECTWEIGHTEDATTACKBEHAVIOR_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
struct WeightSource {
    char pad[0x2C];
    f32 first;
    f32 second;
    f32 third;
};
struct func_8020DCA0_S1 {
    void * unk0;
    char pad0[0x230 - 0x0 - sizeof(void*)];
    s32 unk230;
};
struct ObjRecAt18V4 {
    char pad0[0x18];
    s32 unk18;
};
extern void Attack_SelectWeightedAttackBehavior(void *arg0);
#endif
