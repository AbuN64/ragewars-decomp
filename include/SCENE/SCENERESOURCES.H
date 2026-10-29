#ifndef SCENE_SCENERESOURCES_H
#define SCENE_SCENERESOURCES_H
#include "SCENE/SCENEACTORRESOURCES.H"
#include "SCENE/SCENEFONTRESOURCES.H"

typedef struct Shared_SceneResources Shared_SceneResources;
struct Shared_SceneResources {
    Shared_SceneFontResources font; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    Shared_SceneActorResources actors; /* +0x2C8: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneResources_size_check[(sizeof(Shared_SceneResources) == 0x2C9) ? 1 : -1];
#endif
