#ifndef COMMON_EXTERNS_15_H
#define COMMON_EXTERNS_15_H
#include "TYPES.H"

extern void Libsn_WritePortByte(s32 address, s32 value);

extern void D_002039F8();
extern void D_00203E78();
extern void D_00202E4C();
extern void D_00203DF0();

extern void PitchMatrix(void *matrixStorage, f32 pitchAngle);
#endif
