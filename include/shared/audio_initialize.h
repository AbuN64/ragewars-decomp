#ifndef RW_AUDIO_INITIALIZE_H
#define RW_AUDIO_INITIALIZE_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
typedef union AudioQueueMessage { void *pointer; u32 signal; } AudioQueueMessage;
typedef struct AudioTask {
    u32 type, flags;
    void *boot; u32 bootSize;
    void *code; u32 codeSize;
    void *codeData; u32 codeDataSize;
    void *stack; u32 stackSize;
    void *output; u32 outputSize;
    void *commands; u32 commandSize;
    void *yield; u32 yieldSize;
} AudioTask;
typedef struct AudioQueue { u32 words[6]; } AudioQueue;
typedef struct AudioWork {
    s16 *samples;
    u8 reserved4[0x14]; AudioTask task;
    AudioQueue *queue;
    struct AudioWork *message;
    u8 reserved60[0x10];
} AudioWork;
typedef struct AudioCacheEntry {
    struct AudioCacheEntry *next, *prev;
    u32 state; void *buffer;
    u32 link;
} AudioCacheEntry;
typedef struct AudioInitializeConfig {
    u8 reserved0[0x10]; s32 *(*callback)(s32 **);
    ALHeap *heap;
    s32 frequency;
} AudioInitializeConfig;
typedef struct AudioInitializeTiming { u32 frequency, frameTime, samples; } AudioInitializeTiming;
#endif
