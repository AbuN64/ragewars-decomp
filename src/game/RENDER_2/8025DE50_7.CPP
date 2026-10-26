#include "COMMON/STATERECAT34.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "AUDIO_2/802591C0.H"
#include "TEXTURE/80256220_15.H"
#include "TEXTURE/80256220_16.H"

void func_8025E11C_de(s32 callback) {
    if (D_8011FAC0.transitionBlocked == 0) {
        Audio_PlayDialogGroup(&D_8010C080, callback);
    }
}

void func_8025E150_de(void) {
    Audio_StopContextDialog((s32) &D_8010C080);
}

void func_8025E174_de(s32 soundId) {
    func_80257A14_de(&D_8010C080, soundId);
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
    func_8025842C_de(&D_8010C080);
}
