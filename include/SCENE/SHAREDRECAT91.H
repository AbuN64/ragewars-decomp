#ifndef SCENE_SHAREDRECAT91_H
#define SCENE_SHAREDRECAT91_H
#include "TYPES.H"

typedef struct LevelResourceLoadFlags LevelResourceLoadFlags;
struct LevelResourceLoadFlags {
    char pad0[0x78];
    u8 unk78; /* +0x78: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad79[0x18];
    u8 unk91; /* +0x91: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char LevelResourceLoadFlagsSizeCheck[(sizeof(LevelResourceLoadFlags) == 0x92) ? 1 : -1];
#endif
