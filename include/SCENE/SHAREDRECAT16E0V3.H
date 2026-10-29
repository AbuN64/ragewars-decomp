#ifndef SCENE_SHAREDRECAT16E0V3_H
#define SCENE_SHAREDRECAT16E0V3_H
#include "TYPES.H"

typedef struct ScenePlayerNavigationLinkView ScenePlayerNavigationLinkView;
struct ScenePlayerNavigationLinkView {
    char pad0[0x8];
    u8 address8; /* +0x8: src/func_80286A78.c */
    char pad9[0x144B];
    void * navigationRecord; /* +0x1454: src/func_80286A78.c */
    char pad1458[0x288];
    void * nextPlayer; /* +0x16E0: src/func_80286A78.c */
};
typedef char ScenePlayerNavigationLinkSizeCheck[(sizeof(ScenePlayerNavigationLinkView) == 0x16E4) ? 1 : -1];
#endif
