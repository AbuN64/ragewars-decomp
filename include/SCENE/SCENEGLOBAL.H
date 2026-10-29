#ifndef SCENE_SCENEGLOBAL_H
#define SCENE_SCENEGLOBAL_H
#include "TYPES.H"

typedef struct Shared_SceneGlobal Shared_SceneGlobal;
struct Shared_SceneGlobal {
    u8 pad0[72]; /* +0x0: src/Scene_LoadLevelResources_SceneResourceState.c */
    u8 address48; /* +0x48: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char Shared_SceneGlobal_size_check[(sizeof(Shared_SceneGlobal) == 0x49) ? 1 : -1];
#endif
