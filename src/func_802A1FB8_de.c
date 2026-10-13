#include "span_1000/code_802A208C.h"



/** Apply state two for event class three when the subcode is six or seven. */
int func_802A1FB8_de(void *object, int unused, unsigned int event, int subcode) {
    struct CommandListController *controller = object;
    if ((event >> 16) == 3 && subcode < 8 && subcode >= 6) {
        controller->state = 2;
        controller->progress = 0;
    }
    return 0;
}
