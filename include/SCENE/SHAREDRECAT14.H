#ifndef SCENE_SHAREDRECAT14_H
#define SCENE_SHAREDRECAT14_H
#include "TYPES.H"

typedef struct SceneResourceSixWordRecord SceneResourceSixWordRecord;
struct SceneResourceSixWordRecord {
    s32 unk0; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 unk4; /* +0x4: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 unk8; /* +0x8: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 unkC; /* +0xC: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 unk10; /* +0x10: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 unk14; /* +0x14: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneResourceSixWordRecordSizeCheck[(sizeof(SceneResourceSixWordRecord) == 0x18) ? 1 : -1];
#endif
