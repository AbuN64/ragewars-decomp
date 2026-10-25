#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_54.H"

/* Saves entry i of the 2920-byte records of the block D_800E54A4 points to into the 0x640-byte
   template at offset 0x2E28 through Resmgr_CopyBytes, copies the entry's word at 0xBBC to the block's
   0x3468, and stores in the block's 0x346C what func_804057F8_de computes over the template with 0x640
   and 7. */
extern s32 Ovlgame_Crc32(void *, s32, s32);




void func_8043542C_de(s32 index) {
    s32 offset = index * 2920;
    char *recordTemplate = (char *)&D_800E54A4->packet;

    Resmgr_CopyBytes(recordTemplate, (void *)(offset + (s32)D_800E54A4 + 0x70), 0x640);
    D_800E54A4->packet.savedProfile = ((struct IntegerStateBC0 *) ((char *)D_800E54A4 + offset))->unk_BBC;
    D_800E54A4->packet.checksum = Ovlgame_Crc32(recordTemplate, 0x640, 7);
}
