#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"
#include "sdk/libgultra/__POSTNEXTSEQEVENT.H"
#include "sdk/libgultra/alunlink.h"

extern void alSynSetPriority(void *unused, void *object, s16 value);

extern void alSynSetVol(void *synth, void *voice, s16 targetVolume, s32 rampTime);

extern s32 alEvtqPostEvent(void *, s16 *, s32);

/* Voice events serialize the voice pointer in the first four payload bytes. */
static inline ALVoice_s *event_voice(ALEvent *event) {
    return (ALVoice_s *)event->msg.note.voice;
}

extern s32 __alSeqNextDelta(void *sequence, s32 *deltaTicks);

extern s32 alSeqGetTicks(void *sequence);

extern void alSeqSetLoc(void *sequence, void *marker);

/** Store a new history slot (pointer + selected byte/word fields) into the ring buffer at arg0+0x60. */
void __setInstChanState(void *seqPlayer, void *selectedInstrument, s32 channelNumber) {
    s32 stride = channelNumber * 0x10;

    ((ALChanState *)(stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState))->instrument = selectedInstrument;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->pan = ((ALInstrument *)selectedInstrument)->pan;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->vol = ((ALInstrument *)selectedInstrument)->volume;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->priority = ((ALInstrument *)selectedInstrument)->priority;
    ((ALChanState *)((stride + (s32)((ALSeqPlayer *)seqPlayer)->chanState)))->bendRange = (u16)((ALInstrument *)selectedInstrument)->bendRange;
}

void __seqpReleaseVoice(void *seqPlayer, void *releasedVoice, s32 releaseDuration) {
    ALEventListItem *cur;
    ALEventListItem *next;
    ALVoiceState *object;
    s32 type6;
    SeqplayerVoiceEvent entry;

    object = ((ALVoice_s *)releasedVoice)->clientPrivate;
    if (object->envPhase == 0) {
        cur = (ALEventListItem *)((ALSeqPlayer *)seqPlayer)->evtq.allocList.next;
        if (cur != 0) {
            type6 = 6;
            do {
                next = (ALEventListItem *)cur->node.next;
                if (cur->evt.type == type6 &&
                    event_voice(&cur->evt) == releasedVoice) {
                    if (next != 0) {
                        next->delta = next->delta +
                                            cur->delta;
                    }
                    alUnlink(cur);
                    alLink(cur, &((ALSeqPlayer *)seqPlayer)->evtq);
                }
                cur = next;
            } while (cur != 0);
        }
    }
    object->velocity = 0;
    object->envPhase = 3;
    object->envGain = 0;
    object->envEndTime = ((ALSeqPlayer *)seqPlayer)->curTime + releaseDuration;
    alSynSetPriority(((ALSeqPlayer *)seqPlayer)->drvr, releasedVoice, 0);
    alSynSetVol(((ALSeqPlayer *)seqPlayer)->drvr, releasedVoice, 0, releaseDuration);
    entry.type = 5;
    entry.object = releasedVoice;
    alEvtqPostEvent(&((ALSeqPlayer *)seqPlayer)->evtq, &entry, releaseDuration);
}

void __seqpStopOsc(void *seqPlayer, void *voiceState) {
    ALEventListItem *cur;
    ALEventListItem *next;
    u16 type;
    s32 type16;

    cur = (void *)((ALSeqPlayer *)seqPlayer)->evtq.allocList.next;
    if (cur != 0) {
        type16 = 0x16;
        do {
            type = cur->evt.type;
            next = (void *)cur->node.next;
            if ((type == 0x16 || type == 0x17) &&
                ((ALEvent *)&cur->evt)->msg.osc.vs == voiceState) {
                ((ALSeqPlayer *)seqPlayer)->stopOsc(
                    ((ALEvent *)&cur->evt)->msg.osc.oscState);
                alUnlink(cur);
                if (next != 0) {
                    next->delta = next->delta +
                                        cur->delta;
                }
                alLink(cur, &((ALSeqPlayer *)seqPlayer)->evtq.freeList.next);
                if ((short)type == type16) {
                    ((ALVoiceState *)voiceState)->flags &= 0xFE;
                } else {
                    ((ALVoiceState *)voiceState)->flags &= 0xFD;
                }
                if (((ALVoiceState *)voiceState)->flags == 0) {
                    break;
                }
            }
            cur = next;
        } while (cur != 0);
    }
}

void __postNextSeqEvent(void *seqPlayer) {
    ALEvent referenceEvent;
    s32 deltaTicks;
    s32 remainingLoops;
    void *sequence;

    sequence = ((SequencePlayerEventView *)(seqPlayer))->unk_18;
    if ((((SequencePlayerEventView *)(seqPlayer))->unk_2C == 1) && (sequence != 0) &&
        (__alSeqNextDelta(sequence, &deltaTicks) & 0xFF)) {
        if ((((SequencePlayerEventView *)(seqPlayer))->unk_84 != 0) &&
            ((alSeqGetTicks(sequence) + deltaTicks) >=
             ((struct MenuTextOwnerView *) ((SequencePlayerEventView *) seqPlayer)->unk_80)->flags)) {
            alSeqSetLoc(sequence, ((SequencePlayerEventView *)(seqPlayer))->unk_7C);
            remainingLoops = ((SequencePlayerEventView *)(seqPlayer))->unk_84;
            if (remainingLoops != -1) {
                ((SequencePlayerEventView *)(seqPlayer))->unk_84 = remainingLoops - 1;
            }
        }
        referenceEvent.type = 0;
        alEvtqPostEvent(&((SequencePlayerEventView *)(seqPlayer))->unk_48, &referenceEvent,
                      deltaTicks * ((SequencePlayerEventView *)(seqPlayer))->unk_24);
    }
}

extern void Seqplayer_SetTempoMicrosecondsPerTick(void *player, f32 tempo);

void __handleMetaMsg(void *player, void *metaEvent) {
    u8 *p = (u8 *)metaEvent;
    int pad[4];

    (void)pad;
    if (p[8] == 0xFF && p[9] == 0x51) {
        Seqplayer_SetTempoMicrosecondsPerTick(player, (f32)((p[0xB] << 0x10) | (p[0xC] << 8) | p[0xD]));
    }
}
