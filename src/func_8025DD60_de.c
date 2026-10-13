#include "span_1000/code_8025C544.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8025D948.h"
#include "types.h"

extern f32 D_800C4030_de[];


extern void func_802AE5B8_de(s32 arg0, s32 arg1);


extern void func_802AFEE0_de(s32 arg0, s32 arg1, s8 arg2);









void func_8025DD60_de(void *arg0) {
    s32 i;
    f32 scaled;

    i = 0;
    func_802AE5B8_de(((Track *)arg0)->unk10, ((Track *)arg0)->unkC);
    func_802AFF30_de(((Track *)arg0)->unk14, ((Track *)arg0)->unk10);
    func_802AFEB0_de(((Track *)arg0)->unk14,
                  ((Track *)arg0)->unk8->field_4);
    do {
        func_802AFEE0_de(((Track *)arg0)->unk14, i & 0xFF, 0);
        i++;
    } while (i < 0x14);

    scaled = (f32)((Track *)arg0)->unk24 *
             (((Track *)arg0)->unk0->unk2BA4 * D_800C4030_de[1]);
    func_802AFF60_de(((Track *)arg0)->unk14, (s16)(s32)(scaled * D_800C4038_de));
    ((Track *)arg0)->unk2C = scaled;
}
