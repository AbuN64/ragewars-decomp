#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#if defined(VERSION_DE)
enum { MENU_RESOURCE = 0x38c };
#elif defined(VERSION_EU)
enum { MENU_RESOURCE = 0x392 };
#elif defined(VERSION_EU_X)
enum { MENU_RESOURCE = 0x396 };
#elif defined(VERSION_US)
enum { MENU_RESOURCE = 0x392 };
#elif defined(VERSION_US_REV1)
enum { MENU_RESOURCE = 0x392 };
#endif
#include "types.h"
/* Advances the selected menu item and updates its display state. */


extern Menu_func_8041EE08_de *D_800E39C0;
extern void func_8025DF34_de(int),func_8029973C_de(void),func_8040E8D8_de(Resource_func_80419E54_de *,int);
extern Resource_func_80419E54_de *func_8040EC30_de(int,int);
s32 func_8041EED0_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_hi;
    s32 temp_v0_2;
    s32 temp_v1;
    Resource_func_80419E54_de *temp_v0;
    Resource_func_80419E54_de *temp_v0_3;

    if (arg3 == 1) {
        func_8029973C_de();
        temp_v0 = func_8040EC30_de(D_800E39C0->items[D_800E39C0->unk14], MENU_RESOURCE);
        temp_v0->value = 0xFF;
        func_8040E8D8_de(temp_v0, 0);
        temp_v1 = D_800E39C0->unk1C;
        temp_v0_2 = D_800E39C0->unk14 + 1;
        temp_hi = temp_v0_2 % temp_v1;
        D_800E39C0->unk14 = temp_hi;
        temp_v0_3 = func_8040EC30_de(D_800E39C0->items[temp_hi], MENU_RESOURCE);
        temp_v0_3->value = 0xFF;
        func_8040E8D8_de(temp_v0_3, 1);
        D_800E39C0->unk18 = 0;
        func_8025DF34_de(0xE80);
        return 0;
    }
    return 0;
}
