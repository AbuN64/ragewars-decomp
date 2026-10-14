#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"
/* Steps the selected menu item backwards and updates its display state. */
extern Menu_func_8041EE08_de *D_800E39C0;
extern void func_8025DF34_de(int),func_8029973C_de(void),func_8040E8D8_de(Resource_func_80419E54_de *,int);
extern Resource_func_80419E54_de *func_8040EC30_de(int,int);
s32 func_8041EE08_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0_2;
    s32 idx;
    Resource_func_80419E54_de *temp_v0;
    Resource_func_80419E54_de *temp_v0_3;
    if (arg3 == 1) {
        func_8029973C_de();
        idx = D_800E39C0->unk14;
#if defined(VERSION_DE)
        temp_v0 = func_8040EC30_de(D_800E39C0->items[idx], 0x38C);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        temp_v0 = func_8040EC30_de(D_800E39C0->items[idx], 0x392);
#elif defined(VERSION_EU_X)
        temp_v0 = func_8040EC30_de(D_800E39C0->items[idx], 0x396);
#endif
        temp_v0->value = 0xFF;
        func_8040E8D8_de(temp_v0, 0);
        temp_v0_2 = D_800E39C0->unk14 - 1;
        D_800E39C0->unk14 = temp_v0_2;
        if (temp_v0_2 < 0) {
            D_800E39C0->unk14 = D_800E39C0->unk1C - 1;
        }
        idx = D_800E39C0->unk14;
#if defined(VERSION_DE)
        temp_v0_3 = func_8040EC30_de(D_800E39C0->items[idx], 0x38C);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        temp_v0_3 = func_8040EC30_de(D_800E39C0->items[idx], 0x392);
#elif defined(VERSION_EU_X)
        temp_v0_3 = func_8040EC30_de(D_800E39C0->items[idx], 0x396);
#endif
        temp_v0_3->value = 0xFF;
        func_8040E8D8_de(temp_v0_3, 1);
        D_800E39C0->unk18 = 0;
        func_8025DF34_de(0xE80);
        return 0;
    }
    return 0;
}
