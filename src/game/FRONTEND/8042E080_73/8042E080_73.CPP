#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Calls Tsmos_SetModeOneFlag with 2 and returns zero. */


s32 Frontend_SetPauseMenuInputMode(void) {
    Tsmos_SetModeOneFlag(2);
    return 0;
}
