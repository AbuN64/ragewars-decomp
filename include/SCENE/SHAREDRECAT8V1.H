#ifndef SCENE_SHAREDRECAT8V1_H
#define SCENE_SHAREDRECAT8V1_H
#include "TYPES.H"

typedef struct ScenePackedResourceTableView ScenePackedResourceTableView;
struct ScenePackedResourceTableView {
    char pad0[0x4];
    s32 count; /* +0x4: src/Scene_LoadLevelResources_SceneResourceState.c */
    u8 address8; /* +0x8: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad9[0x3];
};
typedef char ScenePackedResourceTableSizeCheck[(sizeof(ScenePackedResourceTableView) == 0xC) ? 1 : -1];
#endif
