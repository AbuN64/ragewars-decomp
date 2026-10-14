#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80275E44.h"
#include "types.h"







f32 func_8027631C_de(u16 *arg0, f32 arg1, u16 arg2) {
    u16 *node = arg0;
    u16 id = arg2;

    if (*node == id) {
        if (((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_4)->unk4 != arg1 ||
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_8)->unk4 != arg1 ||
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_C)->unk4 != arg1) {
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_4)->unk4 = arg1;
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_8)->unk4 = arg1;
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_C)->unk4 = arg1;

            if (((ObjectLinks1C *)(node))->unk_10.v0 != 0) {
                func_8027631C_de(((ObjectLinks1C *)(node))->unk_10.v1, arg1, id);
            }
            if (((ObjectLinks1C *)(node))->unk_14.v0 != 0) {
                func_8027631C_de(((ObjectLinks1C *)(node))->unk_14.v1, arg1, id);
            }
            if (((ObjectLinks1C *)(node))->unk_18.v0 != 0) {
                func_8027631C_de(((ObjectLinks1C *)(node))->unk_18.v1, arg1, id);
            }
        }
    }
}
