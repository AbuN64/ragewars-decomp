#include "COMMON/RESIDENTSTATE.H"
#include "TEXTURE/80294C64.H"
#include "TEXTURE/80294C64_7.H"
#if defined(VERSION_US_REV1)
/** Report the global count only while its enable byte is set. */
extern unsigned int D_800D2AE0;
int func_802955C8_us_rev1(void) {
    int result = 0;
    if (D_8014AEB0.alternateTitle != 0) {
        result = D_800D2AE0 != 0;
    }
    return result;
}
#endif
