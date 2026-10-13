#include "shared/navigation_graph.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"






void func_8020EE50_de(void) {
    NavigationSearchNode *var_a0;
    f32 k;

    var_a0 = D_801372C8;
    if (var_a0 != 0) {
        k = D_800C1EE0_de;
        do {
            var_a0->extra =
                var_a0->extra +
                (f32) (var_a0->ticks * 0x1E) * k;
            var_a0 = var_a0->next;
        } while (var_a0 != 0);
    }
}
