#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_80434F4C.h"
#include "types.h"
/* Handles the answer on the screen D_800E53C0. */
extern struct MenuRules *D_800E53C0;
extern s32 D_80146894;
extern s32 D_80146918;
extern s32 D_801468F4;
extern void func_8029973C_de();
extern s32 func_8043C308_de(struct MenuRules *);
extern s32 func_80299A08_de();
extern void func_8043C278_de(struct MenuRules *);
extern s32 func_8042AF28_de();
extern void func_8042E988_de(s32);
extern void func_80298368_de(s32);
s32 func_8042D788_de(void) {
    s32 *paused;
    func_8029973C_de();
    if (func_8043C308_de(D_800E53C0) == 1) {
        return 0;
    }
    paused = &D_80146894;
    *paused = 0;
    switch (func_80299A08_de()) {
#if defined(VERSION_DE)
    case 0x235 - 2:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x239 - 2:
#elif defined(VERSION_EU_X)
    case 0x23E - 2:
#endif
        if (((u8 *)paused)[-0x5BF] == 0) {
            func_8043C278_de(D_800E53C0);
            D_800E53C0->locked = 0;
        } else {
            D_80146918 = 0;
            D_801468F4 = 0;
            func_80298368_de(0xF);
        }
        break;
#if defined(VERSION_DE)
    case 0x235 - 1:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x239 - 1:
#elif defined(VERSION_EU_X)
    case 0x23E - 1:
#endif
        func_80434FB4_de(5);
        func_80298368_de(0x13);
        break;
#if defined(VERSION_DE)
    case 0x235 + 3:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x239 + 3:
#elif defined(VERSION_EU_X)
    case 0x23E + 3:
#endif
        if (func_8042AF28_de() == 1) {
            func_8042E988_de(0x21);
            return 0;
        }
        if (((u8 *)paused)[-0x5BF] == 0) {
            func_80298368_de(0x14);
        } else {
            func_80298368_de(0xF);
        }
        break;
    default:
        return 0;
    }
    return 0;
}
