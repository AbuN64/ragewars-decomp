#ifndef SCENE_SHAREDRECAT28V1_H
#define SCENE_SHAREDRECAT28V1_H
#include "TYPES.H"

typedef struct SceneActorDefinitionKindView SceneActorDefinitionKindView;
struct SceneActorDefinitionKindView {
    s32 kind; /* +0x0: src/func_80286A78.c */
    char pad4[0x24];
    s16 flags; /* +0x28: src/func_80286A78.c */
    char pad2A[0x2];
};
typedef char SceneActorDefinitionKindSizeCheck[(sizeof(SceneActorDefinitionKindView) == 0x2C) ? 1 : -1];
#endif
