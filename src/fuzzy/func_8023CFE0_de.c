#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_C76B0/data.h"
#include "types.h"
void func_8023CFE0_de(void *arg0) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fv1f;
    f32 var_fv0f;
    f32 var_fv1;
    void *temp_v1;

    if (((s32 *) arg0)[0x2C / sizeof(s32)] != 0) {
        temp_fv1f = D_800D2988 * D_800C3620_de;
        temp_v1 = ((void **) arg0)[0x40 / sizeof(void *)];
        if (temp_fv1f != 0.0f) {
            var_fv0f = ((f32 *) temp_v1)[0x14 / sizeof(f32)] * D_800C3624_de;
            temp_fv0 = D_800C3628_de / temp_fv1f;
            if (!(var_fv0f <= temp_fv0)) {
                var_fv0f = temp_fv0;
            }
            var_fv1 = 0.0f;
            if (((s32 *) arg0)[0x28 / sizeof(s32)] != 0) {
                var_fv1 = ((f32 *) temp_v1)[8 / sizeof(f32)];
            }
            if (var_fv0f == 0.0f) {
                sp0 = 0.0f;
                sp4 = var_fv1;
                sp8 = 0.0f;
            } else {
                sp0 = -((f32 *) arg0)[0x74 / sizeof(f32)] * var_fv0f;
                sp4 = (-((f32 *) arg0)[0x78 / sizeof(f32)] * var_fv0f) + var_fv1;
                sp8 = -((f32 *) arg0)[0x7C / sizeof(f32)] * var_fv0f;
            }
            temp_fv1 = temp_fv1f * D_800C362C_de;
            ((f32 *) arg0)[0x50 / sizeof(f32)] = (f32) (((f32 *) arg0)[0x50 / sizeof(f32)] + ((((f32 *) arg0)[0x74 / sizeof(f32)] + (sp0 * temp_fv1)) * temp_fv1f));
            ((f32 *) arg0)[0x54 / sizeof(f32)] = (f32) (((f32 *) arg0)[0x54 / sizeof(f32)] + ((((f32 *) arg0)[0x78 / sizeof(f32)] + (sp4 * temp_fv1)) * temp_fv1f));
            ((f32 *) arg0)[0x58 / sizeof(f32)] = (f32) (((f32 *) arg0)[0x58 / sizeof(f32)] + ((((f32 *) arg0)[0x7C / sizeof(f32)] + (sp8 * temp_fv1)) * temp_fv1f));
            ((f32 *) arg0)[0x74 / sizeof(f32)] = (f32) (((f32 *) arg0)[0x74 / sizeof(f32)] + (sp0 * temp_fv1f));
            ((f32 *) arg0)[0x78 / sizeof(f32)] = (f32) (((f32 *) arg0)[0x78 / sizeof(f32)] + (sp4 * temp_fv1f));
            ((f32 *) arg0)[0x7C / sizeof(f32)] = (f32) (((f32 *) arg0)[0x7C / sizeof(f32)] + (sp8 * temp_fv1f));
        }
    }
}
