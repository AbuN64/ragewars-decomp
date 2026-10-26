#ifndef MENU_LEVELSELECT_TYPES_H
#define MENU_LEVELSELECT_TYPES_H
#include "TYPES.H"

typedef struct LevelSelectDescriptor {
    u8 unknown00[0x2D8];
    u32 flags;
} LevelSelectDescriptor;

typedef struct LevelSelectOwner {
    u32 unknown00[3];
    LevelSelectDescriptor *descriptor;
} LevelSelectOwner;

#endif
