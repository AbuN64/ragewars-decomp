#include "span_1000/code_802B243C.h"
#include "audio_events.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"

/* alSeqNextEvent, drafted from ultralib src/audio/seq.c: read the next MIDI file event into an
   ALEvent, decoding tempo and end-of-track meta events and applying running status to channel
   events. */
extern s32 func_802B235C_de(ALSeq_s *);

 /* readVarLen */
extern u8 func_802B23B0_de(ALSeq_s *);

extern s32 func_802B23F4_de(MidiState802B70B8 *state);

extern s16 func_802B23C4_de(MidiState802B70B8 *state);

extern f32 D_800CC740;

/* alSeqSecToTicks, drafted from ultralib src/audio/seq.c: convert seconds to ticks at the given
   tempo. The library evaluates it in single precision as sec * (division * 1e6f), so the product is
   spelled in that order against the cartridge constant after D_800CC740; GCC's u32-to-float and
   float-to-u32 expansions are written out against D_800CC748 and D_800CC750. */
extern const float D_800CC740;

 /* followed by 1000000.0f */
extern const double D_800CC748;

 /* 4294967296.0 */
extern const float D_800CC750;

/* alSeqNewMarker, drafted from ultralib src/audio/seq.c: fill a marker with the sequence position
   of the first event at or after the given tick count (the track start for zero), stepping a
   scratch pass with alSeqNextEvent and restoring the sequence's own position afterwards. */
extern void func_802B1E80_de(ALSeq_s *, ALEvent *);

extern s32 func_802B235C_de(struct ALSeq_s *arg0);

 /* read8 */
void func_802B1E80_de(ALSeq_s *seq, ALEvent *event)
{
    u8 status;
    s32 deltaTicks;
    deltaTicks = func_802B235C_de(seq);
    seq->lastTicks += deltaTicks;
    status = func_802B23B0_de(seq);
    if (status == 0xFF) {
        u8 type = func_802B23B0_de(seq);
        if (type == 0x51) {
            event->type = 3;
            event->msg.tempo.ticks = deltaTicks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len = func_802B23B0_de(seq);
            event->msg.tempo.byte1 = func_802B23B0_de(seq);
            event->msg.tempo.byte2 = func_802B23B0_de(seq);
            event->msg.tempo.byte3 = func_802B23B0_de(seq);
        } else if (type == 0x2F) {
            event->type = AL_SEQ_END_EVT;
            event->msg.end.ticks = deltaTicks;
            event->msg.end.status = status;
            event->msg.end.type = type;
            event->msg.end.len = func_802B23B0_de(seq);
        }
        seq->lastStatus = 0;
    } else {
        event->type = 1;
        event->msg.midi.ticks = deltaTicks;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = func_802B23B0_de(seq);
            seq->lastStatus = status;
        } else {
            event->msg.midi.status = seq->lastStatus;
            event->msg.midi.byte1 = status;
        }
        if (((event->msg.midi.status & 0xf0) != 0xC0) &&
            ((event->msg.midi.status & 0xf0) != 0xD0)) {
            event->msg.midi.byte2 = func_802B23B0_de(seq);
        } else {
            event->msg.midi.byte2 = 0;
        }
    }
}

void func_802B1FE8_de(MidiState802B70B8 *state, s32 start, s32 end) {
    s16 division;

    state->start = start;
    state->end = end;
    state->unk1A = 0;
    state->unkC = 0;
    state->current = start;
    if (func_802B23F4_de(state) == 0x4D546864) {
        func_802B23F4_de(state);
        if (((func_802B23C4_de(state) << 16) == 0) && (func_802B23C4_de(state) == 1)) {
            division = func_802B23C4_de(state);
            state->division = division;
            if (!(division & 0x8000)) {
                state->tick_scale = D_800C74E0_de / (f32) division;
                if (func_802B23F4_de(state) == 0x4D54726B) {
                    func_802B23F4_de(state);
                    state->track_start = state->current;
                }
            }
        }
    }
}

