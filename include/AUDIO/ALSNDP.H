#ifndef AUDIO_ALSNDP_H
#define AUDIO_ALSNDP_H
#include "TYPES.H"
/* Sound-player calls shared by the audio units: stop a playing sound, and release one sample of it. */
extern void alSndpStop(void *sound);
extern void alSndpSetSound(void *sound, s16 sample);
#endif
