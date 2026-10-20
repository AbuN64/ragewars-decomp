#include "include_asm.h"
#include "SDK/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"

void func_802BE030_de(LldivResult *result, s64 numerator, s64 denominator) {
    result->quot = func_802C0230_de(numerator, denominator);
    result->rem = func_802C0820_de(numerator, denominator);
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802BDFE8);
#endif
