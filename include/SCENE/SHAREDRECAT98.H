#ifndef SCENE_SHAREDRECAT98_H
#define SCENE_SHAREDRECAT98_H
#include "TYPES.H"

typedef struct SceneSpecialActorModeView SceneSpecialActorModeView;
struct SceneSpecialActorModeView {
    char pad0[0x98];
    s32 statusBarsEnabled; /* +0x98: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneSpecialActorModeSizeCheck[(sizeof(SceneSpecialActorModeView) == 0x9C) ? 1 : -1];
#endif
