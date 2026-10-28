#ifndef SYSTEM_POLYTRAK2_DECODESCALARSAMPLES_DATA_H
#define SYSTEM_POLYTRAK2_DECODESCALARSAMPLES_DATA_H
#include "COMMON/LOCALDECODERANGE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
struct LocalDecodeRange {
    u32 unused;
    Func802608ECResult range;
};
struct TrackBitarrayExpandCurveSamples {
    s32 keys;
    char pad4[0x2C - 4];
    s32 stride;
};
struct DecodeArray {
    s32 base;
    Func802608ECResult range;
    s32 count; /* 0x10 */
};
struct BitFieldSource {
    int base;
    unsigned int width;
};
struct Entry802612C8 {
    s32 x;
    s32 pad4;
    s32 z;
    f32 f0C;
    s32 n10;
    s32 n14;
};
struct ObjRecAt4V4 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    Triple unk4;
};
typedef struct RootActor { char pad0[0x100]; u32 flags; } RootActor;
typedef struct RootClip { u16 count,loopStart; char pad4[4]; f32 rate; } RootClip;
typedef struct AngleKeys { char header[8]; s16 keys[1]; } AngleKeys;
struct Shared_func_80261EB8_S1 {
    f32 unk0;
    char pad4[0x4];
    s16 unk8;
    char padA[0x2];
    s32 unkC;
    s32 ** unk10;
};
extern void func_80260C6C_de(void *decodeArray, int baseBitAddress, Func802608ECResult t, int elementCount);
extern int Polytrak2_GetPackedHighBitsSetElement(BitFieldSource *packedArray, int elementIndex);
extern f32 Polytrak2_GetQuantizedArrayElement(DecodeArray *packedArray, s32 elementIndex);
extern int Polytrak2_GetUnsignedArrayElement(BitFieldSource *packedArray, int elementIndex);
extern void Polytrak2_WriteQuantizedFloatAtAddress(s32 bitAddress, Func802608ECResult range, f32 sourceValue);
extern void func_80260E1C_de(void *decodeArray, int baseBitAddress, Func802608ECResult t, int elementCount);
extern void Polytrak2_StoreWordAndTriple(void *destination, int wordValue, Triple t);
extern f32 Polytrak2_ReadQuantizedFloatAtAddress(s32 bitAddress, Func802608ECResult range);
extern void func_80260D78_de(void *decodeArray, int baseBitAddress, Func802608ECResult t, int elementCount);
#endif
