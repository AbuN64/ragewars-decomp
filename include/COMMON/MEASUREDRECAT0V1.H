#ifndef COMMON_MEASUREDRECAT0V1_H
#define COMMON_MEASUREDRECAT0V1_H
/* Measured 4-byte access at 0; storage view, complete object unknown. */
struct MeasuredRecAt0V1 { s32 value; };
/* Measured 4-byte access at 0xC; storage view, complete object unknown. */
struct MeasuredRecAtCV1 { unsigned char padding[12]; s32 value; };
/* Measured 4-byte access at 4; storage view, complete object unknown. */
struct MeasuredRecAt4V1 { unsigned char padding[4]; void * value; };
/* Measured 4-byte access at 8; storage view, complete object unknown. */
struct MeasuredRecAt8V1 { unsigned char padding[8]; s32 value; };
#endif
