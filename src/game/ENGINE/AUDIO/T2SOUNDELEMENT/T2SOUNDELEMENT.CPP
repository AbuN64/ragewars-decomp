#include "COMMON/STATERECAT34.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "AUDIO/AUDIO_CHOOSEWEIGHTEDSOUNDVARIANT.H"
#include "TEXTURE/SOUND.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "TEXTURE/SOUND_INITIALIZECONTEXT.H"
#include "include_asm.h"
#include "RENDER/T2SOUNDELEMENT.H"
#include "TEXTURE/SOUND_UPDATEAUDIOCONTEXT.H"

/* 8025DE50_5.CPP */
/** Calls Sound_InitializeContext with &D_8010C080 as its argument. */

struct ContextRecAt2BC0;
extern s32 Audio_PlayPositionedSoundWithScale(struct ContextRecAt2BC0 *context, s32 track, CVector3 position,
                         s32 spatialMode, s32 owner, f32 arg5);

void SoundElement_InitializeContext(void) {
    Sound_InitializeContext(&D_8010C080);
}

s32 SoundElement_PlaySoundAtPosition(s16 track, CVector3 soundPosition, s32 position, s32 ownerId) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Sound_PlaySoundAtPosition(&D_8010C080, track, soundPosition, position, ownerId);
}

s32 SoundElement_PlayPositionedSoundWithScale(s32 trackId, CVector3 soundPosition, s32 spatialMode, s32 ownerId, f32 playbackScale) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Audio_PlayPositionedSoundWithScale(&D_8010C080, (s16)trackId, soundPosition, spatialMode, ownerId, playbackScale);
}

s32 SoundElement_PlayFlatSound(s32 track) {
    s32 playbackResult;
    s32 previousMixValue;

    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    {
        CVector3 vec;
        register f32 zero = 0.0f;

        vec.z = zero;
        vec.y = zero;
        vec.x = zero;
        previousMixValue = Audio_GetVoiceMixValue(&D_8010C080);
        Audio_SetVoiceMixValue(&D_8010C080, 1);
        playbackResult = Sound_PlaySoundAtPosition(&D_8010C080, (s16)track, vec, 0, -1);
        Audio_SetVoiceMixValue(&D_8010C080, previousMixValue);
    }
    return playbackResult;
}

s32 SoundElement_PlayInstrumentAtPosition(s32 index, CVector3 position, s32 voiceParameter) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Sound_PlayInstrumentAtPosition(&D_8010C080, index, position, voiceParameter);
}

int SoundElement_PlayFlatInstrument(int index) {
    int playbackResult;
    int previousMixValue;

    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    {
        CVector3 vec;
        register float zero = (float)0;

        vec.z = zero;
        vec.y = zero;
        vec.x = zero;
        previousMixValue = Audio_GetVoiceMixValue(&D_8010C080);
        Audio_SetVoiceMixValue(&D_8010C080, 1);
        playbackResult = Sound_PlayInstrumentAtPosition(&D_8010C080, index, vec, 0);
        Audio_SetVoiceMixValue(&D_8010C080, previousMixValue);
    }
    return playbackResult;
}

/* 8025DE50_6.CPP */
/* Return the existing owner-count result to callers that test it. */
s32 SoundElement_CountOwnerVoices(s32 owner)
{
    return Audio_CountSoundVoices((char *)&D_8010C080, owner);
}

/* 8025DE50_7.CPP */
void SoundElement_PlayDialogGroup(s32 callback) {
    if (D_8011FAC0.transitionBlocked == 0) {
        Audio_PlayDialogGroup(&D_8010C080, callback);
    }
}

void SoundElement_StopDialog(void) {
    Audio_StopContextDialog((s32) &D_8010C080);
}

void SoundElement_StopSoundsByIdentifier(s32 soundId) {
    Sound_StopSoundsByIdentifier(&D_8010C080, soundId);
}

void SoundElement_StopAudioByKey(s32 matchingKey) {
    Audio_StopAudioByKey(&D_8010C080, matchingKey);
}

void SoundElement_StopAudioBySecondaryValue(s32 matchingValue) {
    Audio_StopAudioBySecondaryValue(&D_8010C080, matchingValue);
}

void SoundElement_StopAudioByMask(s32 matchingFlags) {
    Audio_StopAudioByMask(&D_8010C080, matchingFlags);
}

void SoundElement_StopAudioExceptKey(s32 retainedKey) {
    Audio_StopAudioExceptKey(&D_8010C080, retainedKey);
}

void SoundElement_UpdateContext(void) {
    Sound_UpdateAudioContext(&D_8010C080);
}
