#ifndef SCENE_SHARED_S2_H
#define SCENE_SHARED_S2_H
#include "TYPES.H"

typedef struct ScenePlayerResourceView ScenePlayerResourceView;
struct ScenePlayerResourceView {
    char pad0[0x5D8];
    struct Shared_func_80286A78_S6 * profile; /* +0x5D8: src/func_80286A78.c */
    char pad5DC[0xE78];
    s32 controllerState; /* +0x1454: src/func_80286A78.c */
};
typedef char ScenePlayerResourceViewSizeCheck[(sizeof(ScenePlayerResourceView) == 0x1458) ? 1 : -1];
#endif
