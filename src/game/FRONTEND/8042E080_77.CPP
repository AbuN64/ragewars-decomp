#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Calls MarkMenuEventHandled with the arguments it was given and returns zero. */
extern void MarkMenuEventHandled();

s32 Frontend_ConsumePauseMenuEvent(void) {
    MarkMenuEventHandled();
    return 0;
}
