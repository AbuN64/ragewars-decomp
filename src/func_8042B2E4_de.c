#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Sets the byte at offset 0x10 of the two objects at offsets 0x454 and 0x450 of the structure D_800E4F60
   points to to 0xFF, shows both through func_8040E8D8_de and clears the word at 0x46C. */





extern func_8042B4C4_S1 *D_800E4F60;
extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);

void func_8042B2E4_de(void) {
    (D_800E4F60->unk454)->value = 0xFF;
    (D_800E4F60->unk450)->value = 0xFF;
    func_8040E8D8_de(D_800E4F60->unk450, 1);
    func_8040E8D8_de(D_800E4F60->unk454, 1);
    D_800E4F60->unk46C = 0;
}
