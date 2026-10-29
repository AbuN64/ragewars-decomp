#ifndef SCENE_SCENEACTORTABLES_H
#define SCENE_SCENEACTORTABLES_H
#include "SCENE/SCENEPRIMARYACTORS.H"

typedef struct Shared_SceneActorTables Shared_SceneActorTables;
struct Shared_SceneActorTables {
    void * kind64e[10]; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    Shared_ScenePrimaryActors primary; /* +0x28: src/Scene_LoadLevelResources_SceneResourceState.c */
    void * kindBd6; /* +0x3C: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneActorTables_size_check[(sizeof(Shared_SceneActorTables) == 0x40) ? 1 : -1];
#endif
