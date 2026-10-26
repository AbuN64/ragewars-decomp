#include "COMMON/STATERECAT34.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "AUDIO_2/802591C0.H"
#include "TEXTURE/80256220_15.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "TEXTURE/80256220_14.H"

/** Calls func_80257360_de with &D_8010C080 as its argument. */





struct ContextRecAt2BC0;
extern s32 Audio_PlayPositionedSoundWithScale(struct ContextRecAt2BC0 *arg0, s32 arg1, CVector3 arg2,
                         s32 arg3, s32 arg4, f32 arg5);







void func_8025DE30_de(void) {
    func_80257360_de(&D_8010C080);
}

s32 Render_PlaySoundAtPosition(s16 track, CVector3 soundPosition, s32 position, s32 ownerId) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Texture_PlaySoundAtPosition(&D_8010C080, track, soundPosition, position, ownerId);
}

s32 func_8025DEC0_de(s32 trackId, CVector3 soundPosition, s32 spatialMode, s32 ownerId, f32 playbackScale) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Audio_PlayPositionedSoundWithScale(&D_8010C080, (s16)trackId, soundPosition, spatialMode, ownerId, playbackScale);
}

s32 Render_PlayFlatSound(s32 track) {
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
        playbackResult = Texture_PlaySoundAtPosition(&D_8010C080, (s16)track, vec, 0, -1);
        Audio_SetVoiceMixValue(&D_8010C080, previousMixValue);
    }
    return playbackResult;
}

s32 func_8025DFE8_de(s32 index, CVector3 position, s32 voiceParameter) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Texture_PlayInstrumentAtPosition(&D_8010C080, index, position, voiceParameter);
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
        playbackResult = Texture_PlayInstrumentAtPosition(&D_8010C080, index, vec, 0);
        Audio_SetVoiceMixValue(&D_8010C080, previousMixValue);
    }
    return playbackResult;
}
