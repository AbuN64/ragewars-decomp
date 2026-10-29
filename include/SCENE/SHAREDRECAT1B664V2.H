#ifndef SCENE_SHAREDRECAT1B664V2_H
#define SCENE_SHAREDRECAT1B664V2_H
#include "TYPES.H"

typedef struct SceneSelectedActorSlotView SceneSelectedActorSlotView;
struct SceneSelectedActorSlotView {
    char pad0[0x1B664];
    s32 unk1B664; /* +0x1B664: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneSelectedActorSlotSizeCheck[(sizeof(SceneSelectedActorSlotView) == 0x1B668) ? 1 : -1];
#endif
