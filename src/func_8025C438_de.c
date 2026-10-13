#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025A3EC.h"
#include "types.h"

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern void func_802B2F10_de(void *arg0, s16 arg1);








void func_8025C438_de(void *arg0, s32 arg1) {
    Record_func_8025B758_de *slot = arg0;
    Owner_func_8025B5F0_de *owner;
    s32 temp_s0;
    void *temp_s0_2;

    temp_s0 = slot->owner;
    owner = (Owner_func_8025B5F0_de *)temp_s0;
    temp_s0_2 = owner->sound;
    func_802B2F00_de(temp_s0_2, owner->samples[slot->index]);
    func_802B2F10_de(temp_s0_2, (s16)(s32)((f32) arg1 * (slot->fC8)));
}
