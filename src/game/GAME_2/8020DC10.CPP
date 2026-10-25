#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
#include "GAME_2/8020DC10.H"

extern void ReselectCloseAttack(void *);


s32 Nav_SetBehaviourState(void *, s32);

s32 func_8020DD04_de(s32);

/* The original MIPS preserves a0 for either close-attack update. */
s32 UpdateCloseAttack(void *brainAddress) {
    AiController *brain = brainAddress;
    if (brain->target != 0) {
        if ((u32)(brain->state - 3) < 3U) {
            ReselectCloseAttack(brainAddress);
            return 1;
        }
        func_8020DC60_de(brainAddress);
        return 1;
    }
    return 1;
}

void func_8020DC60_de(void *brainAddress) {
    s32 temp_v0;
    temp_v0 = func_8020DD04_de((((struct ObjRecAt18V4 *) ((s8 *) ((struct func_8020DCA0_S1 *) ((s8 *) brainAddress))->unk0))->unk18) + 0x14);
    (((struct func_8020DCA0_S1 *) ((s8 *) brainAddress))->unk230) = temp_v0;
    Nav_SetBehaviourState(brainAddress, temp_v0);
}
