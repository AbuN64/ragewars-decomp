#include "RSP/8026E1F8_5.H"
#include "include_asm.h"





#if defined(VERSION_DE)
#include "COMMON/SELF.H"

void Nav_InitPursuitStrafeDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Nav_ResetBehaviorState(brain);
    brain->timer = GraphU64_NextRandom() % 4 + 12;
    brain->pattern = GraphU64_NextRandom() % 2;
}
#endif

#if defined(VERSION_DE)
void Nav_InitRangedCombatDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Nav_ResetBehaviorState(brain);
    brain->timer = GraphU64_NextRandom() % 4 + 12;
    brain->pattern = GraphU64_NextRandom() % 2;
    brain->distance = GraphU64_NextRandom() % 250000 + 360000;
    brain->fireTimer = -1;
    brain->frames = 0;
    brain->visible = 0;
}
#endif

#if defined(VERSION_DE)
void Nav_InitCloseCombatDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    brain->timer = GraphU64_NextRandom() % 4 + 2;
    brain->pattern = GraphU64_NextRandom() % 2;
    brain->distance = GraphU64_NextRandom() % 32400 + 10000;
    Nav_ResetBehaviorState(brain);
    brain->frames = 0;
    brain->visible = 0;
    brain->fireTimer = -1;
}
#endif

#if defined(VERSION_DE)
void Nav_InitVisiblePursuitDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Nav_ResetBehaviorState(brain);
    brain->timer = GraphU64_NextRandom() % 4 + 12;
    brain->pattern = GraphU64_NextRandom() % 2;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_80211120_de_padding_13264[12] = { 0xAD, 0x20, 0x00, 0x08, 0x8C, 0xE5, 0x00, 0x00, 0x24, 0xE7, 0x00, 0x04 };
#endif

