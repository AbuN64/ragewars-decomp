#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_BUILDSAVEPACKET.H"

/* Saves entry i of the 2920-byte records of the block g_pakProfileScreenState points to into the 0x640-byte
   template at offset 0x2E28 through XPlus_CopyBytes, copies the entry's word at 0xBBC to the block's
   0x3468, and stores in the block's 0x346C what Note_Crc32_PakinterfaceBuildsavepacket computes over the template with 0x640
   and 7. */
extern s32 Note_Crc32(void *, s32, s32);




void PAKInterface_BuildSavePacket(s32 index) {
    s32 offset = index * 2920;
    char *recordTemplate = (char *)&g_pakProfileScreenState->packet;

    XPlus_CopyBytes(recordTemplate, (void *)(offset + (s32)g_pakProfileScreenState + 0x70), 0x640);
    g_pakProfileScreenState->packet.savedProfile = ((struct IntegerStateBC0 *) ((char *)g_pakProfileScreenState + offset))->savedProfile;
    g_pakProfileScreenState->packet.checksum = Note_Crc32(recordTemplate, 0x640, 7);
}
