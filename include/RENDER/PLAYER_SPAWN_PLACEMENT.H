#ifndef RENDER_PLAYER_SPAWN_PLACEMENT_H
#define RENDER_PLAYER_SPAWN_PLACEMENT_H
#include "TYPES.H"
struct Player;
extern void func_8021A78C_de(void *playerObject);
extern void Player_PlacePlayerAtSpawnPoint(struct Player *player, s32 model, s32 scale, s32 reset);
#endif
