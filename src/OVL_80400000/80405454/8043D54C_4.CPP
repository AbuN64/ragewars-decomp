#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043D54C.h"
#include "TYPES.H"














/* note: Clears eight status bytes and selects the first available profile. */
void func_8025E384_de(void);
unsigned int func_8026437C_de(void *);
extern s32 D_8010F328;
extern s32 D_80146302;
extern struct SharedRecAt148 D_80142622[];










void func_8043DE50_de(func_80250BD4_S1 *arg0) {
    Shared_func_8043DEDC_S3 *settings;
    s8 *status;
    s32 *profile;
    s32 on;
    s32 i;

    i = 7;
    status = (s8 *)&D_80142622[0];
    for (; i >= 0; i--) {
        ((SharedRecAt148 *)status)->unk148 = 0;
        status -= 0x96;
    }
    i = 0;
    settings = (Shared_func_8043DEDC_S3 *)&D_80146302;
    /* FAKEMATCH: constant-holding local places li across the callback. */
    on = 1;
    for (profile = &D_8010F328; i < 4; i++, profile = &((SharedRecAt224 *)profile)->unk224) {
        if (func_8026437C_de(profile) != 0) {
            settings->unk78 = on;
            settings->unk7F = i;
            arg0->unk20 = profile;
            break;
        }
    }
    func_8025E384_de();
}
