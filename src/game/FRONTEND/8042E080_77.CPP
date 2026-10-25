#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */
extern void MarkMenuEventHandled();

s32 func_80435CB8_de(void) {
    MarkMenuEventHandled();
    return 0;
}
