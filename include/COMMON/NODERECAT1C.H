#ifndef COMMON_NODERECAT1C_H
#define COMMON_NODERECAT1C_H
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
struct Node802C07B0;
typedef struct Node802C07B0 Node802C07B0;

struct TimerInterruptNode;

struct Node802C07B0;
struct Node802C07B0 {
    s32 next;
    s32 prev;
    u64 interval;
    u64 value;
    void *mq;
    void *msg;
};

extern void Util_InitializeTimerServices(void);



struct ThreadNode;
struct ThreadNode {
    struct ThreadNode *next;
    s32 priority;
    struct ThreadNode **queue;
    s32 tlnext;
    u16 state;
};

struct ThreadNode;
typedef struct ThreadNode ThreadNode;

struct TimerInterruptNode;
typedef struct TimerInterruptNode TimerInterruptNode;
#endif
