#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Saves entry i of the 2920-byte records of the block D_800E54A4 points to into the 0x640-byte
   template at offset 0x2E28 through func_802A0724_de, copies the entry's word at 0xBBC to the block's
   0x3468, and stores in the block's 0x346C what func_804057F8_de computes over the template with 0x640
   and 7. */
extern char *D_800E54A4;
extern void func_802A0724_de(void *, void *, s32);
extern s32 func_804057F8_de(void *, s32, s32);




void func_8043542C_de(s32 index) {
    s32 offset = index * 2920;
    char *template = D_800E54A4 + 0x2E28;

    func_802A0724_de(template, (void *)(offset + (s32)D_800E54A4 + 0x70), 0x640);
    ((IntegerState3470 *)(D_800E54A4))->unk_3468 = ((struct IntegerStateBC0 *) (D_800E54A4 + offset))->unk_BBC;
    ((IntegerState3470 *)(D_800E54A4))->unk_346C = func_804057F8_de(template, 0x640, 7);
}
