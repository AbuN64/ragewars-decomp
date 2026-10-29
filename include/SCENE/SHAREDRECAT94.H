#ifndef SCENE_SHAREDRECAT94_H
#define SCENE_SHAREDRECAT94_H
#include "TYPES.H"

typedef struct SceneStatusBarModeView SceneStatusBarModeView;
struct SceneStatusBarModeView {
    char pad0[0x84];
    u8 address84; /* +0x84: src/func_80286A78.c */
    char pad85[0xF];
    u8 statusBarMode; /* +0x94: src/func_80286A78.c */
};
typedef char SceneStatusBarModeSizeCheck[(sizeof(SceneStatusBarModeView) == 0x95) ? 1 : -1];
#endif
