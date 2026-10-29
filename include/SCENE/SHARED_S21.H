#ifndef SCENE_SHARED_S21_H
#define SCENE_SHARED_S21_H
#include "TYPES.H"

typedef struct SceneResourceSectionHeader SceneResourceSectionHeader;
struct SceneResourceSectionHeader {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneResourceSectionHeaderSizeCheck[(sizeof(SceneResourceSectionHeader) == 0x8) ? 1 : -1];
#endif
