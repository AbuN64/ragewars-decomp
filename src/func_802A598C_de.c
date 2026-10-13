#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"
















void func_802A598C_de(Owner802A697C *owner, int object) {
    float temp_f1;
    u8 temp_v0;
    u8 temp_v0_2;
    void *temp_a0;
    void *temp_a0_2;
    void *var_v1;

    var_v1 = owner->head;
    if (var_v1 != 0) {
        do {
            temp_a0 = ((struct State802A697C *)var_v1)->object;
            if ((int)temp_a0 == object) {
                if (temp_a0 != 0) {
                    if (((struct State802A697C *)var_v1)->flags & 1) {
                        temp_v0 = ((Entity1DC *)temp_a0)->unk_13B;
                        if (temp_v0 != 0) {
                            ((Entity1DC *)temp_a0)->unk_13B = (u8)(temp_v0 - 1);
                        }
                    }
                    if (((struct State802A697C *)var_v1)->flags & 2) {
                        temp_a0_2 = ((struct State802A697C *)var_v1)->object;
                        temp_v0_2 = ((Entity1DC *)temp_a0_2)->unk_1D9;
                        if (temp_v0_2 != 0) {
                            ((Entity1DC *)temp_a0_2)->unk_1D9 = (u8)(temp_v0_2 - 1);
                        }
                    }
                }
                ((struct State802A697C *)var_v1)->object = 0;
                temp_f1 = ((struct State802A697C *)var_v1)->node->value;
                if (((struct State802A697C *)var_v1)->value < temp_f1) {
                    ((struct State802A697C *)var_v1)->value = temp_f1;
                }
            }
            var_v1 = ((struct State802A697C *)var_v1)->next;
        } while (var_v1 != 0);
    }
}
