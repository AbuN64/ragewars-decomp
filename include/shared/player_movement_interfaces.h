#ifndef RW_PLAYER_MOVEMENT_INTERFACES_H
#define RW_PLAYER_MOVEMENT_INTERFACES_H
#include "shared/actor_header.h"
#include "span_1000/code_8021CD70.h"
#include "common/unused.h"

/* Published implementations use these concrete actor and tuning records. */
void func_8022404C_de(struct Object *object);
void func_802233F0_de(SharedPlayer *player,
                     func_802165F8_S1 *body, SharedMovement *tuning);
s32 func_802227F4_de(SharedPlayer *player, void *body, s32 state);
/* Turn-rate limits shared by player movement. */
extern const f32 D_800C2A64_de;
extern const f32 D_800C2A68_de;
#endif
