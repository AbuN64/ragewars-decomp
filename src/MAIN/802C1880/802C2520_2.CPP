#include "MAIN/802C1880.H"
#include "MAIN/802BD1A8.H"
#include "TYPES.H"




void func_802BE030_de(LldivResult *result, s64 numerator, s64 denominator) {
    result->quot = func_802C0230_de(numerator, denominator);
    result->rem = func_802C0820_de(numerator, denominator);
}
