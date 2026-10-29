#ifndef LIBGULTRA_INFERRED_CSEQ_H
#define LIBGULTRA_INFERRED_CSEQ_H
#include "COMMON/COMPRESSED_SEQUENCE_AND_EVENT_VIEWS.H"
extern f32 alCSeqTicksToSec(void **sequenceHandle, s32 tickCount, s32 microsecondsPerQuarter);
extern u32 alCSeqSecToTicks(void **sequenceHandle, f32 seconds, s32 microsecondsPerQuarter);
extern int alCSeqGetTicks(void *sequence);
extern void alCSeqGetLoc(ALCSeq_s *src, ALCSeqMarker *dst);
extern void alCSeqSetLoc(ALCSeq_s *dst, ALCSeqMarker *src);
extern void alCSeqNewMarker(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks);
extern void alCSeqNew(ALCSeq_s *state, ALCMidiHdr *base);
extern void alCSeqNextEvent(ALCSeq_s *state, struct ALEvent *result);
extern s32 __alCSeqNextDelta(ALCSeq_s *seq, s32 *result);
#endif
