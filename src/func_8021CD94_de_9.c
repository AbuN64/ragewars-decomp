#include "common/unused.h"
#include "shared/gameplay_transition.h"
#include "shared/func_80425674_de_layout.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"

/* Switches a player to a new state unless option D_801462E5 is on, func_8022C460_de refuses and the
   state is not 0x13 to 0x15: keeps the previous state and timer, clears flag 0x800000, runs the new
   state's entry handler from the player's state table at 0x13B4, loads the state's timer and its
   nonzero parameter at 0x86C, and returns 1 with the counter at 0x658 cleared when the handler left
   the state in place, otherwise 0. */





extern unsigned char D_801462E5;
extern s32 func_8022C460_de(void *player);

s32 func_802227F4_de(SharedPlayer *player, void *arg1, s32 state) {
    void (*enter)(void *, void *);
    s32 parameter;

    if (D_801462E5 != 0 && func_8022C460_de(player) != 0 && state != 0x15 && state != 0x13 && state != 0x14) {
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













void func_80222908_de(void *arg0, void *arg1, ObjectState54 *ground) {
    u8 *options;

    if ((u16)((Shared_ActorView *)arg0)->action < 2) {
        ((Shared_ActorView *)arg0)->speedFactor = D_800C2848_de[0];
        return;
    }
    ((Shared_ActorView *)arg0)->speedFactor = ((MovementDescriptor *)(((ObjectLinks3C *)arg1)->unk_18))->speed;
    if (((Shared_ActorView *)arg0)->remote != 0) {
        switch (((Shared_ActorView *)arg0)->controls->difficulty) {
        default:
            ((Shared_ActorView *)arg0)->controls->difficulty = 0;
        case 0:
            ((Shared_ActorView *)arg0)->speedFactor *= D_800C2848_de[1];
            break;
        case 1:
            ((Shared_ActorView *)arg0)->speedFactor *= D_800C2850_de[0];
            break;
        case 2:
            break;
        }
        if (((Shared_ActorView *)arg0)->remote != 0) {
            switch (((Shared_ActorView *)arg0)->controls->difficulty) {
            default:
                ((Shared_ActorView *)arg0)->controls->difficulty = 0;
            case 0:
                ((Shared_ActorView *)arg0)->speedFactor *= D_800C2850_de[1];
                break;
            case 1:
                ((Shared_ActorView *)arg0)->speedFactor *= D_800C7948;
                break;
            case 2:
                break;
            }
        }
    }
    options = (u8 *)&D_801462C8;
    if (options[0x1D] != 0) {
        ((Shared_ActorView *)arg0)->speedFactor *= ((Shared_Game *)options)->speedFactor;
    }
    if (!(((ObjectLinks3C *)(arg1))->unk_38 & 3) && ground != 0
        && (func_8024E62C_de(arg1) != 0 || (ground->unk_52 & 0x800))) {
        ((Shared_ActorView *)arg0)->speedFactor *= ground->unk_30;
    }
}
