#ifndef SCENE_SHARED_S11_H
#define SCENE_SHARED_S11_H
#include "TYPES.H"

typedef struct Shared_SceneLoadLevelResources Shared_SceneLoadLevelResources;
struct Shared_SceneLoadLevelResources {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneLoadLevelResources_size_check[(sizeof(Shared_SceneLoadLevelResources) == 0x8) ? 1 : -1];
#endif
