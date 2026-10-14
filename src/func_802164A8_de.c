#include "span_1000/code_80213ED4.h"
#include "types.h"









extern f32 D_800D2988;
extern void func_80217388_de(void);
extern void func_80213CF8_de(Source_func_802164A8_de *, Dest_func_802164A8_de *);
extern void func_80213ED4_de(Source_func_802164A8_de *, Dest_func_802164A8_de *);

void func_802164A8_de(Source_func_802164A8_de *src, Dest_func_802164A8_de *dst) {
    if ((dst->aux != 0) && (dst->aux->unkC == -1)) {
        func_80217388_de();
    }
    if (dst->timer != 0) {
        dst->timer--;
        D_800D2988 = 0.0f;
        return;
    }
    if ((src->active != 0) && (src->kind != 0)) {
        if (*src->kind == 2) {
            dst->old_position = src->position;
            dst->height = src->height;
        }
        dst->position = src->position;
        dst->value += D_800D2988;
        if (src->flags & 0x10000) {
            func_80213CF8_de(src, dst);
        }
        if (dst->callback != 0) {
            dst->callback(src, dst);
        }
        func_80213ED4_de(src, dst);
        if (*src->kind != 2) {
            dst->old_position = src->position;
            dst->height = src->height;
        }
    }
}
