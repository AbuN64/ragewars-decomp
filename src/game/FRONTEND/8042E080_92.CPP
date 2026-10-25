#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */
extern void MarkMenuEventHandled();

s32 func_8043639C_de(void) {
    MarkMenuEventHandled();
    return 0;
}
