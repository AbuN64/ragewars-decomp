#ifndef SCENE_SCENEACTORPREFIX_H
#define SCENE_SCENEACTORPREFIX_H
#include "TYPES.H"

typedef struct Shared_SceneActorPrefix Shared_SceneActorPrefix;
struct Shared_SceneActorPrefix {
    u8 pad0[24]; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    void * definition; /* +0x18: src/Scene_LoadLevelResources_SceneResourceState.c */
    u8 pad1C[200]; /* +0x1C: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneActorPrefix_size_check[(sizeof(Shared_SceneActorPrefix) == 0xE4) ? 1 : -1];
#endif
