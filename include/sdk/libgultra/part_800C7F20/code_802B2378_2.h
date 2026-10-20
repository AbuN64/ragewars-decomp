#ifndef SDK_LIBGULTRA_PART_800C7F20_CODE_802B2378_2_H
#define SDK_LIBGULTRA_PART_800C7F20_CODE_802B2378_2_H
#include "TYPES.H"
/* RNC method 1 unpacker; src is the packed data after the 18-byte header. */
void Rnc_UnpackMethod1(const void *src, void *dst, s32 packedSize, s32 unpackedSize);
#endif
