#include "span_1000/code_8020AF9C.h"
#include "types.h"







void func_8020D014_de(struct Obj8020BC50 *arg0) {
    struct Node8020BC50 *var_v0;
    f32 k;

    var_v0 = arg0->nodes;
    if (var_v0 != 0) {
        k = (-1.0f);
        do {
            var_v0->value = k;
            var_v0->state = -1;
            var_v0->field18 = 0;
            var_v0->field1C = 0;
            var_v0->field20 = 0;
            var_v0->field24 = 0;
            var_v0->field28 = 0;
            var_v0->field2C = 0;
            var_v0->field30 = 0;
            var_v0 = var_v0->next;
        } while (var_v0 != 0);
    }
    arg0->value = (-1.0f);
    arg0->selected = -1;
}
