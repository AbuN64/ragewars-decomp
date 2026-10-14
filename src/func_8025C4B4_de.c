#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025A3EC.h"
#include "types.h"

extern void func_802B2F00_de(void *arg0, s16 arg1);
extern void func_802B2E80_de(void *arg0, f32 arg1);








void func_8025C4B4_de(void *arg0, f32 arg1) {
    Record_func_8025B758_de *slot = arg0;
    Owner_func_8025B5F0_de *owner;
    s32 temp_s0;
    void *temp_s0_2;
    f32 scaled;

    temp_s0 = slot->owner;
    owner = (Owner_func_8025B5F0_de *)temp_s0;
    temp_s0_2 = owner->sound;
    func_802B2F00_de(temp_s0_2, owner->samples[slot->index]);
    scaled = arg1 * (slot->f34);
    scaled = scaled * (slot->fB8);
    func_802B2E80_de(temp_s0_2, scaled);
}
