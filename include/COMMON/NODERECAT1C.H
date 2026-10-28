#ifndef COMMON_NODERECAT1C_H
#define COMMON_NODERECAT1C_H
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
struct Node802C07B0;
typedef struct Node802C07B0 Node802C07B0;

struct NodeRecAt1C;

struct Node802C07B0;
struct Node802C07B0 {
    s32 field0;
    s32 field4;
    u64 field8;
    u64 field10;
    void *field18;
    void *field1C;
};

extern void Util_InitializeTimerServices(void);



struct ThreadNode;
struct ThreadNode {
    struct ThreadNode *next;
    s32 priority;
    struct ThreadNode **queue;
    s32 unk0C;
    u16 state;
};

struct ThreadNode;
typedef struct ThreadNode ThreadNode;

struct NodeRecAt1C;
typedef struct NodeRecAt1C NodeRecAt1C;
#endif
