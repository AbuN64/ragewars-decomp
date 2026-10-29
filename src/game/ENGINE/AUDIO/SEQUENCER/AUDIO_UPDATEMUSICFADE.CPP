#include "COMMON/EXTERNS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "AUDIO/PLAYER_STATE_AND_PARAMETERS.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/COMPRESSED_SEQUENCE_AND_EVENT_VIEWS.H"
#include "COMMON/TRIPLE.H"
#include "AUDIO/AUDIO_UPDATEMUSICFADE.H"
#include "include_asm.h"

/* 8025D470_2.CPP */
s32 alHeapDBAlloc(s32 a, s32 b, void *c, s32 d, s32 e);

void alCSPNew(void *sequencePlayer, InitParams *config);

extern void alCSPStop(s32 player);

void Audio_InitializeMusicPlayer(struct AudioStateD844 *state, struct AudioRootD844 *root) {
    struct AudioParamsD844 params;
    void *player;
    state->root = root;
    state->mode = 16;
    state->index = -1;
    state->flags = 0;
    params.count38 = 20;
    params.count1C = 192;
    params.kind = 20;
    params.context = &state->root->heap;
    params.value10 = 0;
    params.value14 = 0;
    params.value18 = 0;
    player = alHeapDBAlloc(0, 0, &state->root->heap, 1, 0x7C);
    state->player = player;
    alCSPNew(player, &params);
    state->allocation = alHeapDBAlloc(0, 0, &state->root->heap, 1, 0xF8);
    state->timer = 50;
    state->counter = 0;
    state->first = k_musicPlayerInitialUnitValue_de;
    state->second = k_musicPlayerInitialSecondValue_de;
    state->third = k_musicPlayerInitialUnitValue_de;
    state->fourth = k_musicPlayerInitialUnitValue_de;
}

void Audio_UpdateMusicFade(void *queue) {
    MusicTrackVolumeView *o = queue;
    f32 currentGain;
    f32 targetGain;
    f32 nextGain;
    s32 nextVolume;

    if (o->flags & 2) {
        alCSPSetVol(o->unk_14, (s16)o->volume);
        nextVolume = (s32) ((f32) o->volume - o->fadeStep);
        o->volume = nextVolume;
        if (nextVolume <= 0) {
            o->volume = 0;
            alCSPStop(o->unk_14);
            o->flags |= 4;
        }
    } else if (o->unk_38 != 0) {
        currentGain = o->unk_3C;
        targetGain = o->targetGain;
        if (targetGain < currentGain) {
            nextGain = currentGain - g_musicFadeGainStep;
            if (targetGain <= nextGain) {
                goto store;
            }
            goto clamp;
        }
        if (currentGain < targetGain) {
            nextGain = currentGain + (0.01666666753590107f);
            if (nextGain <= targetGain) {
                goto store;
            }
clamp:
            nextGain = targetGain;
store:
            o->unk_3C = nextGain;
        }
    }
}

/* 800C90F8.CPP */
/* ROM-grounded data: src/g_audio_LoadMusicSequenceConstantWords_AudioUpdatemusicfade.c */
const unsigned int g_audio_LoadMusicSequenceConstantWords[1] = {
    0x3DCCCCCD,
};
