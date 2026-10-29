#ifndef SCENE_SCENEACTORRESOURCES_H
#define SCENE_SCENEACTORRESOURCES_H
#include "TYPES.H"

typedef struct Shared_SceneActorResources Shared_SceneActorResources;
struct Shared_SceneActorResources {
    u8 base; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneActorResources_size_check[(sizeof(Shared_SceneActorResources) == 0x1) ? 1 : -1];
#endif
