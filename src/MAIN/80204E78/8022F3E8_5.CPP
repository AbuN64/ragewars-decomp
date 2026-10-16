#include "common/unused.h"
#include "span_C76B0/data.h"
/* Handles a player's attack trigger: nothing while cooling down past D_800C2EE0_de; the trigger is the
 * controller latch at 0x23C (cleared when read) for a flagged controlled player, else flag 0x2000; when it
 * fires and func_80230058_de accepts the attack, a ranged attack (type 2) that may fire takes action 8 and
 * returns 2, otherwise action 4 starts with the combo byte cleared and returns 1. Adapted from
 * func_80231BB0_de with the fire check as the same static helper. */
#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/func_80443B3C_de_closed.h"
#include "span_1000/code_8022F3E8.h"
/* func_802301E4_S* are unresolved canonical player/actor/control/attack types. */

extern Profile D_80102B00[];


extern s32 D_800D30BC;




extern s32 func_8022F55C_de(void *, s16);
extern void func_80239908_de(void *, void *, s32, s32, f32);
extern void func_80214178_de(void *, void *, s32);










typedef struct AttackTriggerPlayer AttackTriggerPlayer;
typedef struct AttackTriggerActor AttackTriggerActor;
typedef struct AttackTriggerControl AttackTriggerControl;
typedef struct AttackTriggerAction AttackTriggerAction;
struct AttackTriggerPlayer {
    char pad0[0x5D4];
    s32 unk5D4;
    char pad5D4[0x5DC - 0x5D4 - sizeof(s32)];
    void* unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x11D8 - 0x6AC - sizeof(s32)];
    f32 unk11D8;
    char pad11D8[0x1450 - 0x11D8 - sizeof(f32)];
    s32 unk1450;
    char pad1450[0x1454 - 0x1450 - sizeof(s32)];
    char* unk1454;
};
struct AttackTriggerActor {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    char* unk1D8;
};
struct AttackTriggerControl {
    char pad0[0x23C];
    s32 unk23C;
};
struct AttackTriggerAction {
    char pad0[0xCB];
    u8 unkCB;
    char padCB[0x13C - 0xCB - sizeof(u8)];
    s32 unk13C;
};


static inline s32 can_fire(char *player) {
    s32 ammo;

    if (((AttackTriggerPlayer *)(player))->unk11D8 > 0.0f) {
        return 0;
    }
    if (((AttackTriggerPlayer *)(player))->unk1450 != 0) {
        return 1;
    }
    if (D_801462D5 != 1) {
        return 1;
    }
    ammo = func_8022F55C_de(&D_80102B00[((AttackTriggerPlayer *)(player))->unk5D4], ((AttackTriggerPlayer *)(player))->unk62E);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (((AttackTriggerPlayer *)(player))->unk5DC != 0) {
            func_80239908_de(&D_80145088, ((AttackTriggerPlayer *)(player))->unk5DC, D_800D30BC, func_8022A5A0_de(&D_80145040, player),
                          D_800C2EE4_de);
        }
    }
    return ammo;
}

s32 func_802301F4_de(void *actor, void *attack) {
    char *player;
    s32 trigger;
    char *control;

    player = ((AttackTriggerActor *)(actor))->unk1D8;
    if (((AttackTriggerPlayer *)(player))->unk11D8 > D_800C2EE0_de) {
        return 0;
    }
    if ((((AttackTriggerActor *)(actor))->unk100 & 0x300000) && ((AttackTriggerPlayer *)(player))->unk1450 != 0) {
        control = ((AttackTriggerPlayer *)(player))->unk1454;
        trigger = ((AttackTriggerControl *)(control))->unk23C;
        ((AttackTriggerControl *)(control))->unk23C = 0;
    } else {
        trigger = ((AttackTriggerPlayer *)(player))->unk6AC & 0x2000;
    }
    if (trigger != 0 && func_80230058_de(actor, attack) != 0) {
        if (((AttackTriggerAction *)(attack))->unk13C == 2 && can_fire(player)) {
            func_80214178_de(actor, attack, 8);
            return 2;
        }
        func_80214178_de(actor, attack, 4);
        ((AttackTriggerAction *)(attack))->unkCB = 0;
        return 1;
    }
    return 0;
}

