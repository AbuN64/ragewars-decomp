#include "span_1000/code_802AD504.h"
#include "audio_events.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"
#include "common/unused.h"

/* alCSeqNewMarker, drafted from ultralib src/audio/cseq.c: fill a compressed-sequence marker
   with the track state of the first event at or after the given tick count, stepping a scratch
   copy of the sequence. The -O3 library inlined alCSeqNew and alCSeqNextEvent into it; they are
   static inline helpers here, with alCSeqNew's u32-to-float conversion written out against the
   cartridge constants and each deltaFlag store made through a pointer local, as the library's
   -fforce-addr kept it frame-relative. */


 /* __readVarLen */


 /* __alCSeqGetTrackEvent */

 /* 4294967296.0 */

 /* 1.0f */
static inline void alCSeqNew(ALCSeq_s *seq, u8 *ptr)
{
    extern u32 func_802AEA2C_de(ALCSeq_s *, u32);
    u32 i, tmpOff, flagTmp;
    f64 t;
    s32 division;
    u32 *deltaFlag;
    seq->base = (ALCMidiHdr *)ptr;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    deltaFlag = &seq->deltaFlag;
    *deltaFlag = 1;
    for (i = 0; i < 16; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = 0;
        seq->curBULen[i] = 0;
        tmpOff = seq->base->trackOffset[i];
        if (tmpOff) {
            flagTmp = 1 << i;
            seq->validTracks |= flagTmp;
            seq->curLoc[i] = (u8 *)((u32)ptr + tmpOff);
            seq->evtDeltaTicks[i] = func_802AEA2C_de(seq, i);
        } else
            seq->curLoc[i] = 0;
    }
    division = seq->base->division;
    t = (f64)division;
    if (division < 0) {
        t += D_800C72F0_de;
    }
    seq->qnpt = D_800C72F8_de / (f32)t;
}

static inline void alCSeqNextEvent(ALCSeq_s *seq, ALEvent *evt)
{
    extern u32 func_802AEA2C_de(ALCSeq_s *, u32);
    extern u32 func_802AE030_de(ALCSeq_s *, u32, ALEvent *);
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 firstTrack;
    u32 lastTicks = seq->lastDeltaTicks;
    u32 *deltaFlag;
    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag)
                seq->evtDeltaTicks[i] -= lastTicks;
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
                firstTrack = i;
            }
        }
    }
    func_802AE030_de(seq, firstTrack, evt);
    evt->msg.midi.ticks = firstTime;
    seq->lastTicks += firstTime;
    seq->lastDeltaTicks = firstTime;
    if (evt->type != 0x12)
        seq->evtDeltaTicks[firstTrack] += func_802AEA2C_de(seq, firstTrack);
    deltaFlag = &seq->deltaFlag;
    *deltaFlag = 1;
}

void func_802AE290_de(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks)
{
    ALEvent evt;
    ALCSeq_s tempSeq;
    s32 i;
    alCSeqNew(&tempSeq, (u8 *)seq->base);
    do {
        m->validTracks = tempSeq.validTracks;
        m->lastTicks = tempSeq.lastTicks;
        m->lastDeltaTicks = tempSeq.lastDeltaTicks;
        for (i = 0; i < 16; i++) {
            m->curLoc[i] = tempSeq.curLoc[i];
            m->curBUPtr[i] = tempSeq.curBUPtr[i];
            m->curBULen[i] = tempSeq.curBULen[i];
            m->lastStatus[i] = tempSeq.lastStatus[i];
            m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }
        alCSeqNextEvent(&tempSeq, &evt);
        if (evt.type == AL_SEQ_END_EVT)
            break;
    } while (tempSeq.lastTicks < ticks);
}

/* __getTrackByte, drafted from ultralib src/audio/cseq.c: read the next byte of a compressed
   sequence track, following a back-up block (0xFE, offset, length) into the track's earlier data
   and counting down the back-up length while in it. */
u8 func_802AE500_de(ALCSeq_s *seq, u32 track)
{
    u8 theByte;
    if (seq->curBULen[track]) {
        theByte = *seq->curBUPtr[track];
        seq->curBUPtr[track]++;
        seq->curBULen[track]--;
    } else {
        theByte = *seq->curLoc[track];
        seq->curLoc[track]++;
        if (theByte == 0xFE) {
            u8 loBackUp, hiBackUp, theLen, nextByte;
            u32 backup;
            nextByte = *seq->curLoc[track];
            seq->curLoc[track]++;
            if (nextByte != 0xFE) {
                hiBackUp = nextByte;
                loBackUp = *seq->curLoc[track];
                seq->curLoc[track]++;
                theLen = *seq->curLoc[track];
                seq->curLoc[track]++;
                backup = (u32)hiBackUp;
                backup = backup << 8;
                backup += loBackUp;
                seq->curBUPtr[track] = seq->curLoc[track] - (backup + 4);
                seq->curBULen[track] = (u32)theLen;
                theByte = *seq->curBUPtr[track];
                seq->curBUPtr[track]++;
                seq->curBULen[track]--;
            }
        }
    }
    return theByte;
}

