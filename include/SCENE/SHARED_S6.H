#ifndef SCENE_SHARED_S6_H
#define SCENE_SHARED_S6_H
#include "TYPES.H"

typedef struct ScenePlayerProfileView ScenePlayerProfileView;
struct ScenePlayerProfileView {
    char pad0[0x80];
    s8 unk80; /* +0x80: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char ScenePlayerProfileViewSizeCheck[(sizeof(ScenePlayerProfileView) == 0x81) ? 1 : -1];
#endif
