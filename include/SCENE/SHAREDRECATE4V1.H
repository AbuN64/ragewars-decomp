#ifndef SCENE_SHAREDRECATE4V1_H
#define SCENE_SHAREDRECATE4V1_H
#include "SCENE/SCENEACTORKIND.H"
#include "SCENE/SCENEACTORPREFIX.H"

typedef struct SharedRecAtE4V1 SharedRecAtE4V1;
struct SharedRecAtE4V1 {
    Shared_SceneActorPrefix prefix; /* +0x0: src/func_80286A78.c */
    Shared_SceneActorKind kind; /* +0xE4: src/func_80286A78.c */
    char padE6[0x2];
};
typedef char Shared_func_80286A78_S16_size_check[(sizeof(SharedRecAtE4V1) == 0xE8) ? 1 : -1];
#endif
