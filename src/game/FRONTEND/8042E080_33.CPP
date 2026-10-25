#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "TYPES.H"

/* Receives player p's 0x648-byte packet through Pak_ReadNoteData into the buffer at 0x2E28 of the
   records D_800E54A4 points to and, when func_804057F8_de checksums its first 0x640 bytes to the
   word stored after them, copies those bytes to the data at 0x18 of the player's 2920-byte record
   at 0x58 and the trailing word at 0x640 to the record's last word, returning 1; otherwise it reports the failure through
   Pak_DeleteNote, marks both of the record's states at 0x0 and 0x14 as 2 and returns 0. Written
   from the assembly with nested tests each reporting the failure, which GCC cross-jumps into one
   call. */







extern s32 Pak_ReadNoteData(s32, s32, PakSavePacket *, s32);
extern s32 Ovlgame_Crc32(PakSavePacket *, s32, s32);
extern void Pak_DeleteNote(s32, s32);

s32 func_80434638_de(s32 player, s32 channel) {
    PakSavePacket *packet;
    s32 received;

    received = 0;
    packet = &D_800E54A4->packet;
    if (Pak_ReadNoteData(player, channel, packet, 0x648) == 0) {
        if (Ovlgame_Crc32(packet, 0x640, 7) == packet->checksum) {
            Resmgr_CopyBytes(D_800E54A4->players[player].slots, &D_800E54A4->packet, 0x640);
            received = 1;
            D_800E54A4->players[player].profile = D_800E54A4->packet.savedProfile;
        } else {
            Pak_DeleteNote(player, channel);
        }
    } else {
        Pak_DeleteNote(player, channel);
    }
    if (received == 0) {
        D_800E54A4->players[player].back = 2;
        D_800E54A4->players[player].state = 2;
    }
    return received;
}
