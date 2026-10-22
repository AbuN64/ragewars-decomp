#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", func_802301F4_de);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
/* Handles a player's attack trigger: nothing while cooling down past D_800C2EE0_de; the trigger is the
 * controller latch at 0x23C (cleared when read) for a flagged controlled player, else flag 0x2000; when it
 * fires and func_80230058_de accepts the attack, a ranged attack (type 2) that may fire takes action 8 and
 * returns 2, otherwise action 4 starts with the combo byte cleared and returns 1. Adapted from
 * func_80231BB0_de with the fire check as the same static helper. */
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/EXTERNS_13.H"
#include "COMMON/OBJECTLINKS14C.H"
/* func_802301E4_S* are unresolved canonical player/actor/control/attack types. */

extern Profile D_80102B00[];


extern s32 D_800D30BC;




extern s32 func_8022F55C_de(void *, s16);
extern void func_80239908_de(void *, void *, s32, s32, f32);










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
#endif

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C2EE8_de, D_800C2EEC_de;
extern s16 D_800CE8DC[];
extern void *D_800D052C[];
/* Per-frame handler for a weapon in its alternate-fire mode: without ammo it drops the mode request and
 * lets func_8022F96C_de pick the next weapon; while the fire flag 0x4000 is held and the state is a firing
 * state it toggles the request (0x13C between 1 and 2), plays the empty-click effect when the magazine runs
 * out, and otherwise runs func_802301F4_de or the default action from the weapon table. */
void func_802303A0_de(void *actor, void *attack) {
    void *player = FIELD(void *, actor, 0x1D8);
    s16 action = D_800CE8DC[FIELD(s16, player, 0x650) * 12];
    char *info = (char *)D_800D052C[FIELD(s16, player, 0x62E)];
    s32 ready;
    s32 handled = 1;
    if (Weapons_HasAmmoForMode(player, FIELD(s16, player, 0x62E)) == 0) {
        if (FIELD(s32, attack, 0x13C) == 2) {
            FIELD(s32, attack, 0x13C) = 1;
            if ((FIELD(u32, info, 0x14) & 0x20) != 0) {
                FIELD(s32, player, 0x7E8) = 0;
            }
            handled = Weapons_HasAmmoForMode(player, FIELD(s16, player, 0x62E));
        } else {
            handled = 0;
        }
        if (handled == 0) {
            FIELD(s16, player, 0x770) = func_8022F96C_de(player);
            return;
        }
    }
    if ((FIELD(u32, player, 0x6B0) & 0x4000) != 0 && FIELD(s16, player, 0x62E) < 0x12) {
        if (0.0f < FIELD(f32, player, 0x11D8)) {
            ready = 0;
        } else if (FIELD(s32, player, 0x1450) != 0 || D_801462D5 != 1) {
            ready = 1;
        } else {
            ready = func_8022F55C_de((char *)D_80102B00 + FIELD(s32, player, 0x5D4) * 400, 3);
            if (ready == 0) {
                func_8025DF34_de(0xD4D);
                if (FIELD(void *, player, 0x5DC) != 0) {
                    func_8022A5A0_de(&D_80145040, player);
                    func_80239908_de(&D_80145088, FIELD(void *, player, 0x5DC), D_800D30BC, ready, D_800C2EE8_de);
                }
            }
        }
        if (ready != 0) {
            if (FIELD(s32, attack, 0x13C) != 1) {
                FIELD(s32, attack, 0x13C) = 1;
                if ((FIELD(u32, info, 0x14) & 0x20) != 0) {
                    FIELD(s32, player, 0x7E8) = 0;
                }
            } else {
                FIELD(s32, attack, 0x13C) = 2;
                if (Weapons_HasAmmoForMode(player, FIELD(s16, player, 0x62E)) == 0) {
                    func_8025DF34_de(0xD4D);
                    if (FIELD(void *, player, 0x5DC) != 0) {
                        s32 result = func_8022A5A0_de(&D_80145040, player);
                        func_80239908_de((char *)&D_80145040 + 0x48, FIELD(void *, player, 0x5DC), D_800D30BC, result, D_800C2EEC_de);
                    }
                    FIELD(s32, attack, 0x13C) = 1;
                } else if ((FIELD(u32, info, 0x14) & 0x20) != 0) {
                    FIELD(s32, player, 0x7E8) = 1;
                }
            }
        }
    }
    if (func_802301F4_de(actor, attack) == 0 && !(FIELD(u32, actor, 0x100) & 0x400)) {
        func_80214178_de(actor, attack, action);
    }
}
#else
INCLUDE_ASM("span_1000", func_802303A0_de);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", func_80230610_eu);
#endif
#endif
