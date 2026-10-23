#include "include_asm.h"
#include "TYPES.H"
#include "ANIM/MEASUREDRECAT8V3.H"
#include "ANIM/MEASUREDRECAT8V4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OUTPUT.H"
#include "ANIM/RAY180.H"
#include "stddef.h"

extern f32 func_802B72B0_de(f32);

/* Returns the distance from point p to the segment from a to b: the offset of p from a is reduced by
 * its projection onto the segment direction, clamped to the segment ends, before taking the length. */





extern void func_80271F9C_de(CVector3 *, CVector3 *, f32);

f32 func_80241840_de(CVector3 *a, CVector3 *b, CVector3 *p) {
    extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
    CVector3 offset;
    CVector3 dir;
    f32 value;
    f32 len;

    func_80271F68_de(&offset, p, a);
    func_80271F68_de(&dir, b, a);
    value = dir.x * offset.x + dir.y * offset.y + dir.z * offset.z;
    if (!(value < 0.0f)) {
        len = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
        if (!(len <= value)) {
            func_80271F9C_de(&dir, &dir, value / len);
        }
        func_80271F68_de(&offset, &offset, &dir);
    }
    value = offset.x * offset.x + offset.y * offset.y + offset.z * offset.z;
    return func_802B72B0_de(value);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8024192C[1] = {
    0x49546172,
};
#endif
