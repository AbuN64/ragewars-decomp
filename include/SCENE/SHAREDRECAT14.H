#ifndef SCENE_SHAREDRECAT14_H
#define SCENE_SHAREDRECAT14_H
#include "TYPES.H"

typedef struct SceneResourceSixWordRecord SceneResourceSixWordRecord;
struct SceneResourceSixWordRecord {
    s32 visibilityHeaderWord0; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord1; /* +0x4: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord2; /* +0x8: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord3; /* +0xC: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord4; /* +0x10: src/Scene_LoadLevelResources_SceneResourceState.c */
    s32 visibilityHeaderWord5; /* +0x14: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneResourceSixWordRecordSizeCheck[(sizeof(SceneResourceSixWordRecord) == 0x18) ? 1 : -1];
#endif
