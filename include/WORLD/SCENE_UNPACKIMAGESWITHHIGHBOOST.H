#ifndef WORLD_SCENE_UNPACKIMAGESWITHHIGHBOOST_H
#define WORLD_SCENE_UNPACKIMAGESWITHHIGHBOOST_H
#include "TYPES.H"
struct NearbySpecialActorView {
    u8 kind;
    char pad1[0x17];
    s32 *definition;
    char pad2[0xE4 - 0x1C];
    u16 modelId;
};
#endif
