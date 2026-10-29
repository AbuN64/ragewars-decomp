#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_RESTORESAVEPACKET.H"

/* Copies the 0x640-byte template at offset 0x2E28 of the block g_pakProfileScreenState points to into offset
   0x70 of its 2920-byte entry i through XPlus_CopyBytes, then copies the block's word at 0x3468 to
   that entry's word at 0xBBC. */






void PAKInterface_RestoreSavePacket(s32 index) {
    s32 offset = index * 2920;

    XPlus_CopyBytes(&((PakSavePacketView *)((offset + (s32) g_pakProfileScreenState)))->unk_70, &g_pakProfileScreenState->packet, 0x640);
    ((struct IntegerStateBC0 *) ((char *)g_pakProfileScreenState + offset))->unk_BBC = g_pakProfileScreenState->packet.savedProfile;
}
