#ifndef SCENE_SHAREDRECAT98_H
#define SCENE_SHAREDRECAT98_H
#include "TYPES.H"

typedef struct SceneSpecialActorModeView SceneSpecialActorModeView;
struct SceneSpecialActorModeView {
    char pad0[0x98];
    s32 unk98; /* +0x98: src/func_80286A78.c */
};
typedef char SceneSpecialActorModeSizeCheck[(sizeof(SceneSpecialActorModeView) == 0x9C) ? 1 : -1];
#endif
