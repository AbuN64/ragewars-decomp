#include "span_1000/code_802BD1A8.h"
#include "types.h"



extern s64 func_802C0230_de(s64, s64) __attribute__((const));
extern s64 func_802C0820_de(s64, s64) __attribute__((const));

void func_802BE030_de(LldivResult *result, s64 numerator, s64 denominator) {
    result->quot = func_802C0230_de(numerator, denominator);
    result->rem = func_802C0820_de(numerator, denominator);
}
