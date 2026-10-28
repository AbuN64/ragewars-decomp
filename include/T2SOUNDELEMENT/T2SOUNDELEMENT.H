#ifndef T2SOUNDELEMENT_T2SOUNDELEMENT_H
#define T2SOUNDELEMENT_T2SOUNDELEMENT_H
#include "COMMON/STATERECAT34.H"
extern void SoundElement_InitializeContext(void);
extern s32 SoundElement_PlayPositionedSoundWithScale(s32 trackId, CVector3 soundPosition, s32 spatialMode, s32 ownerId, f32 playbackScale);
extern s32 SoundElement_PlayFlatSound(s32 track);
extern s32 SoundElement_PlayInstrumentAtPosition(s32 index, CVector3 position, s32 voiceParameter);
extern int SoundElement_PlayFlatInstrument(int index);
extern s32 SoundElement_CountOwnerVoices(s32 owner);
extern void SoundElement_PlayDialogGroup(s32 callback);
extern void SoundElement_StopDialog(void);
extern void SoundElement_StopSoundsByIdentifier(s32 soundId);
extern void SoundElement_StopAudioByKey(s32 matchingKey);
extern void SoundElement_StopAudioBySecondaryValue(s32 matchingValue);
extern void SoundElement_StopAudioByMask(s32 matchingFlags);
extern void SoundElement_StopAudioExceptKey(s32 retainedKey);
extern void SoundElement_UpdateContext(void);
#endif
