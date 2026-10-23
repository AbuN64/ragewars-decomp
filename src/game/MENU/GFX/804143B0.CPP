#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
/* Ratio of the cycle counter func_802BADC0_de returns to the counter rate D_80149B00, each converted to a double. */
extern u64 func_802BADC0_de(void);
extern double func_802C1880_de(s64 value);
f64 func_804143B0_de(void) {
    return func_802C1880_de(func_802BADC0_de()) / func_802C1880_de(D_80149B00);
}
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_8041447C[1] = {
    0x5F47524F,
};
#endif
