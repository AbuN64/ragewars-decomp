#include "types.h"
#include "span_1000/code_8029BBA0.h"

extern const f64 D_800C5850_de;
extern const f64 D_800C5858_de;
extern const f64 D_800C5860_de;
extern const f64 D_800C5868_de;
extern const f64 D_800C5870_de;

static inline f64 remainder_round_down(f64 value) {
    f64 temporary;
    f64 limit = D_800C5850_de;
    if (limit <= value) {
        return value;
    }
    if (value < 0.0) {
        return -func_8029D9DC_de(-value);
    }
    temporary = value;
    temporary += limit;
    temporary -= limit;
    if (value < temporary) {
        return temporary - D_800C5858_de;
    }
    return temporary;
}

static inline f64 remainder_round_up(f64 value) {
    f64 temporary;
    f64 limit = D_800C5850_de;
    if (limit <= value) {
        return value;
    }
    if (value < 0.0) {
        return -remainder_round_down(-value);
    }
    temporary = value;
    temporary += limit;
    temporary -= limit;
    if (temporary < value) {
        return temporary + D_800C5860_de;
    }
    return temporary;
}

static inline f64 remainder_round_down_positive(f64 value) {
    f64 temporary;
    f64 limit = D_800C5868_de;
    if (limit <= value) {
        return value;
    }
    if (value < 0.0) {
        return -func_8029D9DC_de(-value);
    }
    temporary = value;
    temporary += limit;
    temporary -= limit;
    if (value < temporary) {
        return temporary - D_800C5870_de;
    }
    return temporary;
}

f64 func_8029B278_de(f64 arg0, f64 arg1) {
    f64 quotient = arg0 / arg1;
    if (quotient < 0.0) {
        quotient = remainder_round_up(quotient);
    } else {
        quotient = remainder_round_down_positive(quotient);
    }
    return arg0 - quotient * arg1;
}
