#ifndef SCENE_SCENEACTORKIND_H
#define SCENE_SCENEACTORKIND_H
#include "TYPES.H"

typedef struct Shared_SceneActorKind Shared_SceneActorKind;
struct Shared_SceneActorKind {
    u16 kind; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneActorKind_size_check[(sizeof(Shared_SceneActorKind) == 0x2) ? 1 : -1];
#endif
