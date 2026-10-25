#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"

/* Switches a player to a new state unless option D_801462E5 is on, func_8022C460_de refuses and the
   state is not 0x13 to 0x15: keeps the previous state and timer, clears flag 0x800000, runs the new
   state's entry handler from the player's state table at 0x13B4, loads the state's timer and its
   nonzero parameter at 0x86C, and returns 1 with the counter at 0x658 cleared when the handler left
   the state in place, otherwise 0. */





extern s32 func_8022C460_de(void *player);

s32 Weapons_SetPlayerState(SharedPlayer *player, void *arg1, s32 state) {
    void (*enter)(void *, void *);
    s32 parameter;

    if (D_801462C8.local != 0 && func_8022C460_de(player) != 0 && state != 0x15 && state != 0x13 && state != 0x14) {
        return 0;
    }
    player->views5E8.view652_20.previous = player->views5E8.view650_16.state;
    player->views5E8.view660_26.previousTimer = player->views5E8.view664_28.timer;
    player->views5E8.view650_16.state = state;
    player->views1C.view100_9.flags &= ~0x800000;
    enter = player->views13B4.view13B4_1.states[state].enter;
    if (enter != 0) {
        enter(player, arg1);
    }
    player->views5E8.view664_28.timer = player->views13B4.view13B4_1.states[player->views5E8.view650_16.state].timer;
    parameter = player->views13B4.view13B4_1.states[player->views5E8.view650_16.state].parameter;
    if (parameter != 0) {
        player->views5E8.view86C_126.parameter = parameter;
    }
    if (player->views5E8.view650_16.state == state) {
        player->views5E8.view658_22.counter = 0;
        return 1;
    }
    return 0;
}

/* Sets a player's movement speed factor at 0x784: D_800C2848_de[0] in states 0 and 1, otherwise the
   character's speed at 0x1C of its descriptor, which for a computer player (0x1450) is scaled twice by
   its skill byte at 0x93 (D_800C2848_de[1] then D_800C2850_de[1] for skill 0, D_800C2850_de[0] then D_800C7948
   for skill 1, unchanged for skill 2, other values reset to 0), then by the game option factor at 0x20
   of D_801462C8 when enabled at 0x1D, and by the ground's factor at 0x30 when state bits 3 at 0x38 are
   clear, there is ground, and func_8024E62C_de reports true or the ground is flagged 0x800. */

extern f32 D_800C2848_de[];
extern f32 D_800C2850_de[];
extern f32 D_800C7948;

extern s32 func_8024E62C_de(void *);













void func_80222908_de(void *actorView, void *arg1, ObjectState54 *ground) {
    u8 *options;

    if ((u16)((Shared_ActorView *)actorView)->action < 2) {
        ((Shared_ActorView *)actorView)->speedFactor = D_800C2848_de[0];
        return;
    }
    ((Shared_ActorView *)actorView)->speedFactor = ((MovementDescriptor *)(((ObjectLinks3C *)arg1)->unk_18))->speed;
    if (((Shared_ActorView *)actorView)->remote != 0) {
        switch (((Shared_ActorView *)actorView)->controls->difficulty) {
        default:
            ((Shared_ActorView *)actorView)->controls->difficulty = 0;
        case 0:
            ((Shared_ActorView *)actorView)->speedFactor *= D_800C2848_de[1];
            break;
        case 1:
            ((Shared_ActorView *)actorView)->speedFactor *= D_800C2850_de[0];
            break;
        case 2:
            break;
        }
        if (((Shared_ActorView *)actorView)->remote != 0) {
            switch (((Shared_ActorView *)actorView)->controls->difficulty) {
            default:
                ((Shared_ActorView *)actorView)->controls->difficulty = 0;
            case 0:
                ((Shared_ActorView *)actorView)->speedFactor *= D_800C2850_de[1];
                break;
            case 1:
                ((Shared_ActorView *)actorView)->speedFactor *= D_800C7948;
                break;
            case 2:
                break;
            }
        }
    }
    options = (u8 *)&D_801462C8;
    if (options[0x1D] != 0) {
        ((Shared_ActorView *)actorView)->speedFactor *= ((Shared_Game *)options)->speedFactor;
    }
    if (!(((ObjectLinks3C *)(arg1))->unk_38 & 3) && ground != 0
        && (func_8024E62C_de(arg1) != 0 || (ground->unk_52 & 0x800))) {
        ((Shared_ActorView *)actorView)->speedFactor *= ground->unk_30;
    }
}

#include "COMMON/VECTOR4F.H"
#include "COMMON/LOADOUT.H"

extern WeaponInfo *D_800D052C[];

/* Check the ammo required by the selected primary or alternate weapon mode. */
s32 Weapons_HasAmmoForMode(void *object, s32 weaponNumber)
{
    Player *player = object;
    s32 weapon = weaponNumber;
    s32 slot;
    WeaponInfo *definition;
    s16 *condition;

    definition = D_800D052C[weapon];
    if (player->gear == 1) {
        condition = definition->weaponClass;
    } else {
        condition = definition->alternateClass;
    }
    slot = condition != 0 ? condition[0] : -1;
    if (slot != -1) {
        if (player->gear == 2) {
            switch (weapon) {
            default: {
                s16 *alternate = D_800D052C[weapon]->alternateClass;
                if (alternate != 0) {
                    return player->ammo[slot] >= alternate[3];
                }
                return -1;
            }
            case 4:
                return player->ammo[slot] >= 48;
            case 3:
                return player->ammo[slot] >= 25;
            }
        }
        if (player->gear == 1) {
            switch (weapon) {
            default: {
                s16 *primary = D_800D052C[weapon]->weaponClass;
                if (primary != 0) {
                    return player->ammo[slot] >= primary[3];
                }
                return -1;
            }
            case 4:
                return player->ammo[slot] >= 5;
            case 3:
                return player->ammo[slot] >= 3;
            }
        }
    }
    return -1;
}
