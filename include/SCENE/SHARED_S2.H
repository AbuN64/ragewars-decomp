#ifndef SCENE_SHARED_S2_H
#define SCENE_SHARED_S2_H
#include "TYPES.H"

typedef struct ScenePlayerResourceView ScenePlayerResourceView;
struct ScenePlayerResourceView {
    char pad0[0x5D8];
    struct ScenePlayerProfileView * profile; /* +0x5D8: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad5DC[0xE78];
    s32 controllerState; /* +0x1454: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char ScenePlayerResourceViewSizeCheck[(sizeof(ScenePlayerResourceView) == 0x1458) ? 1 : -1];
#endif
