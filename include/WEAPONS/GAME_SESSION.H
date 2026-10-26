#ifndef WEAPONS_GAME_SESSION_H
#define WEAPONS_GAME_SESSION_H
#include "TYPES.H"
#include "COMMON/SESSION_STATE.H"
/* The match rules block at D_801468A0, which is also GameSession.rules at 0x1284 of D_8014561C. */
struct GameRules;
typedef struct GameRules GameRules;
struct GameRules {
    char pad0[0x14];
    f32 timeLimit;
    s32 scoreLimit;
    s32 locked;
    char pad20[0x24 - 0x20];
    s32 teams;
    char pad28[0x40 - 0x28];
    s32 teamPoints[5];
    s32 sudden;
    s32 totalScoreTarget;
    char pad5C[0x78 - 0x5C];
    s32 teamRule;
    s32 pointTarget;
    char pad80[0x9C - 0x80];
    s32 rounds;
    char padA0[0xA8 - 0xA0];
    s32 humanWon;
};
/* The running game session at D_8014561C: its message list first (the asm reads the head at 0 and the flag
   at 0x10, as MessageList does), settings at 0xCAC, the pause flag at 0x1278, the rules at 0x1284. */
struct GameSession;
typedef struct GameSession GameSession;
struct GameSession {
    MessageList messages;
    char pad18[0xCAC - sizeof(MessageList)];
    Settings580 settings;
    char pad122C[0x1278 - 0x122C];
    s32 paused;
    char pad127C[0x1284 - 0x127C];
    GameRules rules;
};
#endif
