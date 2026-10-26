#ifndef SDK_LIBGULTRA_INFERRED_802AD870_8_H
#define SDK_LIBGULTRA_INFERRED_802AD870_8_H
#include "COMMON/OBJECTSTATE10_2.H"
extern f32 alCSeqTicksToSec(void **arg0, s32 arg1, s32 arg2);
extern u32 alCSeqSecToTicks(void **arg0, f32 arg1, s32 arg2);
extern int alCSeqGetTicks(void *arg0);
extern void alCSeqGetLoc(ALCSeq_s *src, ALCSeqMarker *dst);
extern void alCSeqSetLoc(ALCSeq_s *dst, ALCSeqMarker *src);
extern void alCSeqNewMarker(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks);
extern void func_802AE5B8_de(ALCSeq_s *state, ALCMidiHdr *base);
extern void func_802AE6BC_de(ALCSeq_s *state, struct ALEvent *result);
extern s32 func_802AE9B0_de(ALCSeq_s *seq, s32 *result);
#endif
