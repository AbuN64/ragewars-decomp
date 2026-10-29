#ifndef COMMON_LEVEL_PLACEMENT_H
#define COMMON_LEVEL_PLACEMENT_H
#include "COMMON/SHAREDPLAYER.H"
typedef struct Shared_Placed Shared_Placed;
struct Shared_Placed {
    CVector3 pos; /* +0x0: src/func_80220EB0.c */
    f32 heading; /* +0xC: spawn heading */
    s16 kind; /* +0x10: src/func_80220EB0.c */
    s16 pad12; /* +0x12: src/func_80220EB0.c */
};
#endif
