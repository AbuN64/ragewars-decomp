#ifndef UNBAKE_SPAN_1000_CODE_802536F4_H
#define UNBAKE_SPAN_1000_CODE_802536F4_H
#include "types.h"
/* The resource API retains an unused arena selector. */
void func_80253908_de(s32 unusedHeap);
#include "common/types_1dc8418c21db.h"
extern int func_802547CC_de(void);

extern s32 func_80253AD4_de();

extern int func_802547BC_de(void);

extern void func_80254D00_de(void);

extern int func_8025478C_de(void);

struct func_80254420_S1;
struct func_80254420_S1 {
    char pad0[0x1C];
    u32 unk1C;
};

extern void *func_80254A28_de(s32 unused0, s32 arg1);

struct func_8025398C_S1;
typedef struct func_8025398C_S1 func_8025398C_S1;

extern int D_80104580;

struct NodePair80253E04;
typedef struct NodePair80253E04 NodePair80253E04;

extern int D_80101108;

struct NodePair80253E04;
struct NodePair80253E04 {
    Node80253610 *first;
    Node80253610 *second;
};

extern int func_802547AC_de(void);

struct func_80254420_S1;
typedef struct func_80254420_S1 func_80254420_S1;

struct func_8025398C_S1;
struct func_8025398C_S1 {
    char pad0[0xB98];
    char unkB98;
};

/* Resource manager slot and its wait queue (D_801005A8 / D_80101140). */
typedef struct ResourceLockState {
    s32 slot;
    u8 reserved4[0xB98 - 4];
    OSMesgQueue waitQueue;
} ResourceLockState;

#endif
