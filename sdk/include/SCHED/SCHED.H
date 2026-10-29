#ifndef SCHED_SCHED_H
#define SCHED_SCHED_H
#include "TYPES.H"
#include "COMMON/OSTASK_T.H"
/* Scheduler message: type 1 retrace, 2 task done, 4 pre-NMI. */
typedef struct OSScMsg {
    s16 type;
    char misc[0x1E];
} OSScMsg;
/* Scheduler task, 0x68 bytes. */
typedef struct OSScTask_s {
    struct OSScTask_s *next; /* 0x00 */
    u32 state;
    u32 flags;
    void *framebuffer; /* 0x0C */
    OSTask_t list; /* 0x10 */
    OSMesgQueue *msgQ; /* 0x50 */
    void *msg; /* 0x54 */
    u32 startTime[2]; /* 0x58 */
    u32 totalTime[2]; /* 0x60 */
} OSScTask_s;
#endif
