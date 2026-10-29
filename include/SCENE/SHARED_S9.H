#ifndef SCENE_SHARED_S9_H
#define SCENE_SHARED_S9_H
#include "TYPES.H"

typedef struct ScenePackedResourceCountView ScenePackedResourceCountView;
struct ScenePackedResourceCountView {
    char pad0[0x4];
    s32 count; /* +0x4: src/func_80286A78.c */
};
typedef char ScenePackedResourceCountSizeCheck[(sizeof(ScenePackedResourceCountView) == 0x8) ? 1 : -1];
#endif
