#include "include_asm.h"
#include "SDK/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"

void lldiv(LldivResult *result, s64 numerator, s64 denominator) {
    result->quot = func_802C0230_de(numerator, denominator);
    result->rem = func_802C0820_de(numerator, denominator);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BDFE8[2] = {
    0x494F5200, 0x00010000,
};
#endif
