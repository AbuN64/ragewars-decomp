#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_55.H"

/* Copies the 0x640-byte template at offset 0x2E28 of the block D_800E54A4 points to into offset
   0x70 of its 2920-byte entry i through XPlus_CopyBytes, then copies the block's word at 0x3468 to
   that entry's word at 0xBBC. */






void func_804354C0_de(s32 index) {
    s32 offset = index * 2920;

    XPlus_CopyBytes(&((ObjectState71 *)((offset + (s32) D_800E54A4)))->unk_70, &D_800E54A4->packet, 0x640);
    ((struct IntegerStateBC0 *) ((char *)D_800E54A4 + offset))->unk_BBC = D_800E54A4->packet.savedProfile;
}