void func_802AE5B8_de(RuntimeStateRecAtB8 *state, u32 base) {
    extern u32 func_802AEA2C_de(RuntimeStateRecAtB8 *state, u32 index);
    f64 converted;
    s32 count;
    u32 entry;
    u32 i;

    i = 0;
    state->resources = (ResourceTable *)base;
    state->active = 0;
    state->unk10 = 0;
    state->unkC = 0;
    state->one14 = 1;
    do {
        state->flagsA8[i] = 0;
        state->unk58[i] = 0;
        state->flags98[i] = 0;
        entry = state->resources->entries[i];
        if (entry != 0) {
            state->active |= 1U << i;
            state->objects[i] = (void *)(base + entry);
            state->results[i] = func_802AEA2C_de(state, i);
        } else {
            state->objects[i] = 0;
        }
        i++;
    } while (i < 16U);
    count = state->resources->entries[16];
    converted = (f64)count;
    if (count < 0) {
        converted += D_800C7300_de;
    }
    state->scale = D_800C7308_de / (f32)converted;
}

void func_802AE6BC_de(RuntimeState *state, DecodeResult_func_802AE6BC_de *result) {
    extern u32 func_802AEA2C_de(RuntimeState *state, u32 index);
    extern s32 func_802AE030_de(RuntimeState *state, u32 index, DecodeResult *result);
    u32 minimum;
    u32 index;
    u32 selected;
    u32 decrement;

    minimum = -1;
    index = 0;
    decrement = state->previous;
    do {
        if ((state->active >> index) & 1) {
            if (state->first != 0) {
                state->results[index] -= decrement;
            }
            if (state->results[index] < minimum) {
                minimum = state->results[index];
                selected = index;
            }
        }
        index++;
    } while (index < 16);

    func_802AE030_de(state, selected, result);
    result->value = minimum;
    state->previous = minimum;
    state->total += minimum;
    if (result->type != 0x12) {
        u32 delta;

        delta = func_802AEA2C_de(state, selected);
        state->results[selected] += delta;
    }
    state->first = 1;
}

int func_802AE7B0_de(void *arg0) {
    struct ALCSeq_s *sequence = arg0;
    return sequence->lastTicks;
}

f32 func_802AE7BC_de(void **arg0, s32 arg1, s32 arg2) {
    f64 angle;
    f32 arg1f;
    f32 scaled;
    s32 temp_v0;
    f64 val;

    angle = (f64)arg2;
    arg1f = (f32)arg1;
    if (arg2 < 0) {
        angle += D_800C7310_de;
    }
    temp_v0 = ((ObjRecAt40V1 *)((*arg0)))->unk40;
    scaled = arg1f * (f32)angle;
    val = (f64)temp_v0;
    if (temp_v0 < 0) {
        val += D_800C7318_de;
    }
    return scaled / ((f32)val * D_800C7320_de);
}

/* Scales the float argument by the unsigned rate at offset 0x40 of the object behind arg0 times a constant, divides by the unsigned third argument, and returns the quotient converted to unsigned. Adapted from func_802AE7BC_de with the second argument changed to a float, the product and quotient reordered so the rate term multiplies and the third argument divides, and the result converted to u32 with the explicit 2^31 split. */








u32 func_802AE824_de(void **arg0, f32 arg1, s32 arg2) {
    f64 val;
    f64 div;
    f32 arg1f;
    f32 scaled;
    f32 value;
    s32 temp_v0;
    s32 converted;

    temp_v0 = ((ObjRecAt40V1 *)((*arg0)))->unk40;
    arg1f = arg1;
    val = (f64)temp_v0;
    if (temp_v0 < 0) {
        val += D_800C7328_de;
    }
    scaled = arg1f * ((f32)val * D_800C7330_de);
    div = (f64)arg2;
    if (arg2 < 0) {
        div += D_800C7338_de;
    }
    value = scaled / (f32)div;
    if (!(D_800C7340_de <= value)) {
        converted = (s32)value;
    } else {
        converted = (s32)(value - D_800C7340_de);
        converted |= 0x80000000;
    }
    return converted;
}

void func_802AE8C8_de(CopyDest802B3998 *dst, CopySource802B3998 *src) {
    int i;

    dst->word4 = src->word0;
    dst->wordC = src->word4;
    dst->word10 = src->word8;
    for (i = 0; i < 16; i++) {
        dst->words18[i] = src->wordsC[i];
        dst->words58[i] = src->words4C[i];
        dst->bytes98[i] = src->bytes8C[i];
        dst->bytesA8[i] = src->bytes9C[i];
        dst->wordsB8[i] = src->wordsAC[i];
    }
}

void func_802AE93C_de(CopyDest802B3998 *src, CopySource802B3998 *dst) {
    s32 i;

    dst->word0 = src->word4;
    dst->word4 = src->wordC;
    dst->word8 = src->word10;
    for (i = 0; i < 16; i++) {
        dst->wordsC[i] = src->words18[i];
        dst->words4C[i] = src->words58[i];
        dst->bytes8C[i] = src->bytes98[i];
        dst->bytes9C[i] = src->bytesA8[i];
        dst->wordsAC[i] = src->wordsB8[i];
    }
}

s32 func_802AE9B0_de(ValueSet *set, u32 *result) {
    u32 amount;
    u32 minimum;
    u32 i;

    amount = set->amount;
    minimum = -1;
    if (set->mask == 0) {
        return 0;
    }

    for (i = 0; i < 16; i++) {
        if ((set->mask >> i) & 1) {
            if (set->active != 0) {
                set->values[i] -= amount;
            }
            if (set->values[i] < minimum) {
                minimum = set->values[i];
            }
        }
    }

    set->active = 0;
    *result = minimum;
    return 1;
}