int func_802B20C8_de(struct ALSeq_s *arg0) {
    return arg0->lastTicks;
}

f32 func_802B20D4_de(ObjRecAt18V1 *arg0, s32 arg1, s32 arg2) {
    f64 v;
    f32 new_var;

    v = (f64)arg2;
    new_var = (f32)arg1;
    if (arg2 < 0) {
        v = v + D_800C74E8_de;
    }
    return (new_var * (f32)v) / ((f32)arg0->field18 * D_800CC740);
}

 /* 2147483648.0f */
u32 func_802B2120_de(ObjRecAt18V1 *seq, f32 sec, u32 tempo)
{
    f32 ticks;
    f64 t;
    f32 q;
    u32 result;
    ticks = sec * ((f32)seq->field18 * (*(&D_800CC740 + 1)));
    t = (f64)(s32)tempo;
    if ((s32)tempo < 0) {
        t = t + D_800CC748;
    }
    q = ticks / (f32)t;
    if (!(q >= D_800CC750)) {
        result = (s32)q;
    } else {
        q = q - D_800CC750;
        result = (s32)q;
        result |= 0x80000000;
    }
    return result;
}

 /* alSeqNextEvent */
void func_802B21A8_de(ALSeq_s *seq, ALSeqMarker *m, u32 ticks)
{
    ALEvent evt;
    u8 *savePtr, *lastPtr;
    s32 saveTicks, lastTicks;
    s16 saveStatus, lastStatus;
    if (ticks == 0) {
        m->curPtr = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks = 0;
        m->curTicks = 0;
        return;
    } else {
        savePtr = seq->curPtr;
        saveStatus = seq->lastStatus;
        saveTicks = seq->lastTicks;
        seq->curPtr = seq->trackStart;
        seq->lastStatus = 0;
        seq->lastTicks = 0;
        do {
            lastPtr = seq->curPtr;
            lastStatus = seq->lastStatus;
            lastTicks = seq->lastTicks;
            func_802B1E80_de(seq, &evt);
            if (evt.type == AL_SEQ_END_EVT) {
                lastPtr = seq->curPtr;
                lastStatus = seq->lastStatus;
                lastTicks = seq->lastTicks;
                break;
            }
        } while (seq->lastTicks < ticks);
        m->curPtr = lastPtr;
        m->lastStatus = lastStatus;
        m->lastTicks = lastTicks;
        m->curTicks = seq->lastTicks;
        seq->curPtr = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks = saveTicks;
    }
}

/** Copy selected fields from the compact source record. */
void func_802B22BC_de(ALSeq_s *arg0, ALSeqMarker *arg1) {
    arg0->curPtr = arg1->curPtr;
    arg0->lastStatus = arg1->lastStatus;
    arg0->lastTicks = arg1->lastTicks;
}

/** Copy selected fields into the compact destination record. */
void func_802B22D8_de(void *arg0, void *arg1) {
    struct ALSeq_s *sequence = arg0;
    struct ALSeqMarker *marker = arg1;
    marker->curPtr = sequence->curPtr;
    marker->lastStatus = sequence->lastStatus;
    marker->lastTicks = sequence->lastTicks;
}

s32 func_802B22F4_de(ALSeq_s *arg0, s32 *arg1) {
    u8 *field8;

    field8 = arg0->curPtr;
    if (!(field8 < (arg0->base + arg0->len))) {
        return 0;
    }
    *arg1 = func_802B235C_de(arg0);
    arg0->curPtr = field8;
    return 1;
}

s32 func_802B235C_de(struct ALSeq_s *arg0) {
    u8 *p;
    s32 b;
    s32 val;

    p = arg0->curPtr;
    b = *p;
    arg0->curPtr = p + 1;
    val = b;
    if (val & 0x80) {
        val = val & 0x7F;
        do {
            p = arg0->curPtr;
            b = *p;
            arg0->curPtr = p + 1;
            val = (val << 7) + (b & 0x7F);
        } while (b & 0x80);
    }
    return val;
}
