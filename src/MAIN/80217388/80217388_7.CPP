#include "gfx.h"
#include "abi.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80217388.h"
#include "common/reset_storage.h"
#include "TYPES.H"
#include "n64sdk.h"
#include "gbi.h"
#include "common/unused.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_80291054.h"
#include "span_C76B0/data.h"












/** Reset the object and initialize its thirty-six descending-offset records. */
void func_8021836C_de(char *arg0) {
    s32 i;
    s32 minus_one = -1;
    f32 scale = D_800C224C_de;
    f32 value = D_800C913C_de;

    ((ResetThirtySixStorage *)(arg0))->unk0 = 0;
    ((ResetThirtySixStorage *)(arg0))->unk4 = 0;
    ((ResetThirtySixStorage *)(arg0))->unk8 = 0;
    ((ResetThirtySixStorage *)(arg0))->unkC = 0;
    ((ResetThirtySixStorage *)(arg0))->unk14 = 0;
    ((ResetThirtySixStorage *)(arg0))->unk37C = minus_one;
    ((ResetThirtySixStorage *)(arg0))->unk380 = 1;
    ((ResetThirtySixStorage *)(arg0))->unk388 = minus_one;
    ((ResetThirtySixStorage *)(arg0))->unk18 = 0;
    ((ResetThirtySixStorage *)(arg0))->unk38C = 0;
    ((ResetThirtySixStorage *)(arg0))->unk390 = minus_one;

    for (i = 0; i < 0x24; i++, arg0 = (char *)((u32)arg0 + 0x18)) {
        f32 scaled = i * scale;
        ((ResetThirtySixStorage *)(arg0))->unk2C = 0;
        ((ResetThirtySixStorage *)(arg0))->unk30 = value;
        ((ResetThirtySixStorage *)(arg0))->unk28 = -scaled;
    }
}

extern void func_80217928_de(s32 arg0, s32 arg1, s32 arg2);

void func_802183E8_de(s32 arg0, s32 arg1, s32 arg2) {
    Gfx *cmd;

    func_802A9234_de(0xFF);
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    func_80217928_de(arg0, arg1, arg2);
}

/** Preserve the empty hook at VRAM 0x80218464. */
void func_80218464_de(void) {
}









s32 func_8021846C_de(void *arg0, void *arg1) {
    f32 temp_f1;

    temp_f1 = ((ResetTimerStorage *)(arg0))->unk4;
    if (temp_f1 > 0.0f) {
        ((ResetTimerStorage *)(arg0))->unk4 = temp_f1 - D_800D2988;
        return 0;
    }
    if (((ResetFlagsStorage *)((((ResetOwnerStorage *)(arg1))->unk698)))->unkB0 & 0x8000) {
        return 0;
    }
    ((ResetTimerStorage *)(arg0))->unk37C = -1;
    return 1;
}





f32 func_802184C0_de(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    func_80274020_de(&arg0);
    func_80274020_de(&arg1);
    if (arg2 > 0) {
        if (arg1 < arg0) {
            arg1 += D_800C2250_de;
        }
    } else if (arg1 > arg0) {
        arg1 -= D_800C2254_de;
    }
    f3 = arg1 - arg0;
    f1 = f3 * arg3 * D_800D2988;
    f2 = f1;
    if (f1 < 0.0f) {
        f2 = -f1;
    }
    if (f3 < 0.0f) {
        if (-f3 < f2) {
            goto clamp;
        }
    } else if (f3 < f2) {
clamp:
        f1 = f3;
    }
    return f1;
}
