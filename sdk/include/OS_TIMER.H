#ifndef OS_TIMER_H
#define OS_TIMER_H
#include "TYPES.H"
typedef struct OSTimer_s OSTimer_s;
typedef struct OSTimer_s OSTimer;
struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    u64 interval;
    u64 value;
    OSMesgQueue *mq;
    void *msg;
};
#endif
