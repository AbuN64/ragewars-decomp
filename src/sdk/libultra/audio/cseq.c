#include "sdk/OBJECTSTATE2.H"
#include "sdk/AUDIO_EVENTS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/libgultra_inferred/cseq.H"
#include "include_asm.h"
#include "sdk/libgultra_inferred/ALCSPGETSTATE.H"

s32 __readVarLen(ALCSeq_s *seq, s32 track);
extern u32 __alCSeqGetTrackEvent(ALCSeq_s *, u32, ALEvent *);

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
static inline void alCSeqNewMarkerInitSequence(ALCSeq_s *seq, u8 *ptr)
{
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
            seq->evtDeltaTicks[i] = __readVarLen(seq, i);
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

static inline void alCSeqNewMarkerNextEvent(ALCSeq_s *seq, ALEvent *evt)
{
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
    __alCSeqGetTrackEvent(seq, firstTrack, evt);
    evt->msg.midi.ticks = firstTime;
    seq->lastTicks += firstTime;
    seq->lastDeltaTicks = firstTime;
    if (evt->type != 0x12)
        seq->evtDeltaTicks[firstTrack] += __readVarLen(seq, firstTrack);
    deltaFlag = &seq->deltaFlag;
    *deltaFlag = 1;
}

void alCSeqNewMarker(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks)
{
    ALEvent evt;
    ALCSeq_s tempSeq;
    s32 i;
    alCSeqNewMarkerInitSequence(&tempSeq, (u8 *)seq->base);
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
        alCSeqNewMarkerNextEvent(&tempSeq, &evt);
        if (evt.type == AL_SEQ_END_EVT)
            break;
    } while (tempSeq.lastTicks < ticks);
}

/* __getTrackByte, drafted from ultralib src/audio/cseq.c: read the next byte of a compressed
   sequence track, following a back-up block (0xFE, offset, length) into the track's earlier data
   and counting down the back-up length while in it. */
u8 __getTrackByte(ALCSeq_s *seq, u32 track)
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

void alCSeqNew(ALCSeq_s *state, ALCMidiHdr *base) {
    f64 converted;
    s32 count;
    u32 entry;
    u32 i;

    i = 0;
    state->base = base;
    state->validTracks = 0;
    state->lastDeltaTicks = 0;
    state->lastTicks = 0;
    state->deltaFlag = 1;
    do {
        state->lastStatus[i] = 0;
        state->curBUPtr[i] = 0;
        state->curBULen[i] = 0;
        entry = state->base->trackOffset[i];
        if (entry != 0) {
            state->validTracks |= 1U << i;
            state->curLoc[i] = (u8 *)base + entry;
            state->evtDeltaTicks[i] = __readVarLen(state, i);
        } else {
            state->curLoc[i] = 0;
        }
        i++;
    } while (i < 16U);
    count = state->base->division;
    converted = (f64)count;
    if (count < 0) {
        converted += D_800C7300_de;
    }
    state->qnpt = D_800C7308_de / (f32)converted;
}

void alCSeqNextEvent(ALCSeq_s *state, ALEvent *result) {
    u32 minimum;
    u32 index;
    u32 selected;
    u32 decrement;

    minimum = -1;
    index = 0;
    decrement = state->lastDeltaTicks;
    do {
        if ((state->validTracks >> index) & 1) {
            if (state->deltaFlag != 0) {
                state->evtDeltaTicks[index] -= decrement;
            }
            if (state->evtDeltaTicks[index] < minimum) {
                minimum = state->evtDeltaTicks[index];
                selected = index;
            }
        }
        index++;
    } while (index < 16);

    __alCSeqGetTrackEvent(state, selected, result);
    result->msg.midi.ticks = minimum;
    state->lastDeltaTicks = minimum;
    state->lastTicks += minimum;
    if (result->type != 0x12) {
        u32 delta;

        delta = __readVarLen(state, selected);
        state->evtDeltaTicks[selected] += delta;
    }
    state->deltaFlag = 1;
}

int alCSeqGetTicks(void *arg0) {
    struct ALCSeq_s *sequence = arg0;
    return sequence->lastTicks;
}

f32 alCSeqTicksToSec(void **sequenceHandle, s32 tickCount, s32 microsecondsPerQuarter) {
    f64 angle;
    f32 arg1f;
    f32 scaled;
    s32 ticksPerQuarter;
    f64 val;

    angle = (f64)microsecondsPerQuarter;
    arg1f = (f32)tickCount;
    if (microsecondsPerQuarter < 0) {
        angle += D_800C7310_de;
    }
    ticksPerQuarter = ((ObjRecAt40V1 *)((*sequenceHandle)))->unk40;
    scaled = arg1f * (f32)angle;
    val = (f64)ticksPerQuarter;
    if (ticksPerQuarter < 0) {
        val += D_800C7318_de;
    }
    return scaled / ((f32)val * D_800C7320_de);
}

