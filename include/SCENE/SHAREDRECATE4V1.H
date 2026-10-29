#ifndef SCENE_SHAREDRECATE4V1_H
#define SCENE_SHAREDRECATE4V1_H
#include "SCENE/SCENEACTORKIND.H"
#include "SCENE/SCENEACTORPREFIX.H"

typedef struct SceneActorKindView SceneActorKindView;
struct SceneActorKindView {
    Shared_SceneActorPrefix prefix; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    Shared_SceneActorKind kind; /* +0xE4: src/Scene_LoadLevelResources_SceneResourceState.c */
    char padE6[0x2];
};
typedef char SceneActorKindViewSizeCheck[(sizeof(SceneActorKindView) == 0xE8) ? 1 : -1];
#endif
