#ifndef SCENE_SHARED_S14_H
#define SCENE_SHARED_S14_H
#include "TYPES.H"

typedef struct SceneResourceSectionPointerView SceneResourceSectionPointerView;
struct SceneResourceSectionPointerView {
    char pad0[0x18];
    s32 * sectionWords; /* +0x18: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneResourceSectionPointerSizeCheck[(sizeof(SceneResourceSectionPointerView) == 0x1C) ? 1 : -1];
#endif
