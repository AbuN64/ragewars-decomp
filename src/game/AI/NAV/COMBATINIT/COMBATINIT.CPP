#include "include_asm.h"
#include "COMMON/SELF.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_15.H"
#include "RSP/8026E1F8_5.H"

/* 802106E0_15.CPP */
#if !(defined(VERSION_DE))
void Nav_InitRangedCombat(CloseAttackActor *arg0) {
    CloseAttackActor *level1 = arg0->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2, r3;

    inner->state = 0;
    Scaled_ResetBehaviorState(inner);

    r1 = GraphU64_NextRandom();
    inner->timer = r1 % 4 + 0xC;

    r2 = GraphU64_NextRandom();
    inner->pattern = r2 % 2;

    r3 = GraphU64_NextRandom();
    inner->fireTimer = -1;
    inner->frames = 0;
    inner->visible = 0;
    inner->distance = r3 % 250000 + 360000;
}

void Nav_InitCloseCombat(CloseAttackActor *arg0) {
    CloseAttackActor *level1 = arg0->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2, r3;

    inner->state = 0;

    r1 = GraphU64_NextRandom();
    inner->timer = r1 % 4 + 2;

    r2 = GraphU64_NextRandom();
    inner->pattern = r2 % 2;

    r3 = GraphU64_NextRandom();
    inner->distance = r3 % 32400 + 0x2710;

    Scaled_ResetBehaviorState(inner);

    inner->frames = 0;
    inner->visible = 0;
    inner->fireTimer = -1;
}

void Nav_InitVisiblePursuit(CloseAttackActor *arg0) {
    CloseAttackActor *level1 = arg0->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2;

    inner->state = 0;
    Scaled_ResetBehaviorState(inner);

    r1 = GraphU64_NextRandom();
    inner->timer = r1 % 4 + 0xC;

    r2 = GraphU64_NextRandom();
    inner->pattern = r2 % 2;
}
#endif

#if defined(VERSION_US)
unsigned int func_80212610_eu_padding_13264[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_80212668[8] =
    "!SFX_PLA";
#endif

/* 802106E0_9.CPP */
#if defined(VERSION_DE)
#include "COMMON/SELF.H"

void Nav_InitPursuitStrafeDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Scaled_ResetBehaviorState(brain);
    brain->timer = GraphU64_NextRandom() % 4 + 12;
    brain->pattern = GraphU64_NextRandom() % 2;
}
#endif

#if defined(VERSION_DE)
void Nav_InitRangedCombatDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Scaled_ResetBehaviorState(brain);
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
    Scaled_ResetBehaviorState(brain);
    brain->frames = 0;
    brain->visible = 0;
    brain->fireTimer = -1;
}
#endif

#if defined(VERSION_DE)
void Nav_InitVisiblePursuitDe(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Scaled_ResetBehaviorState(brain);
    brain->timer = GraphU64_NextRandom() % 4 + 12;
    brain->pattern = GraphU64_NextRandom() % 2;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_80211120_de_padding_13264[12] = { 0xAD, 0x20, 0x00, 0x08, 0x8C, 0xE5, 0x00, 0x00, 0x24, 0xE7, 0x00, 0x04 };
#endif
