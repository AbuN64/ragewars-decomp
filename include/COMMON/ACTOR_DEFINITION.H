#ifndef COMMON_ACTOR_DEFINITION_H
#define COMMON_ACTOR_DEFINITION_H
#include "TYPES.H"
typedef struct ActorDefinitionHeader {
    s32 kind;
    s32 gate;
    u8 pad8[4];
    s16 character;
    s8 first;
    u8 padF;
    s8 second;
    u8 pad11;
    s8 send;
    u8 pad13;
    s32 flags;
} ActorDefinitionHeader;
#endif
