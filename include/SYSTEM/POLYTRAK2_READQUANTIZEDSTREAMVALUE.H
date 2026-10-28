#ifndef SYSTEM_802609CC_2_H
#define SYSTEM_802609CC_2_H
#include "COMMON/LOCALDECODERANGE.H"
#include "SYSTEM/802609CC.H"
extern f32 Polytrak2_ReadQuantizedStreamValue(LocalDecodeRange *arg0);
extern unsigned int Polytrak2_ReadCursorBits(unsigned int *arg0, unsigned int arg1);
extern void Polytrak2_SeekArrayElement(unsigned int *record, int index);
extern void Polytrak2_SkipCursorBits(int *arg0, int arg1);
#endif
