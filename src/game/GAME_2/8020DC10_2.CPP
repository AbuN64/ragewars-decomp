#include "COMMON/SELF.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"

extern s32 func_8020DD04_de(WeightSource *);
extern s32 Nav_SetBehaviourState(void *, s32);

/* Reconsider an existing attack on one of four signed random remainders. */
void ReselectCloseAttack(void *brainAddress) {
    CloseAttackBrain *brain = brainAddress;
    WeightSource *weights;
    s32 selectedState;
    if (Nav_NextRandom() % 4 == 1) {
        weights = (WeightSource *)((u8 *)((Player *)brain->player)->definition + 0x14);
        selectedState = func_8020DD04_de(weights);
        brain->combat = selectedState;
        Nav_SetBehaviourState(brainAddress, selectedState);
    }
}
