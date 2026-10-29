#include "include_asm.h"
#include "sdk/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"

void lldiv(LldivResult *result, s64 numerator, s64 denominator) {
    result->quot = Libc_SignedDivide(numerator, denominator);
    result->rem = Libc_SignedRemainder(numerator, denominator);
}

#if defined(VERSION_US)
unsigned int k_LldivEncodedWords[2] = {
    0x494F5200, 0x00010000,
};
#endif
