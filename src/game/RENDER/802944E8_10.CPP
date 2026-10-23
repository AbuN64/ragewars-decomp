#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "RENDER/802944E8.H"
#include "TYPES.H"
#include "RENDER/802944E8_10.H"

/* Opens the idle-time prompt when allowed and reports whether the pause input remains active. */


s32 func_80245798_de();                                /* extern */
s32 func_80245850_de();                                /* extern */
s32 func_80245B0C_de();                                /* extern */
void func_804037D4_de(void *);                            /* extern */
s32 func_80442A28_de(void *);                             


extern func_80294BB0_S1 D_8014561C;
extern s32 D_80142868;

s32 func_80294B9C_de(ObjRecAt26DD4 *arg0) {
    s32 var_v0;
    Prompt *temp_a0;

    if ((func_80442A28_de(&D_8014561C) == 0) && (func_80245798_de() != 0)) {
        if (func_80245B0C_de() == 0x78) {
            temp_a0 = &D_8014561C.unk1284;
            if (temp_a0->unk88 == 0) {
                if (arg0->unk26DD4 == 0) {
                    temp_a0->unk88 = 1;
                    func_804037D4_de(temp_a0);
                }
                goto block_6;
            }
            goto block_7;
        }
    }
block_6:
    if (D_80142868 != 0) {
block_7:
        if (func_80245850_de() != 0) return 1;
    }
    return 0;
}