/* Scales the float argument by the unsigned rate at offset 0x40 of the object behind arg0 times a constant, divides by the unsigned third argument, and returns the quotient converted to unsigned. Adapted from alCSeqTicksToSec with the second argument changed to a float, the product and quotient reordered so the rate term multiplies and the third argument divides, and the result converted to u32 with the explicit 2^31 split. */

u32 alCSeqSecToTicks(void **sequenceHandle, f32 seconds, s32 microsecondsPerQuarter) {
    f64 val;
    f64 div;
    f32 arg1f;
    f32 scaled;
    f32 value;
    s32 ticksPerQuarter;
    s32 converted;

    ticksPerQuarter = ((ObjRecAt40V1 *)((*sequenceHandle)))->unk40;
    arg1f = seconds;
    val = (f64)ticksPerQuarter;
    if (ticksPerQuarter < 0) {
        val += D_800C7328_de;
    }
    scaled = arg1f * ((f32)val * D_800C7330_de);
    div = (f64)microsecondsPerQuarter;
    if (microsecondsPerQuarter < 0) {
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

void alCSeqSetLoc(ALCSeq_s *dst, ALCSeqMarker *src) {
    int i;

    dst->validTracks = src->validTracks;
    dst->lastTicks = src->lastTicks;
    dst->lastDeltaTicks = src->lastDeltaTicks;
    for (i = 0; i < 16; i++) {
        dst->curLoc[i] = src->curLoc[i];
        dst->curBUPtr[i] = src->curBUPtr[i];
        dst->curBULen[i] = src->curBULen[i];
        dst->lastStatus[i] = src->lastStatus[i];
        dst->evtDeltaTicks[i] = src->evtDeltaTicks[i];
    }
}

void alCSeqGetLoc(ALCSeq_s *src, ALCSeqMarker *dst) {
    s32 i;

    dst->validTracks = src->validTracks;
    dst->lastTicks = src->lastTicks;
    dst->lastDeltaTicks = src->lastDeltaTicks;
    for (i = 0; i < 16; i++) {
        dst->curLoc[i] = src->curLoc[i];
        dst->curBUPtr[i] = src->curBUPtr[i];
        dst->curBULen[i] = src->curBULen[i];
        dst->lastStatus[i] = src->lastStatus[i];
        dst->evtDeltaTicks[i] = src->evtDeltaTicks[i];
    }
}

s32 __alCSeqNextDelta(ALCSeq_s *seq, s32 *result) {
    u32 amount;
    u32 minimum;
    u32 i;

    amount = seq->lastDeltaTicks;
    minimum = -1;
    if (seq->validTracks == 0) {
        return 0;
    }

    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag != 0) {
                seq->evtDeltaTicks[i] -= amount;
            }
            if (seq->evtDeltaTicks[i] < minimum) {
                minimum = seq->evtDeltaTicks[i];
            }
        }
    }

    seq->deltaFlag = 0;
    *result = minimum;
    return 1;
}

u8 __getTrackByte(ALCSeq_s *seq, u32 track);

s32 __readVarLen(ALCSeq_s *seq, s32 track) {
    s32 temp_v0;
    s32 decodedValue;

    decodedValue = (u8) __getTrackByte(seq, track);
    if (decodedValue & 0x80) {
        decodedValue &= 0x7F;
        do {
            temp_v0 = (u8) __getTrackByte(seq, track);
            decodedValue = (decodedValue << 7) + (temp_v0 & 0x7F);
        } while (temp_v0 & 0x80);
    }
    return decodedValue;
}

/** Read the object word at offset 0x2C. */
int alCSPGetState(void *object) {
    ObjRecAt2CV2 *record = object;
    return record->unk2C;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802AE9DC[1] = {
    0x4576656E,
};
#endif

/* ROM-grounded data: rodata/shared/800CC540 */
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US)
const unsigned int D_blob_phase2_c84bcd6fd8b288cdc90d[3] = {
    0x41F00000, 0x00000000, 0x3F800000,
};
#endif
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
const unsigned int D_blob_phase2_c84bcd6fd8b288cdc90d[2] = {
    0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AE290_CD148_us_rev1.c */
const unsigned int D_blob_6068a82f1f3c1327b771[1] = {
    0x3F800000,
};
#endif
