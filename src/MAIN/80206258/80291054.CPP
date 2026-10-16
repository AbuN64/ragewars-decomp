#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_802944E8.h"
#include "span_C76B0/data.h"

#include "TYPES.H"
#include "common/data.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_80291054.h"



extern int func_8022A414_de(void *arg0);


void func_80291074_de(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_v1;

    if (D_80142898 != 0) {
        temp_f0 = D_80142CB4 - D_800D2988;
        D_80142CB4 = temp_f0;
        if (temp_f0 <= 0.0f) {
            func_8022A414_de(&D_80145040);
            if (D_800CD784_de != 0) {
                if (D_800CD780 == 0) {
                    func_802947C8_de(arg0, 0x7CF);
                    return;
                }
                goto block_6;
            }
            if (D_800CD780 != 0) {
block_6:
                func_80293824_de(arg0, 1);
                D_8014286C = 1;
            }
        }
    } else {
        if (D_800E28D4 >= 0xDF) {
            D_80146CB8 -= D_800C53F0_de;
        } else {
            D_80146CB8 -= D_800C53F4_de;
        }
        temp_f1 = (f32)D_800E28D4 * D_800C53F8_de;
        if (D_80146CB8 <= -temp_f1) {
            temp_v1 = D_8011B9F0 + 1;
            D_8011B9F0 = temp_v1;
            D_80146CB8 += temp_f1;
            if (D_800D3E14_de[0][temp_v1] == 0) {
                D_80142898 = 1;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                D_80142CB4 = D_800C56AC_eu;
#else
                D_80142CB4 = D_800C53FC_de;
#endif
            }
        }
    }
}
