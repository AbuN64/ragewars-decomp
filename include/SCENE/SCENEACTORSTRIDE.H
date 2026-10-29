#ifndef SCENE_SCENEACTORSTRIDE_H
#define SCENE_SCENEACTORSTRIDE_H
#include "TYPES.H"

typedef struct Shared_SceneActorStride Shared_SceneActorStride;
struct Shared_SceneActorStride {
    u8 bytes[744]; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneActorStride_size_check[(sizeof(Shared_SceneActorStride) == 0x2E8) ? 1 : -1];

/* Step through the scene actor storage using its verified element size. */
#define NEXT_SCENE_ACTOR(ptr) ((void *)(((struct Shared_SceneActorStride *)(ptr)) + 1))
#endif
