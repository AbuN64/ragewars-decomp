#include "MAIN/8025DA30.H"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_8025D948.h"
#include "TYPES.H"

/* Sets the sound fade state and derives its step from the clamped duration. */

void func_8025DACC_de(StateRecAt34 *arg0) {
    f32 var_f2;

    var_f2 = arg0->unk30;
    arg0->unk1C = 2;
    arg0->unk18 = 0x20;
    arg0->unk20 = (s32) (arg0->unk2C * 32767.0f);
    if (!(var_f2 >= 0.1f)) {
        var_f2 = 0.1f;
    }
    arg0->unk30 = var_f2;
    arg0->unk28 = 0;
    arg0->unk34 = (f32) ((f32) arg0->unk20 / (var_f2 * 60.0f));
}

void func_8025DB34_de(Track *arg0) {
    arg0->unk38 = 1;
    arg0->unk40 = 0;
}

/** Clear offset 0x38 and initialize offset 0x40 from D_800C9108. */
void func_8025DB44_de(Track *arg0) {
    arg0->unk40 = D_800C9108;
    arg0->unk38 = 0;
}

s32 func_802AFF90_de(s32);
void func_8025DB58_de(s32 a) {
    (((struct IntegerState2C_2 *) ((s8 *) a))->unk_28) = -1;
    func_802AFF90_de((((struct IntegerState2C_2 *) ((s8 *) a))->unk_14));
}
