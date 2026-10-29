#ifndef AUDIO_AUDIO_LOADMUSICSEQUENCE_H
#define AUDIO_AUDIO_LOADMUSICSEQUENCE_H
#include "TYPES.H"
struct MusicFadeState {
    char pad[0x18];
    s32 playbackState;
    s32 fadeMode;
    s32 currentMidiVolume;
    s32 baseVolume;
    s32 requestedSequence;
    f32 volume;
    f32 fadeDuration;
    f32 fadeStep;
};
struct MusicStopState {
    unsigned char padding_0[20];
    s32 unk_14;
    unsigned char padding_18[16];
    s32 unk_28;
};
#endif
