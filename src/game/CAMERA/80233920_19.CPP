#include "COMMON/VIEWFLAGS.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"

extern void *D_80145060;




void *func_802392EC_de(int arg0) {
    Shared_ActorView *node = D_80145060;
    if (node != 0) {
        do {
            if ((s32)node->message == arg0) {
                return node;
            }
            node = node->next;
        } while (node != 0);
    }
    return 0;
}
