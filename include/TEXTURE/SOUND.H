#ifndef TEXTURE_SOUND_H
#define TEXTURE_SOUND_H
#include "COMMON/STATERECAT34.H"
extern int Sound_PlayInstrumentAtPosition(void *self, int index, CVector3 position, int voiceParameter);
extern s32 Sound_StopSoundsByIdentifier(void *context, s32 id);
#endif
