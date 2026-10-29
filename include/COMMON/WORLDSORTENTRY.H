#ifndef COMMON_WORLDSORTENTRY_H
#define COMMON_WORLDSORTENTRY_H
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "sdk/SCHED/SCHED.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
typedef struct WorldSortEntry { s32 item; f32 distance; } WorldSortEntry;

struct Def;
struct Def {
    s32 type;
    s32 flags; /* 0x4 */
    char pad8[0x20];
    s16 id;
};
struct Def;

struct LevelActorArrayView;
typedef struct LevelActorArrayView LevelActorArrayView;



extern float g_schedulerVideoYScale;

struct NearbySpecialActorView;

struct Shared_World;





struct Panel;
struct Panel {
    s16 active;
    char pad2[0x20 - 2];
    s16 mode;
    char pad22[0x40 - 0x22];
    char row0[0x18];
    char row0Slots[0x20];
    char row1[0x18];
    char row1Slots[0x20];
    char elements[0x2E0 - 0xB0];
    s32 clientList;
    s32 audioListHead;
    s32 gfxListHead;
    s32 audioListTail;
    s32 gfxListTail;
    s32 curRSPTask;
    s32 curRDPTask;
    s32 frameCount;
    s32 doAudio;
};


extern int g_schedulerRdpBufferSetFlag;


struct SchedulerCurrentRspTaskView;
struct SchedulerCurrentRspTaskView {
    unsigned char padding_0[756];
    void *currentRspTask;
};

struct LevelActor;
struct LevelActorArrayView;
struct LevelActorArrayView {
    char pad[0x138];
    struct LevelActor *actors;
    s32 pad13C;
    s32 count;
};

extern float g_sceneImageVectorTolerance;







struct OSScClientWork;
struct OSScClientWork {
    struct OSScClientWork *next;
    OSMesgQueue *queue;
};




struct SchedulerTaskFlagsView;
typedef struct SchedulerTaskFlagsView SchedulerTaskFlagsView;



struct OSSched;




struct SchedulerCommandQueueView;
typedef struct SchedulerCommandQueueView SchedulerCommandQueueView;

struct IntPair;


extern int g_schedulerShutdownPending;




struct OSScClientWork;
struct OSScTask_s;
struct OSSched;
struct OSSched {
    char pad0[0x20];
    s16 retraceMessage; /* 0x20 */
    char pad22[0x40 - 0x22];
    OSMesgQueue interruptQueue; /* 0x40 */
    char pad58[0x78 - 0x58];
    OSMesgQueue commandQueue; /* 0x78 */
    char pad90[0x2E0 - 0x90];
    struct OSScClientWork *clientList;
    struct OSScTask_s *audioListHead;
    struct OSScTask_s *gfxListHead;
    struct OSScTask_s *audioListTail;
    struct OSScTask_s *gfxListTail;
    struct OSScTask_s *curRSPTask;
    struct OSScTask_s *curRDPTask;
    u32 frameCount;
    s32 doAudio;
};


struct ImageSet;
struct ImageSet {
    u16 columns;
    u16 rows;
    u16 width;
    u16 height;
};

struct ImageSet;
typedef struct ImageSet ImageSet;


struct OSScClientWork;
typedef struct OSScClientWork OSScClientWork;


struct SchedulerCurrentRspTaskView;
typedef struct SchedulerCurrentRspTaskView SchedulerCurrentRspTaskView;



struct OSSched;
typedef struct OSSched OSSched;

struct NearbySpecialActorView;
typedef struct NearbySpecialActorView NearbySpecialActorView;

struct NodeSchedHandleTaskCommands;
typedef struct NodeSchedHandleTaskCommands NodeSchedHandleTaskCommands;

struct SchedulerCommandQueueView;









struct Panel;
typedef struct Panel Panel;

struct NodeSchedHandleTaskCommands;
struct NodeSchedHandleTaskCommands {
    char pad0[8];
    u32 flags;
    char padC[4];
    s32 type;
};





struct SchedulerTaskFlagsView;
struct SchedulerTaskFlagsView {
    unsigned char padding_0[4];
    s32 state;
    unsigned char padding_8[8];
    s32 taskType;
};



extern f32 g_schedulerAudioDuration;
extern s32 g_schedulerRetraceCount;
#endif
