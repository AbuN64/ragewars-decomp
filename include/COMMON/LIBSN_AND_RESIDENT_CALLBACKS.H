#ifndef COMMON_EXTERNS_15_H
#define COMMON_EXTERNS_15_H
#include "TYPES.H"

extern void Libsn_WritePortByte(s32 address, s32 value);

extern void Turret_AdvanceRomEntry();
extern void Turret_DecreaseHealthRomEntry();
extern void Turret_CalcOrientMtxRomEntry();
extern void Turret_SpecialEffectsRomEntry();

extern void PitchMatrix(void *matrixStorage, f32 pitchAngle);
#endif
