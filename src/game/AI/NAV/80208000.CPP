#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

/* Resets a player controller: marks the active, requested and committed selections empty, sets the
   request kind to 0xB, clears the four link words at 0x14 to -1, resets the stage counters at 0x1BC
   and 0x1C8 and the target list, installs the default table D_800CE040 through Nav_SetBehaviorTable and mode
   2 through func_80209874_de, zeroes the tracking values from 0x23C to 0x260, runs the resets
   Nav_ResetWheelProbeState, Nav_ResetBehaviorState and Nav_ClearAuxiliaryBehaviorState, and clears the remaining state words. */

extern void Nav_SetBehaviorTable(void *, char *, s32);
extern void Nav_SetBehaviourState(void *, s32);
extern void Nav_ResetWheelProbeState(void *);

extern void Nav_ClearAuxiliaryBehaviorState(void *);

void World_ResetPlayerState(s32 *state) {
    s32 i;
    s32 none;

    state[1] = -1;
    state[2] = -1;
    state[3] = 0xB;
    state[4] = -1;
    state[11] = 0;
    state[12] = 0;
    state[13] = 0;
    none = -1;
    for (i = 3; i >= 0; i--) {
        state[5 + i] = none;
    }
    state[10] = -1;
    state[0x1BC / 4] = 0xFFFF;
    state[0x220 / 4] = 0;
    state[0x1C8 / 4] = 0;
    state[14] = 1;
    state[15] = 0;
    state[25] = 0;
    state[0x28C / 4] = 0;
    state[26] = 0;
    state[0xBC / 4] = -1;
    state[0x224 / 4] = -1;
    state[0x228 / 4] = 0;
    for (i = 0; i < 10; i++) {
        state[15 + i] = 0;
        state[27 + i] = 0;
        state[37 + i] = 0;
    }
    state[0x238 / 4] = 0;
    Nav_SetBehaviorTable(state, &D_800CE040, none);
    Nav_SetBehaviourState(state, 2);
    ((f32 *) state)[0x244 / 4] = 0.0f;
    state[0x23C / 4] = 0;
    state[0x240 / 4] = 0;
    ((f32 *) state)[0x250 / 4] = ((f32 *) state)[0x254 / 4] = ((f32 *) state)[0x248 / 4] =
        ((f32 *) state)[0x24C / 4] = ((f32 *) state)[0x258 / 4] = ((f32 *) state)[0x25C / 4] =
        ((f32 *) state)[0x260 / 4] = ((f32 *) state)[0x244 / 4];
    Nav_ResetWheelProbeState(state);
    Nav_ResetBehaviorState(state);
    Nav_ClearAuxiliaryBehaviorState(state);
    state[0x318 / 4] = 0;
    state[0x31C / 4] = 0;
    state[0x320 / 4] = -1;
    state[0x324 / 4] = 0;
    state[0x328 / 4] = 0;
    state[0x2D8 / 4] = 0;
    state[0x2E4 / 4] = 0;
    state[0x2EC / 4] = 0;
    state[0x2E8 / 4] = 0;
    state[0x2DC / 4] = 0;
    state[0x2E0 / 4] = 0;
    state[0x32C / 4] = -1;
}
