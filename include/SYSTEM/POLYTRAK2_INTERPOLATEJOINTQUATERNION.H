#ifndef SYSTEM_POLYTRAK2_INTERPOLATEJOINTQUATERNION_H
#define SYSTEM_POLYTRAK2_INTERPOLATEJOINTQUATERNION_H
#include "COMMON/STREAM.H"
extern unsigned int Polytrak2_BitAddressToByteAddress(unsigned int value);
extern float Polytrak2_UnpackUnitValue(float value, int bits);
extern f32 Polytrak2_ScaleToRange(f32 value, f32 lower, f32 upper);
extern void Polytrak2_WriteBitsAtAddress(u32 arg0, u32 arg1, u32 arg2);
extern unsigned int Polytrak2_BitAddressToWordAddress(unsigned int arg0);
extern Func802608ECResult Polytrak2_ComputeQuantizationRange(f32 arg0, f32 arg1, f32 arg2);
extern void Polytrak2_WriteBitsAndAdvance(u32 *arg0, u32 arg1, u32 arg2);
extern void * Polytrak2_GetResidentResource(void *object);
extern s32 Polytrak2_ByteAddressToBitAddress(s32 arg0);
extern u32 Polytrak2_ReadBitsAndAdvance(u32 *stream, u32 width);
#endif
