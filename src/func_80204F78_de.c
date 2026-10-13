#include "span_1000/code_80206258.h"
#include "span_1000/code_80204E78.h"



/** Update the floating state at offsets 0x40 and 0x64 under its range rules. */
void func_80204F78_de(void *unused, char *object, float value) {
    ActorMotionState *state = (void *)object;
    if (value == 0.0f || state->speed < value) {
        if (state->speed == 0.0f) {
            state->timer = 0.0f;
        }
        state->speed = value;
    }
}
