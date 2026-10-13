#include "shared/gameplay_transition.h"
#include "span_1000/code_80225D10.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"





























extern void func_8023942C_de(void *arg0);
extern void func_8021EEFC_de(void *arg0, void *arg1);
extern s32 D_800D0EBC;






/* Notifies the entity list associated with arg0 about arg1 and calls a handler for each owner. */
void func_8022A398_de(void *arg0, void *arg1) {
    Round *round = arg0;
    Shared_ActorView *var_s0;

#if defined(VERSION_US_REV1)
    if (D_800D0EBC != 0) {
#endif
        func_8023942C_de(arg1);
        var_s0 = round->players;
        if (var_s0 != 0) {
            do {
                if (var_s0->message == arg1) {
                    func_8021EEFC_de(var_s0, arg1);
                }
                var_s0 = var_s0->next;
            } while (var_s0 != 0);
        }
#if defined(VERSION_US_REV1)
    }
#endif
}
