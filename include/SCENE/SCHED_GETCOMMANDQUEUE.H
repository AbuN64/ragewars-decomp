#ifndef SCENE_SCHED_GETCOMMANDQUEUE_H
#define SCENE_SCHED_GETCOMMANDQUEUE_H
#include "TYPES.H"
struct SchedulerCommandQueueView {
    char pad0[0x78];
    char commandQueue;
};
#endif
