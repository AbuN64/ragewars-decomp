#ifndef SCENE_SCENEFONTRESOURCES_H
#define SCENE_SCENEFONTRESOURCES_H
#include "TYPES.H"

typedef struct Shared_SceneFontResources Shared_SceneFontResources;
struct Shared_SceneFontResources {
    u8 bytes[712]; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneFontResources_size_check[(sizeof(Shared_SceneFontResources) == 0x2C8) ? 1 : -1];
#endif
