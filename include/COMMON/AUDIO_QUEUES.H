#ifndef COMMON_AUDIO_QUEUES_H
#define COMMON_AUDIO_QUEUES_H
#include "sdk/os.h"
/* The initializer creates these as queues of 10, 10 and 60 messages. */
extern OSMesgQueue g_audioTaskCompletionQueue, g_audioWorkerEventQueue, g_audioDmaCompletionQueue;
#endif
