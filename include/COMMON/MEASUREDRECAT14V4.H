#ifndef COMMON_MEASUREDRECAT14V4_H
#define COMMON_MEASUREDRECAT14V4_H
#include "COMMON/MEASUREDRECAT14V2.H"
/* Measured 4-byte access at 0x14; storage view, complete object unknown. */
struct MeasuredRecAt14V4 { unsigned char padding[20]; s32 value; };
/* Measured 4-byte access at 0x18; storage view, complete object unknown. */
/* Measured 4-byte access at 0xC; storage view, complete object unknown. */
struct MeasuredRecAtCV4 { unsigned char padding[12]; s32 value; };
/* Measured 4-byte access at 0x10; storage view, complete object unknown. */
struct MeasuredRecAt10V1 { unsigned char padding[16]; s32 value; };
/* Measured 4-byte access at 0x14; storage view, complete object unknown. */
struct MeasuredRecAt14V1 { unsigned char padding[20]; void * * value; };
/* Measured 4-byte access at 0x14; storage view, complete object unknown. */
struct MeasuredRecAt14V5 { unsigned char padding[20]; void * * * value; };
#endif
