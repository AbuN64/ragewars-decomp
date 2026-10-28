#include "COMMON/STATERECAT34.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "AUDIO/802591C0.H"
#include "TEXTURE/80256220_15.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "TEXTURE/SOUND_INITIALIZECONTEXT.H"
#include "include_asm.h"
#include "RENDER/8025DE50_6.H"
#include "TEXTURE/80256220_16.H"

/* 8025DE50_5.CPP */
/** Calls Sound_InitializeContext with &D_8010C080 as its argument. */

struct ContextRecAt2BC0;
extern s32 Audio_PlayPositionedSoundWithScale(struct ContextRecAt2BC0 *arg0, s32 arg1, CVector3 arg2,
                         s32 arg3, s32 arg4, f32 arg5);

void func_8025DE30_de(void) {
    Sound_InitializeContext(&D_8010C080);
}

s32 SoundElement_PlaySoundAtPosition(s16 track, CVector3 soundPosition, s32 position, s32 ownerId) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Sound_PlaySoundAtPosition(&D_8010C080, track, soundPosition, position, ownerId);
}

s32 func_8025DEC0_de(s32 trackId, CVector3 soundPosition, s32 spatialMode, s32 ownerId, f32 playbackScale) {
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

s32 func_8025DFE8_de(s32 index, CVector3 position, s32 voiceParameter) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Sound_PlayInstrumentAtPosition(&D_8010C080, index, position, voiceParameter);
}

int func_8025E04C_de(int index) {
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
s32 func_8025E0F4_de(s32 owner)
{
    return Audio_CountSoundVoices((char *)&D_8010C080, owner);
}

/* 8025DE50_7.CPP */
void func_8025E11C_de(s32 callback) {
    if (D_8011FAC0.transitionBlocked == 0) {
        Audio_PlayDialogGroup(&D_8010C080, callback);
    }
}

void func_8025E150_de(void) {
    Audio_StopContextDialog((s32) &D_8010C080);
}

void func_8025E174_de(s32 soundId) {
    Sound_StopSoundsByIdentifier(&D_8010C080, soundId);
}

void func_8025E19C_de(s32 matchingKey) {
    Audio_StopAudioByKey(&D_8010C080, matchingKey);
}

void func_8025E1C4_de(s32 matchingValue) {
    Audio_StopAudioBySecondaryValue(&D_8010C080, matchingValue);
}

void func_8025E1EC_de(s32 matchingFlags) {
    Audio_StopAudioByMask(&D_8010C080, matchingFlags);
}

void func_8025E214_de(s32 retainedKey) {
    Audio_StopAudioExceptKey(&D_8010C080, retainedKey);
}

void func_8025E23C_de(void) {
    Sound_UpdateAudioContext(&D_8010C080);
}
