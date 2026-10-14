#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Copies the 0x640-byte template at offset 0x2E28 of the block D_800E54A4 points to into offset
   0x70 of its 2920-byte entry i through func_802A0724_de, then copies the block's word at 0x3468 to
   that entry's word at 0xBBC. */
extern char *D_800E54A4;
extern void func_802A0724_de(void *, void *, s32);






void func_804354C0_de(s32 index) {
    s32 offset = index * 2920;

    func_802A0724_de(&((ObjectState71 *)((offset + (s32) D_800E54A4)))->unk_70, D_800E54A4 + 0x2E28, 0x640);
    ((struct IntegerStateBC0 *) (D_800E54A4 + offset))->unk_BBC = ((IntegerState346C *)(D_800E54A4))->unk_3468;
}
