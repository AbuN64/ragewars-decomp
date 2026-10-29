#ifndef SCENE_SHAREDRECAT10V2_H
#define SCENE_SHAREDRECAT10V2_H
#include "TYPES.H"

typedef struct SceneResourceFlagsView SceneResourceFlagsView;
struct SceneResourceFlagsView {
    char pad0[0x10];
    u8 flags; /* +0x10: src/func_80286A78.c */
};
typedef char SceneResourceFlagsSizeCheck[(sizeof(SceneResourceFlagsView) == 0x11) ? 1 : -1];
#endif
