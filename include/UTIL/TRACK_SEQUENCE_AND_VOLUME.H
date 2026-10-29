#ifndef UTIL_TRACK_SEQUENCE_AND_VOLUME_H
#define UTIL_TRACK_SEQUENCE_AND_VOLUME_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
extern void Sequencer_SetTrackVolume(void *track, f32 volume);
extern void Sequencer_UpdateTrackVolume(void *trackState);
extern void Sequencer_AttachTrackSequence(struct Track *track);
#endif
