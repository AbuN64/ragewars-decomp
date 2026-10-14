#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E130.h"
#include "types.h"





f32 func_8024E8B8_de(void *arg0) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f1;
    void *temp_a1;
    temp_a1 = (((struct ObjectLinks18 *) ((s8 *) arg0))->unk_14);
    var_f0 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75_func_802750B0_de *) ((s8 *) temp_a1))->cur))->unk4);
    temp_f1 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75_func_802750B0_de *) ((s8 *) temp_a1))->prev))->unk4);
    if (!(var_f0 <= temp_f1)) {
        var_f0 = temp_f1;
    }
    var_f1 = (((struct func_802077F4_S2 *) ((s8 *) ((struct Node75_func_802750B0_de *) ((s8 *) temp_a1))->next))->unk4);
    if (!(var_f1 <= var_f0)) {
        var_f1 = var_f0;
    }
    return (((struct ObjectLinks18 *) ((s8 *) arg0))->unk_C) - var_f1;
}
