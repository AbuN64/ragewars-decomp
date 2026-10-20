#include "include_asm.h"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"
#include "COMMON/SELF.H"

s32 func_8020DD04_de(WeightSource *arg0) {
    s32 first;
    s32 second;
    s32 third;
    s32 first_end;
    s32 second_end;
    s32 total;
    s32 value;

    first = (s32)arg0->first;
    second = (s32)arg0->second;
    third = (s32)arg0->third;
    first_end = 0;
    if (first > 0) {
        first_end = first;
    }
    second_end = 0;
    if (second > 0) {
        second_end = first_end + second;
    }
    total = first + second + third;
    if (total == 0) {
        return 3;
    }
    value = (func_802744D4_de() % total) + 1;
    if (first_end < value) {
        if (second_end >= value) {
            return 4;
        }
        return 3;
    }
    return 5;
}

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", data_unresolved_8020DDF4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("span_1000", func_8020DDF4_eu_padding_E9F4);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("span_1000", data_unresolved_8020DDD4);
#endif
