#ifndef SCENE_SHAREDRECAT16E0V3_H
#define SCENE_SHAREDRECAT16E0V3_H
#include "TYPES.H"

typedef struct ScenePlayerNavigationLinkView ScenePlayerNavigationLinkView;
struct ScenePlayerNavigationLinkView {
    char pad0[0x8];
    u8 address8; /* +0x8: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad9[0x144B];
    void * navigationRecord; /* +0x1454: src/Scene_LoadLevelResources_SceneResourceState.c */
    char pad1458[0x288];
    void * nextPlayer; /* +0x16E0: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char ScenePlayerNavigationLinkSizeCheck[(sizeof(ScenePlayerNavigationLinkView) == 0x16E4) ? 1 : -1];
#endif
