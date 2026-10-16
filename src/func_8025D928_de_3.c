#include "span_1000/code_8025D948.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "span_1000/code_8025C544.h"
#include "types.h"

extern void func_802AE5B8_de(s32 arg0, s32 arg1);


void func_8025DC34_de(void *arg0, f32 arg1) {
    Track *track = arg0;
    f32 f20 = arg1;
    f32 f0 = f20 * D_800C4020_de;
    func_802AFF60_de(track->unk14, (s16)(s32) f0);
    track->unk2C = f20;
}

void func_8025DC88_de(void *arg0) {
    extern f32 D_800C4030_de;
    ObjectState40 *o = arg0;
    f32 var_f20;
    ContextRecAt2BC0 *temp_v0;

    if (o->unk_38 != 0) {
        f32 prod = o->context->green;
        prod = prod * D_800C4024_de;
        var_f20 = (f32) (o->unk_24);
        var_f20 = var_f20 * prod;
        var_f20 = var_f20 * o->unk_3C;
        goto do_update;
    }
    temp_v0 = o->context;
    var_f20 = (f32) (o->unk_24) * (temp_v0->green * D_800C4028_de);
    if (temp_v0->field2BB8 != 0) {
        var_f20 = var_f20 * (0.699999988079071f);
    }
    if (var_f20 != o->unk_2C) {
do_update:
        func_802AFF60_de(o->unk_14, (s16) (s32) (var_f20 * D_800C4030_de));
        o->unk_2C = var_f20;
    }
}

void func_8025DD60_de(Track *arg0) {
    extern f32 D_800C4030_de[];
    s32 i;
    f32 scaled;

    i = 0;
    func_802AE5B8_de(arg0->unk10, arg0->unkC);
    func_802AFF30_de(arg0->unk14, arg0->unk10);
    func_802AFEB0_de(arg0->unk14,
                  arg0->unk8->field_4);
    do {
        func_802AFEE0_de(arg0->unk14, i & 0xFF, 0);
        i++;
    } while (i < 0x14);

    scaled = (f32)arg0->unk24 *
             (arg0->unk0->unk2BA4 * D_800C4030_de[1]);
    func_802AFF60_de(arg0->unk14, (s16)(s32)(scaled * D_800C4038_de));
    arg0->unk2C = scaled;
}
