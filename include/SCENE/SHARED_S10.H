#ifndef SCENE_SHARED_S10_H
#define SCENE_SHARED_S10_H
#include "TYPES.H"

typedef struct SceneLoadWordPairView SceneLoadWordPairView;
struct SceneLoadWordPairView {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneLoadWordPairView_size_check[(sizeof(SceneLoadWordPairView) == 0x8) ? 1 : -1];
#endif
