#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS4_2.H"
#include "TYPES.H"

/** Expand the four-float X/Z bounds in arg0 over arg1 packed vectors. */
void Region_ExpandHorizontalBounds(f32 *arg0, s32 arg1, CVector3 *arg2)
{
    f32 value;
    f32 bound;
    s32 i;
    i = 0;
    if (arg1 > 0) {
        do {
            value = arg2[i].x;
            bound = arg0[0];
            if (!(value <= bound)) {
                value = bound;
            }
            arg0[0] = value;
            value = arg2[i].z;
            bound = arg0[1];
            if (!(value <= bound)) {
                value = bound;
            }
            arg0[1] = value;
            value = arg2[i].x;
            bound = arg0[2];
            if (!(bound <= value)) {
                value = bound;
            }
            arg0[2] = value;
            value = arg2[i].z;
            bound = arg0[3];
            if (!(bound <= value)) {
                value = bound;
            }
            arg0[3] = value;
            i += 1;
        } while (i < arg1);
    }
}
/** Empty adjacent entry point included in Region_ExpandHorizontalBounds's Splat span. */
void Region_NoOperation(void)
{
}

#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_80276598_us);
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_8027659C[1] = {
    0x0000000A,
};
#endif
