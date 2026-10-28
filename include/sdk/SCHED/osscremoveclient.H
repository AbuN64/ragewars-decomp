#ifndef SDK_SCHED_OSSCREMOVECLIENT_H
#define SDK_SCHED_OSSCREMOVECLIENT_H
#include "COMMON/WORLDSORTENTRY.H"
extern void osScAddClient(OSSched *, OSScClientWork *, OSMesgQueue *);
extern OSSched D_80142928;
extern OSMesgQueue D_801428C0;
extern OSScClientWork D_80146CC0;
extern void osScRemoveClient(struct OSSched *scheduler, void *arg1);
extern int Sched_GetInterruptQueueAddress(int arg0);
extern void *Sched_GetTaskWithAvailableFramebuffer(struct OSScTask_s *arg0);
extern void *Sched_GetCommandQueue(void *object);
extern s32 Sched_SelectRunnableTasks(struct OSSched *, struct OSScTask_s **, struct OSScTask_s **, s32);
extern void Sched_StartSelectedTasks(struct OSSched *, struct OSScTask_s *, struct OSScTask_s *);
extern s32 Sched_CompleteTaskAndSwapBuffer(void *,void *);
#endif
