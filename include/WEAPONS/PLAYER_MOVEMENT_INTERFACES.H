#ifndef WEAPONS_PLAYER_MOVEMENT_INTERFACES_H
#define WEAPONS_PLAYER_MOVEMENT_INTERFACES_H
#include "COMMON/ACTOR_HEADER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/UNUSED.H"

/* Published implementations use these concrete actor and tuning records. */
void Player_EaseOwnerHeightEffect(struct Object *object);
void func_802233F0_de(SharedPlayer *player,
                     func_802165F8_S1 *body, SharedMovement *tuning);
s32 Player_SetPlayerState(SharedPlayer *player, void *body, s32 state);
/* Turn-rate limits shared by player movement. */
extern const f32 D_800C2A64_de;
extern const f32 D_800C2A68_de;
#endif
