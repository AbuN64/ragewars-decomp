#ifndef SYSTEM_POLYTRAK2_READQUANTIZEDSTREAMVALUE_H
#define SYSTEM_POLYTRAK2_READQUANTIZEDSTREAMVALUE_H
#include "COMMON/LOCALDECODERANGE.H"
#include "SYSTEM/POLYTRAK2_DECODESCALARSAMPLES_DATA.H"
extern f32 Polytrak2_ReadQuantizedStreamValue(LocalDecodeRange *valueStream);
extern unsigned int Polytrak2_ReadCursorBits(unsigned int *bitCursor, unsigned int bitCount);
extern void Polytrak2_SeekArrayElement(unsigned int *record, int index);
extern void Polytrak2_SkipCursorBits(int *bitCursor, int bitCount);
#endif
