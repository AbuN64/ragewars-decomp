#ifndef ACTORS_80277444_8_H
#define ACTORS_80277444_8_H
#include "COMMON/OBJECTLINKS150C.H"
extern void Link_SelectTriggerMusic(void *arg0);
extern void Link_CaptureActorTransform(void *arg0, void *arg1);
extern void Link_PlayTriggerSound(void *arg0);
extern void Link_DispatchTriggerAudio(s32 arg0, s32 arg1, struct Trigger *arg2);
extern void Link_ClearActorFlagMask(struct LevelActor *object);
extern void Link_PlayTriggerSoundCallback(int arg0, int arg1, void *arg2);
#endif
