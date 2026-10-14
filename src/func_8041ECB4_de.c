#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"
/* Advances the join screen's pulse timer by delta and sets byte 0x10 of node 0x392 under the edited request's root to 150 plus 100 times the sine of the timer over 300; returns zero. */
extern struct Screen_func_8041ECB4_de *D_800E39C0;
extern Resource_func_80419E54_de *func_8040EC30_de(void *root, s32 id);

s32 func_8041ECB4_de(void *arg0, void *arg1, s32 delta) {
    Resource_func_80419E54_de *node;
    D_800E39C0->timer += delta;
#if defined(VERSION_DE)
    node = func_8040EC30_de(D_800E39C0->roots[D_800E39C0->request], 0x38C);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    node = func_8040EC30_de(D_800E39C0->roots[D_800E39C0->request], 0x392);
#elif defined(VERSION_EU_X)
    node = func_8040EC30_de(D_800E39C0->roots[D_800E39C0->request], 0x396);
#endif
    node->value = (u32)(func_802B6560_de(D_800E39C0->timer * 0.0033333334f) * 100.0f + 150.0f);
    return 0;
}
