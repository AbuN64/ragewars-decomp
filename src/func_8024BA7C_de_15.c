#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"
/* Converts the twelve used entries of a 4x4 float matrix to unsigned integers, splitting each pair into the high and low halfword arrays of a packed matrix and setting the final high word's low bit. Adapted from func_8027027C_de with the per-entry scale multiplies removed, the converted value scoped to each conversion block, and the D_800C8C70 thresholds changed. */
void func_8024CC30_de(f32 *src, PackedMatrixWords *dst) {
    u32 *upper = dst->upper;
    u32 *lower = dst->lower;
    s32 a;
    s32 b;
    { f32 value = (src[0]); if (!((D_800C8C70) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C8C70)); (a) |= 0x80000000; } };
    { f32 value = (src[1]); if (!((*(&D_800C8C70 + 1)) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (*(&D_800C8C70 + 1))); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[2]); if (!((D_800C3B88) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C3B88)); (a) |= 0x80000000; } };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;
    { f32 value = (src[4]); if (!((*(&D_800C3B88 + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3B88 + 1))); (a) |= 0x80000000; } };
    { f32 value = (src[5]); if (!((D_800C3B90) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (D_800C3B90)); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[6]); if (!((*(&D_800C3B90 + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3B90 + 1))); (a) |= 0x80000000; } };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;
    { f32 value = (src[8]); if (!((D_800C3B98) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C3B98)); (a) |= 0x80000000; } };
    { f32 value = (src[9]); if (!((*(&D_800C3B98 + 1)) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (*(&D_800C3B98 + 1))); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[10]); if (!((D_800C3BA0_de) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (D_800C3BA0_de)); (a) |= 0x80000000; } };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;
    { f32 value = (src[12]); if (!((*(&D_800C3BA0_de + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3BA0_de + 1))); (a) |= 0x80000000; } };
    { f32 value = (src[13]); if (!((D_800C3BA8) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - (D_800C3BA8)); (b) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;
    { f32 value = (src[14]); if (!((*(&D_800C3BA8 + 1)) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - (*(&D_800C3BA8 + 1))); (a) |= 0x80000000; } };
    *upper = (a & 0xFFFF0000) | 1;
    *lower = a << 16;
}
