#include "span_1000/code_8022AE90.h"
#include "shared/gameplay_transition.h"



/** Report whether the floating field at offset 0x11FC is positive. */
int func_8022B460_de(char *object) {
    Shared_ActorView *actor = (void *)object;
    return actor->field11FC > 0.0f;
}
