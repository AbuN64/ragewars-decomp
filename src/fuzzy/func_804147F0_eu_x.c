#include "types.h"
extern u64 func_802BADC0_de(void);
extern u64 D_80149B00;
extern f64 func_802C6970_us_rev1(u64);

f64 func_804147F0_eu_x(void) {
    return func_802C6970_us_rev1(func_802BADC0_de()) / func_802C6970_us_rev1(D_80149B00);
}
