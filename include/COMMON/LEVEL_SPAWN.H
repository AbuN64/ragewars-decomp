#ifndef COMMON_LEVEL_SPAWN_H
#define COMMON_LEVEL_SPAWN_H
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/LEVEL_PLACEMENT.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "COMMON/SHAREDRECAT1B92C.H"
#include "COMMON/LEVEL_INPUT.H"
/* The resource header is followed by count input records or runtime actors. */
typedef struct LevelBlock {
    s32 size;
    s32 count;
    LevelActor objects[1];
} LevelBlock;
typedef struct LevelNode {
    s32 size;
    s32 count;
    InputRecAt27 records[1];
} LevelNode;
extern SharedPlayer *D_80140F84;
#endif
