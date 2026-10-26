#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Calls Tsmos_SetModeOneFlag with 2 and returns zero. */


s32 func_80435C40_de(void) {
    Tsmos_SetModeOneFlag(2);
    return 0;
}
