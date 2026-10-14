#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804366C4.h"
#include "types.h"
/* Handles menu selection and updates the active menu state. */
extern func_8029A838_S1 *D_800E5780; extern u8 D_800FEB0F, D_80102B7E, D_80142358; void func_8029973C_de(void); s32 func_80299A08_de(void); s32 func_80265650_de(void *,s32); void func_8041A430_de(s32,s32);
s32 func_804375B0_de(void) {
    s32 temp_v0;
    s32 var_v0;
    func_8029973C_de();
    temp_v0 = func_80299A08_de();
    switch (temp_v0) { /* irregular */
#if defined(VERSION_DE)
    case 0x138 + 2:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A + 2:
#elif defined(VERSION_EU_X)
    case 0x13E + 2:
#endif
        D_800E5780->unk10 = -1;
        break;
#if defined(VERSION_DE)
    case 0x138 + 1:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A + 1:
#elif defined(VERSION_EU_X)
    case 0x13E + 1:
#endif
        if (func_80265650_de(&D_80102B7E, 0) == 0) {
            D_800E5780->unk10 = 7;
        } else {
            D_800E5780->unk10 = 0x1E;
        }
        break;
#if defined(VERSION_DE)
    case 0x138:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x13A:
#elif defined(VERSION_EU_X)
    case 0x13E:
#endif
        D_80142358 = D_800FEB0F;
        D_800E5780->unk10 = 0xA;
        break;
    }
    func_8041A430_de(D_800E5780->unk0, 2);
    return 0;
}
