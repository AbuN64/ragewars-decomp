#ifndef RW_LEVEL_SPAWN_H
#define RW_LEVEL_SPAWN_H
#include "shared/level_actor.h"
#include "shared/level_track.h"
#include "shared/level_placement.h"
#include "shared/gameplay_settings.h"
#include "shared/func_80286a78_s1.h"
#include "shared/level_input.h"
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
