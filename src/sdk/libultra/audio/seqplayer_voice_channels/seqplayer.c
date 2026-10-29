#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
#include "AUDIO/AUDIO_ASSERT.H"
#include "COMMON/ALDELAY28.H"

/* seqplayer_4.c */
extern char g_sequencePlayerAssertText;
extern char g_audioSeqplayerText;

void *__lookupSoundQuick(void *seqPlayer, s32 noteKey, s32 noteVelocity, s32 channelNumber) {
    s32 high;
    s32 low;
    s32 middle;
    u8 x;
    u8 y;
    ALInstrument *table;
    ALSound_s *entry;
    u8 *bounds;

    table = ((ALSeqPlayer *)seqPlayer)->chanState[channelNumber & 0xFF].instrument;
    high = table->soundCount;
    low = 1;
    if (table == 0) {
        Audio_Assert(&g_sequencePlayerAssertText, &g_audioSeqplayerText, 0x376);
    }

    if (high > 0) {
        x = noteKey;
        y = noteVelocity;
        do {
            middle = (low + high) / 2;
            entry = table->soundArray[middle - 1];
            bounds = (u8 *)entry->keyMap;
            if (x >= bounds[2] && x <= bounds[3] &&
                y >= bounds[0] && y <= bounds[1]) {
                return entry;
            }
            if (x < bounds[2] ||
                (y < bounds[0] && x <= bounds[3])) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        } while (low <= high);
    }
    return 0;
}

/* seqplayer_voice_channels.c */
extern void __setInstChanState(void *seqPlayer, void *selectedInstrument, s32 channelNumber);

/* __vsVol, drafted from ultralib src/audio/seqplayer.c: combine a voice's tremolo, velocity and
   envelope gain with its sound's sample volume, the player volume and the channel volume. */

s16 __vsVol(ALVoiceState *vs, ALSeqPlayer *seqp)
{
    u32 t1, t2;

    t1 = (vs->tremelo * vs->velocity * vs->envGain) >> 6;
    t2 = (vs->sound->sampleVolume * seqp->vol *
          seqp->chanState[vs->channel].vol) >> 14;

    t1 *= t2;
    t1 >>= 15;

    return (s16)t1;
}

/** Clamp (record - arg1) at a lower bound of 0x3E8 for negative results. */
int __vsDelta(void *voiceObject, int currentTime) {
    struct ALVoiceState *voice = voiceObject;
    int v = voice->envEndTime - currentTime;
    if (v >= 0) {
        return v;
    }
    return 0x3E8;
}

s32 __vsPan(void *voiceObject, void *playerObject) {
    ALVoiceState *voice = voiceObject;
    ALSeqPlayer *player = playerObject;
    s32 pan;
    char center = 0x40;
    pan = player->chanState[voice->channel].pan + (voice->sound->samplePan - center);
    if (pan < 0) pan = 0;
    if (pan >= 0x80) pan = 0x7F;
    return pan & 0xFF;
}

void __initFromBank(void *seqPlayer, void *instrumentBank) {
    s32 i;
    ALBank_s *p;
    void *found;

    p = instrumentBank;
    i = 0;
    do {
        found = p->instArray[i];
        i++;
    } while (found == 0);
    i = 0;
    if (((ALSeqPlayer *)seqPlayer)->maxChannels != 0) {
        do {
            __resetPerfChanState(seqPlayer, i);
            __setInstChanState(seqPlayer, found, i);
            i += 1;
        } while (i < ((ALSeqPlayer *)seqPlayer)->maxChannels);
    }
    if (((ALBank_s *)instrumentBank)->percussion != 0) {
        __resetPerfChanState(seqPlayer, i);
        __setInstChanState(seqPlayer, ((ALBank_s *)instrumentBank)->percussion, 9);
    }
}

void __initChanState(void *playerObject) {
    ALSeqPlayer *player = playerObject;
    s32 i;
    s32 off;
    s32 c40, c7f, c5, cc8;
    f32 val;

    i = 0;
    if (player->maxChannels != 0) {
        c40 = 0x40;
        c7f = 0x7F;
        c5 = 5;
        cc8 = 0xC8;
        val = g_sequenceChannelInitialOscillatorValue;
        do {
            off = i << 4;
            player->chanState[i].instrument = 0;
            player->chanState[i].fxId = 0;
            player->chanState[i].fxmix = 0;
            player->chanState[i].pan = (u8) c40;
            player->chanState[i].vol = (u8) c7f;
            player->chanState[i].priority = (u8) c5;
            player->chanState[i].sustain = 0;
            player->chanState[i].bendRange = (u16) cc8;
            player->chanState[i].pitchBend = val;
            i += 1;
        } while (i < (s32) player->maxChannels);
    }
}

/* Initialize one channel of the sequence player's channel table. */
void __resetPerfChanState(void *playerObject, s32 index) {
    ALSeqPlayer *player = playerObject;

    player->chanState[index].fxId = 0;
    player->chanState[index].fxmix = 0;
    player->chanState[index].pan = 0x40;
    player->chanState[index].vol = 0x7F;
    player->chanState[index].priority = 5;
    player->chanState[index].sustain = 0;
    player->chanState[index].bendRange = 0xC8;
    player->chanState[index].pitchBend = g_sequenceInitialPitchBend;
}
