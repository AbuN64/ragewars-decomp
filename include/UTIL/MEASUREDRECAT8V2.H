#ifndef UTIL_MEASUREDRECAT8V2_H
#define UTIL_MEASUREDRECAT8V2_H
/* Measured 4-byte access at 8; storage view, complete object unknown. */
struct MeasuredRecAt8V2 { unsigned char padding[8]; void * value; };
/* Measured 4-byte access at 4; storage view, complete object unknown. */
struct MeasuredRecAt4V4 { unsigned char padding[4]; u32 value; };
/* Measured 4-byte access at 0x10; storage view, complete object unknown. */
struct MeasuredRecAt10V3 { unsigned char padding[16]; s32 value; };
/* Measured 4-byte access at 0x14; storage view, complete object unknown. */
struct MeasuredRecAt14V3 { unsigned char padding[20]; s32 value; };
/* Measured 4-byte access at -0x20; storage view, complete object unknown. */
struct MeasuredRecAt4V3 { void * value; unsigned char trailing[28]; };
/* Measured 4-byte access at 0xC; storage view, complete object unknown. */
struct MeasuredRecAtCV2 { unsigned char padding[12]; void * value; };
/* Measured 4-byte access at 0; storage view, complete object unknown. */
struct MeasuredRecAt0V2 { void * value; };
/* Measured 4-byte access at 4; storage view, complete object unknown. */
struct MeasuredRecAt4V2 { unsigned char padding[4]; void * value; };
#endif
