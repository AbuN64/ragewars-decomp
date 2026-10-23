#include "COMMON/LEVEL_TRACK.H"
#include "include_asm.h"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEVEL.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"

/* Asks func_8044D220_de about D_8011FE88 with a minus-one selector, clears the words of D_801468A0 and puts the object at arg0 into state 0xC with byte 0x26DC1 set to two and the selector, or zero when the lookup failed, stored at 0x26DD8. Adapted from func_80293284_de with the selector fixed at minus one, the word at 0x26DDC cleared before the last word of D_801468A0 instead of set after the selector, and the state 0xC instead of 0xD changed. */







void func_8044DDD4_de(GameSession *arg0) {
    Shared_Placed spawn;
    s32 var_s0;

    var_s0 = -1;
    if (func_8044D220_de(&D_8011FE88, var_s0, var_s0, &spawn, 1) == 0) {
        var_s0 = 0;
    }
    D_801462C8.counters.ticks = 0;
    D_801462C8.counters.seconds = 0;
    D_801462C8.counters.m_GameTimeMinutes = 0;
    D_801462C8.counters.m_GameTimeHours = 0;
    arg0->selectionActive = 0;
    D_801462C8.counters.first = 0;
    arg0->phase = 2;
    arg0->selector = var_s0;
    arg0->target = 0xC;
}

#ifdef NON_MATCHING
#include "COMMON/OBJB.H"
#include "TYPES.H"

struct ResetActorDE7C {
    char pad0[0x26825];
    u8 enabled;
    char pad26826[0x596];
    s32 state;
    char pad26DC0;
    u8 phase;
    char pad26DC2[0x16];
    s32 key;
    s32 counter;
};

void func_8044DE7C_de(struct ResetActorDE7C *actor, s32 key) {
    Shared_Placed entry;
    s32 next;
    if (func_8044D220_de(&D_8011FE88, -1, key, &entry, 1) == 0) {
        key = 0;
    }
    D_801462C8.counters.ticks = 0;
    D_801462C8.counters.seconds = 0;
    D_801462C8.counters.m_GameTimeMinutes = 0;
    D_801462C8.counters.m_GameTimeHours = 0;
    D_801462C8.counters.first = 0;
    actor->counter = 0;
    actor->key = key;
    if (actor->enabled != 0 && D_801462C8.counters.transitionActive != 0) {
        actor->phase = 2;
        next = 13;
    } else {
        actor->phase = 2;
        next = 12;
    }
    actor->state = next;
}
#else
INCLUDE_ASM("ovl_80400000", func_8044DE7C_de);
#endif
